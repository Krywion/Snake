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


class Game {
public:
    Game(std::string title);
    ~Game() noexcept;

    int getCellSize();
    int getCellCount();
    int getOffset();

    void tick();
    void keyHandler();

    const static int cellSize;
    const static int cellCount;
    const static int offset;

    static Color green;
    static Color darkGreen;
private:

    bool eventTriggered(double interval);
    void checkCollisions();

    bool running;
    void draw();
    void update();


    Board board;
    Snake snake;
    Food food;

    double lastUpdateTime;


    void snakeWithFood();

    void snakeWithTail();

    void gameOver();

    void snakeWithEdge();
};


#endif //GAME_GAME_H
