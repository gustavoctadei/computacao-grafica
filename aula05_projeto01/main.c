#include <stdlib.h>
#include <GL/glut.h>

GLfloat fAspect = 1;

void Desenha(){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100,fAspect,0.5,500);
  //glFrustum(0.4, 0.4, 0.4,0.4,0.3,0.8);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(40,60,100, 0,0,0, 0,1,0);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,1);

  glutWireCube(50);
  //glutWireTeapot(30);
  //glutWireSphere(30,10,10);
  //glutWireCone(30, 50,10,10);

  glFlush();
}

void Teclado (unsigned char key, int x, int y)
{       if (key == 27)
                exit(0);
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Primeiro_Programa");

    init();
    glutDisplayFunc(Desenha);
    glutMainLoop();

    return 0;
}
