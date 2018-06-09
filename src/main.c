#include "../inc/Game.h"

int main(int argc, char **argv) {
    srand(time(0));
    snake = createSnake();
    fruits = createList();
    obstacles = createObstacleList();
    setup(&argc, argv);
    return 0;
}