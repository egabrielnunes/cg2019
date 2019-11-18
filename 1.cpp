#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init(void)
{
       //Seta a janela (background) na cor Branca
       glClearColor(0.0,0.0,0.0,0.0);
       //Parâmetros de projeção BI-Dimensional
       glMatrixMode(GL_PROJECTION);
       gluOrtho2D(0.0,1.0,0.0,1.0);
       glMatrixMode(GL_MODELVIEW);
       
}



void drawGrid(void)
{
       glClear(GL_COLOR_BUFFER_BIT);

       glColor3f(1.0,1.0,0.0);

       glBegin(GL_LINES);
           glVertex2f(0.25,0.0);     
           glVertex2f(0.25,1.0);
       glEnd();


       glBegin(GL_LINES);
           glVertex2f(0.5,0.0);     
           glVertex2f(0.5,1.0);
       glEnd();

        glBegin(GL_LINES);
           glVertex2f(0.75,0.0);     
           glVertex2f(0.75,1.0);
       glEnd();


        glBegin(GL_LINES);
           glVertex2f(0.0,0.25);     
           glVertex2f(1.0,0.25);
       glEnd();


        glBegin(GL_LINES);
           glVertex2f(0.0,0.5);     
           glVertex2f(1.0,0.5);
       glEnd();


        glBegin(GL_LINES);
           glVertex2f(0.0,0.75);     
           glVertex2f(1.0,0.75);
       glEnd();

       glBegin(GL_TRIANGLES);
			glVertex2f(0.25,0.0);
			glVertex2f(0.5,0.0);
			glVertex2f(0.5, 0.5);
	    glEnd();


	    glTranslated(-0.25,0.0)
	    glEscaleted()
		glTranslated(0.25,0.0)
	    

	    glBegin(GL_TRIANGLES);
			glVertex2f(0.25,0.0);
			glVertex2f(0.5,0.0);
			glVertex2f(0.5, 0.5);
	    glEnd();

     
       glFlush();

}

int main (int argc, char** argv) {
       glutInit (&argc, argv);
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
       glutCreateWindow("");

       glutInitWindowSize(1000,1000);

       init();
       glutDisplayFunc(drawGrid);

       glutMainLoop();
}
