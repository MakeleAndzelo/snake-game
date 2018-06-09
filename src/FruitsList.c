#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/FruitsList.h"
#include "../inc/Point.h"

struct FruitsList *createList() {
    struct FruitsListNode *newNode = (struct FruitsListNode *) malloc(sizeof(struct FruitsListNode));
    struct FruitsList *list = (struct FruitsList *) malloc(sizeof(struct FruitsList));
    struct Point *point;

    if (NULL != newNode) {
        point = randomPoint();
        newNode->x = point->x;
        newNode->y = point->y;
        newNode->isToxic = (rand() % 101) > 90 ? true : false;
        newNode->next = NULL;

        list->front = newNode;
    }

    for (int i = 0; i < 2; i++) {
        insertNode(&list);
    }

    return list;
}

struct FruitsList *insertFront(struct FruitsList *list, struct FruitsListNode *newNode) {
    newNode->next = list->front;
    list->front = newNode;
    return list;
}

bool insertNode(struct FruitsList **list) {
    if (NULL == list) {
        return false;
    }

    struct FruitsListNode *newNode = (struct FruitsListNode *) malloc(sizeof(struct FruitsListNode));
    struct Point *point;

    if (NULL != newNode) {
        point = randomPoint();
        newNode->x = point->x;
        newNode->y = point->y;
        newNode->isToxic = (rand() % 101) > 90 ? true : false;
        newNode->next = NULL;

        *list = insertFront(*list, newNode);
    }

    return true;
}

struct FruitsListNode *findPrevNode(struct FruitsListNode *front, int x, int y) {
    struct FruitsListNode *prev = front;
    while (((front->x != x) && (front->y != y)) && front) {
        prev = front;
        front = front->next;
    }
    return prev;
}

void deleteAfter(struct FruitsListNode *node) {
    struct FruitsListNode *next = NULL != node ? node->next : NULL;
    if (NULL != next) {
        node->next = next->next;
        free(next);
    }
}

bool deleteNode(struct FruitsList **list, int x, int y, bool *isToxic) {
    if (NULL == list) {
        return false;
    }

    if (((*list)->front->x == x) && ((*list)->front->y == y)) {
        *isToxic = (*list)->front->isToxic;
        struct FruitsListNode *next = (*list)->front->next;
        free((*list)->front);
        (*list)->front = next;
    } else {
        struct FruitsListNode *prev = findPrevNode((*list)->front, x, y);
        *isToxic = NULL == prev->next ? prev->isToxic : prev->next->isToxic;
        deleteAfter(prev);
    }

    return true;
}

void printList(struct FruitsList list) {
    for (; NULL != list.front; list.front = list.front->next) {
        if (true == list.front->isToxic) {
            glColor3d(1.0, 0.0, 0.0);
        } else {
            glColor3d(0.0, 1.0, 0.0);
        }
        glRectd(list.front->x, list.front->y, list.front->x + 1, list.front->y + 1);
    }
}

bool searchList(struct FruitsList list, int x, int y) {
    for (; NULL != list.front; list.front = list.front->next) {
        if (list.front->x == x && list.front->y == y) {
            return true;
        }
    }

    return false;
}