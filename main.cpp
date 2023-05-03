#include <iostream>
#include <raylib.h>
#include "headers/Game.h"


int main() {
    std::cout << "Game starting..." << std::endl;

    Game game = Game("Snake");

    while (!WindowShouldClose()) {
        game.tick();
    }

    return 0;
}
