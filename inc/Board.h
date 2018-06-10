#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

/**
 * funkcja rysująca planszę
 * @param boardWidth szerokość planszy
 * @param boardHeight wysokość planszy
 */
void drawBoard(int boardWidth, int boardHeight);

/**
 * funkcja rysująca pojedynczy kwadrat planszy
 * @param x współrzędna X
 * @param y współrzędna Y
 */
void unit(int x, int y);

#endif //SNAKE_BOARD_H
