#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H

#include <stdbool.h>

struct Point {
    int x, y;
};

bool points[40][40];

struct Point *randomPoint();

void changePointStatus(int, int);

#endif //SNAKE_POINT_H
