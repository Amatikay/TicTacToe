//
// Created by sergey on 31.08.23.
//

#ifndef TIC_TAC_TOE_GAMER_H
#define TIC_TAC_TOE_GAMER_H


#include <utility>
/**
 * @brief Абстрактный класс игрока.
 * Класс игрока содержит виртуальный метод makeMove, который должен быть переопределен в наследниках.
 *
 */
class Gamer {
    public:
    Gamer(){};
    /**
     * @brief Метод для совершения хода.
     * @param std::istream& input - ссылка на входной поток, из которого будут взяты координаты след хода.
     * @param char board[3][3] - игровое поле в текущее время.
     * @return std::pair<unsigned int, unsigned int> - пара координат следующего хода.
     */
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream& input,char board[3][3]) = 0;
protected:
    char symbol;
};
/**
 * @brief Класс игрока человека.
 *
 */
class PersonGamer: public Gamer {
    public:

    PersonGamer(){};
    /**
     * @brief Метод для совершения хода. Переопределенный метод из абстрактного класса.
     * @param input поток ввода. Откуда будут взяты координаты следующего хода.
     * @param board текущее состояние игрового поля. Не нужно. Вставть хоть что.
     * @return std::pair<unsigned int, unsigned int> - пара координат следующего хода.
     */
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream& input, char board[3][3] = nullptr) override {
        return inputNextStep(input);
    }
    /**
     * @brief Конструктор класса c параметром символа игрока
     * @param symbol - символ игрока (X или O)
     */
    PersonGamer(const char& symbol){this->symbol = symbol;};
private:
    std::pair<unsigned int, unsigned int> inputNextStep(std::istream& input);
};
/**
 * @brief Класс игрока компьютера.
 * Класс анализирует игорвое поле исовершает ход.
 * Для хода используется метод из теории игр - минимакс.
 * Метод предполагает, что противник будет играть оптимально.
 * На основе этого алкгоритм соверашет выбор о своем ходе.
 * Алгоритм силен в нападении, но слаб если совершать "глупые" ходы.
 *
 */
class ComputerGamer: public Gamer {
    public:
    ComputerGamer(){};
    /**
     * @brief Метод для совершения хода. Переопределенный метод из абстрактного класса.
     * @param board состояние игрового поля. нужно для приняти решения о следующем ходе.
     * @return Возвращает пару - координаты следующего хода.
     */
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream&, char board[3][3]) override {// просто игнорировать входной поток. исправил принци нарушения инверсии зависимости.
        return calculateNextStep(board);
    }
    /**
     * @brief Конструктор класса c параметром символа игрока
     * @param symbol - символ игрока (X или O)
     */
    ComputerGamer(const char& symbol){this->symbol = symbol;};

private:
    std::pair<unsigned int, unsigned int> calculateNextStep( char board[3][3]);
    int calculateUtilityFunction( char board[3][3]);
    int checkWin(const char board[3][3]);
};

#endif //TIC_TAC_TOE_GAMER_H
