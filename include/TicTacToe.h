//
// Created by sergey on 30.08.23.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include "Gamer.h"
#include "UI.h"
#include "Board.h"


/**
 * @brief Класс игры в крестики нолики.
 * Класс написан в соотвествии с паттерном одиночка, так как в процессе игры должен существовать только один экземпляр класса.
 * С созданием экземпляра класса начинается игра.
 * При уничтожении экземпляра игра заканчивается.
 */
class TicTacToe {
public:
    /**
     * @brief Статический метод для получения единственного экземпляра класса.
     * @return Единственный экземпляр класса.
     */
    static TicTacToe* getInstance();
    /**
     * @brief Метод для запуска игры.
     */
    void play();

private:
    static TicTacToe* instance;
    TicTacToe();
    void makeChange(const unsigned int x, const unsigned int y, const char symbol);
    Board board = Board();//TODO:  Singleton?
    Gamer *personGamer;
    Gamer *computerGamer;
    bool isPersonGamerTurn = rand() % 2;
    bool hasMovesLeft();
    bool checkWin();
    UI *ui;
    ~TicTacToe();
};


#endif //TIC_TAC_TOE_TICTACTOE_H
