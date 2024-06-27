
/*
A esfera "A" é sólida, e os valores das suas constantes de reflexão difusa e
especular pode ser modificados através de seleção de opções em um menu.
A esfera "B" é translúcida, e sua translucidez pode ser ajustada através do canal alfa.

Até o momento, o canal alfa tem sido ignorado (alfa é o A em RGBA). Os valores do
canal alfa variam de 0 a 1, e são especificados com as funções glColor().
Quando os efeitos de composição (blending) são utilizados, o valor de alfa é
utilizado para combinar a cor do fragmento que está sendo processado com a cor
já presente no framebuffer. De modo geral, a composição de imagens utilando o
canal alfa é dada pela seguinte expressão:
IT = IP * alfa + (1-alfa)* IFB
- IT é a imagem total resultante,
- IP é a imagem que está sendo processada,
- IFB é a imagem anteriormente presente no framebuffer.

Manual de uso

teclas LEFT e RIGHT: servem para rotacionar a posição do observador em torno do
                     eixo y contra e a favor do sentido dos ponteiros do relógio, respectivamente
r, R: altera a distância entre o observador e o centro de rotação (raio de observação)
teclas UP e DOWN: controlam a altitude do observador (no eixo y).
Botão direito do mouse (menu): é possível modificar os graus de reflexão difusa e especular da esfera maciça

http://www.ceset.unicamp.br/~magic/opengl/modelos-iluminacao.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.1415

GLint WIDTH =320;
GLint HEIGHT=240;

// Define o número de fatias (longitude), o número de pilhas (latitude) e o raio das esferas da cena.
GLint fatias=30;
GLint pilhas=30;
GLint raioEsfera=1.5;

GLfloat obs[3]={0.0,7.0,0.0};
GLfloat olho[3]={0.0,3.0,0.0};

//Define os coeficientes de reflexão difusa (*_difusa) e especular (*_especular) para os três objetos da cena.
/*Obs: O brilho do material, que pode assumir valores entre 1 e 128, é um expoente
que modela a função de distribuição espacial da componente de luz refletida
especularmente. À medida em que o valor do brilho aumenta, diminui o espalhamento
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
//GLfloat mat_b_difusa[]    = { 0.7, 0.7, 0.7, transparencia_esfera_b };   // o valor de alfa=0.5 dá a aparência translúcida
//GLfloat mat_b_especular[] = { 1.0, 1.0, 1.0, transparencia_esfera_b };
GLfloat mat_b_brilho[]    = { 50.0 };


GLfloat posicao_luz0[]    = { 0.0, 10.0, 0.0, 1.0};  // posição luz
GLfloat cor_luz0[]        = { 1.0, 1.0, 1.0, 1.0};  // componentes de luz para reflexão difusa e especular
GLfloat cor_luz0_amb[]    = { 0.3, 0.3, 0.3, 1.0};  // componente de luz para reflexão ambiente

GLfloat posicao_luz1[]    = { 0.0, 10.0, 5.0, 1.0};
GLfloat cor_luz1[]        = { 0.0, 0.0, 1.0, 1.0};
GLfloat direcao_luz1[]    = { 0.0, -10.0, -5.0, 1.0};
GLint   spot_luz1         = 30;

GLfloat sem_cor[]         = { 0.0, 0.0, 0.0, 1.0};

GLint gouraud=1;

GLfloat tetaxz=0;
GLfloat raioxz=6;

void reshape(int width, int height){
  WIDTH=width;
  HEIGHT=height;
  glViewport(0,0,(GLint)width,(GLint)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0,width/(float)height,0.1,30.0);
  glMatrixMode(GL_MODELVIEW);
}

void display(void){
/*o depth-buffer (também conhecido por z-buffer) serve para guardar o valor de
profundidade de cada pixel desenhado. Assim, é fácil impôr a condição de que cada
novo pixel só será desenhado se tiver um valor de profundidade superior (valores
negativos) ao que já lá estava, evitando sobrepôr pixels mais próximos.
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


/*A função glMaterialfv() define as propriedades de reflexão difusa e especular,
e brilho do material que será utilizado para compor o objeto imediatamente desenhado,
neste caso um plano, via GL_QUADS.

Observe a chamada à função glNormal3f() antes
do plano ser desenhado. Isto é necessário porque, por default, o vetor normal
encontra-se na direção (x,y,z)=(0,0,1) e para que a normal à superfície encontra-se
orientada com eixo y, ou seja, na direção (x,y,z)=(0,1,0).
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

/*Para facilitar a identificação da fonte de luz, é desenhada uma esfera na posição
desta fonte.
Na chamada à função glMaterialfv(), o parâmetro GL_EMISSION define a intensidade
luminosa emitida pelo material como sendo a própria cor da fonte de luz, dando a
aparência de que a esfera brilha, assim como brilharia uma lâmpada.
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

  GLfloat mat_b_difusa[]    = { 0.7, 0.7, 0.7, transparencia_esfera_b };   // o valor de alfa=0.5 dá a aparência translúcida
  GLfloat mat_b_especular[] = { 1.0, 1.0, 1.0, transparencia_esfera_b };

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_b_difusa);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_b_especular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_b_brilho);

  glTranslatef(0.0,+3.0,+3.0);

  glutSolidSphere(raioEsfera,fatias,pilhas);

  glPopMatrix();
  glutSwapBuffers();
}

// Rotaciona a cena - é possível ver a posição das luzes
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

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'g':
    gouraud = !gouraud;
    glutPostRedisplay();
    break;
  case 'r':
    raioxz=raioxz+1;
    glutPostRedisplay();
    break;
  case 'R':
    if(raioxz>1){
      raioxz=raioxz-1;
      glutPostRedisplay();
    }
    break;
  case 'T':
      if (transparencia_esfera_b < 1.0){
        transparencia_esfera_b += 0.1;
        glutPostRedisplay();
      }
    break;
  case 't':
      if (transparencia_esfera_b > 0.1) {
        transparencia_esfera_b -= 0.1;
        glutPostRedisplay();
      }
    break;
  }
}


void init(){
  gouraud=1;
  glEnable(GL_DEPTH_TEST);

/*Habilita a composição (blending) de imagens dos valores RGBA correntes com aqueles
presentes no framebuffer. */
  glEnable(GL_BLEND);

/*A função glBlendFunc() define os pesos para a imagem que está sendo processada (IP)
e a presente no framebuffer. Neste caso, os pesos são o próprio valor do canal
alfa (GL_SRC_ALPHA) e 1-alfa (GL_ONE_MINUS_SRC_ALPHA). */
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

// Define a posição e as componentes de cor da fonte de luz GL_LIGHT0.
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

/*A função menu é ativada quando o botão direito do mouse é pressionado. De acordo
com o valor da variável value, determinadas propriedades do material que compõe
a esfera A são modificadas. */

void menu(int value){
  switch (value) {
  case 0:
    mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=0.0;
    break;
  case 1:
    mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=0.5;
    break;
  case 2:
    mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=1.0;
    break;
  case 3:
    mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=0.0;
    break;
  case 4:
    mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=0.5;
    break;
  case 5:
    mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=1.0;
    break;
  case 6:
    gouraud = 1;
    break;
  case 7:
    gouraud = 0;
    break;
  }
  glutPostRedisplay();
}


int main(int argc,char **argv){
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);

  if(!glutCreateWindow("Modelos de iluminacao")) {
    fprintf(stderr,"Error opening a window.\n");
    exit(-1);
  }

  init();

  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

/*A função glutCreateMenu(), em conjunto com a função glutAddMenuEntry(),
habilita um menu popup com seis opções que permitirão ativar entradas presentes
na função menu, de acordo com os valores passados nos segundos argumentos das
funções glutAddMenuEntry().
A função glutAttachMenu() associa o aparecimento deste menu ao pressionamento do
botão direito do mouse.
*/
  glutCreateMenu(menu);
  glutAddMenuEntry("-sem spec", 0);
  glutAddMenuEntry("-spec média", 1);
  glutAddMenuEntry("-spec alta", 2);
  glutAddMenuEntry("-sem difusa", 3);
  glutAddMenuEntry("-difusa média", 4);
  glutAddMenuEntry("-difusa alta", 5);
  glutAddMenuEntry("-flat", 6);
  glutAddMenuEntry("-gouraud", 7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return(0);
}
