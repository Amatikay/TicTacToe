//
// Created by sergey on 30.08.23.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include "Gamer.h"
//TODO у меня алкогритм ходит крестиками, а человек ноликами. Надо адаптировать
class TicTacToe {
public:
    TicTacToe();
    void printBoard();
    void play();
private:
    void makeChange(const unsigned int x, const unsigned int y, const char symbol);
    char board[3][3];
    PersonGamer personGamer;
    ComputerGamer computerGamer;
    bool isPersonGamerTurn = false;
    bool hasMovesLeft();
    bool checkWin();
};


#endif //TIC_TAC_TOE_TICTACTOE_H
