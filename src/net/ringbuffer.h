#ifndef _RINGBUFFER_H_
#define _RINGBUFFER_H_

class RingBuffer{
    public:
        RingBuffer(unsigned long order);
        RingBuffer(const RingBuffer &ringBuffer);
        RingBuffer& operator=(const RingBuffer &ringBuffer);
        ~RingBuffer();

        void* WriteAddress();
        void WriteAdvance(unsigned long count_bytes);
        void* ReadAddress();
        void ReadAdvance(unsigned long count_bytes);
        unsigned long CountBytes();
        unsigned long CountFreeBytes();

    private:
        void create(unsigned long order);
        void free();
        void clear();

    private:
        void* m_address;
        unsigned long m_count_bytes;
        unsigned long m_write_offset_bytes;
        unsigned long m_read_offset_bytes;
};
#endif /* _RINGBUFFER_H_ */
