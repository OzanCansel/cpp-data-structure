#include "utest.h"
#include "stack.hpp"

UTEST(stack, test)
{
    stack<int> s;

    s.push(1);
    s.push(2);

    EXPECT_EQ(s.top(), 2);
    EXPECT_EQ(s.size(), size_t(2));

    s.pop();

    EXPECT_EQ(s.top(), 1);
    EXPECT_FALSE(s.empty());

    s.pop();

    EXPECT_TRUE(s.empty());
}


UTEST_MAIN();
