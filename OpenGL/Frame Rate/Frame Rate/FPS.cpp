//*************************************************************************
//
//  File Name	: FPS
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: April 2010  
//
//  Description	: Measuring the frames per second in order to get an idea 
//				  about the speed of our animation.
//  
//*************************************************************************

//  Standard Input\Output C Library
#include <stdio.h>

//  To use functions with variables arguments
#include <stdarg.h>

//  for malloc
#include <stdlib.h>

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Avoid showing up the console window
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//  Initialization
void init ();

//  Callback functions
void display (void);
void reshape (int w, int h);
void idle (void);

//  Support Functions
void centerOnScreen ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 512;
int window_height = 512;

//  variable representing the window title
char *window_title = "OpenGL FPS";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;

//  printf prints to file. printw prints to window
void printw (float x, float y, float z, char* format, ...);

//  The number of frames
int frameCount = 0;

//  Number of frames per second
float fps = 0;

//  currentTime - previousTime is the time elapsed
//  between every call of the Idle function
int currentTime = 0, previousTime = 0;

//  variables used for rotation
GLfloat rotate_x, rotate_y, rotate_z;

// Methods
void animateObject();
void drawObject();
void calculateFPS();
void drawFPS();

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Set the frame buffer clear color to black. 
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);

    drawObject();
    drawFPS();
	
	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  Draws the object
//-------------------------------------------------------------------------
void drawObject()
{
    //  Draw a wire teapot
	glColor3f (0, 0, 1);
	glutWireTeapot (0.5);
}

//-------------------------------------------------------------------------
//  Draw FPS
//-------------------------------------------------------------------------
void drawFPS()
{
    //  Load the identity matrix so that FPS string being drawn
    //  won't get animates
	glLoadIdentity ();

	//  Print the FPS to the window
	printw (-0.9, -0.9, 0, "FPS: %4.2f", fps);
}

//-------------------------------------------------------------------------
//  This function is called when OpenGL\GLUT is not working on 
//  something else... It is mainly used for animation... 
//
//  It's like the timers but time intervals are dependent on how busy
//  the app is, instead of having a constant value set by the user.
//-------------------------------------------------------------------------
void idle (void)
{
    //  Animate the object
    animateObject();

    //  Calculate FPS
    calculateFPS();

    //  Call display function (draw the current frame)
    glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Animate the object
//-------------------------------------------------------------------------
void animateObject()
{
    //  Rotate the object around the y axis
	rotate_y += 1;

	if (rotate_y > 360)
		rotate_y = 0;

    //  Set rotation
	glRotatef (rotate_x, 1, 0, 0);
	glRotatef (rotate_y, 0, 1, 0);
	glRotatef (rotate_z, 0, 0, 1);
}

//-------------------------------------------------------------------------
// Calculates the frames per second
//-------------------------------------------------------------------------
void calculateFPS()
{
    //  Increase frame count
    frameCount++;

    //  Get the number of milliseconds since glutInit called 
    //  (or first call to glutGet(GLUT ELAPSED TIME)).
    currentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int timeInterval = currentTime - previousTime;

    if(timeInterval > 1000)
    {
        //  calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);

        //  Set time
        previousTime = currentTime;

        //  Reset frame count
        frameCount = 0;
    }
}

//-------------------------------------------------------------------------
//  This function is passed to the glutReshapeFunc and is called 
//  whenever the window is resized.
//-------------------------------------------------------------------------
void reshape (int w, int h)
{
	//  Stay updated with the window width and height
	window_width = w;
	window_height = h;

	//  Reset viewport
	glViewport(0, 0, window_width, window_height);
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
//  Draws a string at the specified coordinates.
//-------------------------------------------------------------------------
void printw (float x, float y, float z, char* format, ...)
{
	va_list args;	//  Variable argument list
	int len;		//	String length
	int i;			//  Iterator
	char * text;	//	Text

	//  Initialize a variable argument list
	va_start(args, format);

	//  Return the number of characters in the string referenced the list of arguments.
	//  _vscprintf doesn't count terminating '\0' (that's why +1)
	len = _vscprintf(format, args) + 1; 

	//  Allocate memory for a string of the specified size
	text = (char *)malloc(len * sizeof(char));

	//  Write formatted output using a pointer to the list of arguments
	vsprintf_s(text, len, format, args);

	//  End using variable argument list 
	va_end(args);

	//  Specify the raster position for pixel operations.
	glRasterPos3f (x, y, z);

	//  Draw the characters one by one
    for (i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(font_style, text[i]);

	//  Free the allocated memory for the string
	free(text);
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
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);

	//  Create window with the specified title
	glutCreateWindow (window_title);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Set OpenGL program initial state.
	init();
	
	// Set the callback functions
	glutDisplayFunc (display);
	glutReshapeFunc  (reshape);
	glutIdleFunc (idle);

	//  Start GLUT event processing loop
	glutMainLoop();
}

