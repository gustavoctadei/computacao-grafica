#include <stdlib.h>
#include <GL/freeglut.h>

int id;

void display(void) {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
        glColor3f(0, 1, 0);
        glVertex3f(0, 0.8, 0);
        glColor3f(1, 0, 0);
        glVertex3f(-0.2, 0, 0);
        glVertex3f(-0.5, -0.6, 0);
        glColor3f(0, 0, 1);
        glVertex3f(0, -0.4, 0);
        glVertex3f(0.5, -0.6, 0);
        glColor3f(0, 1, 0);
        glVertex3f(0.2, 0, 0);
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
