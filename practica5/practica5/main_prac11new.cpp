//Bonilla Galicia Yardiel
//visual 2017 
// movimiento de mmano piedra,papel,tijeras 
#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotHomIz = 0;
float giroMonito = 0;
float movBrazoDer = 0.0;
float angCodo = 0.0;
float angHombro = 0.0;
float angMano = 0.0;
float angPulg = 0.0;
float pulg = 0.0;
float dedos = 0.0;
float dedos1 = 0.0;
float dedos2 = 0.0;
float tije = 0.0;
float tije2 = 0.0;


#define MAX_FRAMES 20  // Cuantos cuadros capturamos por segundo
int i_max_steps = 200;
int i_curr_steps = 0;
typedef struct _frame  // Debemos declarar la variable y otra que es su incremento
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;  //incremento de torRodIzq
	float giroMonito;
	float giroMonitoInc;
	float movBrazoDer;
	float movBrazoDerInc;
	float rotHomIz;
	float rotHomIzInc;
	float transZ = -0.0f;
	float transX = 0.0f;
	float angleX = 0.0f;
	float angleY = 0.0f;
	int screenW = 0.0;
	int screenH = 0.0;
	float pulg = 0.0;
	float dedos = 0.0;
	float dedos1 = 0.0;
	float dedos2 = 0.0;
	float pulgInc = 0.0;
	float dedosInc = 0.0;
	float dedos1Inc = 0.0;
	float dedos2Inc = 0.0;
	float tije = 0.0;
	float tije2 = 0.0;
	float tijeInc = 0.0;
	float tije2Inc = 0.0;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 20;			//introducir datos
bool play = false;  //Play en falso
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat ManoDiffuse[] = { 1.0, 0.4, 0.250, 1.0f };			// Jupiter
GLfloat ManoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ManoShininess[] = { 50.0 };

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CTexture tree;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;

//Animación del coche
float angRot = 0.0;
float movKitX = 0.0;
float movKitZ = 0.0;
float rotKit = 0.0;
float rotTires = 0.0;
bool g_fanimacion = false;
bool g_avanza = false;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;

int timer = 0;




GLuint createDL()
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL, GL_COMPILE);
	// call the function that contains 
	// the rendering commands
	;
	//monito();
// endList
	glEndList();

	return(ciudadDL);
}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
	//glColor4f(1.0f, 1.0f, 1.0f, 0.5); 

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	//text2.LoadBMP("hulkcara.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	tree.LoadTGA("Tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	kit._3dsLoad("kitt.3ds");
	//kit.VertexNormals();

	llanta._3dsLoad("k_rueda.3ds");


	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	/*for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
		KeyFrame[i].giroBrazo =0;
		KeyFrame[i].giroBrazoInc = 0;
	}*/

	//Index empezaba en 5 porque del 1 al 4 ya estan creados, siempre hara esta animacion.

	KeyFrame[0].pulg = 0;
	KeyFrame[0].dedos = 0;
	KeyFrame[0].dedos1 = 0;
	KeyFrame[0].dedos2 = 0;
	KeyFrame[0].tije = 0;
	KeyFrame[0].tije2 = 0;


	KeyFrame[1].pulg = -3;
	KeyFrame[1].dedos = 0;
	KeyFrame[1].dedos1 = 8.8;
	KeyFrame[1].dedos2 = 5.99;
	KeyFrame[1].tije = 8.8;
	KeyFrame[1].tije2 = 5.99;



	KeyFrame[2].pulg = -3;
	KeyFrame[2].dedos = 0;
	KeyFrame[2].dedos1 = 8.8;
	KeyFrame[2].dedos2 = 5.99;
	KeyFrame[2].tije = 8.8;
	KeyFrame[2].tije2 = 5.99;

	KeyFrame[3].pulg = -3;
	KeyFrame[3].dedos = 0;
	KeyFrame[3].dedos1 = 8.8;
	KeyFrame[3].dedos2 = 5.99;
	KeyFrame[3].tije = 0.0;
	KeyFrame[3].tije2 = 0.0;



	KeyFrame[4].pulg = -3;
	KeyFrame[4].dedos = 0;
	KeyFrame[4].dedos1 = 8.8;
	KeyFrame[4].dedos2 = 5.99;
	KeyFrame[4].tije = 0.0;
	KeyFrame[4].tije2 = 0.0;

	KeyFrame[5].pulg = -3;
	KeyFrame[5].dedos = 0;
	KeyFrame[5].dedos1 = 8.8;
	KeyFrame[5].dedos2 = 5.99;
	KeyFrame[5].tije = 0.0;
	KeyFrame[5].tije2 = 0.0;


	KeyFrame[6].pulg = 0;
	KeyFrame[6].dedos = 0;
	KeyFrame[6].dedos1 = 0;
	KeyFrame[6].dedos2 = 0;
	KeyFrame[6].tije = 0.0;
	KeyFrame[6].tije2 = 0.0;

	KeyFrame[7].pulg = 0.0;
	KeyFrame[7].dedos = 0;
	KeyFrame[7].dedos1 = 0.0;
	KeyFrame[7].dedos2 = 0.0;
	KeyFrame[7].tije = 0.0;
	KeyFrame[7].tije2 = 0.0;

	KeyFrame[8].pulg = 0.0;
	KeyFrame[8].dedos = 3;
	KeyFrame[8].dedos1 = 8.8;
	KeyFrame[8].dedos2 = 5.9;
	KeyFrame[8].tije = 8.8;
	KeyFrame[8].tije2 = 5.9;

	KeyFrame[9].pulg = 0.0;
	KeyFrame[9].dedos = 3;
	KeyFrame[9].dedos1 = 8.8;
	KeyFrame[9].dedos2 = 5.9;
	KeyFrame[9].tije = 8.8;
	KeyFrame[9].tije2 = 5.9;

	KeyFrame[10].pulg = 0.0;
	KeyFrame[10].dedos = 3;
	KeyFrame[10].dedos1 = 8.8;
	KeyFrame[10].dedos2 = 5.9;
	KeyFrame[10].tije = 8.8;
	KeyFrame[10].tije2 = 5.9;

	KeyFrame[11].pulg = 0.0;
	KeyFrame[11].dedos = 3;
	KeyFrame[11].dedos1 = 8.8;
	KeyFrame[11].dedos2 = 5.9;
	KeyFrame[11].tije = 8.8;
	KeyFrame[11].tije2 = 5.9;

	KeyFrame[12].pulg = 0.0;
	KeyFrame[12].dedos = 3;
	KeyFrame[12].dedos1 = 8.8;
	KeyFrame[12].dedos2 = 5.9;
	KeyFrame[12].tije = 8.8;
	KeyFrame[12].tije2 = 5.9;

	KeyFrame[13].pulg = 0.0;
	KeyFrame[13].dedos = 3;
	KeyFrame[13].dedos1 = 8.8;
	KeyFrame[13].dedos2 = 5.9;
	KeyFrame[13].tije = 8.8;
	KeyFrame[13].tije2 = 5.9;

	KeyFrame[14].pulg = 0.0;
	KeyFrame[14].dedos = 3;
	KeyFrame[14].dedos1 = 8.8;
	KeyFrame[14].dedos2 = 5.9;
	KeyFrame[14].tije = 8.8;
	KeyFrame[14].tije2 = 5.9;
	//NEW//////////////////NEW//////////////////NEW//////////////////   // Despues de aqui agregamos los keyframes que queramos cada que se
																		//ejecuta el programa.
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

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, ManoDiffuse);

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
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

	//muñeca
	glPushMatrix();
	glTranslatef(8.25, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(0.72, 0.99, 0.89);
	prisma();
	glPopMatrix();
	//mano
	//glRotatef(angMano, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.50, 0, 0);
	glScalef(2, 2, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	//pulgar1

	glPushMatrix();

	glTranslatef(10.25, 1.25, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.05, 0.725, 0.15);
	prisma();
	glPopMatrix();
	//pulgar2

	glPushMatrix();
	glRotatef(pulg, 1.0, 0.0, 1.0);
	glTranslatef(10.25, 1.75, 0);
	glScalef(0.4, 0.75, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice1

	glRotatef(dedos, 1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(10.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//indice2

	glPushMatrix();
	glRotatef(tije, 1.0, 1.0, 0.0);

	glTranslatef(11.25, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//indice3
	glPushMatrix();
	glRotatef(tije, 1.0, 1.0, 0.0);
	glRotatef(tije2, 1.0, 1.0, 0.0);

	glTranslatef(11.75, 0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//dedo medio
	glPushMatrix();
	glTranslatef(10.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio2

	glPushMatrix();
	glRotatef(tije, 1.0, 1.0, 0.0);

	glTranslatef(11.25, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//dedo medio 3
	glPushMatrix();
	glRotatef(tije, 1.0, 1.0, 0.0);
	glRotatef(tije2, 1.0, 1.0, 0.0);

	glTranslatef(11.75, 0.40, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//anular1
	glPushMatrix();
	glTranslatef(10.75, -0.2, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//anular2
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//anular3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.20, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	//meñique1
	glPushMatrix();
	glTranslatef(10.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.25, 0.45, 0.65);
	prisma();
	glPopMatrix();
	//meñique2
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glTranslatef(11.25, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.15, 0.35, 0.65);
	prisma();
	glPopMatrix();
	//meñique3
	glPushMatrix();
	glRotatef(dedos1, 1.0, 1.0, 0.0);
	glRotatef(dedos2, 1.0, 1.0, 0.0);
	glTranslatef(11.75, -0.90, 0);
	glScalef(0.5, 0.2, 2);
	glColor3f(0.80, 0.45, 0.85);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Practica Mano");
	pintaTexto(-11, 8.5, -14, (void *)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	fig3.text_izq -= 0.01;
	fig3.text_der -= 0.01;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;

	//Movimiento del coche
	if (g_fanimacion)
	{
		if (g_avanza)
		{
			movKitZ += 1.0;
			rotTires -= 10;
			if (movKitZ > 130)
				g_avanza = false;
		}
		else
		{
			movKitZ -= 1.0;
			rotTires += 10;
			if (movKitZ < 0)
				g_avanza = true;
		}
	}



	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation

				//Interpolaciones incremento.
				//el incremento es la distancia entre dos cuadros, el 2 - 1 y se divide entre el 90(i_max_steps)   Se hace la interpolacion


				KeyFrame[playIndex].pulgInc = (KeyFrame[playIndex + 1].pulg - KeyFrame[playIndex].pulg) / i_max_steps;
				KeyFrame[playIndex].dedosInc = (KeyFrame[playIndex + 1].dedos - KeyFrame[playIndex].dedos) / i_max_steps;
				KeyFrame[playIndex].dedos1Inc = (KeyFrame[playIndex + 1].dedos1 - KeyFrame[playIndex].dedos1) / i_max_steps;
				KeyFrame[playIndex].dedos2Inc = (KeyFrame[playIndex + 1].dedos2 - KeyFrame[playIndex].dedos2) / i_max_steps;

				KeyFrame[playIndex].tijeInc = (KeyFrame[playIndex + 1].tije - KeyFrame[playIndex].tije) / i_max_steps;
				KeyFrame[playIndex].tije2Inc = (KeyFrame[playIndex + 1].tije2 - KeyFrame[playIndex].tije2) / i_max_steps;

			}
		}
		else
		{	//Draw information


			pulg += KeyFrame[playIndex].pulgInc;
			dedos += KeyFrame[playIndex].dedosInc;
			dedos1 += KeyFrame[playIndex].dedos1Inc;
			dedos2 += KeyFrame[playIndex].dedos2Inc;

			tije += KeyFrame[playIndex].tijeInc;
			tije2 += KeyFrame[playIndex].tije2Inc;

			i_curr_steps++;
		}

	}

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1) {
		sprintf(s, "FPS:%4.2f", frame*10.0 / (time - timebase));
		timebase = time;
		frame = 0;
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

	case 'O':		//  
	case 'o':
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
		circuito = false;
		break;

	case 'i':		//  
	case 'I':
		circuito ^= true; //Activamos/desactivamos la animacíon
		g_fanimacion = false;
		break;

	case 'k':		//
	case 'K':


		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex > 1))
		{

			pulg = KeyFrame[0].pulg;
			dedos = KeyFrame[0].dedos;
			dedos1 = KeyFrame[0].dedos1;
			dedos2 = KeyFrame[0].dedos2;
			tije = KeyFrame[0].tije;
			tije2 = KeyFrame[0].tije2;

			//First Interpolation


			KeyFrame[playIndex].pulgInc = (KeyFrame[playIndex + 1].pulg - KeyFrame[playIndex].pulg) / i_max_steps;
			KeyFrame[playIndex].dedosInc = (KeyFrame[playIndex + 1].dedos - KeyFrame[playIndex].dedos) / i_max_steps;
			KeyFrame[playIndex].dedos1Inc = (KeyFrame[playIndex + 1].dedos1 - KeyFrame[playIndex].dedos1) / i_max_steps;
			KeyFrame[playIndex].dedos2Inc = (KeyFrame[playIndex + 1].dedos2 - KeyFrame[playIndex].dedos1) / i_max_steps;

			KeyFrame[playIndex].tijeInc = (KeyFrame[playIndex + 1].tije - KeyFrame[playIndex].tije) / i_max_steps;
			KeyFrame[playIndex].tije2Inc = (KeyFrame[playIndex + 1].tije2 - KeyFrame[playIndex].tije2) / i_max_steps;

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


		break;
	case 'b':
		angPulg += 0.2f;
		pulg = 0.2f;
		printf("%f \n", angPulg);
		if (angPulg >= 0) {
			angPulg = 0;                  //movimiento del pulgar
		}

		printf(" pulgar %f \n", angPulg);
		break;
	case 'B':
		angPulg -= 0.2f;
		pulg = 0.2f;
		printf(" pulgar %f \n", angPulg);
		if (angPulg <= -4) {
			angPulg = -4;
		}

		break;
	case 'v':
		dedos += 0.2f;
		printf("articulacion 1 %f \n", dedos);
		if (dedos >= 6) {
			dedos = 6;                  //movimiento del hombro
		}

		printf("articulacion 1 %f \n", dedos);
		break;
	case 'V':
		dedos -= 0.2f;
		printf("%f \n", dedos);
		if (dedos <= 0) {
			dedos = 0;
		}

		break;
		break;
	case 'c':
		dedos1 += 0.2f;
		printf("articulacion 2%f \n", dedos1);
		if (dedos1 >= 1) {
			dedos1 = 1;                  //movimiento del dedos
		}

		printf("%f \n", dedos1);
		break;
	case 'C':
		dedos1 -= 0.2f;
		printf("articualcion 2 %f \n", dedos1);
		if (dedos1 <= 0) {
			dedos1 = 0;
		}

		break;
	case 'x':
		dedos2 += 0.2f;
		printf("articualcion 3 %f \n", dedos2);
		if (dedos2 >= 1) {
			dedos2 = 1;                  //movimiento del dedos
		}

		printf("articulacion 3 %f \n", dedos2);
		break;
	case 'X':
		dedos2 -= 0.2f;
		printf("articulacion 3 %f \n", dedos2);
		if (dedos2 <= 0) {
			dedos2 = 0;
		}

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
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
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
	glutCreateWindow("Mano"); // Nombre de la Ventana
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