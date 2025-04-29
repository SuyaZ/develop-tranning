#include"linklistTest.h"
#include<iostream>

void linklist_unit_test::LinklistTest::SetUp()
{
    m_linklistFirst.insert(1, 10);
    m_linklistFirst.insert(2, 20);
    m_linklistFirst.insert(3, 30);

    m_linklistSecond.insert(1, 10);
    m_linklistSecond.insert(2, 20);
    m_linklistSecond.insert(3, 30);

    m_linklistThird.insert(1, 10);
    m_linklistThird.insert(2, 20);
    m_linklistThird.insert(3, 30);

    m_linklistFourth.insert(1, 10);
    m_linklistFourth.insert(2, 20);
    m_linklistFourth.insert(3, 30);

}

void linklist_unit_test::LinklistTest::TearDown()
{
    std::cout<<"Test End!"<<std::endl;
}