#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float x, y, u;
int d;

void keyboardHandler(unsigned char k, int x, int y) {
    exit(0);
}

void l(float dx, float dy) {
    glBegin(GL_LINES);
    glVertex2f(x,y);
    x = x + dx;
    y = y + dy;
    glVertex2f(x,y);
    glEnd();
    glutSwapBuffers();
}

void A(int i) {
    if (i > 0) {
        D(i - 1); l(-u, 0);
        A(i - 1); l(0, -u);
        A(i - 1); l(u, 0);
        B(i - 1);
    }
}

void B(int i) { 
    if (i > 0) {
        C(i - 1); l(0, u);
        B(i - 1); l(u, 0);
        B(i - 1); l(0, -u);
        A(i - 1);
    }
}

void C(int i) {
    if (i > 0) {
        B(i - 1); l(u, 0);
        C(i - 1); l(0, u);
        C(i - 1); l(-u, 0);
        D(i - 1);
    }
}

void D(int i) {
    if (i > 0) {
        A(i - 1); l(0, -u);
        D(i - 1); l(-u, -0);
        D(i - 1); l(0, u);
        C(i - 1);
    }
}

void displayHandler() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    x = 0.8;
    y = 0.8;
    u = 1.6 / (pow(2, d) - 1);
    A(d);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutCreateWindow("glut");
    // glutFullScreen();

    sscanf(argv[1], "%d", &d);

    // Make the window full screen
    // usleep(100);

    glutDisplayFunc(displayHandler);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop();
}
