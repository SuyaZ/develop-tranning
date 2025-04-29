#ifndef __LINKLISTTEST_H__
#define __LINKLISTTEST_H__

#include "linklist.h"
#include"gtest/gtest.h"

namespace linklist_unit_test
{
    class LinklistTest : public testing::Test
    {
    protected:
        void SetUp() override;
        void TearDown() override;

        linklist m_linklistFirst;
        linklist m_linklistSecond;
        linklist m_linklistThird;
        linklist m_linklistFourth;

    };
}


#endif