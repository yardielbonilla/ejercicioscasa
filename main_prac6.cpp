//Bonilla Galicia Yardiel//
//practica  #6
//ejercicio de casa
//visual studio 2017 
// generar el sismtema solar con lunas 
#include "Main.h"

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna = 0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -7.0 + camaraZ);
	//sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	
	glColor3f(1.0, 1.0, 0.0);	
	glutSolidSphere(2.7, 30, 30);  
	glPopMatrix();
	//mercurio
	glPushMatrix();
	glRotatef(mercurio, 0, 1, 1);
	glTranslatef(5, 0, 0);
	glColor3f(0.937, 0.286, 0.062);
	glRotatef(mercurio, 1, 0, 0);
	glutWireSphere(0.5, 20, 20);
	glPopMatrix();
	//venus
	glPushMatrix();
	glRotatef(venus, 0, 1, 1);
	glTranslatef(7, 0, 0);
	glColor3f(1.0, 0.635, 0.203);
	glRotatef(venus, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	//tierra
	glPushMatrix();
	glRotatef(tierra, 0, 1, 1);
	glTranslatef(10, 0, 0);
	glColor3f(0.0705, 0.403, 0.945);
	glRotatef(tierra, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);


	glRotatef(luna, 1, 1, 1);//rotacion 
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glColor3f(0.4, 0.4, 0.4);
	glutWireSphere(0.3, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//marte
	glPushMatrix();
	glRotatef(marte, 0, 1, 1);
	glTranslatef(13, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//jupiter
	glPushMatrix();
	glRotatef(jupiter, 0, 1, 1);
	glTranslatef(16, 0, 0);
	glColor3f(0.6, 0.3, 0.1);
	glRotatef(jupiter, 8, 0, 0);
	glutWireSphere(2.0, 30, 30);
	glutWireTorus(0., 3.0, 1.0, 32.0);
	glutWireTorus(0., 4.0, 4.0, 32.0);
	glutWireTorus(0., 4.0, 4.0, 32.0);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//saturno
	glPushMatrix();
	glRotatef(saturno, 0, 1, 1);
	glTranslatef(19, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(saturno, 1, 0, 0);
	glutWireSphere(1.0, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//urano
	glPushMatrix();
	glRotatef(urano, 0, 1, 1);
	glTranslatef(21, 0, 0);
	glColor3f(0.1, 0.9, 0.7);
	glRotatef(urano, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//neptuno
	glPushMatrix();
	glRotatef(neptuno, 0, 1, 1);
	glTranslatef(24, 0, 0);
	glColor3f(0.15, 0.15, 0.8);
	glRotatef(neptuno, 1, 0, 0);
	glutWireSphere(0.5, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.4, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glutWireSphere(0.4, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 9) % 360;
		venus = (venus - 7) % 360;
		tierra = (tierra - 6) % 360;
		marte = (marte - 5) % 360;
		jupiter = (jupiter - 4) % 360;
		saturno = (saturno - 3) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 1) % 360;
		luna = (luna - 8) % 360;


		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        
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

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
