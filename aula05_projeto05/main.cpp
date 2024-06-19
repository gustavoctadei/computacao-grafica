#include <GL/freeglut.h>
#include <stdlib.h>

//Variáveis Globais
float eyex = 0;
float eyey = 80;
float eyez = 150;

//Angulos de rotação
float angulo_mercurio = 0;
float angulo_venus = 0;
float angulo_terra = 0;
float angulo_marte = 0;
float angulo_jupiter = 0;
float angulo_saturno = 0;
float angulo_urano = 0;
float angulo_netuno = 0;
float angulo_lua = 0;

void sol() {
    glColor3f(1, 1, 0);
    glutSolidSphere(12, 16, 16);
}

void mercurio() {
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(2, 16, 16);
}

void venus() {
    glColor3f(0.8, 0.5, 0.2);
    glutSolidSphere(4, 16, 16);
}

void terra() {
    glColor3f(0, 0, 1);
    glutSolidSphere(5, 16, 16);
}

void marte() {
    glColor3f(1, 0.2, 0);
    glutSolidSphere(4, 16, 16);
}

void jupiter() {
    glColor3f(0.9, 0.6, 0.3);
    glutSolidSphere(11, 16, 16);
}

void saturno() {
    glColor3f(0.9, 0.7, 0.4);
    glutSolidSphere(9, 16, 16);

    //Aneis de Saturno
    glPushMatrix();
        glColor3f(0.7, 0.5, 0.3);
        glRotatef(90, 1, 0, 0);
        glutSolidTorus(1.5, 13, 30, 30);
    glPopMatrix();
}

void urano() {
    glColor3f(0.4, 0.7, 0.9);
    glutSolidSphere(7, 16, 16);
}

void netuno() {
    glColor3f(0.3, 0.3, 1);
    glutSolidSphere(7, 16, 16);
}

void lua() {
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(1, 16, 16);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

    //Desenhar o Sistema Solar
    glPushMatrix();
        sol();

        //mercurio
        glPushMatrix();
            glRotatef(angulo_mercurio, 0, 1, 0);
            glTranslatef(15, 0, 0);
            mercurio();
        glPopMatrix();//mercurio

        //venus
        glPushMatrix();
            glRotatef(angulo_venus, 0, 1, 0);
            glTranslatef(25, 0, 0);
            venus();
        glPopMatrix();//venus

        //terra
        glPushMatrix();
            glRotatef(angulo_terra, 0, 1, 0);
            glTranslatef(35, 0, 0);
            terra();

            //lua
            glPushMatrix();
                glRotatef(angulo_lua, 0, 1, 0);
                glTranslatef(7, 0, 0);
                lua();
            glPopMatrix();
        glPopMatrix();//terra

        //marte
        glPushMatrix();
            glRotatef(angulo_marte, 0, 1, 0);
            glTranslatef(45, 0, 0);
            marte();
        glPopMatrix(); //marte

        //jupiter
        glPushMatrix();
            glRotatef(angulo_jupiter, 0, 1, 0);
            glTranslatef(60, 0, 0);
            jupiter();
        glPopMatrix();//jupiter

        //saturno
        glPushMatrix();
            glRotatef(angulo_saturno, 0, 1, 0);
            glTranslatef(75, 0, 0);
            saturno();
        glPopMatrix();//saturno

        //urano
        glPushMatrix();
            glRotatef(angulo_urano, 0, 1, 0);
            glTranslatef(90, 0, 0);
            urano();
        glPopMatrix();//urano

        //netuno
        glPushMatrix();
            glRotatef(angulo_netuno, 0, 1, 0);
            glTranslatef(105, 0, 0);
            netuno();
        glPopMatrix();//netuno

    glPopMatrix(); //sistema solar

    glutSwapBuffers();
}

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    angulo_mercurio += 4.7;
    if (angulo_mercurio >= 360)
        angulo_mercurio = 0;

    angulo_venus += 3.5;
    if (angulo_venus >= 360)
        angulo_venus = 0;

    angulo_terra += 3;
    if (angulo_terra >= 360)
        angulo_terra = 0;

    angulo_marte += 2.4;
    if (angulo_marte >= 360)
        angulo_marte = 0;

    angulo_jupiter += 1.3;
    if (angulo_jupiter >= 360)
        angulo_jupiter = 0;

    angulo_saturno += 0.97;
    if (angulo_saturno >= 360)
        angulo_saturno = 0;

    angulo_urano += 0.68;
    if (angulo_urano >= 360)
        angulo_urano = 0;

    angulo_netuno += 0.54;
    if (angulo_netuno >= 360)
        angulo_urano = 0;

    angulo_lua = angulo_terra * 4;

    glutPostRedisplay();
    glutTimerFunc(40, timer, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 3 - Sistema Solar");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(40, timer, 1);

    glutMainLoop();
    return 0;
}
