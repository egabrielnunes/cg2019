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

    GLfloat luzAmbiente[4]={0.4,0.4,0.4,1.0};
//    GLfloat luzDifusa[4]={1.5,1.5,1.5,1.0};	   // "cor"
//    GLfloat luzEspecular[4]={3.0, 5.0, 2.0, 1.0};// "brilho"
//    GLfloat posicaoLuz[4]={-5, -2, -3, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={0.5,0.5,0.5,1.0};
    GLint especMaterial = 60;

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
//    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
//    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
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
    glVertex3f(2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,-6);
    glEnd();


}

//Laterais do Quarto
void drawSides(){
    //============== BEGIN LATERAIS ===================

    // wall right side
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);

    glTranslatef(0.0f, 1.3f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2,0.5,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2,-1.5,1);
    glEnd();
    glPopMatrix();


    // wall left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBindTexture(GL_TEXTURE_2D, texture_id[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2,0.5,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2,0.5,-6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2,-1.5,-6);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2,-1.5,1);
    glEnd();

    //============== END LATERAIS ===================
}

//Televisão
void drawTv(){

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.9999,0.2,-2.5);
    glVertex3f(-1.9999,0.2,-4);
    glVertex3f(-1.9999,-0.7,-4);
    glVertex3f(-1.9999,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.91,0.2,-2.5);
    glVertex3f(-1.91,0.2,-4);
    glVertex3f(-1.91,-0.7,-4);
    glVertex3f(-1.91,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.92,0.2,-2.5);
    glVertex3f(-1.92,0.2,-4);
    glVertex3f(-1.92,-0.7,-4);
    glVertex3f(-1.92,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.93,0.2,-2.5);
    glVertex3f(-1.93,0.2,-4);
    glVertex3f(-1.93,-0.7,-4);
    glVertex3f(-1.93,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.94,0.2,-2.5);
    glVertex3f(-1.94,0.2,-4);
    glVertex3f(-1.94,-0.7,-4);
    glVertex3f(-1.94,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.95,0.2,-2.5);
    glVertex3f(-1.95,0.2,-4);
    glVertex3f(-1.95,-0.7,-4);
    glVertex3f(-1.95,-0.7,-2.5);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.97,0.2,-2.5);
    glVertex3f(-1.97,0.2,-4);
    glVertex3f(-1.97,-0.7,-4);
    glVertex3f(-1.97,-0.7,-2.5);
    glEnd();

    //tv
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[7]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(-1.9,0.2,-2.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.9,0.2,-4);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.9,-0.7,-4);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.9,-0.7,-2.5);
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
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, texture_id[9]);
    glBegin(GL_QUADS);  // Wall
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1,-0.7,-5.9);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1,-0.7,-5.9);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1,0.3,-5.9);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1,0.3,-5.9);
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

    //baixo
    glBindTexture(GL_TEXTURE_2D, texture_id[19]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2, -0.75, -1.9);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2, -0.75, -1.7);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.8, -0.75, -1.7);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.8, -0.75, -1.9);
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
    glVertex3f(1.5f, -0.6, -6.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5f, -0.6, -5.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -5.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -0.6, -6.0f);
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
    glVertex3f(1.5,-0.6,-6);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.5,-0.6,-5.1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.5,-1.5,-5.1);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.5,-1.5,-6);
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

//Desenha itens do quarto
void drawBedroom(){

    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glLineWidth(2.5);

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