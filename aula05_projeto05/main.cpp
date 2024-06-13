//Atividade 3 - Prática 2 - Exercicio 2

#include <stdlib.h>
#include <GL/freeglut.h>

/* angulos de rotacao para os corpos celestes */
float angleEarth = 0;
float angleMoon = 0;
float angleMars = 0;
int id;

/* para a camera, lembrem-se dos exercicios anteriores */
#define y_min 60
#define ro_min 120
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

/* angulos de rotacao para os corpos celestes */

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

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);

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
void
TimerFunction( int value ){

	angleEarth += 3;
	if( angleEarth >= 360 ) angleEarth = 0;

	angleMoon += 6;
	if( angleMoon >= 360 ) angleMoon = 0;

	angleMars += 2;
	if( angleMars >= 360 ) angleMars = 0;

	glutPostRedisplay();
	glutTimerFunc( 33, TimerFunction, 1);
}

void reshape(int width,int height)
{
glViewport(0,0,width,height); // Reset The Current Viewport

glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
glLoadIdentity(); // Reset The Projection Matrix

// Calculate The Aspect Ratio Of The Window
gluPerspective(45.0f,(float)640/(float)480,0.1f,1000.0f);
// Always keeps the same aspect as a 640 wide and 480 high window

glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
glLoadIdentity(); // Reset The Modelview Matrix
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc( 33, TimerFunction, 1);
	glutMainLoop();
	return 0;
}
