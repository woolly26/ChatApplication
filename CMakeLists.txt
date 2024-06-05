cmake_minimum_required(VERSION 3.10)

project(ChatApplication VERSION 1.0 DESCRIPTION "A chat application")

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configuration options
option(BUILD_TESTS "Build tests" OFF)

# Include external libraries
find_package(Threads REQUIRED)

# Add source files
add_subdirectory(src)
add_subdirectory(include)

# Installation configuration
install(TARGETS ChatApplication DESTINATION bin)


