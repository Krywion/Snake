//
// Created by Maks Krywionek on 04/05/2023.
//

#ifndef GAME_SHADOWSNAKE_H
#define GAME_SHADOWSNAKE_H

#include "Snake.h"
#include "Board.h"
#include "deque"
#include "Vec2.h"

class ShadowSnake : public Snake{
public:
    ShadowSnake(std::deque<Vec2<int>> trace, int maxBodySize);
    ~ShadowSnake();
    void draw() override;
    void move();

    std::deque<Vec2<int>> getBody() const;

private:

    std::deque<Vec2<int>> trace;
    std::deque<Vec2<int>> body;

    int maxBodySize;

    static const Color skinColor;

    void reset();
};


#endif //GAME_SHADOWSNAKE_H
