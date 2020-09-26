cmake_minimum_required(VERSION 3.15)
project(javaoptlab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(javaoptlab1 main.cpp PoolInfo.cpp pool_info/RefPoolInfo.cpp pool_info/NumberPoolInfo.cpp pool_info/OneIndexPoolInfo.cpp pool_info/Utf8PoolInfo.cpp pool_info/FloatPoolInfo.cpp pool_info/MethodHandlePoolInfo.cpp pool_info/LongPoolInfo.cpp pool_info/DoublePoolInfo.cpp)