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

//Variáveis de escala
GLfloat escala_mandioca_x = 0.0f, escala_mandioca_y = 0.0f, escala_mandioca_z = 0.0f;
GLfloat escala_folha_mandioca_x = 0.0f, escala_folha_mandioca_y = 0.0f, escala_folha_mandioca_z = 0.0f;

int contador_animacao = 0;

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
        glRotatef(70.0, 0.0, 0.0, 1.0);
        glScalef(0.2, 0.8, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0, 0.25, -0.5);
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

void drawOca() {
    // Base da Oca
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_DIFFUSE, plano_difusa);
        glTranslatef(0.0, 0.0, -5.0); // Posição da oca atrás de Mani
        glScalef(3.0, 0.5, 3.0);
        glutSolidCube(1);
    glPopMatrix();

    // Estrutura da Oca
    for (float i = -1.0; i <= 1.0; i += 0.5) {
        for (float j = -1.0; j <= 1.0; j += 0.5) {
            glPushMatrix();
                glMaterialfv(GL_FRONT, GL_DIFFUSE, cor_mae);
                glTranslatef(i, 0.5, -5.0 + j);
                glScalef(0.1, 2.0, 0.1);
                glutSolidCube(1);
            glPopMatrix();
        }
    }

    // Teto da Oca
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_DIFFUSE, cor_mani);
        glTranslatef(0.0, 2.5, -5.0);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glutSolidCone(3.0, 2.0, 30, 30);
    glPopMatrix();
}

void drawMandioca() {
    //Mandioca
    glPushMatrix();
        glScalef(escala_mandioca_x, escala_mandioca_y, escala_mandioca_z);
        glutSolidCube(1);

        //Folhas da direita
        glPushMatrix();
            glTranslatef(1, 0.7, 4);
            glRotatef(15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1, 0.4, 4);
            glRotatef(15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1, 0.1, 4);
            glRotatef(15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();

        //Folhas da esquerda
        glPushMatrix();
            glTranslatef(-1, 0.1, 4);
            glRotatef(-15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-1, 0.4, 4);
            glRotatef(-15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-1, 0.7, 4);
            glRotatef(-15, 0.0, 0.0, 1.0);
            glScalef(escala_folha_mandioca_x, escala_folha_mandioca_y, escala_folha_mandioca_z);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}


void display(void) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glPushMatrix();
        //Visão padrão
        gluLookAt(0.0, 10.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        //Visão mais alta
        //gluLookAt(0.0, 20.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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

        // Mandioca
        glPushMatrix();
            glTranslatef(pos_mani_x, 1.0, 2.0);
            drawMandioca();
        glPopMatrix();

        // Oca ao fundo de Mani
        drawOca();

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

void animacao(int value) {

    //Mani sendo enterrada
    if (contador_animacao > 50) {
        if (pos_mani_y > -0.6f){
            pos_mani_y = pos_mani_y - 0.005;
        }
    }

    //Lágrimas da mãe da Mani caindo
    //ToDo

    //Mandioca nascendo
    if (contador_animacao > 280) {

        if (escala_mandioca_x <= 0.3) {
            escala_mandioca_x = escala_mandioca_x + 0.005;
        }

        if (escala_mandioca_y <= 2.0) {
            escala_mandioca_y = escala_mandioca_y + 0.005;
        }

        if (escala_mandioca_z <= 0.2) {
            escala_mandioca_z = escala_mandioca_z + 0.005;
        }

        if (escala_folha_mandioca_x <= 1.5) {
            escala_folha_mandioca_x += 0.005;
        }

        if (escala_folha_mandioca_y <= 0.1) {
            escala_folha_mandioca_y += 0.005;
        }

        if (escala_folha_mandioca_z <= 0.1) {
            escala_folha_mandioca_z + 0.005;
        }

    }

    contador_animacao += 1;
    glutPostRedisplay();
    glutTimerFunc(30, animacao, 0);
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
    //glutSpecialFunc(specialKeys);  // Adiciona a função para teclas especiais
    glutTimerFunc(30, animacao, 0);

    glutMainLoop();
    return 0;
}
