//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Snake.h"
#include "../headers/Game.h"


Snake::Snake() : body({Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}}),
                 trace({Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}}),
                 direction({1, 0}),
                 addSegment(false),
                 skinColor(LIME) {
}

Snake::~Snake() {

}

void Snake::draw() {

    for(auto cell : body) {
        int posX = cell.getX();
        int posY = cell.getY();
        Board::drawRect(posX, posY, skinColor);
    }
}

void Snake::move() {
    body.push_front(body[0] + direction);
    trace.push_front(body[body.size()-1]);
    if(addSegment) {
        addSegment = false;
    } else {
        body.pop_back();
    }
    this->printPos();
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

std::deque<Vec2<int>> Snake::getTrace() const {
    std::deque<Vec2<int>> reversedTrace;
    for(int i = 0; i < this->trace.size(); i++) {
       reversedTrace.push_front(trace[i]);
    }

    return reversedTrace;
}

void Snake::setSegment(bool addSegment) {
    this->addSegment = addSegment;
}

void Snake::reset() {
    body = {Vec2{6, 9}, Vec2{5,9}, Vec2{4, 9}};
    trace = {};
    direction = {1, 0};
}

void Snake::printPos() {
    std::cout << "[SNAKE] x: " << this->body[0].getX() << " y: " << this->body[0].getY()<< std::endl;
}


