#include "ringbuffer.h"

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

#include "common/logger.h"

#define report_exceptional_condition() abort ()

RingBuffer::RingBuffer(unsigned long order){
    create(order);
}

RingBuffer::~RingBuffer(){
    free();
}

//Warning order should be at least 12 for Linux
//order初始化大小为2的order次方
void RingBuffer::create(unsigned long order){
    if(order<12){
        LOG_DEBUG("create fail: order can not less than 12, order=%d.", order);
        report_exceptional_condition();
    }

    char path[] = "/dev/shm/ring-buffer-XXXXXX";
    int file_descriptor;
    void *address;
    int status;

    file_descriptor = mkstemp(path);
    if (file_descriptor < 0)
        report_exceptional_condition();

    status = unlink(path);
    if (status)
        report_exceptional_condition();

    m_count_bytes = 1UL << order;
    m_write_offset_bytes = 0;
    m_read_offset_bytes = 0;

    status = ftruncate(file_descriptor, m_count_bytes);
    if (status)
        report_exceptional_condition();

    m_address = mmap(NULL, m_count_bytes << 1, PROT_NONE,
            MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    if (m_address == MAP_FAILED)
        report_exceptional_condition();

    address = mmap(m_address, m_count_bytes, PROT_READ | PROT_WRITE,
            MAP_FIXED | MAP_SHARED, file_descriptor, 0);

    if (address != m_address)
        report_exceptional_condition();

    address = mmap((char*)m_address + m_count_bytes,
            m_count_bytes, PROT_READ | PROT_WRITE,
            MAP_FIXED | MAP_SHARED, file_descriptor, 0);

    if (address != (char*)m_address + m_count_bytes)
        report_exceptional_condition();

    status = close(file_descriptor);
    if (status)
        report_exceptional_condition();
}

void RingBuffer::free(){
    int status;
    status = munmap (m_address, m_count_bytes << 1);
    if (status)
        report_exceptional_condition ();
}

void* RingBuffer::WriteAddress(){
    return (char*)m_address + m_write_offset_bytes;
}

void RingBuffer::WriteAdvance(unsigned long count_bytes){
    m_write_offset_bytes += count_bytes;
}

void* RingBuffer::ReadAddress(){
    return (char*)m_address + m_read_offset_bytes;
}

void RingBuffer::ReadAdvance(unsigned long count_bytes){
    m_read_offset_bytes += count_bytes;

    if (m_read_offset_bytes >= m_count_bytes){
        /*如果读指针大于等于缓冲区长度，那些读写指针同时折返回[0, buffer_size]范围内  */
        m_read_offset_bytes -= m_count_bytes;
        m_write_offset_bytes -= m_count_bytes;
    }
}

unsigned long RingBuffer::CountBytes(){
    return m_write_offset_bytes - m_read_offset_bytes;
}

unsigned long RingBuffer::CountFreeBytes(){
    return m_count_bytes - CountBytes();
}

void RingBuffer::clear(){
    m_write_offset_bytes = 0;
    m_read_offset_bytes = 0;
}

/*Note, that initial anonymous mmap() can be avoided - after initial mmap() for descriptor fd,
  you can try mmap() with hinted address as (buffer->address + buffer->count_bytes) and if it fails -
  another one with hinted address as (buffer->address - buffer->count_bytes).
  Make sure MAP_FIXED is not used in such case, as under certain situations it could end with segfault.
  The advantage of such approach is, that it avoids requirement to map twice the amount you need initially
  (especially useful e.g. if you want to use hugetlbfs and the allowed amount is limited)
  and in context of gcc/glibc - you can avoid certain feature macros
  (MAP_ANONYMOUS usually requires one of: _BSD_SOURCE, _SVID_SOURCE or _GNU_SOURCE).*/
