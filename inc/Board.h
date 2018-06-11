#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <stdbool.h>

/**
 * funkcja rysująca planszę o podanej szerokości
 * @param boardWidth szerokość planszy
 * @param boardHeight wysokość planszy
 */
void drawBoard(int boardWidth, int boardHeight);

/**
 * funkcja rysująca pojedynczy kwadrat planszy o podanym kolorze i koordynatach
 * @param x współrzędna X
 * @param y współrzędna Y
 * @param red czerwony
 * @param green zielony
 * @param blue niebieski
 */
void unit(int x, int y, float red, float green, float blue);

#endif //SNAKE_BOARD_H
