cmake_minimum_required(VERSION 3.10)

project(linklist)

#设置包含当前目录
SET(CMAKE_INCLUDE_CURRENT_DIR ON) 

#默认生成静态库
add_library(${PROJECT_NAME} STATIC)

#向工程添加源码
target_sources(${PROJECT_NAME} PRIVATE
    linklistnode.h
    linklistnode.cpp
    linklist.h
    linklist.cpp
)
