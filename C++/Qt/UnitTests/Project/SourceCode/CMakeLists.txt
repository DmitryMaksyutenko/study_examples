set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)

add_library(gui SHARED
  gui.cpp
  gui.h
  add.cpp
  add.h
)

target_link_libraries(gui PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)
target_compile_definitions(gui PUBLIC GUI_LIBRARY)
