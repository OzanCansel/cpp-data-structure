#include "heap.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cassert>

template<typename T>
std::string to_string(const T& val)
{
    return (std::stringstream {} << val).str();
}

template<typename T>
void shift_up(std::vector<T>& vec, size_t idx)
{
    assert(idx < vec.size());

retry:
    if (idx == 0)
        return;

    size_t parent { (idx - 1) / 2 };

    if (vec[idx] > vec[parent])
    {
        std::swap(vec[idx], vec[parent]);

        idx = parent;

        goto retry;
    }
}

template<typename T>
void shift_down(std::vector<T>& vec, size_t N, size_t parent)
{
    assert(vec.size() <= N);

retry:
    size_t left  = parent * 2 + 1;
    size_t right = parent * 2 + 2;
    size_t new_parent { parent };

    if (left < N && vec[left] > vec[new_parent])
        new_parent = left;

    if (right < N && vec[right] > vec[new_parent])
        new_parent = right;

    if (new_parent != parent)
    {
        std::swap(vec[new_parent], vec[parent]);

        parent = new_parent;

        goto retry;
    }
}

template<typename T>
void heapify(std::vector<T>& vec, size_t N)
{
    if (vec.empty())
        return;

    for (int64_t deepest_non_leaf = int64_t(vec.size()) / 2 - 1;
         deepest_non_leaf >= 0;
         --deepest_non_leaf)
        shift_down(vec, vec.size(), deepest_non_leaf);
}

template<typename T>
void heapify(std::vector<T>& vec)
{
    heapify(vec, vec.size());
}

template<typename T>
void print_heap(std::vector<T>& vec, size_t N)
{
    int depth { int(std::ceil(std::log2(float(vec.size()) + 1))) };
    int n_elems_at_bottom { int(std::pow(2, depth - 1)) };

    auto max_elem = *max_element(
        begin(vec),
        end(vec),
        [](const T& x, const T& y){
            return to_string(x).size() < to_string(y).size();
        }
    );

    auto max_elem_size = to_string(max_elem).size();
    auto elem_size = max_elem_size + 2;

    auto max_n_chars_per_line { elem_size * n_elems_at_bottom }; 

    for (int i = 0, curr = 0; i < depth; ++i)
    {
        int n_elems = int(std::pow(2, i));
        int left_shift = (max_n_chars_per_line - (n_elems * elem_size)) / 2;

        std::cout << std::setw(left_shift) << "";

        for (int n = 0; n < n_elems && size_t(curr) < vec.size(); ++n)
        {
            std::cout << std::setw(elem_size) << vec[curr++]; 
        }

        std::cout << std::endl;
    }
}

