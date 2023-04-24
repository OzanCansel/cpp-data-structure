#include "stack.hpp"

template<typename T>
void
stack<T>::push(T value)
{
    m_list.push_back(std::move(value));
}

template<typename T>
T&
stack<T>::top()
{
    return m_list.at(m_list.size() - 1);
}

template<typename T>
const T&
stack<T>::top() const
{
    return m_list.at(m_list.size() - 1);
}

template<typename T>
void
stack<T>::pop()
{
    m_list.erase_at(m_list.size() - 1);
}

template<typename T>
size_t
stack<T>::size() const
{
    return m_list.size();
}

template<typename T>
bool
stack<T>::empty() const
{
    return size() == 0;
}
