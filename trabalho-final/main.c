
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.1415

GLint WIDTH = 800;
GLint HEIGHT = 600;

// Define o n�mero de fatias (longitude), o n�mero de pilhas (latitude) e o raio das esferas da cena.
GLint fatias=30;
GLint pilhas=30;
GLint raioEsfera=1.5;

GLfloat obs[3]={0.0,7.0,0.0};
GLfloat olho[3]={0.0,3.0,0.0};

//Define os coeficientes de reflex�o difusa (*_difusa) e especular (*_especular) para os tr�s objetos da cena.
/*Obs: O brilho do material, que pode assumir valores entre 1 e 128, � um expoente
que modela a fun��o de distribui��o espacial da componente de luz refletida
especularmente. � medida em que o valor do brilho aumenta, diminui o espalhamento
da luz refletida.*/
// Cores do plano
GLfloat plano_difusa[]    = { 0.5, 0.5, 0.0, 1.0 };
GLfloat plano_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat plano_brilho[]    = { 50.0 };

//Cores da esfera A
GLfloat mat_a_difusa[]    = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_a_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_a_brilho[]    = { 50.0 };

//Cores da esfera B
GLfloat transparencia_esfera_b = 0.5;
//GLfloat mat_b_difusa[]    = { 0.7, 0.7, 0.7, transparencia_esfera_b };   // o valor de alfa=0.5 d� a apar�ncia transl�cida
//GLfloat mat_b_especular[] = { 1.0, 1.0, 1.0, transparencia_esfera_b };
GLfloat mat_b_brilho[]    = { 50.0 };


GLfloat posicao_luz0[]    = { 0.0, 10.0, 0.0, 1.0};  // posi��o luz
GLfloat cor_luz0[]        = { 1.0, 1.0, 1.0, 1.0};  // componentes de luz para reflex�o difusa e especular
GLfloat cor_luz0_amb[]    = { 0.3, 0.3, 0.3, 1.0};  // componente de luz para reflex�o ambiente

GLfloat posicao_luz1[]    = { 0.0, 10.0, 5.0, 1.0};
GLfloat cor_luz1[]        = { 0.0, 0.0, 1.0, 1.0};
GLfloat direcao_luz1[]    = { 0.0, -10.0, -5.0, 1.0};
GLint   spot_luz1         = 30;

GLfloat sem_cor[]         = { 0.0, 0.0, 0.0, 1.0};

GLint gouraud=1;

GLfloat tetaxz=0;
GLfloat raioxz=6;

void display(void){
/*o depth-buffer (tamb�m conhecido por z-buffer) serve para guardar o valor de
profundidade de cada pixel desenhado. Assim, � f�cil imp�r a condi��o de que cada
novo pixel s� ser� desenhado se tiver um valor de profundidade superior (valores
negativos) ao que j� l� estava, evitando sobrep�r pixels mais pr�ximos.
*/
  glEnable(GL_DEPTH_TEST);   // teste de profundidade - habilita z-buffer
  glEnable(GL_LIGHTING);

  glDepthMask(GL_TRUE);
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  if(gouraud){
    glShadeModel(GL_SMOOTH);
  }
  else{
    glShadeModel(GL_FLAT);
  }

  glPushMatrix();

  /* calcula a posicao do observador */
  obs[0]=raioxz*cos(2*PI*tetaxz/360);
  obs[2]=raioxz*sin(2*PI*tetaxz/360);
  gluLookAt(obs[0],obs[1],obs[2],olho[0],olho[1],olho[2],0.0,1.0,0.0);


/*A fun��o glMaterialfv() define as propriedades de reflex�o difusa e especular,
e brilho do material que ser� utilizado para compor o objeto imediatamente desenhado,
neste caso um plano, via GL_QUADS.

Observe a chamada � fun��o glNormal3f() antes
do plano ser desenhado. Isto � necess�rio porque, por default, o vetor normal
encontra-se na dire��o (x,y,z)=(0,0,1) e para que a normal � superf�cie encontra-se
orientada com eixo y, ou seja, na dire��o (x,y,z)=(0,1,0).
*/
  /* propriedades do material do plano */
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, plano_difusa);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, plano_especular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, plano_brilho);

  /* desenha o plano */
  glNormal3f(0,1,0);
  glBegin(GL_QUADS);
  glVertex3f(-10,0,10);
  glVertex3f(10,0,10);
  glVertex3f(10,0,-10);
  glVertex3f(-10,0,-10);
  glEnd();

/* desenha esferas */

/*Para facilitar a identifica��o da fonte de luz, � desenhada uma esfera na posi��o
desta fonte.
Na chamada � fun��o glMaterialfv(), o par�metro GL_EMISSION define a intensidade
luminosa emitida pelo material como sendo a pr�pria cor da fonte de luz, dando a
apar�ncia de que a esfera brilha, assim como brilharia uma l�mpada.
*/
  glPushMatrix();
  glTranslatef(posicao_luz0[0],posicao_luz0[1],posicao_luz0[2]);
  glMaterialfv(GL_FRONT, GL_EMISSION, cor_luz0);
  glutSolidSphere(0.3,5,5);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(posicao_luz1[0],posicao_luz1[1],posicao_luz1[2]);
  glMaterialfv(GL_FRONT, GL_EMISSION, cor_luz1);
  glutSolidSphere(0.3,5,5);
  glPopMatrix();

  glMaterialfv(GL_FRONT, GL_EMISSION, sem_cor);

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_a_difusa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_a_especular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_a_brilho);

  glPushMatrix();
  glTranslatef(0.0,3.0,-3.0);
  glutSolidSphere(raioEsfera,fatias,pilhas);
  glPopMatrix();

  GLfloat mat_b_difusa[]    = { 0.7, 0.7, 0.7, transparencia_esfera_b };   // o valor de alfa=0.5 d� a apar�ncia transl�cida
  GLfloat mat_b_especular[] = { 1.0, 1.0, 1.0, transparencia_esfera_b };

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_b_difusa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_b_especular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_b_brilho);

  glTranslatef(0.0,+3.0,+3.0);

  glutSolidSphere(raioEsfera,fatias,pilhas);

  glPopMatrix();
  glutSwapBuffers();
}

// Rotaciona a cena - � poss�vel ver a posi��o das luzes
void special(int key, int x, int y){
  switch (key) {
  case GLUT_KEY_UP:
    obs[1]=obs[1]+1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_DOWN:
    obs[1] =obs[1]-1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_LEFT:
    tetaxz=tetaxz+2;
    glutPostRedisplay();
    break;
  case GLUT_KEY_RIGHT:
    tetaxz=tetaxz-2;
    glutPostRedisplay();
    break;
  }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void reshape(int width, int height){
    WIDTH=width;
    HEIGHT=height;
    glViewport(0,0,(GLint)width,(GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0,width/(float)height,0.1,30.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(){
  gouraud=1;
  glEnable(GL_DEPTH_TEST);

/*Habilita a composi��o (blending) de imagens dos valores RGBA correntes com aqueles
presentes no framebuffer. */
  glEnable(GL_BLEND);

/*A fun��o glBlendFunc() define os pesos para a imagem que est� sendo processada (IP)
e a presente no framebuffer. Neste caso, os pesos s�o o pr�prio valor do canal
alfa (GL_SRC_ALPHA) e 1-alfa (GL_ONE_MINUS_SRC_ALPHA). */
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

// Define a posi��o e as componentes de cor da fonte de luz GL_LIGHT0.
  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz0);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz0_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz0);

  glLightfv(GL_LIGHT1, GL_DIFFUSE, cor_luz1);
  glLightfv(GL_LIGHT1, GL_SPECULAR, cor_luz1);
  glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, spot_luz1);
  glLightfv(GL_LIGHT1, GL_POSITION, posicao_luz1);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_luz1);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);

  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
}


int main(int argc,char **argv) {
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutCreateWindow("Trabalho Final - Lenda da Mandioca");

    //init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //glutSpecialFunc(special);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return(0);
}
