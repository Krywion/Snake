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
    virtual ~Snake();
    virtual void draw() override;
    virtual void move();

    virtual void printPos() override;

    Vec2<int> getDirection() const;
    void setDirection(Vec2<int> direction);
    void setSegment(bool addSegment);

    virtual std::deque<Vec2<int>> getBody() const;
    std::deque<Vec2<int>> getTrace() const;

    void reset();

private:
    std::deque<Vec2<int>> trace;
    std::deque<Vec2<int>> body;
    Vec2<int> direction;
    bool addSegment;

    Color skinColor;

};


#endif //GAME_SNAKE_H
