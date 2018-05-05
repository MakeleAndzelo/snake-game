#include "../inc/Snake.h"
#include "../inc/Game.h"
#include "../inc/FruitsList.h"

int main(int argc, char **argv)
{
    setup(&argc, argv);
    struct Snake snake = createSnake();

    removeList(&fruits);
    return 0;
}