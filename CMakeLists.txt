cmake_minimum_required(VERSION 3.19)
project(lists)

set(CMAKE_CXX_STANDARD 17)

add_library(list INTERFACE "${CMAKE_SOURCE_DIR}/include/list/singly_linked_list.hpp")
target_include_directories(list INTERFACE "${CMAKE_SOURCE_DIR}/include")

add_executable(list_demo main.cpp)
target_link_libraries(list_demo PUBLIC list)
