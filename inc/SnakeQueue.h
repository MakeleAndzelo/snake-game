#include <stdbool.h>
#include <stdlib.h>

#ifndef SNAKE_QUEUE_H
#define SNAKE_QUEUE_H

/*! typ bazowy elementu kolejki węża (lista dwukierunkowa) */
struct SnakeQueueNode {
    /** Współrzędna X */
    int x;
    /** Współrzędna Y */
    int y;
    /** Wskaźnik na następny element węża */
    struct SnakeQueueNode *next;
    /** Wskaźnik na poprzedni element węża */
    struct SnakeQueueNode *prev;
};

/**
 * typ bazowy kolejki węża
 */
struct SnakeQueue {
    struct SnakeQueueNode *head, *tail;
    unsigned int size;
};

/**
 * funkcja dodająca element o podanych koordynatach na początek kolejki
 * @return flaga określająca czy dodawanie się powiodło
 */
bool pushFront(struct SnakeQueue *, int x, int y);

/**
 * funkcja dodająca element o podanych koordynatach na koniec kolejki
 * @return flaga określająca czy dodawanie się powiodło
 */
bool pushBack(struct SnakeQueue *, int x, int y);

/**
 * funkcja zdejmująca element z końca kolejki
 * @return flaga określająca czy zdejmowanie się powiodło
 */
bool popBack(struct SnakeQueue *);

/**
 * funkcja określająca czy w kolejce występuje element o podanych koordynatach
 * @return flaga określająca czy podany element wystąpił
 */
bool searchQueue(struct SnakeQueue, int x, int y);

/**
 * funkcja pobierająca ilość elementów w kolejce węża
 * @return ilość elementów w kolejce węża
 */
int getSize(struct SnakeQueue *);

/**
 * funkcja określająca czy kolejka węża jest pusta
 * @return flaga określająca czy kolejka jest pusta
 */
bool isEmpty(struct SnakeQueue);

#endif //SNAKE_QUEUE_H
