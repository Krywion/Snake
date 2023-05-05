//
// Created by Maks Krywionek on 04/05/2023.
//

#include "../headers/ShadowSnake.h"
#include "../headers/Game.h"

const Color ShadowSnake::skinColor = GRAY;

ShadowSnake::ShadowSnake(std::deque<Vec2<int>> trace, int maxBodySize) : trace(trace), maxBodySize(maxBodySize){
    maxBodySize = (maxBodySize/3) + 1;
    for(int i = 0; i < maxBodySize; i++) {
        body.push_back(Vec2<int>{trace[i].getX(), trace[i].getY()});
    }
    for(int i = 0; i < trace.size(); i++) {
    }
    std::cout << "Utworzono ducha...\n";
}
ShadowSnake::~ShadowSnake() {
    std::cout << "Usunięto ducha...\n";
}

void ShadowSnake::draw() {
    for(unsigned int i = 0; i < body.size(); i++) {
        int posX = body[i].getX();
        int posY = body[i].getY();
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

std::deque<Vec2<int>> ShadowSnake::getBody() const {
    return this->body;
}

