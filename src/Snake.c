#include "../inc/Snake.h"

struct Snake createSnake()
{
    struct SnakeQueue *snakeQueue = (struct SnakeQueue *) malloc(sizeof(struct SnakeQueue));


    pushFront(snakeQueue, 0, 1);
    pushFront(snakeQueue, 0, 0);

    struct Snake snake = {*snakeQueue};

    return snake;
}

bool moveUp(struct Snake *snake)
{
    int newY = snake->snakeQueue.head->y - 1, newX = snake->snakeQueue.head->x;

    if (!areCollisions(snake, newY, newX) || newY == -1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveDown(struct Snake *snake)
{
    int newY = snake->snakeQueue.head->y + 1, newX = snake->snakeQueue.head->x;

    if (!areCollisions(snake, newY, newX) || newY == yMax + 1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveLeft(struct Snake *snake)
{
    int newY = snake->snakeQueue.head->y, newX = snake->snakeQueue.head->x - 1;

    if (!areCollisions(snake, newY, newX) || newX == -1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveRight(struct Snake *snake)
{
    int newY = snake->snakeQueue.head->y, newX = snake->snakeQueue.head->x + 1;

    if (!areCollisions(snake, newY, newX) || newX == xMax + 1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

enum Status moveSnake(struct Snake *snake, enum Direction direction)
{
    switch (direction) {
        case UP:
            if (!moveUp(snake)) return FAILURE;
            break;
        case DOWN:
            if (!moveDown(snake)) return FAILURE;
            break;
        case RIGHT:
            if (!moveRight(snake)) return FAILURE;
            break;
        case LEFT:
            if (!moveLeft(snake)) return FAILURE;
            break;
        default:
            break;
    }

    return SUCCESS;
}

void eatFruit(struct Snake *snake, int y, int x)
{
    insertNode(&fruits);
    pushFront(&snake->snakeQueue, y + 1, x + 1);
    deleteNode(&fruits, y, x);
}

void display(struct Snake snake)
{
    struct SnakeQueueNode *head = snake.snakeQueue.head;
    while (NULL != head) {
        mvaddch(head->y, head->x, 'o');
        head = head->next;
    }
}

