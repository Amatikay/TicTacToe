//
// Created by sergey on 12.09.23.
//

#include <iostream>
#include "../include/UI.h"
#include "../include/Board.h"

void TerminalUI::printBoard(Board &board, char userChar, char computerChar) {

    std::cout << "\033[2J\033[H";// очистка терминала
    std::cout << "User char is " << userChar << " Computer char is " << computerChar << std::endl;
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getSize(); ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
