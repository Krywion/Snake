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
    ~ShadowSnake() = default;
    void draw() override;
    void move() override;

    std::deque<Vec2<int>> getBody();

private:

    std::deque<Vec2<int>> trace;
    std::deque<Vec2<int>> body;

    static const Color skinColor;
};


#endif //GAME_SHADOWSNAKE_H
