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
#include "fstream"
#include "Settings.h"


class Game{
public:
    friend class Board;

    explicit Game();
    ~Game() = default;
    Game (Game &other) = delete;
    void operator=(const Game &) = delete;
    void tick();
    static std::deque<ShadowSnake> shadowSnakes;
private:
    bool running;
    double lastUpdateTime;
    static const float speed;

    bool eventTriggered(double interval);

    void checkCollisions();

    void snakeWithEdge();
    void snakeWithFood();
    void snakeWithTail();
    void snakeWithOtherSnakes();

    void keyHandler();
    void draw();
    void update();

    Snake snake;
    Food food;

    void gameOver();
    void gamePause();

    static int loadBestScore();
    static void saveBestScore();

    const static int cellSize;
    const static int cellCount;
    const static int offset;

    static int score;
    static int bestScore;

    static Color green;
    static Color darkGreen;



};


#endif //GAME_GAME_H
