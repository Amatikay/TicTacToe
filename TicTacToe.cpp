//
// Created by sergey on 30.08.23.
//

#include <iostream>
#include "TicTacToe.h"

void TicTacToe::makeChange(const unsigned int x, const unsigned int y, const char symbol) {
//    TODO: обработать не верные данные. Например, если x или y больше 2, или если клетка уже занята.
    if ('_' == board[x][y])    {
        board[x][y] = symbol;
    }
}

TicTacToe::TicTacToe() {
    for (auto & i : board) {
        for (char & j : i) {
            j = '_';
        }
    }
    personGamer = PersonGamer();
    computerGamer = ComputerGamer();
}

void TicTacToe::printBoard() {
    std::cout << "\033c";//Очистка терминала.
    for (auto & i : board) {
        for (char j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

}

void TicTacToe::play() {
    this->printBoard();
    while (!checkWin() && hasMovesLeft() ){
         std::pair<unsigned int, unsigned int> nextStep;
        if (isPersonGamerTurn == true){
            nextStep = personGamer.inputNextStep();
            makeChange(nextStep.first, nextStep.second, 'O');
        }
        if(isPersonGamerTurn == false){
            nextStep = computerGamer.calculateNextStep(board);
            makeChange(nextStep.first, nextStep.second, 'X');
        }
        isPersonGamerTurn = !isPersonGamerTurn;
        this->printBoard();
    }
}

bool TicTacToe::hasMovesLeft() {
    for (auto & i : board) {
        for (char j : i) {
            if ('_' == j) {
                return true;
            }
        }
    }
}

bool TicTacToe::checkWin() {
    // Проверка строк на наличие победы
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
            return true;

    // Проверка столбцов на наличие победы
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_')
            return true;

    // Проверка диагоналей на наличие победы
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_')
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_')
        return true;

    // Если ни одна из предыдущих проверок не вернула true, нет победителя
    return false;
}