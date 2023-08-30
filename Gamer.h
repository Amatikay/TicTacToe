//
// Created by sergey on 31.08.23.
//

#ifndef TIC_TAC_TOE_GAMER_H
#define TIC_TAC_TOE_GAMER_H


#include <utility>

class Gamer {
    public:
    Gamer(){};
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream& input,char board[3][3]) = 0;
protected:
    char symbol;
};
class PersonGamer: public Gamer {
    public:
    PersonGamer(){};
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream& input, char board[3][3]) override {
        return inputNextStep(input);
    }
    PersonGamer(const char& symbol){this->symbol = symbol;};
    std::pair<unsigned int, unsigned int> inputNextStep(std::istream& input);
};
class ComputerGamer: public Gamer {
    public:
    ComputerGamer(){};
    virtual std::pair<unsigned int, unsigned int> makeMove(std::istream&, char board[3][3]) override {// просто игнорировать входной поток. исправил принци нарушения инверсии зависимости.
        return calculateNextStep(board);
    }
    ComputerGamer(const char& symbol){this->symbol = symbol;};
    std::pair<unsigned int, unsigned int> calculateNextStep( char board[3][3]);
private:
    int calculateUtilityFunction( char board[3][3]);
    int checkWin(const char board[3][3]);
};

#endif //TIC_TAC_TOE_GAMER_H
