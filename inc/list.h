#ifndef SNAKE_LIST_H
#define SNAKE_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct listNode {
    int data;
    struct listNode *next;
};

struct list {
    struct listNode *front;
    int size;
};

struct list *createList(int);

struct list *insertFront(struct list *, struct listNode *);

struct listNode *findSpot(struct listNode *, int);

void insertAfter(struct listNode *, struct listNode *);

void insertBack(struct listNode *, struct listNode *);

bool insertNode(struct list **, int);

struct list *deleteFront(struct list *);

struct listNode *findPrevNode(struct listNode *, int );

void deleteAfter(struct listNode *);

bool deleteNode(struct list **, int);

void printList(struct list *);

void removeList(struct list **);

bool isListEmpty(struct list *);

int getListSize(struct list *);

#endif
