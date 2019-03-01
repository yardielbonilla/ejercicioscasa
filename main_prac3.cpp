//Semestre 2017 - 2
//Bonilla Galicia Yardiel//
//Grupo1//
//visual2017//
//imagen en 3d//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(255.0f, 255.0f, 255.0f, 255.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void cafe(void)
{
	GLfloat vertice[8][3] = {
				{1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 0 V0
				{-1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 1 V1
				{-1.0 ,-1.0, -1.0},    //Coordenadas V�rtice 2 V2
				{1.0,-1.0, -1.0},    //Coordenadas V�rtice 3 V3
				{1.0 ,1.0, 1.0},    //Coordenadas V�rtice 4 V4
				{1.0 ,1.0, -1.0},    //Coordenadas V�rtice 5 V5
				{-1.0 ,1.0, -1.0},    //Coordenadas V�rtice 6 V6
				{-1.0 ,1.0, 1.0},    //Coordenadas V�rtice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}
void rosa(void)
{
	GLfloat vertice[8][3] = {
				{1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 0 V0
				{-1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 1 V1
				{-1.0 ,-1.0, -1.0},    //Coordenadas V�rtice 2 V2
				{1.0,-1.0, -1.0},    //Coordenadas V�rtice 3 V3
				{1.0 ,1.0, 1.0},    //Coordenadas V�rtice 4 V4
				{1.0 ,1.0, -1.0},    //Coordenadas V�rtice 5 V5
				{-1.0 ,1.0, -1.0},    //Coordenadas V�rtice 6 V6
				{-1.0 ,1.0, 1.0},    //Coordenadas V�rtice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.2f, 0.3f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(1.2f, 0.4f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(1.2f, 0.4f, 1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.2f, 0.4f, 1.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(1.5f, 0.5f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(1.5f, 0.5f, 1.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void negro(void)
{
	GLfloat vertice[8][3] = {
				{1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 0 V0
				{-1.0 ,-1.0, 1.0},    //Coordenadas V�rtice 1 V1
				{-1.0 ,-1.0, -1.0},    //Coordenadas V�rtice 2 V2
				{1.0,-1.0, -1.0},    //Coordenadas V�rtice 3 V3
				{1.0 ,1.0, 1.0},    //Coordenadas V�rtice 4 V4
				{1.0 ,1.0, -1.0},    //Coordenadas V�rtice 5 V5
				{-1.0 ,1.0, -1.0},    //Coordenadas V�rtice 6 V6
				{-1.0 ,1.0, 1.0},    //Coordenadas V�rtice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner C�digo Aqu�.
	glTranslatef(transX, transY, transZ);


	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	//fila 8
	glTranslatef(-16.8f, 2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();


	//fila 6
	glTranslatef(-12.6f, 2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	//primela fila 4
	glTranslatef(-8.4f, 2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	//ceja cafe inicio
	glTranslatef(-14.6f, -8.4f, 0.0f);
	cafe();

	glTranslatef(6.2f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();


	glTranslatef(6.2f, 0.0f, 0.0f);
	cafe();

	//ceja renglon2
	glTranslatef(-25.0f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(6.2f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(6.2f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	//ceja renglon 3
	glTranslatef(-27.1f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(18.7f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	//renglon 4 ojo 
	glTranslatef(-29.2f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(8.4f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(8.2f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	//ojo renglon 5
	glTranslatef(-31.3f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(8.4f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(8.2f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	//tira de cafe completa 
	glTranslatef(-31.3f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	// ultimos cuatro 
	glTranslatef(-29.4f, -2.1f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();

	glTranslatef(14.7f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	glTranslatef(2.1f, 0.0f, 0.0f);
	cafe();
	//rosa 1 

	glTranslatef(-18.9f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	//rosa 2
	glTranslatef(-12.6f, -2.1f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	//rosa 3
	glTranslatef(-14.7f, -2.1f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	//rosa 4
	glTranslatef(-10.5f, -2.1f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();
	//rosa 5
	glTranslatef(-4.1f, -2.1f, 0.0f);
	rosa();
	glTranslatef(2.1f, 0.0f, 0.0f);
	rosa();

	//negro ceja
	glTranslatef(-10.6f, 21.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	glTranslatef(14.6f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	//negro ceja2

	glTranslatef(-14.7f, -2.1f, 0.0f);
	negro();
	glTranslatef(10.5f, 0.0f, 0.0f);
	negro();

	//negro ceja3

	glTranslatef(-10.5f, -2.1f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	//negro ceja4
	glTranslatef(-10.5f, -2.1f, 0.0f);
	negro();
	glTranslatef(10.5f, 0.0f, 0.0f);
	negro();

	//zapato 1
	
	glTranslatef(-16.8f, -10.5f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	glTranslatef(18.9f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	//zapato 2

	glTranslatef(-25.1f, -2.1f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	glTranslatef(10.5f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	//zapato 3
	glTranslatef(-27.3f, -2.1f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	glTranslatef(6.3f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	//negro 4
	glTranslatef(-25.2f, -2.1f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();

	glTranslatef(6.3f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	glTranslatef(2.1f, 0.0f, 0.0f);
	negro();
	

	
	glutSwapBuffers();
	//glFlush();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transY += 0.2f;
		break;
	case 'e':
	case 'E':
		transY -= 0.2f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}
