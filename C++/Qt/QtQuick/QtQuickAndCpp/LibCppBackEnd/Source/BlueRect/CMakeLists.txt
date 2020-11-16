cmake_minimum_required(VERSION 3.10)

project(bluerect)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_PARENT_DIR ${PARENT_DIR} DIRECTORY)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PARENT_PARENT_DIR}/Libraries)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Quick REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})

set(QML_IMPORT_NAME BlueRect)
set(QML_IMPORT_MAJOR_VERSION 1)

add_library(${PROJECT_NAME} SHARED
                bluerect.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                              Qt${QT_VERSION_MAJOR}::Widgets
                                              Qt${QT_VERSION_MAJOR}::Quick)
