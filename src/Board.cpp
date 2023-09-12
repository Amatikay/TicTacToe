//
// Created by sergey on 12.09.23.
//

#include <iostream>
#include "../include/Board.h"

Board::Board(size_t size) {
    this->size = size;
    board = new char*[size];
    for (int i = 0; i < size; ++i) {
        board[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            board[i][j] = '_';
        }
    }
}

void Board::makeMove(const unsigned int x, const unsigned int y, const char symbol) {
    this->board[x][y] = symbol;
}

Board::Board(char **board) {
    this->board = board;
}
