//
// Created by sergey on 30.08.23.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include "Gamer.h"
class TicTacToe {
public:
    TicTacToe();
    void printBoard();
    void play();
private:
    void makeChange(const unsigned int x, const unsigned int y, const char symbol);
    char board[3][3];
    char personChar;
    char computerChar;
    PersonGamer personGamer;
    ComputerGamer computerGamer;
    bool isPersonGamerTurn = rand() % 2;
    bool hasMovesLeft();
    bool checkWin();
};


#endif //TIC_TAC_TOE_TICTACTOE_H
