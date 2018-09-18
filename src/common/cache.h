#ifndef _CACHE_H_
#define _CACHE_H_

#include<cassert>
#include<iostream>
#include <mutex>
#include <unistd.h>

using namespace std;
template<typename T>
class Queue
{
    public:
        Queue(int maxsize = 10, bool fix=true);
        Queue(const Queue<T>& rhs);
        Queue<T>& operator=(const Queue<T>& rhs);
        ~Queue();
    public:
        bool empty() const;
        bool IsFull() const;
        int size() const;

        void push(const T& data);
        T* pop();
        T& front();
        T   front() const;
        T& back();
        T   back() const;
    private:
        T *array;
        int Front;//队首元素
        int rear;//队尾元素
        int capacity;
        bool m_fix;
        std::mutex m_mtx;
};

template<typename T>
Queue<T>::Queue(int maxsize, bool fix):
    Front(0),
    rear(0),
    capacity(maxsize+1), //队尾需始终空一个元素
    m_fix(fix)
{
    array = new T[maxsize];
    assert(array != NULL);    //存储分配失败则退出;
}

    template<typename T>
Queue<T>::Queue(const Queue<T>& rhs) :Front(rhs.Front), rear(rhs.rear),capacity(rhs.capacity)
{
    array = new T[capacity];
    for (int i = 0; i != (this->size()); i++)
        array[i] = rhs.array[i];
}

    template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if (this != &rhs)
    {
        delete[] array;
        capacity = rhs.capacity;
        Front = rhs.Front;
        rear = rhs.rear;
        array = new T[capacity];
        for (int i = 0; i != (this->size()); i++)
            array[i] = rhs.array[i];
    }
    return *this;
}
    template<typename T>
Queue<T>::~Queue()
{
    delete[] array;
}

template<typename T>
bool Queue<T>::empty() const
{
    return Front == rear;      //此处为循环队列，当front==rear时为空。
}

template<typename T>
bool Queue<T>::IsFull() const
{
    return(rear + 1) % capacity == Front;   //当（rear+1）%capacity==front为满,因为为满时差一个元素，但是可能rear>front,也可能rear<front.
}

template<typename T>
int Queue<T>::size() const
{
    return (rear - Front + capacity) % capacity;
}

    template<typename T>
void Queue<T>::push(const T& data)
{
    if (m_fix){
        while(IsFull()){
            usleep(1000*10);
        }
        std::lock_guard<std::mutex> mtx_locker(m_mtx);
        array[rear] = data;
        rear = (rear + 1) % capacity;
    }else{
        std::lock_guard<std::mutex> mtx_locker(m_mtx);
        if (!IsFull())
        {
            array[rear] = data;
            rear = (rear + 1) % capacity;
        }
        else                                                  //当队列满了之后可进行扩容
        {
            T *newarray=new T[ 2*capacity ];
            for (int i = 0; i != 2*capacity&&!this->empty(); i++)
            {
                newarray[i] =this-> front();
                this->pop();
            }
            delete [ ] array;
            array = newarray;
            Front = 0;
            array[rear] = data;
            rear =this->rear+1;
            capacity = 2*capacity;
        }
    }
}

//template<typename T>
//void Queue<T>::pop()
//{
//if (!empty())
//{
////array[Front].~T();   //将队头元素析构掉
//Front = (Front + 1) % capacity;
//}
//else
//cout<<"empty queue!"<<endl;
//}

    template<typename T>
T* Queue<T>::pop()
{
    T* p = NULL;
    while (true){
        if (!empty())
        {
            std::lock_guard<std::mutex> mtx_locker(m_mtx);
            //array[Front].~T();   //将队头元素析构掉
            p = &array[Front];
            Front = (Front + 1) % capacity;
            break;
        }
        else{
            usleep(1000*10);
        }
    }
    return p;
}

    template<typename T>
T& Queue<T>::front()
{
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    if (empty())
        cerr << "Error, queue is empty!";
    return array[Front];
}
template<typename T>
T Queue<T>::front() const
{
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    if (empty())
        cerr << "Error, queue is empty!";
    return array[Front];
}
    template<typename T>
T& Queue<T>::back()
{
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    if (empty())
        cerr << "Error, queue is empty!";
    return array[rear-1];                             //rear类似与尾后指针
}
template<typename T>
T Queue<T>::back() const
{
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    if (empty())
        cerr << "Error, queue is empty!";
    return array[rear-1];
}

#endif /* _CACHE_H_ */
