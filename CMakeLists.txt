cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 23)

include_directories(/opt/homebrew/Cellar/raylib/4.5.0/include)
link_directories(/opt/homebrew/Cellar/raylib/4.5.0/lib)

add_executable(Game main.cpp source/Game.cpp headers/Game.h source/Snake.cpp headers/Snake.h source/Food.cpp headers/Food.h source/GameObject.cpp headers/GameObject.h headers/Vec2.h source/Board.cpp headers/Board.h source/ShadowSnake.cpp headers/ShadowSnake.h headers/Settings.h)

target_link_libraries(Game libraylib.4.2.0.dylib)