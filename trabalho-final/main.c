#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLint WIDTH = 1024;
GLint HEIGHT = 768;

GLfloat sem_cor[] = {0.0, 0.0, 0.0, 1.0};

// Cores do plano
GLfloat plano_difusa[] = {0.5, 0.5, 0.0, 1.0};

// Cores das figuras
GLfloat cor_mani[] = {1.0, 0.8, 0.6, 1.0};
GLfloat cor_mae[] = {0.8, 0.5, 0.3, 1.0};

// Variáveis de posição
GLfloat pos_mani_x = 0.0f, pos_mani_y = 0.5f;
GLfloat pos_mae_x = 2.0f, pos_mae_y = 0.5f;

void reshape(int width, int height) {
    WIDTH = width;
    HEIGHT = height;
    glViewport(0, 0, (GLint) width, (GLint) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, width/(float)height, 0.1, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawMani() {
    // Cabeça da Mani
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cor_mani);
    glPushMatrix();
        glTranslatef(-2.5, 0.0, 0.0);
        glutSolidSphere(0.5, 30, 30);
    glPopMatrix();

    // Corpo da Mani
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        glScalef(1.5, 0.6, 0.4);
        glutSolidCube(1);
    glPopMatrix();

    // Braços da Mani
    glPushMatrix();
        glTranslatef(-1.0, 0.25, 1.0);
        //glRotatef(-30, 0.0, 0.0, 1.0);
        glRotatef(70.0, 0.0, 0.0, 1.0);
        glScalef(0.2, 0.8, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0, 0.25, -0.5);
        //glRotatef(-30, 0.0, 0.0, 1.0);
        glRotatef(-70.0, 0.0, 0.0, 1.0);
        glScalef(0.2, 0.8, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    // Pernas da Mani
    glPushMatrix();
        glTranslatef(0.2, 0.5, -0.0005);
        glScalef(0.8, 0.2, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    //glPushMatrix();
    glPushMatrix();
        glTranslatef(0.2, 0.5, 0.5);
        glScalef(0.8, 0.2, 0.2);
        glutSolidCube(1);
    glPopMatrix();
}

void drawMae() {
    // Cabeça da mãe
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cor_mae);
    glPushMatrix();
        glTranslatef(0.0, 3.5, 0.0);
        glutSolidSphere(0.5, 30, 30);
    glPopMatrix();

    // Corpo da mãe
    glPushMatrix();
        glTranslatef(0.0, 2.25, 0.0);
        glScalef(0.6, 2.0, 0.4);
        glutSolidCube(1);
    glPopMatrix();

    // Braços da mãe
    glPushMatrix();
        glTranslatef(0.5, 2.25, 0.0);
        glRotatef(-45, 0.0, 0.0, 1.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5, 2.25, 0.0);
        glRotatef(45, 0.0, 0.0, 1.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    // Pernas da mãe
    glPushMatrix();
        glTranslatef(0.2, 0.25, 0.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0.25, 0.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();
}

void display(void) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glPushMatrix();
        //Visão padrão
        //gluLookAt(0.0, 10.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        //Visão mais alta
        gluLookAt(0.0, 20.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        // Plano
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, plano_difusa);
        glNormal3f(0, 1, 0);
        glBegin(GL_QUADS);
            glVertex3f(-10, 0, 10);
            glVertex3f(10, 0, 10);
            glVertex3f(10, 0, -10);
            glVertex3f(-10, 0, -10);
        glEnd();

        // Mani deitada
        glPushMatrix();
            glTranslatef(pos_mani_x, pos_mani_y, 0.0);
            drawMani();
        glPopMatrix();

        // Mãe chorando
        glPushMatrix();
            glTranslatef(pos_mae_x, pos_mae_y, 0.0);
            drawMae();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        // Movimentação de Mani
        case GLUT_KEY_UP:
            pos_mani_y += 0.1f;
            break;
        case GLUT_KEY_DOWN:
            pos_mani_y -= 0.1f;
            break;
        case GLUT_KEY_LEFT:
            pos_mani_x -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            pos_mani_x += 0.1f;
            break;
    }
    glutPostRedisplay();
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

int main(int argc, char **argv) {
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutCreateWindow("Trabalho Final- Lenda Amazonica - Mandioca");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);  // Adiciona a função para teclas especiais

    glutMainLoop();
    return 0;
}
