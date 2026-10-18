cmake_minimum_required(VERSION 3.20)
project(unit_tests_lab_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(late_fee late_fee.cpp)
target_include_directories(late_fee PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(demo demo.cpp)
target_link_libraries(demo late_fee)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(late_fee_tests tests/test_late_fee.cpp)
target_link_libraries(late_fee_tests late_fee GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(late_fee_tests)