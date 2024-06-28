#include <stdlib.h>
#include <GL/glut.h>

int id;

void display(void) {
	glClearColor(1,1,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(10);

    glBegin(GL_LINES);
        glVertex3f(0.0, 1, 0.0);
        glVertex3f(0.0, 0.04, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(0.0, -1, 0.0);
        glVertex3f(0.0, -0.04, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(0.04, 0, 0);
        glVertex3f(1, 0, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-0.04, 0, 0);
        glVertex3f(-1, 0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
         glVertex3f(-0.5, -0.5, 0);
    glEnd();

	//Executa os comandos OpenGL
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
