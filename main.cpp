#include <iostream>
#include <raylib.h>
#include "headers/Game.h"


void exit();
int main() {
    std::cout << "Game starting..." << std::endl;



    InitWindow(2 * settings::offset + settings::cellCount * settings::cellSize,
               2 * settings::offset + settings::cellCount * settings::cellSize,
               "Snake");
    atexit(exit);
    Game game = Game();

    while (!WindowShouldClose()) {
        game.tick();
    }


    return 0;
}

void exit() {
    CloseWindow();
}
