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

struct FruitsList *createList();

struct FruitsList *insertFront(struct FruitsList *, struct FruitsListNode *);

bool insertNode(struct FruitsList **);

struct FruitsListNode *findPrevNode(struct FruitsListNode *, int, int);

void deleteAfter(struct FruitsListNode *);

bool deleteNode(struct FruitsList **, int, int, bool *);

void printList(struct FruitsList);

bool searchList(struct FruitsList, int, int);

#endif
