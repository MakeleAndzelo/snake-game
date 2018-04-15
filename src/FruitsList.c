#include "../inc/FruitsList.h"

struct FruitsList *createList()
{
    struct FruitsListNode *newNode = (struct FruitsListNode *) malloc(sizeof(struct FruitsListNode));

    struct FruitsList *list = (struct FruitsList *) malloc(sizeof(struct FruitsList));

    if (NULL != newNode) {
        newNode->y = rand() % yMax;
        newNode->x = rand() % xMax;
        newNode->next = NULL;

        list->front = newNode;
    }

    for(int i = 0; i < 5; i++) {
        insertNode(&list);
    }

    list->size = 6;

    return list;
}

struct FruitsList *insertFront(struct FruitsList *list, struct FruitsListNode *newNode)
{
    newNode->next = list->front;
    list->front = newNode;
    return list;
}

bool insertNode(struct FruitsList **list)
{
    if (NULL == list) {
        return false;
    }

    struct FruitsListNode *newNode = (struct FruitsListNode *) malloc(sizeof(struct FruitsListNode));

    if (NULL != newNode) {
        newNode->y = rand() % yMax;
        newNode->x = rand() % xMax;
        newNode->next = NULL;

        *list = insertFront(*list, newNode);
    }

    (*list)->size += 1;
    return true;
}

struct FruitsList *deleteFront(struct FruitsList *list)
{
    struct FruitsListNode *next = list->front->next;
    free(list->front);
    list->front = next;

    return list;
}

struct FruitsListNode *findPrevNode(struct FruitsListNode *front, int y, int x)
{
    struct FruitsListNode *prev = NULL;
    while (NULL != front && front->y != y && front->x != x) {
        prev = front;
        front = front->next;
    }

    return prev;
}

void deleteAfter(struct FruitsListNode *node)
{
    struct FruitsListNode *next = NULL != node ? node->next : NULL;
    if (NULL != next) {
        node->next = next->next;
        free(next);
    }
}

bool deleteNode(struct FruitsList **list, int y, int x)
{
    if (NULL == list) {
        return NULL;
    }

    if ((*list)->front->y == y && (*list)->front->x == x) {
        (*list)->size -= 1;
        *list = deleteFront(*list);
        return true;
    }

    struct FruitsListNode *prev = findPrevNode((*list)->front, y, x);
    deleteAfter(prev);

    (*list)->size -= 1;
    return true;
}

void printList(struct FruitsList list)
{
    for (; NULL != list.front; list.front = list.front->next) {
        mvaddch(list.front->y, list.front->x, '*');
    }
    printf("\n");
}

void removeList(struct FruitsList **list)
{
    struct FruitsListNode *next = NULL;
    while (NULL != (*list)->front) {
        next = (*list)->front->next;
        free((*list)->front);
        (*list)->front = next;
    }
}

bool searchList(struct FruitsList list, int y, int x)
{
    for (; NULL != list.front; list.front = list.front->next) {
        if(list.front->y == y && list.front->x == x) {
            return true;
        }
    }

    return false;
}

bool isListEmpty(struct FruitsList *list)
{
    return list->size == 0;
}

int getListSize(struct FruitsList *list)
{
    return list->size;
}