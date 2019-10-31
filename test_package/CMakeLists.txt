cmake_minimum_required(VERSION 2.8.12)
project(fixed-point-tests CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(fixed-point REQUIRED)
find_package(gtest REQUIRED)

add_executable(${PROJECT_NAME} fixed-point-tests.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
    fixed-point::fixed-point gtest::gtest)
