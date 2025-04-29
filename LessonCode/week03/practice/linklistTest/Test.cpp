#include"linklist.h"
#include"linklistTest.h"
#include"gtest/gtest.h"

namespace linklist_unit_test
{
    TEST_F(LinklistTest, insert)
    {
        EXPECT_EQ(3, m_linklistFirst.getSize());
        EXPECT_EQ(4, m_linklistFirst.insert(4, 40));
        EXPECT_EQ(-1, m_linklistFirst.insert(99, 99));
    }

    TEST_F(LinklistTest, remove)
    {
        EXPECT_EQ(-999, m_linklistSecond.remove(99));

        EXPECT_EQ(20, m_linklistSecond.remove(2));
        EXPECT_EQ(30, m_linklistSecond.remove(2));
        EXPECT_EQ(10, m_linklistSecond.remove(1));
    }

    TEST_F(LinklistTest, get)
    {
        EXPECT_EQ(-999, m_linklistThird.get(99));

        EXPECT_EQ(10, m_linklistThird.get(1));
        EXPECT_EQ(20, m_linklistThird.get(2));
        EXPECT_EQ(30, m_linklistThird.get(3));
    }

    TEST_F(LinklistTest, update)
    {
        EXPECT_EQ(-999, m_linklistFourth.Update(99, 99));

        EXPECT_EQ(200, m_linklistFourth.Update(2, 200));
    }


}