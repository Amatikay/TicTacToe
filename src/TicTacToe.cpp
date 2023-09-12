//
// Created by sergey on 30.08.23.
//

#include <iostream>
#include <fstream>
#include "../include/TicTacToe.h"

TicTacToe* TicTacToe::instance= nullptr;

void TicTacToe::makeChange(const unsigned int x, const unsigned int y, const char symbol) {
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
    srand(time(0));

    bool randNumber = rand() % 2;
    if (randNumber){
        personChar = '0';
        computerChar = 'X';
    }
    else{
        personChar = 'X';
        computerChar = '0';
    }
    personGamer = new PersonGamer(personChar);
    computerGamer = new ComputerGamer(computerChar);
}

void TicTacToe::printBoard() {
    std::cout << "\033c";//Очистка терминала.
    std::cout<<"User char is " << this->personChar << " Computer char is " << this->computerChar << std::endl;
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
            nextStep = personGamer->makeMove(std::cin, nullptr);
            makeChange(nextStep.first, nextStep.second, personChar);
        }
        if(isPersonGamerTurn == false){
            nextStep = computerGamer->makeMove(std::cin,board);// просто игнорировать входной поток. исправил принци нарушения инверсии зависимости.
            makeChange(nextStep.first, nextStep.second, computerChar);
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

TicTacToe::~TicTacToe() {
    std::cout << "The Game is end. Thank you for game!"<<std::endl;
    delete personGamer;
    delete computerGamer;
    delete instance;
}
