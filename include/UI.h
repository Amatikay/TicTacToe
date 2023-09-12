//
// Created by sergey on 12.09.23.
//

#ifndef TIC_TAC_TOE_UI_H
#define TIC_TAC_TOE_UI_H

#include "Board.h"

class UI {
public:
    UI() = default;
    virtual void printBoard(Board& board, char userChar, char computerChar) = 0;
    virtual ~UI() = default;
};

class TerminalUI: public UI {
public:
    TerminalUI() = default;
    void printBoard(Board& board, char userChar, char computerChar) override;
    ~TerminalUI() override = default;

};
class ColorfulTerminalUI: public UI {};

class GUI: public UI {};


#endif //TIC_TAC_TOE_UI_H
