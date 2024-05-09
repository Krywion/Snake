cmake_minimum_required(VERSION 3.25)
project(Game)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib 3.0 REQUIRED)

add_executable(Game main.cpp source/Game.cpp headers/Game.h source/Snake.cpp headers/Snake.h source/Food.cpp headers/Food.h source/GameObject.cpp headers/GameObject.h headers/Vec2.h source/Board.cpp headers/Board.h source/ShadowSnake.cpp headers/ShadowSnake.h headers/Settings.h)

target_link_libraries(Game raylib)