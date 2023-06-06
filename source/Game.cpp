//
// Created by Maks Krywionek on 02/05/2023.
//

#include <regex>
#include "../headers/Game.h"


Color Game::green = {173, 204, 96, 255};
Color Game::darkGreen = {43, 51, 24, 255};

const int Game::cellCount = settings::cellCount;
const int Game::cellSize = settings::cellSize;
const int Game::offset = settings::offset;

const float Game::speed = settings::speed;

int Game::score = 0;
int Game::bestScore;


std::deque<ShadowSnake> Game::shadowSnakes = {};

Game::Game() : snake(Snake()), food(snake.getBody()){
    lastUpdateTime = 0;
    running = false;
    bestScore = loadBestScore();
    shadowSnakes = {};
}

void Game::draw() {
    Board::draw();
    snake.draw();
    for(auto &shadowSnake: shadowSnakes) {
        shadowSnake.draw();
    }
    food.draw();
}

void Game::update() {
    if(running) {
        snake.move();
        for(auto &shadowSnake : shadowSnakes) {
            shadowSnake.move();
        }
        checkCollisions();
    }
}

void Game::tick() {
    BeginDrawing();
    if(eventTriggered(speed)) {
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
    if(IsKeyPressed(KEY_SPACE)) {
        gamePause();
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
    snakeWithOtherSnakes();
}

void Game::snakeWithFood() {
    if(snake.getBody()[0] == food.getPos()) {
        food.genereRandomPos(snake.getBody());
        snake.setSegment(true);
        score++;
        shadowSnakes.emplace_back(snake.getTrace(), snake.getBody().size());
    }
}

void Game::snakeWithTail() {
    std::deque<Vec2<int>> headlessBody = snake.getBody();
    headlessBody.pop_front();

    if(Vec2<int>::elementInDeque(snake.getBody()[0], headlessBody)) {
        gameOver();
    }
}

void Game::snakeWithOtherSnakes() {
    for(auto &shadowSnake : shadowSnakes) {
        if(Vec2<int>::elementInDeque(snake.getBody()[0], shadowSnake.getBody())) {
            gameOver();
        }
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
    if(score > bestScore) {
        bestScore = score;
        saveBestScore();
    }
    score = 0;
    shadowSnakes = {};
}

void Game::gamePause() {
    running = false;
}

int Game::loadBestScore() {

    std::regex pattern("\\d+");
    std::smatch matches;
    int number = 0;

    std::ifstream is;
    is.open("../leaderboards.txt");

    if(is.is_open()) {
        std::string line;
        while (getline(is,line))
        {
            if (std::regex_search(line, matches, pattern)) {
                std::string numberStr = matches.str();
                number = std::stoi(numberStr);
            }
        }
    } else {
        std::cout << "Nie udało się otworzyć pliku 1" << std::endl;
    }
    is.close();
    return number;
}

void Game::saveBestScore() {
    std::fstream fs;

    fs.open("../leaderboards.txt");

    std::string line = "Bestscore: " + std::to_string(bestScore);
    line += "\n";

    if(fs.is_open()) {
        std::cout << "zapisuje: " << line;
        fs << line;
    } else {
        std::cout << "Nie udało się otworzyć pliku 2" << std::endl;
    }
    fs.close();
}




