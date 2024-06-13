#include <iostream>
#include <GL/freeglut.h>

// Função para desenhar o torso
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

// Função para desenhar o braço
void desenhaBraco(float angulo) {
  // Define a cor do braço como azul
  glColor3f(0.0, 0.0, 1.0);

  // Desenha um triângulo para representar o braço
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

// Função de exibição principal
void display() {
  // Limpa a tela com preto
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Desenha o torso
  desenhaTorso();

  // Desenha o braço com diferentes ângulos para simular o aceno
  for (float angulo = 0; angulo <= 60; angulo += 5) {
    desenhaBraco(angulo);
  }

  // Troca os buffers e exibe a imagem
  glutSwapBuffers();
}

// Função para lidar com a redefinição da janela
void reshape(int w, int h) {
  // Define a área de visualização
  glViewport(0, 0, w, h);

  // Define a matriz de projeção como ortogonal
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

  // Volta para a matriz de modelo
  glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char** argv) {
  // Inicializa a biblioteca FreeGLUT
  glutInit(&argc, argv);

  // Define o modo de exibição
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // Define o tamanho da janela
  glutInitWindowSize(400, 300);

  // Define a posição da janela
  glutInitWindowPosition(100, 100);

  // Cria a janela
  glutCreateWindow("Pessoa Acenando com o Braço");

  // Define as funções de callback para exibição e redefinição da janela
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  // Entra no loop principal da GLUT
  glutMainLoop();

  return 0;
}
