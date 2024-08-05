#include <stdlib.h>
#include <GL/freeglut.h>

int id;
GLfloat fAspect = 1;
GLfloat translada_x = 0.0;
GLfloat translada_y = 0.0;
GLfloat translada_z = 0.0;

GLfloat tx = 0;
GLfloat ty = 0;
GLfloat tz = 0;

void desenha(void) {
glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glTranslatef(translada_x, translada_y, translada_z);
  glRotatef(tx, 1.0f, 1.0f, 1.0f);

  gluPerspective(100,fAspect,0.5,500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(40,60,100, 0,0,0, 0,1,0);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,1);

  glutWireTeapot(30);

  glFlush();
}

// tecla, posicao onde estava o mouse quando a tecla foi pressionada
void teclado(unsigned char key, int x, int y) {
    switch(key){

    case 'a':
        translada_x = translada_x - 0.01;
        break;

    case 'd':
        translada_x = translada_x + 0.01;
        break;

    case 'w':
        translada_y = translada_y + 0.01;
        break;

    case 's':
        translada_y = translada_y - 0.01;
        break;

    case 27:
        glutDestroyWindow(id);
        exit(0);
        break;
    }
}

int main(int argc,char ** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	id = glutCreateWindow("Bom dia alunos!!!");
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutMainLoop();

	return 0;
}
