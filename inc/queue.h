#include <stdbool.h>
#include <stdlib.h>
#ifndef SNAKE_QUEUE_H
#define SNAKE_QUEUE_H

struct queueNode {
    int data;
    struct queueNode *next;
};

struct queuePointers {
    struct queueNode *head, *tail;
};

bool enqueue(struct queuePointers *, int);

bool dequeue(struct queuePointers *, int *);

#endif //SNAKE_QUEUE_H
