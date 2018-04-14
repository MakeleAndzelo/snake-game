#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "../inc/Snake.h"
#include "../inc/Game.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    keypad(stdscr, true);
    refresh();

    struct Snake snake = createSnake();

    do {
        clear();
        display(snake);
        refresh();
    } while(getMove(&snake) != 'x');

    getch();
    endwin();

    return 0;
}