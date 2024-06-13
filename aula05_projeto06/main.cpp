#include <iostream>
#include <GL/freeglut.h>

// Fun��o para desenhar o torso
void desenhaTorso() {
  // Define a cor do torso como vermelho
  glColor3f(1.0, 0.0, 0.0);

  // Desenha um quadrado para representar o torso
  glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.5);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, -0.2);
    glVertex2f(-0.2, -0.2);
  glEnd();
}

// Fun��o para desenhar o bra�o
void desenhaBraco(float angulo) {
  // Define a cor do bra�o como azul
  glColor3f(0.0, 0.0, 1.0);

  // Desenha um tri�ngulo para representar o bra�o
  glPushMatrix();
    glTranslatef(0.0, -0.3, 0.0);
    glRotatef(angulo, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
      glVertex2f(0.0, 0.0);
      glVertex2f(0.2, 0.0);
      glVertex2f(0.1, 0.2);
    glEnd();
  glPopMatrix();
}

// Fun��o de exibi��o principal
void display() {
  // Limpa a tela com preto
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Desenha o torso
  desenhaTorso();

  // Desenha o bra�o com diferentes �ngulos para simular o aceno
  for (float angulo = 0; angulo <= 60; angulo += 5) {
    desenhaBraco(angulo);
  }

  // Troca os buffers e exibe a imagem
  glutSwapBuffers();
}

// Fun��o para lidar com a redefini��o da janela
void reshape(int w, int h) {
  // Define a �rea de visualiza��o
  glViewport(0, 0, w, h);

  // Define a matriz de proje��o como ortogonal
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

  // Volta para a matriz de modelo
  glMatrixMode(GL_MODELVIEW);
}

// Fun��o principal
int main(int argc, char** argv) {
  // Inicializa a biblioteca FreeGLUT
  glutInit(&argc, argv);

  // Define o modo de exibi��o
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // Define o tamanho da janela
  glutInitWindowSize(400, 300);

  // Define a posi��o da janela
  glutInitWindowPosition(100, 100);

  // Cria a janela
  glutCreateWindow("Pessoa Acenando com o Bra�o");

  // Define as fun��es de callback para exibi��o e redefini��o da janela
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  // Entra no loop principal da GLUT
  glutMainLoop();

  return 0;
}
