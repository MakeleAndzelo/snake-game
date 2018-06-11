#ifndef SNAKE_OBSTACLEQUEUE_H
#define SNAKE_OBSTACLEQUEUE_H

#include <stdbool.h>

/*! typ bazowy elementu listy przeszkód (lista jednokierunkowa) */
struct ObstacleListNode {
    /** Współrzędna X */
    int x;
    /** Współrzędna Y */
    int y;
    /** Wskaźnik na kolejny element listy przeszkód */
    struct ObstacleListNode *next;
};

/* typ bazowy listy przeszkód */
struct ObstacleList {
    struct ObstacleListNode *front; /**!< Wskaźnik na początek listy */
};

/**
 * funkcja tworząca listę przeszkód
 * @return wskaźnik na strukturę listy przeszkód po zmianach
 */
struct ObstacleList *createObstacleList();

/**
 * funkcja wstawiająca element na początek listy przeszkód
 * @return wskaźnik na strukturę listy przeszkód po zmianach
 */
struct ObstacleList *insertToObstaclesFront(struct ObstacleList *, struct ObstacleListNode *);

/**
 * funkcja dodająca przeszkodę do listy
 * @return flaga określająca czy dodawanie się powiodło
 */
bool insertObstacle(struct ObstacleList **);

/**
 * funkcja drukująca listę przeszkód
 */
void printObstacleList(struct ObstacleList);

/**
 * funkcja wyszukująca przeszkodę w liście o zadanych koordynatach
 * @return
 */
bool searchObstacleList(struct ObstacleList, int x, int y);

#endif //SNAKE_OBSTACLEQUEUE_H
