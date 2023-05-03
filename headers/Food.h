//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_FOOD_H
#define GAME_FOOD_H

#include "GameObject.h"
#include <raylib.h>

class Food : public GameObject{
public:
    Food();

    void draw();
    Vec2<int> genereRandomPos(std::deque<Vec2<int>> snakeBody);
private:
    Vec2<int> genereteRandomCell();


    std::deque<Vec2<int>> snakeBody;
};


#endif //GAME_FOOD_H
