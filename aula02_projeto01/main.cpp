#include <GL/glut.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.3, 0.3, 0.0);
        glVertex3f(0.7, 0.3, 0.0);
        glVertex3f(0.7, 0.7, 0.0);
        glVertex3f(0.3, 0.7, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Primeiro_Programa");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
