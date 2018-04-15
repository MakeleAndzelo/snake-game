#include "../inc/Game.h"

void setup()
{
    srand(time(0));
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, yMax, xMax);
    keypad(stdscr, true);
    timeout(100);

    fruits = createList();
    dir = RIGHT;
    status = SUCCESS;
}

enum Direction getUserInput(enum Direction previousDirection)
{
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            if (previousDirection != RIGHT) return LEFT;
        case KEY_RIGHT:
            if (previousDirection != LEFT) return RIGHT;
        case KEY_DOWN:
            if (previousDirection != UP) return DOWN;
        case KEY_UP:
            if (previousDirection != DOWN) return UP;
        default:
            return previousDirection;
    }
}

bool areCollisions(struct Snake *snake, int y, int x)
{
    if (searchList(*fruits, y, x)) {
        eatFruit(snake, y, x);
    }

    if (searchQueue(snake->snakeQueue, y, x)) {
        return false;
    }

    return true;
}