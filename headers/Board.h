//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GameObject.h"
#include <raylib.h>

class Board{
public:
    static void draw();
    static void drawTexture2D(Texture2D texture2D, int posX, int posY);
    static void drawRect(int posX, int posY, Color color);

    static Vec2<int> genereRandomCell();

};


#endif //GAME_BOARD_H
