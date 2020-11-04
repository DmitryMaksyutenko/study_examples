cmake_minimum_required(VERSION 3.14)

project(JSBase LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Qml)

add_executable(JSBase
  main.cpp
)
target_link_libraries(JSBase Qt${QT_VERSION_MAJOR}::Core
                                Qt${QT_VERSION_MAJOR}::Qml)
