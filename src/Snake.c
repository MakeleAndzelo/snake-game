#include "../inc/Snake.h"

struct Snake createSnake()
{
    struct SnakeQueue *snakeQueue = (struct SnakeQueue *) malloc(sizeof(struct SnakeQueue));

    pushFront(snakeQueue, 1, 7);
    pushFront(snakeQueue, 1, 6);
    pushFront(snakeQueue, 1, 5);
    pushFront(snakeQueue, 1, 4);
    pushFront(snakeQueue, 1, 3);
    pushFront(snakeQueue, 1, 2);

    struct Snake snake = {*snakeQueue};

    return snake;
}

void moveUp(struct Snake *snake)
{
    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, snake->snakeQueue.head->y - 1 , snake->snakeQueue.head->x);
}

void moveDown(struct Snake *snake)
{
    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, snake->snakeQueue.head->y + 1 , snake->snakeQueue.head->x);
}

void moveLeft(struct Snake *snake)
{
    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, snake->snakeQueue.head->y , snake->snakeQueue.head->x - 1);
}

void moveRight(struct Snake *snake)
{
    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, snake->snakeQueue.head->y , snake->snakeQueue.head->x + 1);
}

int getMove(struct Snake *snake)
{
    int choice = getch();

    switch (choice) {
        case KEY_UP:
            moveUp(snake);
            break;
        case KEY_DOWN:
            moveDown(snake);
            break;
        case KEY_RIGHT:
            moveRight(snake);
            break;
        case KEY_LEFT:
            moveLeft(snake);
            break;
        default:
            break;
    }

    return choice;
}

void display(struct Snake snake)
{
    struct SnakeQueueNode *head = snake.snakeQueue.head;
    while (NULL != head) {
        mvaddch(head->y, head->x, '#');
        head = head->next;
    }
}

