
add_executable(list_test list_test.cpp)
target_link_libraries(list_test PUBLIC list Catch2::Catch2)
add_test(list_test NAME list_test COMMAND list_test)

add_executable(performance performance.cpp)
target_link_libraries(performance PUBLIC list)
