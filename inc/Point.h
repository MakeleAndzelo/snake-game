#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H

#include <stdbool.h>

/*! typ bazowy punktu w układzie kartezjańskim */
struct Point {
    /** Współrzędna X */
    int x;
    /** Współrzędna Y */
    int y;
};

bool points[40][40];

/**
 * funkcja zwracająca punkt o losowych koordynatach
 * @return wskaźnik na wylosowany punkt
 */
struct Point *randomPoint();

/**
 * funkcja ustawiająca flagę zajętości na polu o zadanych koordynatach
 * @param x współrzędna X
 * @param y współrzędna Y
 */
void changePointStatus(int x, int y);

#endif //SNAKE_POINT_H
