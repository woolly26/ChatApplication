cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server main.cpp server.cpp client.cpp)

target_link_libraries(server ${CMAKE_DL_LIBS} ${CMAKE_NETWORK_LIBS})
