//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include <raylib.h>
#include <string>
#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "ShadowSnake.h"


class Game{
public:
    friend class Board;

    Game(std::string title);
    ~Game() noexcept;
    Game (Game &other) = delete;
    void operator=(const Game &) = delete;


    void tick();
    static std::deque<ShadowSnake> shadowSnakes;
private:
    bool running;
    double lastUpdateTime;

    bool eventTriggered(double interval);

    void checkCollisions();

    void snakeWithEdge();
    void snakeWithFood();
    void snakeWithTail();

    void keyHandler();
    void draw();
    void update();

    Snake snake;
    Food food;

    void gameOver();

    const static int cellSize;
    const static int cellCount;
    const static int offset;

    static int score;

    static Color green;
    static Color darkGreen;


    void snakeWithOtherSnakes();
};


#endif //GAME_GAME_H
