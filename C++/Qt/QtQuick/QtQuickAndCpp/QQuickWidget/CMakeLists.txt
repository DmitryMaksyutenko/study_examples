cmake_minimum_required(VERSION 3.5)

project(QQuickWidget LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Qml QuickWidgets Quick Core REQUIRED)
find_package(Qt5QuickCompiler)


include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
qtquick_compiler_add_resources(QT_RESOURCES qmls.qrc)

if(ANDROID)
  add_library(QQuickWidget SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
  )
else()
  add_executable(QQuickWidget
    main.cpp
    mainwindow.cpp
    mainwindow.h
    qmls.qrc
  )
endif()

target_link_libraries(QQuickWidget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Qml
                                            Qt${QT_VERSION_MAJOR}::QuickWidgets
                                            Qt${QT_VERSION_MAJOR}::Quick
                                            Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(QQuickWidget PRIVATE ${CMAKE_SOURCE_DIR}
                                                ${CMAKE_SOURCE_DIR}/Qml)
