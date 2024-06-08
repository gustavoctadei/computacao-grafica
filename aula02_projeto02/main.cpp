#include<GL/glut.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);

    //Desenhando as retas dos eixos X e Y
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0.1, 0.1, 0.0);
        glVertex3f(0.1, 0.9, 0.0);

        glVertex3f(0.1, 0.1, 0.0);
        glVertex3f(0.9, 0.1, 0.0);
    glEnd();

    //Desenhando os triângulos nas pontas das retas do eixo X e Y
    glBegin(GL_TRIANGLES);
        glVertex3f(0.08, 0.90, 0.0);
        glVertex3f(0.12, 0.90, 0.0);
        glVertex3f(0.1, 0.92, 0.0);

        glVertex3f(0.90, 0.08, 0.0);
        glVertex3f(0.90, 0.12, 0.0);
        glVertex3f(0.92, 0.10, 0.0);
    glEnd();

    //Desenhando os pontos na cor vermelha
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.25, 0.3, 0.0);
        glVertex3f(0.5, 0.15, 0.0);
        glVertex3f(0.6, 0.4, 0.0);
        glVertex3f(0.22, 0.25, 0.0);
        glVertex3f(0.7, 0.7, 0.0);
        glVertex3f(0.8, 0.56, 0.0);
        glVertex3f(0.3, 0.4, 0.0);
        glVertex3f(0.5, 0.68, 0.0);
        glVertex3f(0.64, 0.3, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Grafico_de_Dispersao");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
