cmake_minimum_required(VERSION 3.14)

project(MyLib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_library(MyLib SHARED
  MyLib_global.h
  mylib.cpp
  mylib.h
)

target_link_libraries(MyLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(MyLib PRIVATE MYLIB_LIBRARY)
