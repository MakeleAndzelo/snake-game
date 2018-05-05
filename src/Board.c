#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/Board.h"

void initBoard(int x, int y)
{
    boardX = x;
    boardY = y;
}

void drawBoard(int boardWidth, int boardHeight)
{
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            unit(i, j);
        }
    }
}

void unit(int x, int y)
{
    if (0 == x || 0 == y || x == 40 - 1 || y == 40 - 1 ) {
        glLineWidth(3.0);
        glColor3f(1.0, 0.0, 0.0);
    } else {
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }

    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);
    glVertex2f(x+1, y);
    glVertex2f(x+1, y+1);
    glVertex2f(x, y+1);

    glEnd();
}