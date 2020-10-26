cmake_minimum_required(VERSION 3.14)

project(BaseTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

enable_testing(true)

find_package(Qt5Test)

add_executable(BaseTest tst_tests.cpp)
add_test(test_one test_condition COMMAND BaseTest)

target_link_libraries(BaseTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
