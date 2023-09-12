//
// Created by sergey on 30.08.23.
//

#include <iostream>
#include <fstream>
#include "../include/TicTacToe.h"

TicTacToe* TicTacToe::instance= nullptr;

//TODO:  Почему то компьютер ходит тем же символом, что и игрок

void TicTacToe::makeChange(const unsigned int x, const unsigned int y, const char symbol) {
    if ('_' == board[x][y])    {
        board.makeMove(x,y,symbol);
    }
}
TicTacToe::TicTacToe() {
    srand(time(0));
    bool randNumber = rand() % 2;
    if (randNumber){
        personGamer = new PersonGamer('0');
        computerGamer = new ComputerGamer('X');
    }
    else{
        personGamer = new PersonGamer('X');
        computerGamer = new ComputerGamer('0');

    }

    std::cout<<"Choose type of UI: 0 - terminal, 1 - colorful terminal, 2 - GUI"<<std::endl;
    unsigned int typeOfUI;
    std::cin>>typeOfUI;
    switch (typeOfUI) {
        case 0:
            this->ui = new TerminalUI();
            break;
            //TODO прописать интерфейсы для остальных типов UI
//        case 1:
//            this->ui = new ColorfulTerminalUI();
//            break;
//        case 2:
//            this->ui = new GUI();
//            break;

    }
}

void TicTacToe::play() {
    ui->printBoard(board, personGamer->getSymbol(), computerGamer->getSymbol());
    std::pair<unsigned int, unsigned int> nextStep;
    while (!checkWin() && hasMovesLeft() ){

        if (isPersonGamerTurn){
            nextStep = personGamer->makeMove(std::cin, board);
            makeChange(nextStep.first, nextStep.second, personGamer->getSymbol());
        }
        if(!isPersonGamerTurn){
            nextStep = computerGamer->makeMove(std::cin,board);// просто игнорировать входной поток. исправил принци нарушения инверсии зависимости.
            makeChange(nextStep.first, nextStep.second, personGamer->getSymbol());
        }
        isPersonGamerTurn = !isPersonGamerTurn;
        ui->printBoard(board,personGamer->getSymbol(), computerGamer->getSymbol());
    }
}

bool TicTacToe::hasMovesLeft() {
    for (size_t i = 0; i < board.getSize(); ++i) {
        for (size_t j = 0; j < board.getSize(); ++j) {
            if ('_' == board[i][j]) {
                return true;
            }
        }
    }
    return false;
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
    delete ui;
}

TicTacToe *TicTacToe::getInstance(){
    if (instance == nullptr) {
        instance = new TicTacToe();
    }
    return instance;
}