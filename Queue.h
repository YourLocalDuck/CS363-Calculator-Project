#ifndef _QUEUE_H
#define _QUEUE_H

#define defaultSize 5

#include "Array.h"

template <typename T>
class Queue
{
public:
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception(void)
            : std::exception() {}

        /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
        empty_exception(const char *msg)
            : std::exception(msg) {}
    };

    typedef T type;

    Queue(void);

    Queue(const Queue &q);

    ~Queue(void);

    const Queue &operator=(const Queue &rhs);

    void enqueue(T element);

    T dequeue(void);

    bool is_empty(void) const;

    size_t size(void) const;

    size_t max_size(void) const;

    T front(void) const;

    void clear(void);

private:
    T front_;
    
    // COMMENT You are supposed to use your array class. No feedback
    // will be provided since the array class and raw C array result
    // in a completely different design.

    // FIX: I misread the instructions. I redesigned the Queue class to use the Array class.

    Array<T> *data_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.hpp"

#endif
