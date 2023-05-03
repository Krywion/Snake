//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Food.h"
#include "../headers/Game.h"

Food::Food() {
}

void Food::draw() {
    DrawRectangle(Game::offset + this->getPosX()*Game::cellSize,
                  Game::offset + this->getPosY()*Game::cellSize,
                  Game::cellSize,
                  Game::cellSize,
                  Game::darkGreen);
}

Vec2<int> Food::genereteRandomCell() {
    int x = GetRandomValue(0, Game::cellCount -1);
    int y = GetRandomValue(0, Game::cellCount -1);
    return Vec2<int>{x, y};
}

Vec2<int> Food::genereRandomPos(std::deque<Vec2<int>> snakeBody) {
    Vec2<int> position;
    do {
        position = genereteRandomCell();
    } while(Vec2<int>::elementInDeque(position, snakeBody));
    return position;
}

