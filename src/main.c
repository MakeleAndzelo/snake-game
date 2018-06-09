#include "../inc/Snake.h"
#include "../inc/Game.h"
#include "../inc/FruitsList.h"

int main(int argc, char **argv) {
    srand(time(0));
    fruits = createList();
    snake = createSnake();
    setup(&argc, argv);

    removeList(&fruits);

    return 0;
}