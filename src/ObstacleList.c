#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/ObstacleList.h"
#include "../inc/Point.h"

struct ObstacleList *createObstacleList() {
    struct ObstacleListNode *newNode = (struct ObstacleListNode *) malloc(sizeof(struct ObstacleListNode));
    struct ObstacleList *list = (struct ObstacleList *) malloc(sizeof(struct ObstacleList));
    struct Point *point;

    if (NULL != newNode) {
        point = randomPoint();
        newNode->x = point->x;
        newNode->y = point->y;
        newNode->next = NULL;

        list->front = newNode;
    }

    for (int i = 0; i < 15; i++) {
        insertObstacle(&list);
    }

    return list;
}

struct ObstacleList *insertToObstaclesFront(struct ObstacleList *list, struct ObstacleListNode *newNode) {
    newNode->next = list->front;
    list->front = newNode;
    return list;
}

bool insertObstacle(struct ObstacleList **list) {
    if (NULL == list) {
        return false;
    }

    struct ObstacleListNode *newNode = (struct ObstacleListNode *) malloc(sizeof(struct ObstacleListNode));
    struct Point *point;

    if (NULL != newNode) {
        point = randomPoint();
        newNode->x = point->x;
        newNode->y = point->y;
        newNode->next = NULL;

        *list = insertToObstaclesFront(*list, newNode);
    }

    return true;
}

void printObstacleList(struct ObstacleList list) {
    for (; NULL != list.front; list.front = list.front->next) {
        glColor3f(0.5, 0.5, 0.5);
        glRectd(list.front->x, list.front->y, list.front->x + 1, list.front->y + 1);
    }
}

bool searchObstacleList(struct ObstacleList list, int x, int y) {
    for (; NULL != list.front; list.front = list.front->next) {
        if (list.front->x == x && list.front->y == y) {
            return true;
        }
    }

    return false;
}
