#include <iostream>
#include "gtest/gtest.h"

int Factorial(int n)
{
    if (n == 0) 
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

TEST(FactorialTest,HandleCalResult)
{
    ASSERT_TRUE(1==1);//true
    ASSERT_FALSE(2==3); //true
    EXPECT_EQ(Factorial(2),2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}