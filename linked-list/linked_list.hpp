#pragma once

#include <cstddef>

template<typename T>
class linked_list
{
public:

    linked_list();
    ~linked_list();
    linked_list(const linked_list&);
    linked_list(linked_list&&);
    linked_list& operator=(const linked_list&);
    linked_list& operator=(linked_list&&);

    linked_list& push_front(T val);
    linked_list& push_back(T val);
    void insert(T val, size_t idx);
    void erase(const T& val);
    void erase_at(size_t idx);
    bool empty() const;
    size_t size() const;

    template<typename Predicate>
    const T* find_if(Predicate&& value) const;
    const T& at(size_t idx) const;
    T& at(size_t idx);
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
