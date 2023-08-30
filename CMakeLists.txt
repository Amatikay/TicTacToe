cmake_minimum_required(VERSION 3.26)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp
        TicTacToe.cpp
        TicTacToe.h
        Gamer.cpp
        Gamer.h)
