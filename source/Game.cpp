//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Game.h"


Color Game::green = {173, 204, 96, 255};
Color Game::darkGreen = {43, 51, 24, 255};

const int Game::cellSize = 30;
const int Game::cellCount = 25;
const int Game::offset = 50;

Game::Game(std::string title) {

    InitWindow(2 * offset + cellCount * cellSize,
               2 * offset + cellCount * cellSize,
               title.c_str());
    SetTargetFPS(60);

    lastUpdateTime = 0;

    board = Board(this-> cellSize, this->cellCount, this->offset);
    snake = Snake();
    food = Food();
    food.setPos(food.genereRandomPos(snake.getBody()));
}
Game::~Game() noexcept {
    CloseWindow();
}

int Game::getCellSize() {
    return this->cellSize;
}

int Game::getCellCount() {
    return this->cellCount;
}

int Game::getOffset() {
    return this->offset;
}

void Game::draw() {
    food.draw();
    snake.draw();
    board.draw();
}

void Game::update() {
    if(running) {
        snake.move();
        checkCollisions();
    }


}

void Game::tick() {
    BeginDrawing();
    if(eventTriggered(0.2)) {
        update();
    }
    keyHandler();
    draw();
    EndDrawing();
}


void Game::keyHandler() {
    if(IsKeyPressed(KEY_UP) && snake.getDirection().getY() != 1) {
        snake.setDirection({0, -1});
        running = true;
    }
    if(IsKeyPressed(KEY_DOWN) && snake.getDirection().getY()!= -1) {
        snake.setDirection({0, 1});
        running = true;
    }
    if(IsKeyPressed(KEY_LEFT) && snake.getDirection().getX() != 1) {
        snake.setDirection({-1, 0});
        running = true;
    }
    if(IsKeyPressed(KEY_RIGHT) && snake.getDirection().getX() != -1) {
        snake.setDirection({1, 0});
        running = true;
    }
}

bool Game::eventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    } else {
        return false;
    }
}

void Game::checkCollisions() {
    snakeWithFood();
    snakeWithTail();
    snakeWithEdge();
}

void Game::snakeWithFood() {
    if(snake.getBody()[0] == food.getPos()) {
        food.setPos(food.genereRandomPos(snake.getBody()));
        snake.setSegment(true);
    }
}

void Game::snakeWithTail() {
    std::deque<Vec2<int>> headlessBody = snake.getBody();
    headlessBody.pop_front();

    if(Vec2<int>::elementInDeque(snake.getBody()[0], headlessBody)) {
        gameOver();
    }
}

void Game::snakeWithEdge() {
    if(snake.getBody()[0].getX() == cellCount || snake.getBody()[0].getX() == -1) {
        gameOver();
    }
    if(snake.getBody()[0].getY() == cellCount || snake.getBody()[0].getY() == -1) {
        gameOver();
    }
}

void Game::gameOver() {
    snake.reset();
    food.genereRandomPos(snake.getBody());
    running = false;
}


