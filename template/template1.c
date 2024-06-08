#include <stdlib.h>
#include <GL/freeglut.h>

int id;

// Função de redesenho da janela de visualização
void Desenha(void)
{
	// Limpa a janela de visualização com a cor branca
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor de desenho: vermelho
	glColor3f(1,0,0);
	
	// Desenha um triângulo no centro da janela
	//glBegin(GL_LINE_STRIP);
	//glBegin(GL_LINE_LOOP);
     glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0);
		glVertex3f( 0.0, 0.5,0);
		glVertex3f( 0.5,-0.5,0);
	 glEnd();
	
	

	
	//Executa os comandos OpenGL 
	glFlush();
}

// tecla, posicao onde estava o mouse quando a tecla foi pressionada
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27){
       glutDestroyWindow(id);                 
	   exit(0);
    }
}

// Programa Principal 
int main(int argc,char ** argv)
{
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
	glutDisplayFunc(Desenha);

	// Registra a função para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);
	 
	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
 
	return 0;
}