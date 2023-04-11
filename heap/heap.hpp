#pragma once

#include <vector>
#include <cstdint>
#include <string>

template<typename T>
std::string to_string(const T&);

template<typename T>
void shift_down(std::vector<T>&, size_t N, size_t parent);

template<typename T>
void shift_up(std::vector<T>&, size_t idx);

template<typename T>
void heapify(std::vector<T>&, size_t N);

template<typename T>
void heapify(std::vector<T>&);

template<typename T>
void print_heap(std::vector<T>&, size_t N);

#include "impl/heap_impl.hpp"
