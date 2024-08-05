
#include <GL/glut.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //Desenhando a estrutura da casa
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.17, 0.07);
        glVertex2f(0.17, 0.57);
        glVertex2f(0.47, 0.87);
        glVertex2f(0.77, 0.57);
        glVertex2f(0.77, 0.07);
    glEnd();

    //Desenhando a chaminé da casa
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.2, 0.6);
        glVertex2f(0.2, 0.90);
        glVertex2f(0.35, 0.90);
        glVertex2f(0.35, 0.75);
    glEnd();

    //Desenhando a porta da casa
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.23, 0.07);
        glVertex2f(0.23, 0.3);
        glVertex2f(0.35, 0.3);
        glVertex2f(0.35, 0.07);
    glEnd();

    //Desenhando a porta da janela
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.5, 0.4);
        glVertex2f(0.5, 0.55);
        glVertex2f(0.65, 0.55);
        glVertex2f(0.65, 0.4);
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
