#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ncurses.h>
#include "Snake.h"
#include <time.h>
#include <stdlib.h>
#include "../inc/FruitsList.h"


enum Direction {UP = 1, DOWN, RIGHT, LEFT} dir;
enum Status {FAILURE, SUCCESS} status;
struct FruitsList *fruits;
int yMax, xMax;

void displayWindow();
void reshapeWindow(int, int);
void setup(int *, char **);
enum Direction getUserInput(enum Direction);
bool areCollisions(struct Snake *, int, int);

#endif //SNAKE_GAME_H
