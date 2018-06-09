#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/Game.h"
#include "../inc/Board.h"
#include "../inc/Snake.h"
#include "../inc/Point.h"
#include "../inc/ObstacleList.h"


const int WIDTH = 40;
const int HEIGHT = 40;

void setup(int *argc, char **argv) {
    dir = RIGHT;
    status = SUCCESS;

    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SNAKE");
    glutDisplayFunc(displayWindow);
    glutReshapeFunc(reshapeWindow);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(getUserInput);
    glutMainLoop();
}

void displayWindow() {
    glClear(GL_COLOR_BUFFER_BIT);
    status = moveSnake(&snake);
    drawBoard(WIDTH, HEIGHT);
    if (status == FAILURE || getSize(&snake.snakeQueue) == 1) {
        exit(0);
    }
    printObstacleList(*obstacles);
    printList(*fruits);
    display(snake);
    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int _) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 10, timer, 0);
}

void getUserInput(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            if (dir != RIGHT) dir = LEFT;
            break;
        case GLUT_KEY_RIGHT:
            if (dir != LEFT) dir = RIGHT;
            break;
        case GLUT_KEY_DOWN:
            if (dir != UP) dir = DOWN;
            break;
        case GLUT_KEY_UP:
            if (dir != DOWN) dir = UP;
            break;
        default:
            break;
    }
}

bool areCollisions(struct Snake *snake, int y, int x) {
    if (points[x][y]) {
        if (searchList(*fruits, y, x)) {
            eatFruit(snake, y, x);
            return true;
        }

        if (searchQueue(snake->snakeQueue, y, x) || searchObstacleList(*obstacles, y, x)) {
            return false;
        }
    }

    return true;
}