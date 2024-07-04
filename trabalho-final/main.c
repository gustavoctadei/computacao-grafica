#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLint WIDTH = 1024;
GLint HEIGHT = 768;

GLfloat sem_cor[] = {0.0, 0.0, 0.0, 1.0};

// Cores do plano
GLfloat plano_difusa[] = {0.5, 0.5, 0.0, 1.0};

void reshape(int width, int height) {
    WIDTH = width;
    HEIGHT = height;
    glViewport(0, 0, (GLint) width, (GLint) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, width/(float)height, 0.1, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glPushMatrix();
        gluLookAt(0.0, 10.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        //Plano
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, plano_difusa);
        glNormal3f(0,1,0);
        glBegin(GL_QUADS);
            glVertex3f(-10,0,10);
            glVertex3f(10,0,10);
            glVertex3f(10,0,-10);
            glVertex3f(-10,0,-10);
        glEnd();

        //Esfera
        glMaterialfv(GL_FRONT, GL_EMISSION, sem_cor);
        glPushMatrix();
            glTranslatef(10.0, 1.0, 0.0);
            glutSolidSphere(1, 30, 30);
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
  }
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc,char **argv) {
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);

    glutCreateWindow("Trabalho Final- Lenda Amazonica - Mandioca");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return(0);
}
