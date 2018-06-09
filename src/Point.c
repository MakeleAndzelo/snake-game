#include <stdlib.h>
#include "../inc/Point.h"
#include "../inc/Game.h"

struct Point *randomPoint() {
    struct Point *newPoint = (struct Point *) malloc(sizeof(struct Point));

    if (newPoint) {
        do {
            newPoint->x = rand() % 38 + 1;
            newPoint->y = rand() % 38 + 1;
        } while (points[newPoint->x][newPoint->y]);
    }

    changePointStatus(newPoint->x, newPoint->y);

    return newPoint;
}

void changePointStatus(int x, int y) {
    points[x][y] = points[x][y] ? false : true;
}