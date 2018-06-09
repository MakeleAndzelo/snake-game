#include "../inc/SnakeQueue.h"
#include "../inc/Point.h"

bool pushFront(struct SnakeQueue *queue, int x, int y) {
    struct SnakeQueueNode *newNode = (struct SnakeQueueNode *) malloc(sizeof(struct SnakeQueueNode));

    if (NULL == newNode) {
        return false;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (NULL == queue->head) {
        queue->head = queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        newNode->prev = queue->tail;
        queue->tail = newNode;
    }

    changePointStatus(newNode->x, newNode->y);
    queue->size++;
    return true;
}

bool pushBack(struct SnakeQueue *queue, int x, int y) {
    struct SnakeQueueNode *newNode = (struct SnakeQueueNode *) malloc(sizeof(struct SnakeQueueNode));

    if (NULL == newNode) {
        return false;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (NULL == queue->head) {
        queue->head = queue->tail = newNode;
    } else {
        queue->head->prev = newNode;
        newNode->next = queue->head;
        queue->head = newNode;
    }

    changePointStatus(newNode->x, newNode->y);
    queue->size++;
    return true;
}

bool popBack(struct SnakeQueue *queue) {
    if (NULL == queue->tail) {
        return false;
    }

    changePointStatus(queue->tail->x, queue->tail->y);
    struct SnakeQueueNode *tmp = queue->tail->prev;
    free(queue->tail);
    queue->tail = tmp;
    if (NULL == tmp) {
        queue->head = NULL;
    } else {
        queue->tail->next = NULL;
    }

    queue->size--;
    return true;
}

bool searchQueue(struct SnakeQueue queue, int x, int y) {
    while (NULL != queue.head) {
        if (queue.head->x == x && queue.head->y == y) {
            return true;
        }

        queue.head = queue.head->next;
    }

    return false;
}

int getSize(struct SnakeQueue *queue) {
    return queue->size;
}

bool isEmpty(struct SnakeQueue queue) {
    return queue.size == 0;
}