#include <GL/gl.h>
#include <GL/glut.h>
#include "../inc/Board.h"


void drawBoard(int boardWidth, int boardHeight) {
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            unit(i, j, 0.5, 0.5, 0.5);
        }
    }
}


void unit(int x, int y, float red, float green, float blue) {
    if (0 == x || 0 == y || x == 40 - 1 || y == 40 - 1) {
        glColor3f(red, green, blue);
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x, y + 1);
        glRectd(x, y, x + 1, y + 1);
    }
}