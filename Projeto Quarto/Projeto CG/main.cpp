#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>
#include "texture.cpp"

float lx=0.0f,lz=-1.0f;
float x=0.0f,z=7.0f;
float door_angle = 0.0f;
float angle = 0.0f;

void init(void) {
    // sky color
    glClearColor(0.0, 0.7, 1.0, 1.0);

//    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
//    GLfloat luzDifusa[4]={0.8,0.8,0.8,1.0};	   // "cor"
//    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
//
//    // Capacidade de brilho do material
//    GLfloat especularidade[4]={0.5,0.5,0.5,1.0};
//    GLint especMaterial = 60;
//
//    // Habilita o modelo de colorização de Gouraud
//    glShadeModel(GL_SMOOTH);
//
//    // Define a refletância do material
//    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
//    // Define a concentração do brilho
//    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
//
//    // Ativa o uso da luz ambiente
////    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
//
//    // Define os parâmetros da luz de número 0
//    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
//    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
//
//    // Habilita a definição da cor do material a partir da cor corrente
//    glEnable(GL_COLOR_MATERIAL);
//    //Habilita o uso de iluminação
//    glEnable(GL_LIGHTING);
//    // Habilita a luz de número 0
//    glEnable(GL_LIGHT0);
//
//    GLfloat posicaoLuz[4]={0.5, 0.5, 0, 1.0};
//    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Lighting set up
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHT1);
//    glEnable(GL_LIGHT2);
//    glEnable(GL_LIGHT3);
//    glEnable(GL_LIGHT4);

    // Set lighting intensity and color
    GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
    GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
    GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

    glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);

    glLightfv(GL_LIGHT3, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT3, GL_SPECULAR, qaSpecularLight);

    glLightfv(GL_LIGHT4, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT4, GL_SPECULAR, qaSpecularLight);


    //Luz da janela
    GLfloat qaLightPosition[]	= {-1.9f, 1.0, -5.9f, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

    GLfloat qaLightPosition1[]	= {-5.0f, 1.0, -5.9f, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);

    GLfloat qaLightPosition2[]	= {1.9f, 1.0, -5.9f, 1.0};
    glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition2);

//    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 360.0);
//    GLfloat spot_direction3[] = {-5.0f, 1.0, 2.0};
//    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction3);
//
//    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 360.0);
//    GLfloat spot_direction4[] = {5.0f, -4.0, 2.0};
//    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction4);

    GLfloat qaLightPosition3[]	= {-5.0f, 1.0f, 2.0f, 1.0};
    glLightfv(GL_LIGHT3, GL_POSITION, qaLightPosition3);

    GLfloat qaLightPosition4[]	= {5.0f, -4.0f, 2.0f, 1.0};
    glLightfv(GL_LIGHT4, GL_POSITION, qaLightPosition4);


    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    loadTextures();

}

//Parte de trás do Quarto
void drawBack(){

    //============== BEGIN BACK ==================

    // Back side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0.5,-6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0.5,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5f,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5f,-6);
    glEnd();

    //rodape back
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,-1.1f,-5.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,-1.1f,-5.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5f,-5.99f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5f,-5.99f);
    glEnd();


}

//Laterais do Quarto
void drawSides(){
    //============== BEGIN LATERAIS ===================

    // wall right side
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0.5,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5f,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5f,1);
    glEnd();
    glPopMatrix();

    // rodape right side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.999,-1.1f,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.999,-1.1f,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.999,-1.5f,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.999,-1.5f,1);
    glEnd();
    glPopMatrix();

    // wall left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,0.5,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-1.5f,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5f,1);
    glEnd();

    glPopMatrix();

    // rodape left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.999f,-1.1f,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.999f,-1.1f,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.999f,-1.5f,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.999f,-1.5f,1);
    glEnd();

    //============== END LATERAIS ===================
}

//Tomadas
void drawtomadas() {

    glBindTexture(GL_TEXTURE_2D, texture_id[33]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.9999f, -0.95f, -2.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9999f, -0.95f, -2.6f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9999f, -1.0f, -2.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9999f, -1.0f, -2.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[34]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f,-0.9f,0.89f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.55f,-0.9f,0.89f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.55f,-1.0f,0.89f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f,-1.0f,0.89f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_id[35]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f,-0.4f,0.89f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.55f,-0.4f,0.89f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.55f,-0.5f,0.89f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f,-0.5f,0.89f);
    glEnd();
}

//Televisão
void drawTv(){

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9999f,0.3,-2.5f);
    glVertex3f(-1.9999f,0.3,-4);
    glVertex3f(-1.9999f,-0.6f,-4);
    glVertex3f(-1.9999f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.91f,0.3f,-2.5f);
    glVertex3f(-1.91f,0.3f,-4.0f);
    glVertex3f(-1.91f,-0.6f,-4.0f);
    glVertex3f(-1.91f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.92f,0.3f,-2.5f);
    glVertex3f(-1.92f,0.3f,-4.0f);
    glVertex3f(-1.92f,-0.6f,-4.0f);
    glVertex3f(-1.92f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.93f,0.3,-2.5f);
    glVertex3f(-1.93f,0.3,-4);
    glVertex3f(-1.93f,-0.6f,-4);
    glVertex3f(-1.93f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.94f,0.3,-2.5f);
    glVertex3f(-1.94f,0.3,-4);
    glVertex3f(-1.94f,-0.6f,-4);
    glVertex3f(-1.94f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.95f,0.3,-2.5f);
    glVertex3f(-1.95f,0.3,-4);
    glVertex3f(-1.95f,-0.6f,-4);
    glVertex3f(-1.95f,-0.6f,-2.5f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.97f,0.3,-2.5f);
    glVertex3f(-1.97f,0.3,-4);
    glVertex3f(-1.97f,-0.6f,-4);
    glVertex3f(-1.97f,-0.6f,-2.5f);
    glEnd();

    //tv
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[7]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(-1.9f,0.3,-2.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9f,0.3f,-4.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9f,-0.6f,-4.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9f,-0.6f,-2.5f);
    glEnd();

}

//Quadro RHCP 1
void drawRHCP(){
    //rhcp
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[13]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.9,0.2,-0.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9,0.2,-1.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9,-0.3,-1.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9,-0.3,-0.5);
    glEnd();
}

//Camisa RHCP
void drawRHCP2(){
    //hp1
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[18]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.69,-0.9,-3.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.69,-0.9,-3.5);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.69,-1.2,-3.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.69,-1.2,-3.3);
    glEnd();

}

//Quadro HP 1
void drawHP1(){
    //hp1
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[16]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9,0.2,-4.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9,0.2,-4.8);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.9,-0.3,-4.8);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9,-0.3,-4.3);
    glEnd();

}

//Quadro HP 2
void drawHP2(){
    //hp2
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[17]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9,0.2,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9,0.2,-5.5);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.9,-0.3,-5.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9,-0.3,-5);
    glEnd();
}

//Frente do Quarto
void drawFront(){

    //right wall
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.7,0.5,1);//top left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0.5,1);//top right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5,1);//bottom right
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.7,-1.5,1);//bottom left
    glEnd();

    //rodape right wall
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.7f,-1.1f,0.99f);//top left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.0f,-1.1f,0.99f);//top right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f,-1.5,0.99f);//bottom right
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.7f,-1.5f,0.99f);//bottom left
    glEnd();


    //left wall
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.3,0.5,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.3,-1.5,1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,1);
    glEnd();

    //rodape left wall
    glBindTexture(GL_TEXTURE_2D, texture_id[24]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,-1.1f,0.99f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.3,-1.1f,0.99f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.3,-1.5,0.99f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,0.99f);
    glEnd();

    //modura porta left wall
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.35f,-0.1f,0.89f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.3f,-0.1f,0.89f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.3f,-1.5f,0.89f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.35f,-1.5f,0.89f);
    glEnd();

    //modura porta left wall
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.65f,-0.1f,0.89f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.7f,-0.1f,0.89f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.7f,-1.5f,0.89f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.65f,-1.5f,0.89f);
    glEnd();

    //top door
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.8, 0.5, 1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.3, 0.5, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.3, -0.1, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.8,-0.1, 1);
    glEnd();

    //moldura top door
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.65f, -0.05f, 0.89f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.35f, -0.05f, 0.89f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.35f, -0.1f, 0.89f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.65f,-0.1f, 0.89f);
    glEnd();

    //bottom door
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);  // Wall FRONT MIDDLE botton
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.8, -1.25, 1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.3, -1.25, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.3, -1.5, 1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.8,-1.5, 1);
    glEnd();

    glPopMatrix();

}

//Janela do Quarto
void window(){

    //janela
    glBindTexture(GL_TEXTURE_2D, texture_id[9]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -0.7f,-5.95f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, -0.7f,-5.95f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.3f,-5.95f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 0.3f,-5.95f);
    glEnd();

    //cortina esquerda
    glBindTexture(GL_TEXTURE_2D, texture_id[40]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.9f, -1.1f,-5.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.7f, -1.1f,-5.9f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.7f, 0.4f,-5.9f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9f, 0.4f,-5.9f);
    glEnd();

    //cortina direita
    glBindTexture(GL_TEXTURE_2D, texture_id[40]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.9f, -1.1f,-5.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.7f, -1.1f,-5.9f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.7f, 0.4f,-5.9f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.9f, 0.4f,-5.9f);
    glEnd();

    //cortina centro
    glBindTexture(GL_TEXTURE_2D, texture_id[39]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 0.36f,-5.91f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 0.36f,-5.91f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.38f,-5.91f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 0.38f,-5.91f);
    glEnd();

}

//Guarda Roupa
void drawCloset(){

    //guarda roupa frente
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[10]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.9,0.45,-0.2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.3,0.5,-0.2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.3,-1.5,-0.2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.9,-1.5,-0.2);
    glEnd();

    //lateral guarda roupa
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[15]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.3,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.3,0.5,-0.2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.3,-1.5,-0.2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3,-1.5,1);
    glEnd();


    glPopMatrix();
}

//Piso do Quarto
void drawFloor(){

    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glBegin(GL_QUADS);  // Floor 1
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, -1.2001f, -6.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.0f, -1.2001f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 2.0f, -1.2001f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 2.0f, -1.2001f, -6.0f);
    glEnd();


    //teto
    glBindTexture(GL_TEXTURE_2D, texture_id[8]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, 0.5f, -6.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.0f, 0.5f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 2.0f, 0.5f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 2.0f, 0.5f, -6.0f);
    glEnd();

    //teto
    glBindTexture(GL_TEXTURE_2D, texture_id[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.1f, 0.49f, -4.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.1f, 0.49f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.1f, 0.49f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.1f, 0.49f, -4.0f);
    glEnd();
}

//Prateleira 1
void drawPrateleira1() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, 0, -5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, 0, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 0, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 0, -5);
    glEnd();


    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, -0.05, -5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, -0.05, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.05, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.05, -5);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0,-3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,-0.05,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-0.05,-3);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0,-5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,-0.05,-5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-0.05,-5);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7,0,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,-0.05,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.7,-0.05,-5);
    glEnd();

}

//Prateleira 2
void drawPrateleira2() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, 0.3, -5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, 0.3, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 0.3, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 0.3, -5);
    glEnd();


    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, 0.25, -5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, 0.25, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 0.25, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 0.25, -5);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.3,-3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.25,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,0.25,-3);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.3,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.25,-5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,0.25,-5);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7,0.3,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.25,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.7,0.25,-5);
    glEnd();

}

//Prateleira 3
void drawPrateleira3() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.9, -5.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.9, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7,-0.9, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.9, -5.5);
    glEnd();


    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.95, -5.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, -0.95, -3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7, -0.95, -3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7, -0.95, -5.5);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.9,-3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.9,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.95,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.95,-3);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.9,-5.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.9,-5.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.95,-5.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.95,-5.5);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.9,-5.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.7,-0.9,-3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7,-0.95,-3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.95,-5.5);
    glEnd();

}

//Prateleira 4
void drawPrateleira4() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.75, -4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.75, -1.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7,-0.75, -1.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.75, -4);
    glEnd();

    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.8, -4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, -0.8, -1.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7, -0.8, -1.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7, -0.8, -4);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.75,-1.5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.75,-1.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.8,-1.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.8,-1.5);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.75,-4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.75,-4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.8,-4);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.8,-4);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.7,-0.75,-4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.7,-0.75,-1.5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.7,-0.8,-1.5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.7,-0.8,-4);
    glEnd();

}

//Ar condicionado
void drawAr() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[37]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, 0.3, -2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, 0.3, -1.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 0.3, -1.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 0.3, -2.5f);
    glEnd();


    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[37]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7f, 0.1, -2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7f, 0.1, -1.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 0.1, -1.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 0.1, -2.5f);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[37]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.3,-1.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-1.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.1,-1.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,0.1,-1.5f);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[37]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.3,-2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-2.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.1,-2.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,0.1,-2.5f);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[36]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.7,0.3,-2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.7,0.3,-1.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.7,0.1,-1.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.7,0.1,-2.5f);
    glEnd();

}

//Caixa
void drawCaixa() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.65, -2.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65, -2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -2.3);
    glEnd();

    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.75, -2.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, -0.75, -2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8, -0.75, -2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8, -0.75, -2.3);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-2);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-2.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-2.3);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-2.3);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-2.3);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[20]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-2.3);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-2.3);
    glEnd();

}

//Books
void drawbooks() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.65, -3.4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65, -3.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -3.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -3.4);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-3.1);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-3.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-3.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-3.1);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-3.4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-3.4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-3.4);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-3.4);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[30]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-3.4);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-3.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-3.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-3.4);
    glEnd();

}

//GOT
void drawgot() {

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[31]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.8,-3.2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.8,-3.2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.9,-3.2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.9,-3.2);
    glEnd();

    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[32]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.8,-3.7);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.8,-3.7);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.9,-3.7);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.9,-3.7);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[30]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.8,-3.7);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8,-0.8,-3.2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.9,-3.2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.9,-3.7);
    glEnd();

}

//Macbook
void drawmacbook() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[29]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.73f, -3.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.73f, -3.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8f,-0.73f, -3.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.73f, -3.9f);
    glEnd();


    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[28]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.73f,-3.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.73f,-3.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75f,-3.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75f,-3.5f);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[28]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8f,-0.73f,-3.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.73f,-3.9f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75f,-3.9f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-3.9f);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[26]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8f,-0.73f,-3.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8f,-0.73f,-3.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-3.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-3.9f);
    glEnd();

}

//PS4
void drawPS() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[27]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.7f, -2.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.7f, -2.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8f,-0.7f, -2.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.7f, -2.9f);
    glEnd();


    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[28]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.7f,-2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.7f,-2.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75f,-2.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75f,-2.5f);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[28]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8f,-0.7f,-2.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.7f,-2.9f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75f,-2.9f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-2.9f);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[26]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8f,-0.7f,-2.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8f,-0.7f,-2.5f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-2.5f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8f,-0.75f,-2.9f);
    glEnd();

}

//Jogos
void drawJogos() {

    //cima
    glBindTexture(GL_TEXTURE_2D, texture_id[22]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.65, -1.9);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65, -1.7);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -1.7);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.65, -1.9);
    glEnd();


    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[21]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-1.7);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-1.7);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-1.7);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-1.7);
    glEnd();


    //lateral de tras
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[21]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-1.9);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,-0.65,-1.9);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-0.75,-1.9);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-1.9);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[21]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-1.9);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.8,-0.65,-1.7);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-1.7);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8,-0.75,-1.9);
    glEnd();

}

//Criado Mudo
void drawCriado() {

    //cama
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -5.9f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -5.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -5.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -5.9f);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,-0.6,-5.1);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-5.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-5.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,-5.1);
    glEnd();

    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[14]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5,-0.6,-5.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-5.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-5.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.5,-1.5,-5.9f);
    glEnd();

}

//Criado Mudo 2
void drawCriado2() {

    //cama
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -1.9f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -1.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -1.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -1.9f);
    glEnd();

    //lateral da frente
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,-0.6,-1.1f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-1.1f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-1.1f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,-1.1f);
    glEnd();

    //lateral da tras
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,-0.6,-1.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-1.9f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-1.9f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,-1.9f);
    glEnd();

    //frente
    glBindTexture(GL_TEXTURE_2D, texture_id[14]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5,-0.6,-1.9f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-1.1f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-1.1f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.5,-1.5,-1.9f);
    glEnd();

}

void drawTravesseiros(){

    //travesseiro 1
    glBindTexture(GL_TEXTURE_2D, texture_id[12]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -3.3f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -2.3f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -2.3f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -3.3f);
    glEnd();

    //travesseiro 2
    glBindTexture(GL_TEXTURE_2D, texture_id[12]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -4.7f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -3.7f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -3.7f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -4.7f);
    glEnd();
}

//Cama
void drawBed() {

    //cama
    glBindTexture(GL_TEXTURE_2D, texture_id[12]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -0.8, -5.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, -0.8, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.8, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.8, -5.0f);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,-0.8,-2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1,-0.8,-2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,-1.5,-2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,-2);
    glEnd();

    //lateral da frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,-0.8,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1,-0.8,-5);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,-1.5,-5);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,-5);
    glEnd();


    //frente
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_id[11]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1,-0.8,-5);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1,-0.8,-2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1,-1.5,-2);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1,-1.5,-5);
    glEnd();

}

void drawBall(){
    int i, j;
    int lats = 500;
    int longs =  500;
    float r =  0.2f;

    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);

        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBindTexture(GL_TEXTURE_2D, texture_id[25]);
        glColor3f(1.0f, 0.5f, 0.0f);
        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);
            glTexCoord2f(0.0f, 1.0f);
            glNormal3f(x * zr0-1.7, y * zr0+1, z0-5);

            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(r * x * zr0-1.7, r * y * zr0+1, r * z0-5);

            glTexCoord2f(1.0f, 0.0f);
            glNormal3f(x * zr1-1.7, y * zr1, z1-3);

            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(r * x * zr1-1.7, r * y * zr1+1, r * z1-5);
        }
        glEnd();
    }

}

//Desenha itens do quarto
void drawBedroom(){

    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glLineWidth(2.5);

    drawAr();
    drawmacbook();
    drawPS();
    drawgot();
    drawbooks();
    drawtomadas();

    drawCriado2();
    drawTravesseiros();
    drawJogos();
    drawCaixa();
    drawRHCP2();
    drawHP1();
    drawHP2();
    drawPrateleira1();
    drawPrateleira2();
    drawPrateleira3();
    drawPrateleira4();
    drawCriado();
    drawRHCP();
    drawBed();
    drawFloor();
    drawFront();
    drawBack();
    drawSides();
    drawTv();
    window();
    drawCloset();
}

//Desenha a porta
void drawDoor() {
    glPushMatrix();
    glTranslatef(-1.8, 0.65f, 1);
    glRotatef (door_angle, 0,1,0);
    glTranslatef(0.8, 0, 0);
    glColor3f(0.5f, 0.5f, 0.5f);
    glScalef(0.6, 1.1, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void changeSize(int w, int h){

    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void drawGround(){
    // Draw ground
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();
}

void renderScene(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Set the camera
    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    drawDoor();
    drawGround();
    drawBedroom();
//    drawBall();


    glFlush();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
            break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
            break;

        case '0':
            if(glIsEnabled(GL_LIGHT0))
                glDisable(GL_LIGHT0);
            else
                glEnable(GL_LIGHT0);
            break;

        case '1':
            if(glIsEnabled(GL_LIGHT1))
                glDisable(GL_LIGHT1);
            else
                glEnable(GL_LIGHT1);
            break;

        case '2':
            if(glIsEnabled(GL_LIGHT2))
                glDisable(GL_LIGHT2);
            else
                glEnable(GL_LIGHT2);
            break;

        case '3':
            if(glIsEnabled(GL_LIGHT3))
                glDisable(GL_LIGHT3);
            else
                glEnable(GL_LIGHT3);
            break;

        case '4':
            if(glIsEnabled(GL_LIGHT4))
                glDisable(GL_LIGHT4);
            else
                glEnable(GL_LIGHT4);
            break;
        case 27:
            exit(0);
            break;
    }
}

void processSpecialKeys(int key, int xx, int yy){

    float fraction = 0.5f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("Quarto");

    init();

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 1;
}