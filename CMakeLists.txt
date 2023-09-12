cmake_minimum_required(VERSION 3.26)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)


add_executable(tic_tac_toe src/main.cpp
        src/TicTacToe.cpp
        include/TicTacToe.h
        src/Gamer.cpp
        include/Gamer.h)

add_executable(runTests test/test.cpp
        src/TicTacToe.cpp
        include/TicTacToe.h
        src/Gamer.cpp
        include/Gamer.h)

target_link_libraries(runTests gtest gtest_main)


