#include "queue.hpp"
#include <cassert>

template<typename T>
void
queue<T>::enqueue(T value)
{
    m_inbox.push(std::move(value));
}

template<typename T>
T
queue<T>::dequeue()
{
    assert(!empty());

    if (m_outbox.empty())
    {
        while (!m_inbox.empty())
        {
            m_outbox.push(std::move(m_inbox.top()));

            m_inbox.pop();
        }
    }

    T value = std::move(m_outbox.top());

    m_outbox.pop();

    return value;
}

template<typename T>
size_t
queue<T>::size() const
{
    return m_inbox.size() + m_outbox.size();
}

template<typename T>
bool
queue<T>::empty() const
{
    return size() == 0;
}
