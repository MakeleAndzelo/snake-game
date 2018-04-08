#include "../inc/queue.h"

bool dequeue(struct queuePointers *queue, int *data)
{
    if (NULL == queue->head) {
        return false;
    }

    struct queueNode *tmp = queue->head->next;
    *data = queue->head->data;
    free(queue->head);
    queue->head = tmp;
    if(NULL == tmp) {
        queue->tail = NULL;
    }

    return true;
}

bool enqueue(struct queuePointers *queue, int data)
{
    struct queueNode *newNode = (struct queueNode *) malloc(sizeof(struct queueNode));

    if (NULL == newNode) {
        return false;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(NULL == queue->head) {
        queue->head = queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    return true;
}