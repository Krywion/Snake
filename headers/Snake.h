//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_SNAKE_H
#define GAME_SNAKE_H

#include <deque>
#include <raylib.h>
#include "GameObject.h"



class Snake : public GameObject{
public:
    Snake();
    void draw();
    void move();

    Vec2<int> getDirection() const;
    void setDirection(Vec2<int> direction);
    void setSegment(bool addSegment);

    std::deque<Vec2<int>> getBody() const;

    void reset();

private:
    std::deque<Vec2<int>> body;
    Vec2<int> direction;
    bool addSegment;

};


#endif //GAME_SNAKE_H
