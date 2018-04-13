#include <stdbool.h>
#include <stdlib.h>

#ifndef SNAKE_QUEUE_H
#define SNAKE_QUEUE_H

struct queueNode {
    int data;
    struct queueNode *next;
};

struct queue {
    struct queueNode *head, *tail;
    unsigned int size;
};

bool push(struct queue *, int);

bool pop(struct queue *, int *);

int getSize(struct queue *);

bool isEmpty(struct queue);

#endif //SNAKE_QUEUE_H
