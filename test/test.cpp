//
// Created by sergey on 03.09.23.
//
#include <iostream>
#include "../include/TicTacToe.h"
#include <gtest/gtest.h>
#include <fstream>

TEST(TicTacToe, notEqual_NullPtr_NewTicTacToe)
{
    TicTacToe* game = TicTacToe::getInstance();

    ASSERT_NE( nullptr,game);
}

TEST(PersonGamer, notEqual_NullPtr_NewPersonGamer)
{
    std::unique_ptr<Gamer> personGamer(new PersonGamer());

    ASSERT_NE( nullptr,personGamer.get());
}

TEST(ComputerGamer, notEqual_NullPtr_NewComputerGamer)
{
    std::unique_ptr<Gamer> computerGamer(new ComputerGamer());

    ASSERT_NE( nullptr,computerGamer.get());
}
TEST(PersonGamer, makeMove_Is_Correct_from_file)// проверка корректности в случае необходимости перенаправления ввода
{
    std::unique_ptr<Gamer> personGamer(new PersonGamer());
    std::ofstream file("../test/test.txt");
    if(file.is_open()){
        file << "2 2";// волшебная константа - абсолютно лобое значение в файле
    }
    else {
        std::cerr << "Файл не был открыт!" << std::endl;
    }
    file.close();

    std::ifstream input("../test/test.txt");

    if (input.is_open()) {
        std::pair<unsigned int, unsigned int> nextStep = personGamer->makeMove(input,nullptr);

        ASSERT_EQ(nextStep.first, 2);// волшебная константа - значение в файле.
        ASSERT_EQ(nextStep.second, 2);// волшебная константа - значение в файле.
    } else{
        std::cerr << "Файл не был открыт!"  << std::endl;
    }
    input.close();
}
TEST(PersonGamer, makeMove_Is_Correct_from_terminal_input)
{
    std::unique_ptr<Gamer> personGamer(new PersonGamer());
    std::istringstream input("2 2");
    std::pair<unsigned int, unsigned int> nextStep = personGamer->makeMove(input,nullptr);
    ASSERT_EQ(nextStep.first, 2);
    ASSERT_EQ(nextStep.second, 2);
}
// С тестом ComputerGamer::calculateNextStep я не знаю как поступать. В будущем я хотел бы добавить случанйю надбавку
// к функции полезности для имитации человечности. Но тогда я не смогу заранее указывать какой будет шаг при вводных даннных.
// проверяю, что алгоритм:
// 1. Выдает данные.
// 2. Не выдает ход на занятую клетку.
TEST(ComputerGamer, makeMove_EmptyBoard)
{
    std::unique_ptr<Gamer> computerGamer(new ComputerGamer());
    char board[3][3] = {{'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}};
    std::pair<unsigned int, unsigned int> nextStep = computerGamer->makeMove(std::cin,board);
    ASSERT_EQ(nextStep.first, 0);
    ASSERT_EQ(nextStep.second, 0);
}
TEST(ComputerGamer, makeMove_onlyOneStep)
{
    std::unique_ptr<Gamer> computerGamer(new ComputerGamer('0'));
    char board[3][3] = {{'X','X','X'},
                        {'X','X','X'},
                        {'X','X','_'}};
    std::pair<unsigned int, unsigned int> nextStep = computerGamer->makeMove(std::cin,board);
    ASSERT_EQ(nextStep.first, 2);
    ASSERT_EQ(nextStep.second, 2);
}
TEST(ComputerGamer, makeMove_onlyOneStep2)
{
    std::unique_ptr<Gamer> computerGamer(new ComputerGamer('0'));
    char board[3][3] = {{'0','0','0'},
                        {'0','_','0'},
                        {'0','0','0'}};
    std::pair<unsigned int, unsigned int> nextStep = computerGamer->makeMove(std::cin,board);
    ASSERT_EQ(nextStep.first, 1);
    ASSERT_EQ(nextStep.second, 1);
}

int main() { //Запуск тестов
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}