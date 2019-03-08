//Semestre 2019 - 2
//Bonilla Galicia Yardiel
//visual 2017
//practica4 ejercicio de casa 
//hacer un humano de cubos con colores especificos en brazo,pierna,zapatos,cabeza 
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angY = 0.0;
float tecla = 0.0;


void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{2.5 ,-2.5, 2.5},    //Coordenadas Vértice 0 V0
				{-2.5 ,-2.5, 2.5},    //Coordenadas Vértice 1 V1
				{-2.5 ,-2.5, -2.5},    //Coordenadas Vértice 2 V2
				{2.5 ,-2.5, -2.5},    //Coordenadas Vértice 3 V3
				{2.5 ,2.5, 2.5},    //Coordenadas Vértice 4 V4
				{2.5 ,2.5, -2.5},    //Coordenadas Vértice 5 V5
				{-2.5 ,2.5, -2.5},    //Coordenadas Vértice 6 V6
				{-2.5 ,2.5, 2.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, transZ);
	glTranslatef(transX, 0.0f, 0.0f);
	glRotatef(angY, 0, 1, 0);
	glRotatef(tecla, 1, 0, 0);
	//Poner Código Aquí.



	glRotatef(90, 0, 1, 0);
	prisma();

	glScalef(.4, .4, .4);
	glTranslatef(-0.0f,-8.5f, -3.0f);
	glRotatef(-90, 0, 1, 0);
	prisma();

	glTranslatef(-0.0f, -5.0f, -0.0f);
	glRotatef(-90, 1, 0, 0);
	prisma();

	glTranslatef(-0.0f, -0.0f, -5.0f);
	glRotatef(-90, 0, 0, 1);
	prisma();

	//pierna derecha 
	glTranslatef(-0.0f, 6.0f, 10.0f);
	glRotatef(-90, 0, 0, 1);
	prisma();
	glTranslatef(-0.0f, 0.0f, -5.0f);
	prisma();
	glTranslatef(-0.0f, 0.0f, -5.0f);
	prisma();

	//brazo derecho
	glScalef(.7, .7, .7);
	glTranslatef(-7.0f, 0.0f, 32.0f);
	glRotatef(-180, 0, 0, 1);
	prisma();

	glTranslatef(5.0f, 0.0f, 0.0f);
	glRotatef(-90, 0, 0, 1);
	prisma();

	glTranslatef(0.0f, 5.0f, 0.0f);
	glRotatef(90, 0, 1, 0);
	prisma();
	//mano
	glScalef(1.3, 1.3, 1.3);
	glTranslatef(0.0f, 4.0f, 0.0f);
	glRotatef(90, 1, 0, 0);
	prisma();
	glRotatef(-90, 1, 0, 0);

	//brazo izquiedo
	glScalef(.8, .8, .8);
	glTranslatef(0.0f, -35.0f, 0.0f);
	prisma();
	glTranslatef(0.0f, -5.0f, 0.0f);
	prisma();
	glTranslatef(0.0f, -5.0f, 0.0f);
	prisma();

	//mano 
	glScalef(1.3, 1.3, 1.3);
	glTranslatef(0.0f, -4.0f, 0.0f);
	prisma();

	//cabeza/cuello 
	glTranslatef(-6.0f, 19.0f, 0.0f);
	glRotatef(90, 1, 0, 0);
	prisma();

	glScalef(.8, .8, .8);
	glTranslatef(2.0f, -0.0f, 0.0f);
	glRotatef(90, 1, 0, 0);
	prisma();

	//zapatos

	glScalef(1.3,1.3,1.3);
	glTranslatef(32.0f, -3.0f, 0.0f);
	prisma();

	glTranslatef(0.0f, -3.0f, 0.0f);
	prisma();

	glTranslatef(0.0f, 9.0f, 0.0f);
	prisma();
	glTranslatef(0.0f, 3.5f, 0.0f);
	prisma();
	glutSwapBuffers();
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.3f;
		break;
	case 's':
	case 'S':
		transZ -= 0.3f;
		break;
	case 'a':
	case 'A':
		transX -= 0.3f;
		break;
	case 'd':
	case 'D':
		transX += 0.3f;
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
	case GLUT_KEY_UP:	// Presionamos tecla ARRIBA...
		tecla += 1.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		tecla -= 1.0f;
		break;
	case GLUT_KEY_LEFT:
		angY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angY -= 1.0f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}