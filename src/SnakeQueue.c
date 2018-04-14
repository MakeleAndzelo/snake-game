#include "../inc/SnakeQueue.h"

bool pushFront(struct SnakeQueue *queue, int y, int x)
{
    struct SnakeQueueNode *newNode = (struct SnakeQueueNode *) malloc(sizeof(struct SnakeQueueNode));

    if (NULL == newNode) {
        return false;
    }

    newNode->y = y;
    newNode->x = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (NULL == queue->head) {
        queue->head = queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        newNode->prev = queue->tail;
        queue->tail = newNode;
    }

    queue->size++;
    return true;
}

bool pushBack(struct SnakeQueue *queue, int y, int x)
{
    struct SnakeQueueNode *newNode = (struct SnakeQueueNode *) malloc(sizeof(struct SnakeQueueNode));

    if(NULL == newNode) {
        return false;
    }

    newNode->y = y;
    newNode->x = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (NULL == queue->head) {
        queue->head = queue->tail = newNode;
    } else {
        queue->head->prev = newNode;
        newNode->next = queue->head;
        queue->head = newNode;
    }

    queue->size++;
    return true;
}

bool popFront(struct SnakeQueue *queue)
{
    if (NULL == queue->head) {
        return false;
    }

    struct SnakeQueueNode *tmp = queue->head->next;
    free(queue->head);
    queue->head = tmp;
    if(NULL == tmp) {
        queue->tail = NULL;
    } else {
        queue->head->prev = NULL;
    }

    queue->size--;
    return true;
}

bool popBack(struct SnakeQueue *queue)
{
    if (NULL == queue->tail) {
        return false;
    }

    struct SnakeQueueNode *tmp = queue->tail->prev;
    free(queue->tail);
    queue->tail = tmp;
    if(NULL == tmp) {
        queue->head = NULL;
    } else {
        queue->tail->next = NULL;
    }

    queue->size--;
    return true;
}

int getSize(struct SnakeQueue *queue)
{
    return queue->size;
}

bool isEmpty(struct SnakeQueue queue)
{
    return queue.size == 0;
}