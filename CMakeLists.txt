cmake_minimum_required(VERSION 3.15)
project(lists)

set(CMAKE_CXX_STANDARD 17)

add_library(list INTERFACE)
target_sources(list INTERFACE "${CMAKE_SOURCE_DIR}/include/list/singly_linked_list.hpp")
target_include_directories(list INTERFACE "${CMAKE_SOURCE_DIR}/include")

add_executable(list_demo main.cpp)
target_link_libraries(list_demo PUBLIC list)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
