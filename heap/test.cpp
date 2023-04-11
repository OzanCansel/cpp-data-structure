#include "utest.h"
#include "heap.hpp"

#define CHECK_HEAP(numbers) \
    for (size_t parent = 0; parent < numbers.size() / 2 - 1; parent++) \
    {\
        auto left  = parent * 2 + 1;\
        auto right = parent * 2 + 2;\
\
        if (left < numbers.size())\
            EXPECT_LE(numbers[left] , numbers[parent]);\
\
        if (right < numbers.size())\
            EXPECT_LE(numbers[right], numbers[parent]);\
    }\

UTEST(heap, heapify)
{
    std::vector<int> numbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    heapify(numbers);
    CHECK_HEAP(numbers);
}

UTEST(heap, shift_up)
{
    std::vector<int> numbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    heapify(numbers);

    numbers.push_back(15);

    shift_up(numbers, numbers.size() - 1);

    CHECK_HEAP(numbers);
}

UTEST(heap, shift_down)
{
     std::vector<int> numbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    heapify(numbers);

    numbers.push_back(-1);

    shift_down(numbers, numbers.size(), 0);

    CHECK_HEAP(numbers);
}



UTEST_MAIN();
