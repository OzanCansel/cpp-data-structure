#pragma once

#include "stack.hpp"

template<typename T>
class queue
{
public:

    void enqueue(T val);
    T dequeue();
    size_t size() const;
    bool empty() const;

private:

    stack<T> m_outbox;
    stack<T> m_inbox;
};

#include "impl/queue_impl.hpp"
