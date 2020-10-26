cmake_minimum_required(VERSION 3.5)

project(TestGui LANGUAGES CXX)


find_package(Qt5Test REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestGui tst_testgui.cpp)
add_test(NAME TestGui COMMAND TestGui)

target_link_libraries(TestGui PRIVATE Qt5::Gui Qt5::Test Qt5::Widgets)

