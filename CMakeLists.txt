cmake_minimum_required(VERSION 3.9)
project(Snake C)

set(CMAKE_C_STANDARD 99)

add_executable(Snake src/main.c src/SnakeQueue.c inc/SnakeQueue.h src/FruitsList.c inc/FruitsList.h src/Snake.c inc/Snake.h src/Game.c inc/Game.h)

target_link_libraries(Snake ncurses)