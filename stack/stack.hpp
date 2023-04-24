#pragma once

#include "linked_list.hpp"

template<typename T>
class stack
{
public:

    void push(T val);
    T& top();
    const T& top() const;
    void pop();
    size_t size() const;

private:

    linked_list<T> m_list;
};

#include "impl/stack_impl.hpp"
