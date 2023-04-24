#include "linked_list.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
linked_list<T>::linked_list()
    :   m_head {}
{}

template<typename T>
linked_list<T>::~linked_list()
{
    auto curr { m_head };

    while (curr)
    {
        auto next { curr->next };

        delete curr;

        curr = next;
    }
}

template<typename T>
linked_list<T>::linked_list(const linked_list& x)
{
    m_head = nullptr;

    for (size_t i = 0; i < x.size(); ++i)
        push_back(x.at(i));
}

template<typename T>
linked_list<T>::linked_list(linked_list&& x)
{
    m_head = x.m_head;
    x.m_head = nullptr;
}

template<typename T>
linked_list<T>&
linked_list<T>::operator=(const linked_list<T>& x)
{
    for (size_t i = 0; i < x.size(); ++i)
        push_back(x.at(i));

    return *this;
}

template<typename T>
linked_list<T>&
linked_list<T>::operator=(linked_list<T>&& x)
{
    m_head = x.m_head;
    x.m_head = nullptr;

    return *this;
}

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
template<typename Predicate>
const T*
linked_list<T>::find_if(Predicate&& predicate) const
{
    auto curr { m_head };

    while (curr)
    {
        if (predicate(curr->value))
            return &curr->value;

        curr = curr->next;
    }

    return nullptr;
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
void
linked_list<T>::erase_at(size_t idx)
{
    node* prev { nullptr };
    node* curr { m_head };

    while (curr) {
        if (idx == 0)
            break;

        prev = curr;
        curr = curr->next;
        idx--;
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
const T&
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
T&
linked_list<T>::at(size_t idx)
{
    return const_cast<T&>(
        const_cast<const linked_list<T>*>(this)->at(idx)
    );
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

