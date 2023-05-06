//
// Created by Maks Krywionek on 02/05/2023.
//

#include <regex>
#include "../headers/Game.h"


Color Game::green = {173, 204, 96, 255};
Color Game::darkGreen = {43, 51, 24, 255};

const int Game::cellSize = 25;
const int Game::cellCount = 25;
const int Game::offset = 50;

int Game::score = 0;
int Game::bestScore;

std::deque<ShadowSnake> Game::shadowSnakes = {};

Game::Game(const std::string& title) {

    InitWindow(2 * offset + cellCount * cellSize,
               2 * offset + cellCount * cellSize,
               title.c_str());
    SetTargetFPS(60);

    lastUpdateTime = 0;
    running = false;
    bestScore = loadBestScore();

    snake = Snake();
    food = Food(snake.getBody());
    food.loadImage();
    shadowSnakes = {};

}
Game::~Game() noexcept {
    food.unloadImage();
    CloseWindow();
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
        food.setPos(food.genereRandomPos(snake.getBody()));
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
    gamePause();
    eventTriggered(3);
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
    std::string line;
    std::regex pattern("\\d+");
    std::smatch matches;
    int max = 0, number;

    std::ifstream is;
    is.open("../leaderboards.txt");

    if(is.is_open()) {
        while (getline(is,line))
        {
            if (std::regex_search(line, matches, pattern)) {
                std::string numberStr = matches.str();
                number = std::stoi(numberStr);
                if(number > max) {
                    max = number;
                }
            }
        }
    } else {
        std::cout << "Nie udało się otworzyć pliku 1" << std::endl;
    }
    is.close();
    return max;
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




