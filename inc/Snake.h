#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <ncurses.h>
#include "SnakeQueue.h"

struct Snake {
    struct SnakeQueue snakeQueue;
};

struct Snake createSnake();
void moveUp(struct Snake *);
void moveDown(struct Snake *);
void moveRight(struct Snake *);
void moveLeft(struct Snake *);
int getMove(struct Snake *);
void display(struct Snake);

#endif //SNAKE_SNAKE_H
