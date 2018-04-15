#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ncurses.h>

enum Direction {UP = 1, DOWN, RIGHT, LEFT} dir;
enum Status {FAILURE, SUCCESS} status;
int yMax, xMax;

void setup();
enum Direction getUserInput(enum Direction);

#endif //SNAKE_GAME_H
