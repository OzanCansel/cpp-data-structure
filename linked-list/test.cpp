#include "utest.h"
#include "linked_list.hpp"

UTEST(linked_list, push_front)
{
    linked_list<int> l;

    l.push_front(1);

    EXPECT_EQ(l.size(), size_t(1));
    EXPECT_EQ(l.at(0) , 1);

    l.push_front(2);

    EXPECT_EQ(l.size(), size_t(2));
    EXPECT_EQ(l.at(0) , 2);
    EXPECT_EQ(l.at(1) , 1);

    l.push_front(3);

    EXPECT_EQ(l.size(), size_t(3));
    EXPECT_EQ(l.at(0) , 3);
    EXPECT_EQ(l.at(1) , 2);
    EXPECT_EQ(l.at(2) , 1);
}

UTEST(linked_list, push_back)
{
    linked_list<int> l;

    l.push_back(1);

    EXPECT_EQ(l.size(), size_t(1));
    EXPECT_EQ(l.at(0) , 1);

    l.push_back(2);

    EXPECT_EQ(l.size(), size_t(2));
    EXPECT_EQ(l.at(0), 1);
    EXPECT_EQ(l.at(1), 2);

    l.push_back(3);

    EXPECT_EQ(l.size(), size_t(3));
    EXPECT_EQ(l.at(0) , 1);
    EXPECT_EQ(l.at(1) , 2);
    EXPECT_EQ(l.at(2) , 3);
}

UTEST(linked_list, erase)
{
    linked_list<int> l;

    l.push_back(2);
    l.push_front(1);
    l.push_back(3);

    l.erase(10000);

    EXPECT_EQ(l.size(), size_t(3));
    EXPECT_EQ(l.at(0) , 1);
    EXPECT_EQ(l.at(1),  2);
    EXPECT_EQ(l.at(2),  3);

    l.erase(3);

    EXPECT_EQ(l.size(), size_t(2));
    EXPECT_EQ(l.at(0) , 1);
    EXPECT_EQ(l.at(1) , 2);

    l.push_back(3);
    l.erase(2);

    EXPECT_EQ(l.size(), size_t(2));
    EXPECT_EQ(l.at(0) , 1);
    EXPECT_EQ(l.at(1) , 3);

    l.erase(1);

    EXPECT_EQ(l.size(), size_t(1));
    EXPECT_EQ(l.at(0) , 3);

    l.erase(3);

    EXPECT_EQ(l.size(), size_t(0));
}

UTEST(linked_list, empty)
{
    linked_list<int> l;

    EXPECT_TRUE(l.empty());

    l.push_back(1);

    EXPECT_FALSE(l.empty());

    l.erase(1);

    EXPECT_TRUE(l.empty());
}

UTEST(linked_list, size)
{
    linked_list<int> l;

    EXPECT_EQ(l.size(), size_t(0));

    l.push_back(1);

    EXPECT_EQ(l.size(), size_t(1));

    l.push_back(2);

    EXPECT_EQ(l.size(), size_t(2));
}

UTEST(linked_list, insert)
{
    linked_list<int> l;

    l.insert(0, 0);

    EXPECT_EQ(l.size(), size_t(1));
    EXPECT_EQ(l.at(0) , 0);

    l.insert(2, 1000);

    EXPECT_EQ(l.size(), size_t(2));
    EXPECT_EQ(l.at(1) , 2);

    l.insert(1, 1);

    EXPECT_EQ(l.size(), size_t(3));
    EXPECT_EQ(l.at(1) , 1);
}

UTEST_MAIN();
