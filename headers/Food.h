//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_FOOD_H
#define GAME_FOOD_H

#include "GameObject.h"
#include <raylib.h>

class Food : public GameObject{
public:
    Food() = default;
    ~Food();
    Food(const Food&) = delete;
    Food& operator=(const Food& other) = delete;

    explicit Food(std::deque<Vec2<int>> snakeBody);

    void printPos() override;

    void draw() override;
    void genereRandomPos(const std::deque<Vec2<int>>& snakeBody);
private:
    Texture2D apple;
};


#endif //GAME_FOOD_H
