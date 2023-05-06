//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Food.h"
#include "../headers/Game.h"

Food::Food(std::deque<Vec2<int>> snakeBody) {
    this->setPos(genereRandomPos(snakeBody));
}


void Food::draw() {
    Board::drawTexture2D(apple, this->getPos().getX(), this->getPos().getY());
}

Vec2<int> Food::genereRandomPos(std::deque<Vec2<int>> snakeBody) {
    Vec2<int> position{};
    do {
        position = Board::genereteRandomCell();
    } while(Vec2<int>::elementInDeque(position, snakeBody));
    return position;
}

void Food::loadImage() {
    this->apple = LoadTexture("../assets/apple.png");
}

void Food::unloadImage() {
    UnloadTexture(this->apple);
}





