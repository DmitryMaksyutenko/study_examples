cmake_minimum_required(VERSION 3.5)

project(Project LANGUAGES CXX)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(SourceCode)

add_executable(Project main.cpp)

target_link_libraries(Project PUBLIC Qt${QT_VERSION_MAJOR}::Gui
                                    Qt${QT_VERSION_MAJOR}::Widgets
                                    gui.so)

target_link_directories(Project PRIVATE "${CMAKE_BINARY_DIR}"
                                        "${CMAKE_SOURCE_DIR}"
                                        "${CMAKE_SOURCE_DIR}/SourceCode")
