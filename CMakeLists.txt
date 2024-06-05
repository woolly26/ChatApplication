cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(ChatApp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)
include_directories(src)

# Add the executable targets
add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

