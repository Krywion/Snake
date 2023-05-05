//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Board.h"
#include "../headers/Game.h"


void Board::draw() {
    ClearBackground(Game::green);
    DrawRectangleLinesEx(Rectangle{(float) Game::offset-5, (float) Game::offset-5, (float) Game::cellSize*Game::cellCount+10, (float) Game::cellSize*Game::cellCount+10}, 5, Game::darkGreen);
    DrawText("Modern Snake", Game::offset - 5, 10, 40, Game::darkGreen);
    DrawText(TextFormat("%i", Game::score), Game::offset - 5, Game::offset+Game::cellSize*Game::cellCount+10, 40, Game::darkGreen);
}

void Board::drawTexture2D(Texture2D texture2D, int posX, int posY) {
    DrawTexture(texture2D, Game::offset + Game::cellSize*posX,Game::offset + Game::cellSize*posY ,RAYWHITE);

}

void Board::drawRect(int posX, int posY, Color color) {
    Rectangle rectangle = Rectangle{(float)Game::offset + posX * Game::cellSize,
                                    (float) Game::offset + posY * Game::cellSize,
                                    (float) Game::cellSize,
                                    (float) Game::cellSize};
    DrawRectangleRounded(rectangle, 0.5, 6, color);
}

Vec2<int> Board::genereRandomCell() {
    int x = GetRandomValue(0, Game::cellCount -1);
    int y = GetRandomValue(0, Game::cellCount -1);
    return Vec2<int>{x, y};
}



