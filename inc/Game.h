#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <time.h>
#include <stdlib.h>
#include "../inc/FruitsList.h"
#include "./Snake.h"

enum Direction {
    UP = 1, DOWN, RIGHT, LEFT
} dir;
enum Status {
    FAILURE = 0, SUCCESS
} status;
struct FruitsList *fruits;
struct Snake snake;
struct ObstacleList *obstacles;
int yMax, xMax;

void setup(int *, char **);

void displayWindow();

void reshapeWindow(int, int);

void timer(int);

void drawSnake();

void getUserInput(int, int, int);

bool areCollisions(struct Snake *, int, int);

#endif //SNAKE_GAME_H
