#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/Snake.h"
#include "../inc/Point.h"

struct Snake createSnake() {
    struct SnakeQueue *snakeQueue = (struct SnakeQueue *) malloc(sizeof(struct SnakeQueue));

    pushFront(snakeQueue, 20, 20);
    pushFront(snakeQueue, 20, 21);
    pushFront(snakeQueue, 20, 22);

    changePointStatus(20, 20);
    changePointStatus(20, 21);
    changePointStatus(20, 22);
    struct Snake snake = {*snakeQueue};

    return snake;
}

bool moveUp(struct Snake *snake) {
    int newX = snake->snakeQueue.head->x, newY = snake->snakeQueue.head->y + 1;

    if (!areCollisions(snake, newX, newY) || newY >= 39) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newX, newY);

    return true;
}

bool moveDown(struct Snake *snake) {
    int newX = snake->snakeQueue.head->x, newY = snake->snakeQueue.head->y - 1;

    if (!areCollisions(snake, newX, newY) || newY < 1) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newX, newY);

    return true;
}

bool moveLeft(struct Snake *snake) {
    int newX = snake->snakeQueue.head->x - 1, newY = snake->snakeQueue.head->y;

    if (!areCollisions(snake, newX, newY) || newX <= 0) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newX, newY);

    return true;
}

bool moveRight(struct Snake *snake) {
    int newX = snake->snakeQueue.head->x + 1, newY = snake->snakeQueue.head->y;

    if (!areCollisions(snake, newX, newY) || newX >= 39) {
        return false;
    }

    popBack(&snake->snakeQueue);
    pushBack(&snake->snakeQueue, newX, newY);

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

void eatFruit(struct Snake *snake, int x, int y) {
    bool isToxic;
    deleteNode(&fruits, x, y, &isToxic);

    if (isToxic) {
        popBack(&snake->snakeQueue);
    } else {
        pushFront(&snake->snakeQueue, x + 1, y + 1);
    }

    insertNode(&fruits);
}

void display(struct Snake snake) {
    struct SnakeQueueNode *head = snake.snakeQueue.head;
    glColor3d(0, 0, 1);
    glRectd(head->x, head->y, head->x + 1, head->y + 1);
    head = head->next;

    glColor3d(0.45, 0.60, 0.92);
    while (NULL != head) {
        glRectd(head->x, head->y, head->x + 1, head->y + 1);
        head = head->next;
    }
}

