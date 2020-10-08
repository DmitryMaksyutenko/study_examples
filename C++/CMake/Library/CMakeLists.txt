# if(MYLIB)
    #    list(APPEND EXTRA_LIBS mylib)
    #    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/LibDir")
# endif()

cmake_minimum_required(VERSION 3.10)

project(libTest)

add_subdirectory(LibDir)

add_executable(libTest main.cpp)

target_link_libraries(libTest PUBLIC mylib)

target_include_directories(libTest PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/LibDir/"
                           )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
