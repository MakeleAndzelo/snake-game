#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <time.h>
#include <stdlib.h>
#include "../inc/FruitsList.h"
#include "../inc/ObstacleList.h"
#include "./Snake.h"

/**
 * typ wyliczeniowy reprezentujący kierunek węża
 */
enum Direction {
    UP = 1, DOWN, RIGHT, LEFT
} dir;

enum Status {
    FAILURE = 0, SUCCESS
} status;
struct FruitsList *fruits;
struct Snake snake;
struct ObstacleList *obstacles;

/**
 * funkcja kończąca grę, wyświetla napisy końcowe
 */
void endGame();

/**
 * funkcja inicjująca bibliotekę GLUT
 * @param argc
 * @param argv
 */
void setup(int *argc, char **argv);

/**
 * funkcja inicjująca okno gry
 */
void displayWindow();

/**
 *
 * @param width
 * @param height
 */
void reshapeWindow(int width, int height);

/**
 *
 */
void timer();

/**
 * funkcja pobierająca klawisz naciśnięty przez gracza, oraz ustawiająca pozycję w którą porusza się wąż
 */
void getUserInput(int key);

/**
 * funkcja sprawdzająca czy wąż koliduje z bytem występującym na podanej współrzędnej
 * @param snake struktura węża
 * @param x współrzędna X
 * @param y współrzędna Y
 * @return flaga określająca czy wystąpiła kolizja
 */
bool areCollisions(struct Snake *snake, int x, int y);

#endif //SNAKE_GAME_H
