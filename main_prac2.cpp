//
//Bonilla Galicia Yardiel//
//practica  #2 ejercicio de casa
//visual studio 2017 
// generar imagen
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f);	
	// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
				

	

	glBegin(GL_POLYGON);
	glColor3f(255.0f, 255.0f, 255.0f);

	glVertex3f(2.0f, -16.0f, -0.2f);
	glVertex3f(2.0f, -17.0f, -0.2f);
	glVertex3f(0.0f, -17.0f, -0.2f);
	
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(2.0f, -15.9f, -0.2f);
	glVertex3f(1.5f, -15.9f, -0.2f);
	glVertex3f(1.5f, -1.0f, -0.2f);
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(2.0f, -1.0f, -0.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex3f(0.5f, -1.0f, -0.2f);
	glVertex3f(4.0f, -5.0f, -0.2f);
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(3.5f, -5.5f, -0.2f);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -1.0f, -0.2f);
	glEnd();
	glBegin(GL_POLYGON);


	glVertex3f(4.0f, -5.0f, -0.2f);
	glVertex3f(4.5f, -5.0f, -0.2f);
	glVertex3f(0.5f, -10.0f, -0.2f);
	glVertex3f(-0.5f, -9.5f, -0.2f);
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(2.0f, 3.0f, -0.2f);
	glVertex3f(2.0f, -0.9f, -0.2f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, 3.0f, -0.2f);
	glColor3f(2.0f, 0.5f, 1.0f);
	glEnd();

	glFlush();
	glBegin(GL_POLYGON);

	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(6.5f, 3.5f, -0.2f);
	glVertex3f(11.5f, 3.5f, -0.2f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, 7.0f, -0.2f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(1.5f, 3.0f, -0.2f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, -0.9f, -0.2f);
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-8.0f, 3.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.7f, 7.0f, -0.2f);
	glVertex3f(5.95f, 3.5f, -0.2f);
	glVertex3f(0.5f, 3.5f, -0.2f);
	glVertex3f(-1.5f, 7.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 7.0f, -0.2f);
	glVertex3f(-0.0f, 3.5f, -0.2f);
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(-8.5f, 3.5f, -0.2f);
	glVertex3f(-6.5f, 7.0f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(5.0f, 7.5f, -0.2f);
	glVertex3f(-1.0f, 7.5f, -0.2f);
	glVertex3f(2.0f, 10.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.5f, 10.0f, -0.2f);
	glVertex3f(-4.0f, 10.0f, -0.2f);
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(-1.5f, 7.5f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 7.5f, -0.2f);
	glVertex3f(-6.0f, 7.5f, -0.2f);
	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(-5.0f, 10.0f, -0.2f);
	glVertex3f(-4.5f, 10.0f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-8.0f, 6.0f, -0.2f);
	glVertex3f(-9.5f, 8.5f, -0.2f);
	glVertex3f(-8.5f, 4.5f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);

	glBegin(GL_POLYGON);
	glVertex3f(-10.0f, 8.0f, -0.2f);
	glVertex3f(-11.5f, 7.5f, -0.2f);
	glVertex3f(-8.5f, 4.0f, -0.2f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-11.5f, 8.0f, -0.2f);
	glVertex3f(-11.5f, 11.0f, -0.2f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, 11.0f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);
	glBegin(GL_POLYGON);
	
	glVertex3f(-11.5f, 11.5f, -0.2f);
	glVertex3f(-10.0f, 11.5f, -0.2f);
	glVertex3f(-11.5f, 15.0f, -0.2f);
	glEnd();
	glBegin(GL_POLYGON);

	glVertex3f(-10.5f, 14.0f, -0.2f);
	glVertex3f(-11.5f, 16.0f, -0.2f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.5f, 16.0f, -0.2f);
	glEnd();
	glColor3f(2.0f, 0.5f, 1.0f);

	glBegin(GL_POLYGON);
	
	glVertex3f(-11.5f, 16.2f, -0.2f);
	glVertex3f(-9.5f, 16.2f, -0.2f);
	glVertex3f(-10.5f, 18.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-11.0f, 18.0f, -0.2f);
	glVertex3f(-13.0f, 18.0f, -0.2f);
	glVertex3f(-12.0f, 16.5f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.9f, 17.8f, -0.2f);
	glVertex3f(-12.5f, 15.0f, -0.2f);
	glVertex3f(-11.5f, 15.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-13.2f, 18.0f, -0.2f);
	glVertex3f(-15.0f, 16.5f, -0.2f);

	glColor3f(255.0f, 255.0f, 255.0f);
	glVertex3f(-13.0f, 15.5f, -0.2f);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(-15.0f, 16.0f, -0.2f);
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-17.0f, 15.0f, -0.2f);
	glVertex3f(-16.0f, 14.5f, -0.2f);
	glVertex3f(-13.0f, 15.0f, -0.2f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-17.2f, 14.5f, -0.2f);
	glVertex3f(-16.0f, 14.0f, -0.2f);
	glVertex3f(-16.0f, 12.5f, -0.2f);
	glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-30, 30, -30, 30, 0.1, 2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut funci�n de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

