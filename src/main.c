#include "../inc/Snake.h"
#include "../inc/Game.h"
#include "../inc/FruitsList.h"

int main()
{
    setup();
    struct Snake snake = createSnake();


    do {
        clear();
        status = moveSnake(&snake, dir);
        display(snake);
        printList(*fruits);
        if(status == FAILURE) break;
    } while (dir = getUserInput(dir));

    removeList(&fruits);

    getch();
    endwin();

    return 0;
}