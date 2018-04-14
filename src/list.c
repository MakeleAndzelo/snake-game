#include "../inc/list.h"

struct list *createList(int data)
{
    struct listNode *newNode = (struct listNode *) malloc(sizeof(struct listNode));

    struct list *list = (struct list *) malloc(sizeof(struct list));

    if (NULL != newNode) {
        newNode->data = data;
        newNode->next = NULL;

        list->front = newNode;
    }

    list->size += 1;

    return list;
}

struct list *insertFront(struct list *list, struct listNode *newNode)
{
    newNode->next = list->front;
    list->front = newNode;
    return list;
}

struct listNode *findSpot(struct listNode *front, int data)
{
    struct listNode *prev = NULL;

    while ((NULL != front) && (front->data > data)) {
        prev = front;
        front = front->next;
    }

    return prev;
}

void insertAfter(struct listNode *node, struct listNode *newNode)
{
    newNode->next = node->next;
    node->next = newNode;
}

void insertBack(struct listNode *back, struct listNode *newNode)
{
    back ->next = newNode;
}

bool insertNode(struct list **list, int data)
{
    if (NULL == list) {
        return false;
    }

    struct listNode *newNode = (struct listNode *) malloc(sizeof(struct listNode));

    if (NULL != newNode) {
        newNode->data = data;
        newNode->next = NULL;

        if ((*list)->front->data <= data) {
            (*list)->size += 1;
            *list = insertFront(*list, newNode);
        } else {
            struct listNode *node = findSpot((*list)->front, data);

            if (NULL != node->next) {
                insertAfter(node, newNode);
            } else {
                insertBack(node, newNode);
            }
        }
    }

    (*list)->size += 1;
    return true;
}

struct list *deleteFront(struct list *list)
{
    struct listNode *next = list->front->next;
    free(list->front);
    list->front = next;

    return list;
}

struct listNode *findPrevNode(struct listNode *front, int data)
{
    struct listNode *prev = NULL;
    while ((NULL != front) && (front->data != data)) {
        prev = front;
        front = front->next;
    }

    return prev;
}

void deleteAfter(struct listNode *node)
{
    struct listNode *next = NULL != node ? node->next : NULL;
    if (NULL != next) {
        node->next = next->next;
        free(next);
    }
}

bool deleteNode(struct list **list, int data)
{
    if (NULL == list) {
        return NULL;
    }

    if ((*list)->front->data == data) {
        (*list)->size -= 1;
        *list = deleteFront(*list);
    }

    struct listNode *prev = findPrevNode((*list)->front, data);
    deleteAfter(prev);

    (*list)->size -= 1;

    return true;
}

void printList(struct list *list)
{
    for (; NULL != list->front; list->front = list->front->next) {
        printf("%d ", list->front->data);
    }
    printf("\n");
}

void removeList(struct list **list)
{
    struct listNode *next = NULL;
    while (NULL != (*list)->front) {
        next = (*list)->front->next;
        free((*list)->front);
        (*list)->front = next;
    }
}

bool isListEmpty(struct list *list)
{
    return list->size == 0;
}

int getListSize(struct list *list)
{
    return list->size;
}