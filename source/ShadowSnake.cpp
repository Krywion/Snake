//
// Created by Maks Krywionek on 04/05/2023.
//

#include "../headers/ShadowSnake.h"
#include "../headers/Game.h"

const Color ShadowSnake::skinColor = GRAY;


ShadowSnake::ShadowSnake(std::deque<Vec2<int>> trace, int maxBodySize) : trace(trace) {
    maxBodySize = (maxBodySize/3) + 1;
    for(int i = 0; i < maxBodySize; i++) {
        body.emplace_back(trace[i].getX(), trace[i].getY());
    }
}

void ShadowSnake::draw() {
    for(auto cell : body) {
        int posX = cell.getX();
        int posY = cell.getY();
        Board::drawRect(posX, posY, skinColor);
    }
}

void ShadowSnake::move() {
        if(trace.size() > 1) {
            Vec2<int> direction = (trace[1] - trace[0]);
            body.push_front(body[0] + direction);
            body.pop_back();
            trace.pop_front();
        } else {
            Game::shadowSnakes.pop_front();
        }

}

std::deque<Vec2<int>> ShadowSnake::getBody() {
    return this->body;
}


