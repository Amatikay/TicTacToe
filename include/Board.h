//
// Created by sergey on 12.09.23.
//

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H


#include <cstdio>

class Board {
public:
    Board(size_t size = 3);
    void makeMove();
    ~Board() = default;
    void makeMove(const unsigned int x, const unsigned int y, const char symbol);
    char* operator[](unsigned int i){ return board[i]; }
    size_t getSize(){ return size; }
    Board (char* board[]);
private:
    char** board;
    size_t size;
};


#endif //TIC_TAC_TOE_BOARD_H
