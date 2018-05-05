#include "../inc/Game.h"
#include <GL/gl.h>
#include <GL/glut.h>

void setup(int *argc, char **argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SNAKE");
    glutDisplayFunc(displayWindow);
    glutReshapeFunc(reshapeWindow);
    glutMainLoop();

    srand(time(0));

    fruits = createList();
    dir = RIGHT;
    status = SUCCESS;
}

void displayWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void reshapeWindow(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
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