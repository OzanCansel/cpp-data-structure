#pragma once

#include <cstddef>

template<typename T>
class linked_list
{
public:

    linked_list();
    linked_list& push_front(T val);
    linked_list& push_back(T val);
    void insert(T val, size_t idx);
    void erase(const T& val);
    bool empty() const;
    size_t size() const;
    T at(size_t idx) const;
    void print() const;

private:

    struct node
    {
        node* next;
        T  value;
    };

    node* m_head;
};

#include "impl/linked_list_impl.hpp"
