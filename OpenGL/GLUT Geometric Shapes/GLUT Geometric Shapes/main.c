//*************************************************************************
//
//  File Name	: GLUT Geometric Primitives 
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Learn how to render GLUT Geomtric Shapes.
//  
//*************************************************************************

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Standard Input\Output C Library
#include <stdio.h>

//  Include supporting modules
#include "utils.h"
#include "shapes.h"

//  Initialization
void init ();

//  Callback functions
void display (void);
void mouse (int button, int state, int x, int y);
void motion (int x, int y);
void keyboard (unsigned char key, int x, int y);
void special (int key, int x, int y);

//  Support Functions
void centerOnScreen ();
void drawObject ();
void displayHelp();
void setupLighting();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 512;
int window_height = 512;

//  variable representing the window title
char *window_title = "GLUT Geometric Shapes";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Tells whether the shape should be displayed as wireframe or solid
int wireframe = 1;

//  represents the current shape being drawn
int shape = 1;

//  Represents the size of the shape (0.2 --> 1.5)
float shapeSize = 1.25;

//  Color components of the shape
GLubyte R = 255, G = 255, B = 255;

//  Variables for rotation
float rot_x = 0.0f, rot_y = 0.0f, rot_z = 0.0f;

//  previous mouse position
float previousX, previousY, previousZ;

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Set the frame buffer clear color to black. 
	glClearColor (0.0, 0.0, 0.0, 0.0);

	//  Set up lighting
	setupLighting();

	//  display help message to the user
	displayHelp();
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3ub (R, G, B);

	//  Draw object
	drawObject ();

	//  Print R, G, B
	printw (0.1, -0.9, "R: %d, G: %d, B: %d", R, G, B);

	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject ()
{
	//  Push Matrix then pop it so that shape rotation and scaling don't
	//  affect the shape description.
	glPushMatrix();

	// apply rotation
	glRotatef (rot_x, 1.0f, 0.0f, 0.0f);
	glRotatef (rot_y, 0.0f, 1.0f, 0.0f);
	glRotatef (rot_z, 0.0f, 0.0f, 1.0f);

	if (!wireframe)
		glEnable(GL_LIGHTING);
	drawShape(shape - wireframe, shapeSize);
	if (!wireframe)
		glDisable(GL_LIGHTING);

	glPopMatrix();

	drawShapeDescription(shape - wireframe, -0.9, -0.9);
}

//-------------------------------------------------------------------------
//  Sets up lighting.
//-------------------------------------------------------------------------
void setupLighting()
{
	//  Light properties
	float ambientLight[]	= { 0.3f, 0.3f, 0.3f, 1.0f };	//  Ambient
	float diffuseLight[]	= { 0.6f, 0.6f, 0.6, 1.0f };	//  Diffuse
	float specularLight[]	= { 0.1f, 0.1f, 0.1f, 1.0f };	//  Specular
	float position[]		= { -0.3f, 0.4f, 0.6f, 1.0f };	//  Light Position

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	//  Use light 0
	glEnable(GL_LIGHT0);
	 
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	//  Set light properties
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMouseFunc and is called 
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y)
{
	// reset the previousX, previousY, and previousZ to the current position of the mouse
	previousX = x;
	previousY = y;
	previousZ = y;
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMotionFunc and is called 
//  whenever the mouse is dragged.
//-------------------------------------------------------------------------
void motion (int x, int y)
{
	//  Rotate
	rot_x += (y - previousY);
	rot_y += (x - previousX);

	// reset the previousX, previousY, and previousZ to the current position of the mouse
	previousX = (float)x;
	previousY = (float)y;
	previousZ = (float)y;

	//  Call the display function
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		//  User press w (To toggle wireframe)
		case 'w':
		case 'W':
			wireframe = !wireframe;
			break;
		//  Reduce Red color Component
		case 'r':
			R -= 5;

			if (R < 0)
				R = 0;
			break;
		//  Increase red color Component
		case 'R':
			R += 5;

			if (R > 255)
				R = 255;
			break;
		//  Reduce Green color Component
		case 'g':
			G -= 5;

			if (G < 0)
				G = 0;
			break;
		//  Increase green color Component
		case 'G':
			G += 5;

			if (G > 255)
				G = 255;
			break;
		//  Reduce blue color Component
		case 'b':
			B -= 5;

			if (B < 0)
				B = 0;
			break;
		//  Increase blue color Component
		case 'B':
			B += 5;

			if (B > 255)
				B = 255;
			break;
			
		//  User press Escape (to Exit)
		case 27:
			exit (0);
			break;
	}

	//  Call the display function
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  This function is passed to the glutSpecialFunc and is called 
//  whenever the user hits a special key.
//-------------------------------------------------------------------------
void special (int key, int x, int y)
{
	//  To Chage Shape
	if (key == GLUT_KEY_LEFT)
	{
		shape -= 2;

		if (shape < 1)
			shape = SHAPE_COUNT - 1;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		shape += 2;

		if (shape > SHAPE_COUNT - 1)
			shape = 1;
	}

	//  to Chage Size
	else if (key == GLUT_KEY_UP)
	{
		shapeSize += 0.05;

		if (shapeSize > 1.5)
			shapeSize = 1.5;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		shapeSize -= 0.05;

		if (shapeSize < 0.2)
			shapeSize = 0.2;
	}

	//  Call the display function
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  displays help to the user
//-------------------------------------------------------------------------
void displayHelp()
{
	printf("\n***************** \t\tHelp\t\t *****************\n\n");
	
	printf("Keyboard\n\n");

	printf(" %s\t\t%s\n", "Left\\Right", "Change GLUT Shape");
	printf(" %s\t\t%s\n", "Up\\Down", "Change Shape Size");
	printf("\n");
	printf(" %s\t\t%s\n", "r\\R, g\\G, b\\B", "Change red\\green\\blue color components");
	printf(" %s\t\t\t%s\n", "w", "Toggle Solid\\WireFrame");
	printf(" %s\t\t\t%s\n", "h", "Display this help message");

	printf("\n\nMouse\n\n");

	printf(" %s\t\t%s\n", "Any Button", "Rotate GLUT Shape");

	printf("\n\n***************** \t\tHelp\t\t *****************\n\n");
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen ()
{
	window_x = (glutGet (GLUT_SCREEN_WIDTH) - window_width)/2;
	window_y = (glutGet (GLUT_SCREEN_HEIGHT) - window_height)/2;
}

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main (int argc, char **argv)
{
	//  Connect to the windowing system
	glutInit(&argc, argv);

	//  create a window with the specified dimensions
	glutInitWindowSize (window_width, window_height);

	//  Set the window x and y coordinates such that the 
	//  window becomes centered
	centerOnScreen ();

	//  Position Window
	glutInitWindowPosition (window_x, window_y);
	
	//  Set Display mode
	glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);

	//  Create window with the specified title
	glutCreateWindow (window_title);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Set OpenGL program initial state.
	init();
	
	// Set the callback functions
	glutDisplayFunc (display);
	glutMouseFunc (mouse);
	glutMotionFunc (motion);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);

	//  Start GLUT event processing loop
	glutMainLoop();
}

