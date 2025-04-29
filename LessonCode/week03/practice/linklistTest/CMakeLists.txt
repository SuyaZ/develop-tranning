cmake_minimum_required(VERSION 3.10)  #cmake版本最低3.10

project(linklistTest)  #添加当前项目名称

#默认生成静态库
add_executable(${PROJECT_NAME})

find_package(GTest CONFIG REQUIRED)

#向工程添加源码
target_sources(${PROJECT_NAME} PRIVATE
    linklistTest.h
    linklistTest.cpp
    Test.cpp
)

#向工程添加多个特定头文件的搜索路径——   -I参数
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../linklist
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    linklist
    GTest::gmock_main
    GTest::gtest_main 
)