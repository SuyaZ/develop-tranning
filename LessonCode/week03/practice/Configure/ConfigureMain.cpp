#include"Configure.h"
#include "gtest/gtest.h"

TEST(ConfigureTest, TestAddItem)
{
    Configure cfg;
    
    ASSERT_EQ(cfg.additem("hello"), 0); 
    cfg.additem("world");
    ASSERT_EQ(cfg.additem("world"), 1); 
    ASSERT_EQ(cfg.additem("TESTING"), 2);
}

TEST(ConfigureTest, TestGetItem)
{
    Configure cfg;
    cfg.additem("hello");
    cfg.additem("world");
    cfg.additem("TESTING");

    ASSERT_EQ(cfg.getitem(0), "hello"); 
    ASSERT_EQ(cfg.getitem(1), "world"); 
    ASSERT_EQ(cfg.getitem(2), "TESTING"); 

    ASSERT_EQ(cfg.getitem(4), "");
    ASSERT_EQ(cfg.getitem(-1), "");

}

TEST(ConfigureTest, TestGetSize)
{
    Configure cfg;
    ASSERT_EQ(cfg.getsize(), 0);
    cfg.additem("hello");
    ASSERT_EQ(cfg.getsize(), 1);
    cfg.additem("world");
    ASSERT_EQ(cfg.getsize(), 2);
    cfg.additem("TESTING");
    ASSERT_EQ(cfg.getsize(), 3);
}


int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
