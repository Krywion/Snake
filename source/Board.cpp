//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/Board.h"
#include "../headers/Game.h"


void Board::draw() {
    ClearBackground(Game::green);
    DrawRectangleLinesEx(Rectangle{(float) offset-5, (float) offset-5, (float) cellSize*cellCount+10, (float) cellSize*cellCount+10}, 5, Game::darkGreen);
}

Board::Board(int cellSize, int cellCount, int offset) : cellSize(cellSize), cellCount(cellCount), offset(offset){

}

Board::Board() {

}

