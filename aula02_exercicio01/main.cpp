#include <stdlib.h>
#include <GL/freeglut.h>

int id;

void display(void) {
    // Limpa a janela de visualização com a cor branca
    glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Desenhando o Losango Azul
    glColor3f(0, 0, 1);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex3f(0, 0.75, 0); //Cima
        glVertex3f(-0.25, 0.5, 0); //Esquerdo
        glVertex3f(0, 0.25, 0); //Baixo
        glVertex3f(0.25, 0.5, 0); //Direito
    glEnd();

    //Desenhando o Losango Preto
    glColor3f(0, 0, 0);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex3f(0, -0.25, 0); //Cima
        glVertex3f(-0.25, -0.5, 0); //Esquerdo
        glVertex3f(0, -0.75, 0); //Baixo
        glVertex3f(0.25, -0.5, 0); //Direito
    glEnd();

    //Desenhando o Losango Vermeho
    glColor3f(1, 0, 0);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex3f(0.5, 0.4, 0);
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
