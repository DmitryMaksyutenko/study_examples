cmake_minimum_required(VERSION 3.5)

project(Tests)

find_package(Qt5Test REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(TestAdd tst_testadd.cpp)
add_executable(TestGui tst_gui.cpp)

add_test(NAME TestAdd COMMAND TestAdd)
add_test(NAME TestGui COMMAND TestGui)


target_link_directories(TestAdd PRIVATE ${CMAKE_SOURCE_DIR}/../
                                        ${CMAKE_SOURCE_DIR}/../SourceCode/)

target_link_libraries(TestAdd PRIVATE Qt5::Test
                                        gui.so)


target_link_directories(TestGui PRIVATE ${CMAKE_SOURCE_DIR}/../
                                        ${CMAKE_SOURCE_DIR}/../SourceCode/)

target_link_libraries(TestGui PRIVATE Qt5::Test
                                        Qt5::Gui
                                        Qt5::Widgets
                                        gui.so)
