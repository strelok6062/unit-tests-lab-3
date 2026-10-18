cmake_minimum_required(VERSION 3.20)
project(unit_tests_lab_3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(late_fee late_fee.cpp)

add_executable(demo demo.cpp)
target_link_libraries(demo late_fee)