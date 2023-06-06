//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Food.h"
#include "../headers/Game.h"

Food::Food(std::deque<Vec2<int>> snakeBody) {
    this->genereRandomPos(snakeBody);
    try {
        this->apple = LoadTexture("../assets/apple.png");
    } catch (std::exception e) {
        e.what();
    }

}

Food::~Food() {
    UnloadTexture(this->apple);
}

void Food::draw() {
    Board::drawTexture2D(apple, this->getPos().getX(), this->getPos().getY());
}

void Food::genereRandomPos(const std::deque<Vec2<int>>& snakeBody) {
    Vec2<int> position{};
    do {
        position = Board::genereteRandomCell();
    } while(Vec2<int>::elementInDeque(position, snakeBody) &&
    Vec2<int>::elementInDeque(position, {Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}}));
    setPos(position);
    this->printPos();
}

void Food::printPos() {
    std::cout << "[Food] x: " << this->getPos().getX() << " y: " << this->getPos().getY()<< std::endl;
}









