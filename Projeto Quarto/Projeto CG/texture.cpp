#include <SFML/Graphics.hpp>
#include <fstream>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define FRONT 4
#define BACK 5

GLuint texture_id[50];

void drawCube(GLdouble size, int *tex) {

    static GLfloat n[6][3] = {
        {-1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 0.0, -1.0}
    };

    static GLint faces[6][4] = {
        {0, 1, 2, 3},
        {3, 2, 6, 7},
        {7, 6, 5, 4},
        {4, 5, 1, 0},
        {5, 6, 2, 1},
        {7, 4, 0, 3}
    };
    
    GLfloat v[8][3];
    GLint i;

    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

    for (i = 5; i >= 0; i--) {
        if(tex[i] >= 0) {
            glBindTexture(GL_TEXTURE_2D, texture_id[tex[i]]);
        } else {
    	    glBindTexture(GL_TEXTURE_2D, 0);
        }

        glBegin(GL_QUADS);
        glNormal3fv(&n[i][0]);
    
        if (i == 1) {
            glTexCoord2f(1.0f, 0.0f);
        } else {
            glTexCoord2f(0.0f, 0.0f);
        }
        
        glVertex3fv(&v[faces[i][0]][0]);
        if (i==1) {
            glTexCoord2f(0.0f, 0.0f);
        } else {
            glTexCoord2f(1.0f, 0.0f);
        }
        
        glVertex3fv(&v[faces[i][1]][0]);
        if (i == 1) {
            glTexCoord2f(0.0f, 1.0f);
        } else {
            glTexCoord2f(1.0f, 1.0f);
        }
            
        glVertex3fv(&v[faces[i][2]][0]);
        if (i == 1) {
            glTexCoord2f(1.0f, 1.0f);
        } else {
            glTexCoord2f(0.0f, 1.0f);
        }
    
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }

}

void faceCubeConstructor(double size, int face, int texture) {
	
    double position = size/2;
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	
    if (face == LEFT) {
		glTexCoord2f(0,0);
		glVertex3f(-position, 0, 0);
		glTexCoord2f(1,0);
		glVertex3f(-position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(-position, 0, position);
		glTexCoord2f(1,1);
		glVertex3f(-position, position, position);
	}
	
    if (face == UP) {
		glTexCoord2f(0,0);
		glVertex3f(0, position, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(0, position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
	
    if (face == RIGHT) {
		glTexCoord2f(0,0);
		glVertex3f(position, 0, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(position, 0, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
    
    if (face == DOWN) {
		glTexCoord2f(0,0);
		glVertex3f(0, -position, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, -position, 0);
		glTexCoord2f(0,1);
		glVertex3f(0, -position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, -position, position);
	}
	
    if (face == FRONT) {
		glTexCoord2f(0,0);
		glVertex3f(0, 0, position);
		glTexCoord2f(1,0);
		glVertex3f(position, 0, position);
		glTexCoord2f(0,1);
		glVertex3f(0, position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
	
    if (face == BACK) {
		glTexCoord2f(0,0);
		glVertex3f(0, 0, -position);
		glTexCoord2f(1,0);
		glVertex3f(position, 0, -position);
		glTexCoord2f(0,1);
		glVertex3f(0, position, -position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, -position);
	}

	glEnd();

}

void loadTextureFromFile(char const *filename, int index) {
	
    int width, height;

	sf::Image image;
	image.loadFromFile(filename);

	glGenTextures(1, &texture_id[index]);
	glBindTexture(GL_TEXTURE_2D, texture_id[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

}

void loadTextures() {

	loadTextureFromFile("images/piso.jpeg", 0);
	loadTextureFromFile("images/paredes.jpeg", 1);
	loadTextureFromFile("images/janela.jpg", 2);
	loadTextureFromFile("images/teto.jpg", 3);
	loadTextureFromFile("images/porta.jpg", 4);
	loadTextureFromFile("images/parede1.jpg", 5);
	loadTextureFromFile("images/teto.png", 6);
	loadTextureFromFile("images/tv.jpg", 7);
	loadTextureFromFile("images/teto.jpeg", 8);
	loadTextureFromFile("images/janela1.jpeg", 9);
	loadTextureFromFile("images/roupa2.jpg", 10);
	loadTextureFromFile("images/madeira.jpeg", 11);
	loadTextureFromFile("images/cama.jpeg", 12);
	loadTextureFromFile("images/rhcp.jpeg", 13);
	loadTextureFromFile("images/criado.jpeg", 14);
	loadTextureFromFile("images/branco.jpg", 15);
	loadTextureFromFile("images/hp1.jpeg", 16);
	loadTextureFromFile("images/hp2.jpeg", 17);
	loadTextureFromFile("images/rhcp2.jpeg", 18);
	loadTextureFromFile("images/madeiraclara.jpg", 19);
	loadTextureFromFile("images/frentecaixa.jpg", 20);
	loadTextureFromFile("images/frentejogos.jpg", 21);
	loadTextureFromFile("images/cimajogos.jpeg", 22);
    loadTextureFromFile("images/macbook.jpeg", 23);
    loadTextureFromFile("images/piso 2.jpeg", 24);
    loadTextureFromFile("images/basquete.png", 25);
    loadTextureFromFile("images/psfrente.jpeg", 26);
    loadTextureFromFile("images/ps4cima.jpeg", 27);
    loadTextureFromFile("images/pslateral.jpeg", 28);
    loadTextureFromFile("images/macbook.jpg", 29);
	loadTextureFromFile("images/got.jpg", 30);
	loadTextureFromFile("images/got1.jpg", 31);
	loadTextureFromFile("images/got2.jpg", 32);
	loadTextureFromFile("images/tomada3.jpg", 33);
	loadTextureFromFile("images/tomada1.jpg", 34);
    loadTextureFromFile("images/interruptor.jpg", 35);
    loadTextureFromFile("images/ar.jpg", 36);
    loadTextureFromFile("images/ar2.jpg", 37);

}