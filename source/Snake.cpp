//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Snake.h"
#include "../headers/Game.h"


Snake::Snake() {
    body = {Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}};
    direction = {1, 0};
    addSegment = false;
}

void Snake::draw() {
    for(unsigned int i = 0; i < body.size(); i++) {
        int x = body[i].getX();
        int y = body[i].getY();
        Rectangle rectangle = Rectangle{(float)Game::offset + x * Game::cellSize,
                                        (float) Game::offset + y * Game::cellSize,
                                        (float) Game::cellSize,
                                        (float) Game::cellSize};
        DrawRectangleRounded(rectangle, 0.5, 6, Game::darkGreen);

    }
}

void Snake::move() {
    body.push_front(body[0] + direction);
    if(addSegment) {
        addSegment = false;
    } else {
        body.pop_back();
    }
}

Vec2<int> Snake::getDirection() const {
    return this->direction;
}

void Snake::setDirection(Vec2<int> direction) {
    this->direction = direction;
}

std::deque<Vec2<int>> Snake::getBody() const {
    return this->body;
}

void Snake::setSegment(bool addSegment) {
    this->addSegment = addSegment;
}

void Snake::reset() {
    body = {Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}};
    direction = {1, 0};
}
