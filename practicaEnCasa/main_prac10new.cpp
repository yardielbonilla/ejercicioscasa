//Semestre 2019 - 2
//Bonilla Galicia Yardiel
//visual 2017
// movimiento un planeta la estrella de  la muerte y naves espaciales

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;

//Animación del coche
float movKit,rota = 0.0;
bool a = true;
bool g_fanimacion = false;


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

	

	//Carga de Figuras
	kit._3dsLoad("TIE-fighter.3ds");
	kit.VertexNormals();

	llanta._3dsLoad("death-star-II.3ds");


	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}



void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);




	glPushMatrix();
	//Para que el coche conserve sus colores
	glDisable(GL_COLOR_MATERIAL);



	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(movKit, movKit, 4);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);  //_WIRED O _POINTS
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-500, 0, 1);
	glTranslatef(movKit, movKit, movKit);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-800, 0, 1);
	glTranslatef(2, movKit, 2);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-10, -400, 1);
	glTranslatef(movKit, movKit, 1);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-100, 400, 400);
	glTranslatef(movKit, movKit, 1);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-10, 400, 1);
	glTranslatef(movKit, movKit, 1);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();
glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-100, 300, 1);
	glTranslatef(movKit, movKit, 1);
	//Pongo aquí la carroceria del carro
	kit.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();
	glRotatef(rota, 0, 1, 0);
	glScalef(0.04, 0.04, 0.04);
	llanta.GLrender(NULL, _SHADED, 1.0);


	glPopMatrix();

	//Para que el comando glColor funcione con iluminacion
	glEnable(GL_COLOR_MATERIAL);

	



	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-12, 12.0, -14.0, (void *)font, "Practica 10");
	pintaTexto(-12, 10.5, -14, (void *)font, "Poner algo en Movimiento");
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;

	if (g_fanimacion )
	{
		rota += 1;
		movKit += 5.0;
		if (movKit == 400)
			movKit =0 ;

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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case ' ':		//Poner algo en movimiento
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
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
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 10"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}