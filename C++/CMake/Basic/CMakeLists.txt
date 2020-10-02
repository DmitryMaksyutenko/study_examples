cmake_minimum_required(VERSION 3.10)

# Set the project name and version.
project(base)

# Add the executable.
add_executable(baseapp main.cpp)

# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
