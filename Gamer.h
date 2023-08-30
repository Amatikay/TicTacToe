//
// Created by sergey on 31.08.23.
//

#ifndef TIC_TAC_TOE_GAMER_H
#define TIC_TAC_TOE_GAMER_H


#include <utility>

class Gamer {
    public:
    Gamer(){};
};
class PersonGamer: public Gamer {
    public:
    PersonGamer(){};
    std::pair<unsigned int, unsigned int> inputNextStep(std::istream& input);
};
class ComputerGamer: public Gamer {
    public:
    ComputerGamer(){};
    std::pair<unsigned int, unsigned int> calculateNextStep( char board[3][3]);
private:
    int calculateUtilityFunction( char board[3][3]);
    int checkWin(const char board[3][3]);
};

#endif //TIC_TAC_TOE_GAMER_H
