#include "utest.h"
#include "hash_map.hpp"

UTEST(hash_map, size)
{
    hash_map<int, int> m;

    EXPECT_EQ(m.size(), size_t(0));

    for (int i = 0; i < 100; ++i)
        m.insert(i, i);

    EXPECT_EQ(m.size(), size_t(100));
}

UTEST(hash_map, insert)
{
    hash_map<int, int> m;

    EXPECT_EQ(m.size(), size_t(0));

    for (int i = 0; i < 100; ++i)
        m.insert(i, i);

    EXPECT_EQ(m.size(), size_t(100));

    m.insert(99, 0);

    EXPECT_EQ(m.size(), size_t(100));
}

UTEST(hash_map, value)
{
    hash_map<int, int> m;

    for (int i = 0; i < 100; ++i)
        m.insert(i, i + 1);

    auto result = m.value(50);

    EXPECT_EQ(result, 51);

    ASSERT_EXCEPTION(m.value(-1), std::out_of_range);
}

UTEST_MAIN();
