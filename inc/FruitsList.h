#ifndef SNAKE_LIST_H
#define SNAKE_LIST_H

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/Game.h"

struct FruitsListNode {
    int x, y;
    bool isToxic;
    struct FruitsListNode *next;
};

struct FruitsList {
    struct FruitsListNode *front;
};

/**
 * funkcja tworząca listę owoców
 * @return lista stworzona przez funkcje
 */
struct FruitsList *createList();

/**
 * funkcja dodająca element na początek listy
 * @return lista po dodaniu elementu
 */
struct FruitsList *insertFront(struct FruitsList *, struct FruitsListNode *);

/**
 * funkcja dodająca do listy owoc o losowym położeniu i prawdopodobieństwie 0.1 na bycie toksycznym
 * @return flaga określająca czy dodawanie się powiodło
 */
bool insertNode(struct FruitsList **);

/**
 * funkcja znajdująca owoc, który znajduje sie w liście przed owocem o podanych koordynatach
 * @return szukany owoc
 */
struct FruitsListNode *findPrevNode(struct FruitsListNode *, int, int);

/**
 * funkcja usuwająca element w liście owoców za podanym elementem
 */
void deleteAfter(struct FruitsListNode *);

/**
 * funkcja usuwająca element o podanych koordynatach
 * @param y współrzędna Y
 * @param x współrzędna X
 * @param isToxic flaga określająca czy element był toksyczny dla węża
 * @return
 */
bool deleteNode(struct FruitsList **, int y, int x, bool *isToxic);

/**
 * funkcja drukująca daną listę owoców na ekran
 */
void printList(struct FruitsList);

/**
 * funkcja określająca czy w liście owoców znajduje się owoc o zadanych koordynatach
 * @param y współrzędna Y
 * @param x współrzędna X
 * @return flaga określająca czy owoc został odlaneziony
 */
bool searchList(struct FruitsList, int, int);

#endif
