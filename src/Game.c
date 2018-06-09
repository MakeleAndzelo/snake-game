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
    if (status == FAILURE || isEmpty(snake.snakeQueue)) {
        glClear(GL_COLOR_BUFFER_BIT);
        endGame();
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
        status = moveSnake(&snake);
        drawBoard(WIDTH, HEIGHT);
        printObstacleList(*obstacles);
        printList(*fruits);
        display(snake);
    }
    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer() {
    glutPostRedisplay();
    glutTimerFunc(1000 / 10, timer, 0);
}

void getUserInput(int key) {
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

bool areCollisions(struct Snake *snake, int x, int y) {
    if (points[x][y]) {
        if (searchList(*fruits, x, y)) {
            eatFruit(snake, x, y);
            return true;
        }

        if (searchQueue(snake->snakeQueue, x, y) || searchObstacleList(*obstacles, x, y)) {
            return false;
        }
    }

    return true;
}

void endGame() {
    char end[64] = "KONIEC GRY";
    char score[20];
    sprintf(score, "Dlugosc weza: %d", getSize(&snake.snakeQueue));
    glColor3f(.7, .7, .3);

    glPushMatrix();
    glTranslatef(0, 30, 0);
    glScalef(.05, .05, .05);
    for (int c = 0; end[c] != 0; ++c) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, end[c]);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9, 10, 0);
    glScalef(.02, .02, .02);
    for (int i = 0; score[i] != 0; ++i) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, score[i]);
    }
    glPopMatrix();
}