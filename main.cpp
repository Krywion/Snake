#include <iostream>
#include <raylib.h>
#include "headers/Game.h"


int main() {
    std::cout << "Game starting..." << std::endl;

    InitWindow(2 * settings::offset + settings::cellCount * settings::cellSize,
               2 * settings::offset + settings::cellCount * settings::cellSize,
               "Snake");
    Game game = Game();

    while (!WindowShouldClose()) {
        game.tick();
    }

    CloseWindow();
    return 0;
}

