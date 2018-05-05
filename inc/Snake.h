#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Game.h"
#include "SnakeQueue.h"
#include "../inc/FruitsList.h"

struct Snake {
    struct SnakeQueue snakeQueue;
};

struct Snake createSnake();
bool moveUp(struct Snake *);
bool moveDown(struct Snake *);
bool moveRight(struct Snake *);
bool moveLeft(struct Snake *);
enum Status moveSnake(struct Snake *);
void eatFruit(struct Snake *, int, int);
void display(struct Snake);

#endif //SNAKE_SNAKE_H
