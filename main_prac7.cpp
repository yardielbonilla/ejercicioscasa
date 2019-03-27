//Bonilla Galicia Yardiel//
//practica  #7
//ejercicio de casa
//visual studio 2017 
// generar el sismtema solar con lunas 
//con materiales y reflejos
#include "Main.h"

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;


GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest


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

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 0.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat mdiffuse[] = { 0.937, 0.286, 0.062, 1.0 };	// Object Color main
GLfloat mspecular[] = { 1.0, 1.0, 0.0, 1.0 };				// Specular color
GLfloat mshininess[] = { 90.0 };

GLfloat vendiffuse[] = { 0.952, 0.635, 0.203, 1.0 };					// Object Color main
GLfloat venspecular[] = { 0.952, 0.635, 0.203, 1.0 };				// Specular color
GLfloat venshininess[] = { 100.0 };

GLfloat EarthDiffuse[] = { 0.0705, 0.403, 0.945, 1.0 };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat ju_ambient[] = { 0.517, 0.419, 0.13337, 1.0 };					// Color background
GLfloat ju_diffuse[] = { 0.517, 0.419, 0.13337, 1.0 };					// Object Color main
GLfloat ju_specular[] = { 0.517, 0.419, 0.13337, 1.0 };				// Specular color
GLfloat ju_shininess[] = { 100.0 };

GLfloat sa_ambient[] = { 0.952, 0.635, 0.203, 1.0 };					// Color background
GLfloat sa_diffuse[] = { 0.952, 0.635, 0.203, 1.0 };					// Object Color main
GLfloat sa_specular[] = { 0.952, 0.635, 0.203, 1.0 };				// Specular color
GLfloat sa_shininess[] = { 100.0 };



void InitGL(GLvoid)     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
	//glEnable(GL_LIGHT0);


}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (positional)
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, LightAngle);			// Position The Light


	glPushMatrix();

	glTranslatef(0.0, 0.0, -5.0);

	glPushMatrix(); //Esfera que representa a nuestra fuente de Luz
					//Este código es para que la fuente de luz gire

	if (positional)
	{
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(2.7, 30, 30);
	if (!light)
	{
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();
	glPopMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -7.0 + camaraZ);
	//sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SunDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SunSpecular);
	glMaterialfv(GL_FRONT, GL_POSITION, SunPosition);
	glutSolidSphere(2.7, 30, 30);
	glPopMatrix();
	//mercurio
	glPushMatrix();
	glRotatef(mercurio, 0, 1, 1);
	glTranslatef(5, 0, 0);
	glColor3f(0.937, 0.286, 0.062);
	glRotatef(mercurio, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mspecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mshininess);
	glutWireSphere(0.5, 20, 20);
	glPopMatrix();
	//venus
	glPushMatrix();
	glRotatef(venus, 0, 1, 1);
	glTranslatef(7, 0, 0);
	glColor3f(1.0, 0.635, 0.203);
	glRotatef(venus, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, vendiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, venspecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, venshininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	//tierra
	glPushMatrix();
	glRotatef(tierra, 0, 1, 1);
	glTranslatef(10, 0, 0);
	glColor3f(0.0705, 0.403, 0.945);
	glRotatef(tierra, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	
	glutWireSphere(0.5, 30, 30);


	glRotatef(luna, 1, 1, 1);//rotacion 
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glColor3f(0.4, 0.4, 0.4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.3, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//marte
	glPushMatrix();
	glRotatef(marte, 0, 1, 1);
	glTranslatef(13, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutWireSphere(0.5, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//jupiter
	glPushMatrix();
	glRotatef(jupiter, 0, 1, 1);
	glTranslatef(16, 0, 0);
	glColor3f(0.517, 0.419, 0.13337);
	glRotatef(jupiter, 8, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, ju_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, ju_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, ju_shininess);
	glutWireSphere(2.0, 30, 30);
	glutWireTorus(0., 3.0, 1.0, 32.0);
	glutWireTorus(0., 4.0, 4.0, 32.0);
	glutWireTorus(0., 4.0, 4.0, 32.0);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//saturno
	glPushMatrix();
	glRotatef(saturno, 0, 1, 1);
	glTranslatef(19, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(saturno, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, sa_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sa_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, sa_shininess);
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 500.0);

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
		light = !light;
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
