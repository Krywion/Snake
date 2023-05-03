//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GameObject.h"
#include <raylib.h>

class Board{
public:
    Board();
    Board(int cellSize, int cellCount, int offset);

    void draw();

private:
    int cellSize;
    int cellCount;
    int offset;
};


#endif //GAME_BOARD_H
