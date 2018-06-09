#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <time.h>
#include <stdlib.h>
#include "../inc/FruitsList.h"
#include "../inc/ObstacleList.h"
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


void endGame();

void setup(int *, char **);

void displayWindow();

void reshapeWindow(int, int);

void timer(int);

void getUserInput(int);

bool areCollisions(struct Snake *, int, int);

#endif //SNAKE_GAME_H
