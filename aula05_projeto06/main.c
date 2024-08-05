#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/freeglut.h>

#define _USE_MATH_DEFINES

//Variáveis Globais
float angulo = 0;
float angulo_braco = 0;
float angulo_mao = 0;
float angulo_dedo = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 10, 30, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
        //Braço
        glPushMatrix();
            glColor3f(0.1, 1, 0.1);
            glTranslatef(0, -4, 0);
            glScalef(1, 8, 1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.1, 0.1, 1);
            glRotatef(angulo_braco, 0, 0, 1);
            glTranslatef(0, 4, 0);
            glScalef(0.8, 7, 0.8);
            glutSolidCube(1);
        glPopMatrix();

        //Mão
        glPushMatrix();
            glColor3f(1, 0.1, 0.1);
            glRotatef(angulo_mao, 0, 0, 1);
            glTranslatef(0, 8.5, 0);
            glScalef(2, 1.5, 0.6);
            glutSolidCube(1);
        glPopMatrix();

        //Dedos
        glPushMatrix();
            glColor3f(1, 1, 0.1);
            glRotatef(angulo_dedo, 0, 0, 1);
            glTranslatef(-1, 10.25, 0);
            glScalef(0.2, 1.5, 0.2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1, 1, 0.1);
            glRotatef(angulo_dedo, 0, 0, 1);
            glTranslatef(-0.5, 10.25, 0);
            glScalef(0.2, 1.5, 0.2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1, 1, 0.1);
            glRotatef(angulo_dedo, 0, 0, 1);
            glTranslatef(0, 10.25, 0);
            glScalef(0.2, 1.5, 0.2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1, 1, 0.1);
            glRotatef(angulo_dedo, 0, 0, 1);
            glTranslatef(0.5, 10.25, 0);
            glScalef(0.2, 1.5, 0.2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1, 1, 0.1);
            glRotatef(angulo_dedo, 0, 0, 1);
            glTranslatef(1, 10.25, 0);
            glScalef(0.2, 1.5, 0.2);
            glutSolidCube(1);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void movimento_tchau(int value) {
    angulo_braco = -15 * sin(angulo * M_PI / 180.0);
    angulo_mao = -20 * sin(angulo * M_PI / 180.0);
    angulo_dedo = -20 * sin(angulo * M_PI / 180.0);

    angulo += 2.5;

    glutPostRedisplay();
    glutTimerFunc(20, movimento_tchau, 0);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.33, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tchau");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(45, movimento_tchau, 0);

    glutMainLoop();
    return 0;
}

