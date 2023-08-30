//
// Created by sergey on 31.08.23.
//

#include <iostream>
#include <cmath>
#include "Gamer.h"

std::pair<unsigned int, unsigned int> PersonGamer::inputNextStep(std::istream& input) {
    unsigned int x, y;
    std::cout << "Введите координаты следующего хода:"<<std::endl;
    input >> x >> y;
    return std::make_pair(x, y);
}

std::pair<unsigned int, unsigned int> ComputerGamer::calculateNextStep(char board[3][3]) {
    std::pair<unsigned int, unsigned int> bestNextStep;
    int highestUtilityFunction = -INFINITY;
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            if ('_' == board[i][j]) {
                board[i][j] = this->symbol;
                int currentUtilityFunction = calculateUtilityFunction(board);
                if (currentUtilityFunction > highestUtilityFunction) {
                    highestUtilityFunction = currentUtilityFunction;
                    bestNextStep = std::make_pair(i, j);
                }
                board[i][j] = '_';
            }
        }
    }
    return bestNextStep;
}

int ComputerGamer::calculateUtilityFunction(char board[3][3]) {
    int result = checkWin(board);
    if (result != 0) {
        return result;
    }

    int bestScore = -INFINITY;
    for (unsigned int i = 0; i < 3; ++i) {
        for(unsigned int j = 0; j < 3; ++j){
            if ('_' == board[i][j]) {
                board[i][j] = this->symbol;
                int currentScore = calculateUtilityFunction(board);
                if (currentScore > bestScore) {
                    bestScore = currentScore;
                }
                board[i][j] = '_';
            }
        }
    }
    return bestScore;
}

int ComputerGamer::checkWin(const char board[3][3]) {//TODO: Вот тут вообще не SOLID.
    //Проверяю X
        // Проверка строк на наличие победы
        for (int i = 0; i < 3; i++)
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_' && board[i][0] == 'X')
                return 10;

        // Проверка столбцов на наличие победы
        for (int i = 0; i < 3; i++)
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_' && board[0][i] == 'X')
                return 10;

        // Проверка диагоналей на наличие победы
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_' && board[0][0] == 'X')
            return 10;

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_' && board[0][2] == 'X')
            return 10;

    //Проверяю 0

    // Проверка строк на наличие победы
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_' && board[i][0] == '0')
            return -10;

    // Проверка столбцов на наличие победы
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_' && board[0][i] == '0')
            return -10;

    // Проверка диагоналей на наличие победы
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_' && board[0][0] == '0')
        return -10;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_' && board[0][2] == '0')
        return -10;

    return 0;
}
