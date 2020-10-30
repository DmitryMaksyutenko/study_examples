cmake_minimum_required(VERSION 3.10)

project(libTest)

add_subdirectory(LibDir)
list(APPEND EXTRA_LIBS mylib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/LibDir")

add_executable(libTest main.cpp)

target_link_libraries(libTest PUBLIC ${EXTRA_LIBS})

target_include_directories(libTest PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            ${EXTRA_INCLUDES}
                           )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
