#include <stdbool.h>
#include <stdlib.h>

#ifndef SNAKE_QUEUE_H
#define SNAKE_QUEUE_H

struct SnakeQueueNode {
    int y, x;
    struct SnakeQueueNode *next, *prev;
};

struct SnakeQueue {
    struct SnakeQueueNode *head, *tail;
    unsigned int size;
};

bool pushFront(struct SnakeQueue *, int, int);

bool pushBack(struct SnakeQueue *, int, int);

bool popFront(struct SnakeQueue *);

bool popBack(struct SnakeQueue *);

bool searchQueue(struct SnakeQueue, int, int);

void removeQueue(struct SnakeQueue **);

int getSize(struct SnakeQueue *);

bool isEmpty(struct SnakeQueue);

#endif //SNAKE_QUEUE_H
