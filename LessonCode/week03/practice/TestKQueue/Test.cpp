#include "gtest/gtest.h"
#include "KQueueTest.h"

namespace queue_unit_test 
{
    //
    TEST_F(QueueTest, DefaultConstructor) 
    {
        EXPECT_EQ(3, m_kqueueFirst.getSize());
    }

    
    TEST_F(QueueTest, deleteDataQueue)
    {
        EXPECT_EQ(10, m_kqueueFirst.deleteDataQueue());
        EXPECT_EQ(2, m_kqueueFirst.getSize());

        EXPECT_EQ(40, m_kqueueSecond.deleteDataQueue());
        EXPECT_EQ(50, m_kqueueSecond.deleteDataQueue());
        EXPECT_EQ(1, m_kqueueSecond.getSize());

        EXPECT_EQ(70, m_kqueueThird.deleteDataQueue());
        EXPECT_EQ(80, m_kqueueThird.deleteDataQueue());
        EXPECT_EQ(90, m_kqueueThird.deleteDataQueue());
        EXPECT_EQ(0, m_kqueueThird.getSize());
    }

    TEST_F(QueueTest, clear)
    {
        m_kqueueFirst.clear();
        EXPECT_EQ(0, m_kqueueFirst.getSize());
    }

    TEST_F(QueueTest, enterDataQueue)
    {
        int tmp = 100;
        m_kqueueFirst.enterDataQueue(tmp);
        KQueuenode* kn = m_kqueueFirst.getTail();
        EXPECT_EQ(100, kn->getDate());
    }
}