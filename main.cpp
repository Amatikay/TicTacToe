#include <iostream>
#include "TicTacToe.h"
int main() {
    TicTacToe* game = TicTacToe::getInstance();
    game->play();
    return 0;
}
