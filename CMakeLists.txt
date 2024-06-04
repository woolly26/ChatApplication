cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChatApplication)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_executable(ChatApplication src/main.cpp src/server.cpp src/client.cpp)

# Include directories
target_include_directories(ChatApplication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
