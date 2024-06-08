#include <stdlib.h>
#include <GL/freeglut.h>

int id;

/* angulos de rotacao para os corpos celestes */
float angleEarth = 0;
float angleMoon = 0;
float angleMars = 0;

/* para a camera, lembrem-se dos exercicios anteriores */
#define y_min 60
#define ro_min 120
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

void drawSun(){
    glColor3f( 1, 1, 0 );
    glutSolidSphere( 12, 16, 16 );
}

void drawEarth(){
    glColor3f( 0, 0, 1 );
    glutSolidSphere( 5, 16, 16 );
}

void drawMoon(){
    glColor3f( 0.5, 0.5, 0.5 );
    glutSolidSphere( 1, 16, 16 );
}

void drawMars(){
    glColor3f( 1, 0.2, 0 );
    glutSolidSphere( 4, 16, 16 );
}

void TimerFunction( int value ) {
    angleEarth += 3;
    if( angleEarth >= 360 ) angleEarth = 0;

    angleMoon += 6;
    if( angleMoon >= 360 ) angleMoon = 0;

    angleMars += 2;
    if( angleMars >= 360 ) angleMars = 0;

    glutPostRedisplay();
    glutTimerFunc( 33, TimerFunction, 1);
}

void teclado(unsigned char key, int x, int y) {
	if (key == 27) {
       glutDestroyWindow(id);
	   exit(0);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    //gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);

    // Draw planetary system
    glPushMatrix();
      drawSun();
      glPushMatrix();
        glRotatef( angleEarth, 0, 1, 0 );
        glTranslatef( 30, 0, 0 );
        drawEarth();
        glPushMatrix();
          glRotatef( angleMoon, 0, 1, 0 );
          glTranslatef( 7, 0, 0 );
          drawMoon();
        glPopMatrix();
      glPopMatrix();
      glPushMatrix();
        glRotatef( angleMars, 0, 1, 0 );
        glTranslatef( 50, 0, 0 );
        drawMars();
      glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc,char ** argv) {
	//Inicia a Telinha
	glutInit(&argc,argv);

	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(500,500);

    // Especifica a posicao inicial da Janela
	glutInitWindowPosition(100,100);

	// Cria a janela passando como argumento o título da mesma
	id = glutCreateWindow("Bom dia alunos!!!");

	// Registra a função de redesenho da janela de visualização
	glutDisplayFunc(display);

	// Registra a função para tratamento das teclas ASCII
	glutKeyboardFunc (teclado);

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
