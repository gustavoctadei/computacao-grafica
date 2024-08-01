#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <Windows.h>
#include <MMSystem.h>

// Variáveis para controles de câmera
float camX = 0.0, camY = 5.0, camZ = 15.0;
float lookX = 0.0, lookY = -0.1, lookZ = -1.5;

// Variáveis de posição
GLfloat pos_mani_y = 0.0f;
GLfloat pos_lagrima_y = 3.25f;

//Variáveis de escala
GLfloat escala_mandioca_x = 0.0f, escala_mandioca_y = 0.0f, escala_mandioca_z = 0.0f;
GLfloat escala_folha_mandioca_x = 0.0f, escala_folha_mandioca_y = 0.0f, escala_folha_mandioca_z = 0.0f;
GLfloat raio_lagrima = 0.0f;

int contador_animacao = 0;

void drawMani() {
    //Cabeça
    glColor3f(0.9, 0.6, 0.4);
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glutSolidSphere(0.45, 20, 20);
    glPopMatrix();

    glColor3f(1.0, 0.8, 0.6);
    //Corpo
    glPushMatrix();
        glTranslatef(1.25, 0.0, 0.0);
        glScalef(1.5, 0.6, 0.4);
        glutSolidCube(1);
    glPopMatrix();

    glColor3f(0.9, 0.6, 0.4);
    //Braços
    glPushMatrix();
        glTranslatef(1.0, -0.25, 1.0);
        glRotatef(70.0, 0.0, 0.0, 1.0);
        glScalef(0.2, 0.8, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.0, 0.25, -0.5);
        glRotatef(-70.0, 0.0, 0.0, 1.0);
        glScalef(0.2, 0.8, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    //Pernas
    glPushMatrix();
        glTranslatef(2.5, 0.0, 0.5);
        glScalef(0.8, 0.2, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.5, 0.3, 0.5);
        glScalef(0.8, 0.2, 0.2);
        glutSolidCube(1);
    glPopMatrix();

}

void drawMae() {
    //Cabeça
    glColor3f(0.9, 0.6, 0.4);
    glPushMatrix();
        glTranslatef(1.5, 2.6, 0.0);
        glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    //Corpo
    glColor3f(1.0, 0.8, 0.6);
    glPushMatrix();
        glTranslatef(1.5, 1.35, 0.0);
        glScalef(0.6, 1.5, 0.4);
        glutSolidCube(1);
    glPopMatrix();

    glColor3f(0.9, 0.6, 0.4);
    //Braços
    //Braço Esquerdo
    glPushMatrix();
        glTranslatef(0.85, 1.75, 0.0);
        glRotatef(45, 0.0, 0.0, 1.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    //Braço Direito
    glPushMatrix();
        glTranslatef(2.15, 1.75, 0.0);
        glRotatef(-45, 0.0, 0.0, 1.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    //Pernas
    glPushMatrix();
        glTranslatef(1.3, 0.0, 0.0);

        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.75, 0.0, 0.0);
        glScalef(0.2, 1.0, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    //Lagrimas
    glColor3f(0.7, 0.9, 1.0);
    glPushMatrix();
        glTranslatef(1.2, pos_lagrima_y, 1.0);
        glutSolidSphere(raio_lagrima, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.0, pos_lagrima_y-0.15, 1.0);
        glutSolidSphere(raio_lagrima, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.4, pos_lagrima_y-0.15, 1.0);
        glutSolidSphere(raio_lagrima, 30, 30);
    glPopMatrix();
}

void drawOca() {
    glColor3f(0.8, 0.8, 0.3);
     glPushMatrix();
        glScalef(3.0, 0.5, 3.0);
        glutSolidCube(1);
    glPopMatrix();

    // Estrutura da Oca
    glColor3f(0.9, 0.9, 0.7);
    for (float i = -1.0; i <= 1.0; i += 0.5) {
        for (float j = -1.0; j <= 1.0; j += 0.5) {
            glPushMatrix();
                glTranslatef(i, 0.5, -5.0 + j);
                glScalef(0.1, 2.0, 0.1);
                glutSolidCube(1);
            glPopMatrix();
        }
    }

    // Teto da Oca
    glColor3f(0.8, 0.8, 0.3);
    glPushMatrix();
        glTranslatef(0.0, 1.8, -5.0);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glutSolidCone(3.0, 2.0, 30, 30);
    glPopMatrix();
}

void drawMandioca() {
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, cor_mandioca);
    glColor3f(0.0, 0.8, 0.0);
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

void desenhaCenario() {
    // Desenha o chão
    glColor3f(0.1, 0.6, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(-1000.0, -0.5, -1000.0);
    glVertex3f(-1000.0, -0.5, 1000.0);
    glVertex3f(1000.0, -0.5, 1000.0);
    glVertex3f(1000.0, -0.5, -1000.0);
    glEnd();

    // Desenha o céu
    glColor3f(0.7, 0.9, 1.0);
    GLUquadric* quad = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    gluSphere(quad, 1000.0, 50, 50);
    glPopMatrix();

    // Desenha a mãe
    glPushMatrix();
        glTranslatef(1.5, 0.0, 0.0);
        drawMae();
    glPopMatrix();

    //Desenha a Mani
    glPushMatrix();
        glTranslatef(-3.5, pos_mani_y, 0.0);
        drawMani();
    glPopMatrix();

    //Desenha a Oca
    glPushMatrix();
        glTranslatef(0.0, 0.0, -8.0);
        drawOca();
    glPopMatrix();

    //Desenha a mandioca
    glPushMatrix();
        glTranslatef(-2.0, 0.0, 0.0);
        drawMandioca();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, camX + lookX, camY + lookY, camZ + lookZ, 0.0, 1.0, 0.0);
    desenhaCenario(); // Desenha o cenário com árvores, cogumelos e redemoinhos
    glutSwapBuffers();
}

void animacao(int value) {
    //Mani sendo enterrada
    if (contador_animacao > 50) {
        if (pos_mani_y > -1.5f){
            pos_mani_y = pos_mani_y - 0.002;
        }
    }

    //Lágrimas da mãe da Mani caindo
    if (contador_animacao > 530) {
        raio_lagrima = 0.1;
        if (pos_lagrima_y > -0.8) {
            pos_lagrima_y -= 0.01;
        }
    }

    //Mandioca nascendo
    if (contador_animacao > 900) {

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
    glutTimerFunc(16, animacao, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lenda da Mandioca");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.8, 0.8, 0.1, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, animacao, 0);
    PlaySound("C:\\Users\\gusta\\Projects\\computacao-grafica\\trabalho-final\\flauta_indigena.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();

    return 0;
}
