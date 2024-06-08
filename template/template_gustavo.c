#include <stdlib.h>
#include <GL/freeglut.h>

int id;

void display(void) {
    // Limpa a janela de visualização com a cor branca
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a cor de desenho
    glColor3f(1,0,0);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.0, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
    glEnd();

    glFlush();
}

void teclado (unsigned char key, int x, int y) {
    if (key == 27){
        glutDestroyWindow(id);
        exit(0);
    }
}

int main(int argc,char ** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    id = glutCreateWindow("...");
    glutDisplayFunc(display);
    glutKeyboardFunc (teclado);
    glutMainLoop();

    return 0;
}
