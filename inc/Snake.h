#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Game.h"
#include "SnakeQueue.h"
#include "../inc/FruitsList.h"

/**
 * typ bazowy przechowujący informacje o wężu
 */
struct Snake {
    struct SnakeQueue snakeQueue;
};

/**
 * funkcja tworząca nową instancję wężą
 * @return struktura przechowująca typ bazowy węża
 */
struct Snake createSnake();

/**
 * funkcja przemieszczająca węża w górę
 * @return flaga informująca o tym czy nastąpiła kolizja
 */
bool moveUp(struct Snake *);

/**
 * funkcja przemieszczająca węża w dół
 * @return flaga informująca o tym czy nastąpiła kolizja
 */
bool moveDown(struct Snake *);

/**
 * funkcja przemieszczająca węża w prawo
 * @return flaga informująca o tym czy nastąpiła kolizja
 */
bool moveRight(struct Snake *);

/**
 * funkcja przemieszczająca węża w lewo
 * @return flaga informująca o tym czy nastąpiła kolizja
 */
bool moveLeft(struct Snake *);

/**
 * funkcja określająca czy dany ruch się powiódł
 * @return wartość wyliczenia informująca czy dany ruch zakończył się sukcesem
 */
enum Status moveSnake(struct Snake *);

/**
 * funkcja usuwająca owoc o podanych koordynatach wykonując efekt "zjadania" czyli dodaje lub odejmuje długość węża
 * @param x współrzędna X
 * @param y współrzędna Y
 */
void eatFruit(struct Snake *, int x, int y);

/**
 * funkcja wyświetlająca węża
 */
void display(struct Snake);

#endif //SNAKE_SNAKE_H
