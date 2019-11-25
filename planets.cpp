#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/glut.h>
#include <math.h>

static int year = 0; 
static int year1 = 0; 
static int year3 = 0; 
static int year4 = 0; 
static int day = 0;

void init (void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);

	glPushMatrix(); //SOL
		glRotatef((GLfloat) year, 0.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
		glutWireSphere(1.0, 20, 16);
	glPopMatrix();

	glColor3f(0.0, 1.0, 1.0);

	glPushMatrix(); //PLANETA 1
		glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);
	glPopMatrix();

	glPushMatrix(); //PLANETA 2
		glColor3f(1.0, 0.0, 1.0);

		glRotatef((GLfloat) year1, 0.0, 1.0, 0.0);
		glTranslatef(3.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 3.0, 0.0);
		glutWireSphere(0.1, 10, 8);
		
		glColor3f(0.5,0.5,0.5);

		//LUA 1
		glRotatef((GLfloat) year3, 0.0, 0.5, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 3.0, 0.0);
		glutWireSphere(0.05, 5, 4);

		//LUA 2
		glRotatef((GLfloat) year4, 3.5, 3.0, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 3.0, 0.0);
		glutWireSphere(0.05, 5, 4);
	glPopMatrix();

	glutSwapBuffers();

}

void reshape (int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posicao da camera
}

void keyboard (unsigned char key, int x, int y){
	switch(key){
		case 'd':
			day = (day + 10) % 360; //%valor do resto
			glutPostRedisplay(); // Redesenha a cena com novas coordenadas, é executado no glutMainLoop
			break;
		case 'D':
			day = (day - 10) % 360; //%valor do resto
			glutPostRedisplay(); // Redesenha a cena com novas coordenadas, é executado no glutMainLoop
			break;
		case 'y':
			year = (year + 1) % 360; //%valor do resto		
     		year1 = (year1 - 1) % 360; //%valor do resto
     		year3 = (year3 - 1) % 360; //%valor do resto
			year4 = (year4 - 1) % 360; //%valor do resto
			glutPostRedisplay(); // Redesenha a cena com novas coordenadas, é executado no glutMainLoop
			break;
		case 'Y':
			year = (year + 1) % 360; //%valor do resto
     		year1 = (year1 - 1) % 360; //%valor do resto
	  		year3 = (year3 - 1) % 360; //%valor do resto
	  		year4 = (year4 - 1) % 360; //%valor do resto
			glutPostRedisplay(); // Redesenha a cena com novas coordenadas, é executado no glutMainLoop
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotação de Planetas");

	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
