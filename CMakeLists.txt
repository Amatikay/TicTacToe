cmake_minimum_required(VERSION 3.26)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)



add_library(tic_tac_toe_lib STATIC
        src/TicTacToe.cpp
        include/TicTacToe.h
        src/Gamer.cpp
        include/Gamer.h
        src/UI.cpp
        include/UI.h
        src/Board.cpp
        include/Board.h)

add_executable(tic_tac_toe_run src/main.cpp)
target_link_libraries(tic_tac_toe_run tic_tac_toe_lib)

add_subdirectory(googletest)
add_executable(runTests test/test.cpp )
target_link_libraries(runTests tic_tac_toe_lib gtest gtest_main)


