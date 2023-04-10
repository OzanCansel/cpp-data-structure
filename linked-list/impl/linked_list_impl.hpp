#include "linked_list.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
linked_list<T>::linked_list()
    :   m_head {}
{}

template<typename T>
linked_list<T>&
linked_list<T>::push_front(T val)
{
    auto brand_new = new node{ nullptr, std::move(val) };

    auto old_head = m_head;

    m_head = brand_new;
    m_head->next = old_head;

    return *this;
}

template<typename T>
linked_list<T>&
linked_list<T>::push_back(T val)
{
    auto brand_new = new node{ nullptr, std::move(val) };

    if (!m_head)
    {
        m_head = brand_new;

        return *this;
    }

    auto curr = m_head;

    while (curr->next)
        curr = curr->next;

    curr->next = brand_new;

    return *this;
}

template<typename T>
void
linked_list<T>::insert(T val, size_t idx)
{
    if (!m_head)
    {
        push_back(std::move(val));

        return;
    }

    if (idx == 0 && !m_head->next)
    {
        push_front(std::move(val));

        return;
    }

    node* brand_new = new node { nullptr, std::move(val) };

    if (idx == 0)
    {
        push_front(std::move(val));

        return;
    }

    auto curr { m_head };
    auto prev { m_head };

    while (curr)
    {
        if (idx == 0)
            break;

        prev = curr;
        curr = curr->next;
        idx--;
    }

    if (!curr)
    {
        prev->next = brand_new;
    }
    else
    {
        prev->next = brand_new;
        brand_new->next = curr;
    }
}

template<typename T>
void
linked_list<T>::erase(const T& val)
{
    node* prev { nullptr };
    node* curr { m_head };

    while (curr) {
        if (curr->value == val)
            break;

        prev = curr;
        curr = curr->next;
    }

    if (curr)
    {
        if (!prev)
            m_head = curr->next;
        else
            prev->next = curr->next;

        delete curr;
    }
}

template<typename T>
bool
linked_list<T>::empty() const
{
    return !m_head;
}

template<typename T>
size_t
linked_list<T>::size() const
{
    size_t n {};
    node* curr { m_head };

    while (curr)
    {
        n++;
        curr = curr->next;
    }

    return n;
}

template<typename T>
T
linked_list<T>::at(size_t idx) const
{
    auto curr { m_head };

    while (curr)
    {
        if (idx == 0)
            break;

        curr = curr->next;
        idx--;
    }

    if (idx)
        throw std::out_of_range { "'idx' is out of bound." };

    return curr->value;
}

template<typename T>
void
linked_list<T>::print() const
{
    auto curr { m_head };

    while (curr)
    {
        std::cout << m_head->value << '\n';

        curr = curr->next;
    }

    std::cout << std::endl;
}
