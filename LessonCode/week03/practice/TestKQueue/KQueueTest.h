#ifndef __QUEUETEST_H__
#define __QUEUETEST_H__

#include <iostream>
#include "kqueue.h"
#include "gtest/gtest.h"


namespace queue_unit_test
{
    class QueueTest : public testing::Test
    {
    protected:
        void SetUp() override;
        void TearDown() override;

        KQueue  m_kqueueFirst;
        KQueue  m_kqueueSecond;
        KQueue  m_kqueueThird;
    };
}

#endif