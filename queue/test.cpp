#include "utest.h"
#include "queue.hpp"

UTEST(queue, test)
{
    queue<int> q;

    q.enqueue(1);

    EXPECT_EQ(q.size(), size_t(1));
    EXPECT_FALSE(q.empty());

    q.enqueue(2);

    int value_1 = q.dequeue();

    EXPECT_EQ(1, value_1);

    q.enqueue(3);

    int value_2 = q.dequeue();

    EXPECT_EQ(2, value_2);

    int value_3 = q.dequeue();

    EXPECT_EQ(3, value_3);
}

UTEST_MAIN();
