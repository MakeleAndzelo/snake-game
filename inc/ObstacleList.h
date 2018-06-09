#ifndef SNAKE_OBSTACLEQUEUE_H
#define SNAKE_OBSTACLEQUEUE_H

#include <stdbool.h>

struct ObstacleListNode {
    int x, y;
    struct ObstacleListNode *next;
};

struct ObstacleList {
    struct ObstacleListNode *front;
};

struct ObstacleList *createObstacleList();

struct ObstacleList *insertToObstaclesFront(struct ObstacleList *, struct ObstacleListNode *);

bool insertObstacle(struct ObstacleList **);

void printObstacleList(struct ObstacleList);

bool searchObstacleList(struct ObstacleList, int, int);

#endif //SNAKE_OBSTACLEQUEUE_H
