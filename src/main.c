#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "../inc/Snake.h"
#include "../inc/Game.h"

int main()
{
    setup();
    struct Snake snake = createSnake();

    do {
        clear();
        display(snake);
        status = moveSnake(&snake, dir);
        if(status == FAILURE) break;
    } while (dir = getUserInput(dir));

    endwin();

    return 0;
}