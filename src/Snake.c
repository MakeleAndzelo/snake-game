#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/Snake.h"

struct Snake createSnake() {
    struct SnakeQueue *snakeQueue = (struct SnakeQueue *) malloc(sizeof(struct SnakeQueue));

    pushFront(snakeQueue, 20, 20);
    pushFront(snakeQueue, 21, 20);
    pushFront(snakeQueue, 22, 20);

    struct Snake snake = {*snakeQueue};

    return snake;
}

bool moveUp(struct Snake *snake) {
    int newY = snake->snakeQueue.head->y + 1, newX = snake->snakeQueue.head->x;

    if (!areCollisions(snake, newY, newX) || newY >= 39) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveDown(struct Snake *snake) {
    int newY = snake->snakeQueue.head->y - 1, newX = snake->snakeQueue.head->x;

    if (!areCollisions(snake, newY, newX) || newY < 1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveLeft(struct Snake *snake) {
    int newY = snake->snakeQueue.head->y, newX = snake->snakeQueue.head->x - 1;

    if (!areCollisions(snake, newY, newX) || newX <= 0) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

bool moveRight(struct Snake *snake) {
    int newY = snake->snakeQueue.head->y, newX = snake->snakeQueue.head->x + 1;

    if (!areCollisions(snake, newY, newX) || newX >= 39) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newY, newX);

    return true;
}

enum Status moveSnake(struct Snake *snake) {
    switch (dir) {
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

void eatFruit(struct Snake *snake, int y, int x) {
    bool isToxic;

    deleteNode(&fruits, y, x, &isToxic);

    if (isToxic) {
        popBack(&snake->snakeQueue);
    } else {
        pushFront(&snake->snakeQueue, y + 1, x + 1);
    }

    insertNode(&fruits);
}

void display(struct Snake snake) {
    struct SnakeQueueNode *head = snake.snakeQueue.head;
    glColor3d(0.45, 0.60, 0.92);
    while (NULL != head) {
        glRectd(head->x, head->y, head->x + 1, head->y + 1);
        head = head->next;
    }
}

