cmake_minimum_required(VERSION 3.10)

# Set the project name and version.
project(base VERSION 1.0.0)

# Add the executable.
add_executable(baseapp main.cpp)

# Copy a file to another location and modify its contents.
configure_file(config.h.in config.h)

# Add include directories to a target.
target_include_directories(baseapp PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
