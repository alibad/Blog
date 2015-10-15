//*************************************************************************
//
//  File Name	: Shapes
//  Author		: Ali BaderEddin
//  Created		: December 2003
//  Modified	: March 2010  
//
//  Description	: Constructing shapes from geometric primitives...
//  
//*************************************************************************

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Standard Input\Output C Library
#include <stdio.h>

//  for sin and cos
#include <math.h>       

//  for printf
#include <stdio.h>		

//  to support variable number of arguments (printw func)
#include <stdarg.h>     

//  Initialization
void init ();

//  Callback functions
void display (void);
void reshape (int w, int h);
void mouse (int button, int state, int x, int y);
void keyboard (unsigned char key, int x, int y);
void special (int key, int x, int y);

//  Support Functions
void centerOnScreen ();
void displayHelp ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 256;
int window_height = 256;

//  variable representing the window title
char *window_title = "Shapes";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Represents the default color
float defaultColor [] = {1.0f, 1.0f, 1.0f};

//  Just a pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_10;

//  draws a string (Just as intelligent as printf)
//  If you're new to functions with varaible arguments
//  then check the <stdarg.h> in some C book or
//  type (man stdarg) on Unix terminal. 
void printw (float x, float y, float z, char* format, ...);

/*****					Shapes Prototypes and Declarations				****/

#define PI		3.141592654
#define PI_2	PI * 2

typedef enum Shape
{
	DRAW_OVAL,
	FILL_OVAL,
	DRAW_ARC,
	FILL_ARC
} Shape;

//  Represents the current shape
Shape currentShape = DRAW_OVAL;

//  Represnets the number of diffrent shapes
int shapeNum = sizeof (Shape);

//  An array representing the number of segments for each shape
int segments[sizeof (Shape)];

//  An array representing the number of segments for each shape
float width[sizeof (Shape)];

//  An array representing the number of segments for each shape
float height[sizeof (Shape)];

//  tells whether the shape is colored or not
float color[sizeof (Shape)];

//  represents start and arc angles for fill and wire arcs
float startAngleW, arcAngleW;
float startAngleF, arcAngleF;

//  Tells whether to show the bounding rectangle or not
int showBoundingRect = 0;

//  Java Graphics methods
void drawOval (float x_center, float y_center, float w, float h, int n);
void fillOval (float x_center, float y_center, float w, float h, int n);
void drawArc  (float x_center, float y_center, float w, float h, float startAngle, float arcAngle, int n);
void fillArc  (float x_center, float y_center, float w, float h, float startAngle, float arcAngle, int n);

//  draw the current shape
void drawShape ();

//  draw a string saying what is the current shape
void drawShapeStr ();

//  Draw a string saying how many segments represent the shape
void drawSegmentCount();

//  draws the rectangle bounding the shape
void drawBoundingRect (float w, float h);

//  Sets the initial values of shapes's attributes
void initShapes ();

/*****						 End of Shapes Prototypes					****/

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Set the frame buffer clear color to black.
	glClearColor (0.0, 0.0, 0.0, 0.0);

	//  Initialize shapes' attributes
	initShapes ();

	//  Display Help Message
	displayHelp ();
}

//-------------------------------------------------------------------------
//  Initialize the shapes variables and arrays
//-------------------------------------------------------------------------
void initShapes ()
{
	int i;
	
	//  Set the default width to 1.6, default height to 1.6, segments to 20
	//  and uncolored
	for (i = 0; i < shapeNum; i++)
	{
		width[i] = 1.6;
		height[i] = 1.6;
		segments[i] = 20;
		color[i] = 0;
	}

	//  Set the start and arc angles
	startAngleW = PI / 4;
	arcAngleW = PI /2;

	startAngleF = PI/9;
	arcAngleF = PI;
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	
	//  Set the default color
	glColor3fv (defaultColor);
	
	//  draw the bounding rect for the current shape
	if (showBoundingRect)
		drawBoundingRect (width[currentShape], height[currentShape]);

	//  draw the current shape
	drawShape ();
	
	//  Set the default color
	glColor3fv (defaultColor);

	//  draw a string saying what is the current shape
	drawShapeStr ();

	//  Draw a string saying how many segments represent the shape
	drawSegmentCount();

	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  draws the rectangle bounding the shape
//-------------------------------------------------------------------------
void drawBoundingRect (float w, float h)
{
	glBegin (GL_LINE_LOOP);

		glVertex2f (-w/2, -h/2);
		glVertex2f (w/2, -h/2);
		glVertex2f (w/2, h/2);
		glVertex2f (-w/2, h/2);

	glEnd ();
}

//-------------------------------------------------------------------------
//  draw the current shape
//-------------------------------------------------------------------------
void drawShape ()
{
	switch (currentShape)
	{
		case DRAW_OVAL:

			drawOval (0, 0, width[currentShape], height[currentShape], 
						segments[currentShape]);

			break;
		case FILL_OVAL:

			fillOval (0, 0, width[currentShape], height[currentShape], 
						segments[currentShape]);

			break;
		case DRAW_ARC:

			drawArc (0, 0, width[currentShape], height[currentShape], 
						startAngleW, arcAngleW, segments[currentShape]);

			break;
		case FILL_ARC:

			fillArc (0, 0, width[currentShape], height[currentShape], 
						startAngleF, arcAngleF, segments[currentShape]);

			break;
	}
}

//-------------------------------------------------------------------------
//  draw a string saying what is the current shape
//-------------------------------------------------------------------------  
void drawShapeStr ()
{
	switch (currentShape)
	{
		case DRAW_OVAL:
			printw (-0.8f, -0.9f, 0, "Shape: %s", "drawOval");
			break;
		case FILL_OVAL:
			printw (-0.8f, -0.9f, 0, "Shape: %s", "fillOval");
			break;
		case DRAW_ARC:
			printw (-0.8f, -0.9f, 0, "Shape: %s", "drawArc");
			break;
		case FILL_ARC:
			printw (-0.8f, -0.9f, 0, "Shape: %s", "fillArc");
			break;
	}
}

//-------------------------------------------------------------------------
//  draws the number of segments used to represent the shape
//-------------------------------------------------------------------------  
void drawSegmentCount()
{
	printw (0.4f, -0.9f, 0, "Segments: %d", segments[currentShape]);
}

//-------------------------------------------------------------------------
//  Draws an oval centered at (x_center, y_center)
//
//	The oval is bound inside a rectangle whose width is w
//	and height is h.
//
//	n represents the number of line segments used to draw the oval.
//-------------------------------------------------------------------------
void drawOval (float x_center, float y_center, float w, float h, int n)
{
	float theta, angle_increment;
	float x, y;
	
	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;

	glPushMatrix ();
	
	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  draw the oval using line segments
	glBegin (GL_LINE_LOOP);
	
	for (theta = 0.0f; theta < PI_2; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);
		
		//  Color the vertices!
		if (color[currentShape])
			glColor3f (x, y, x*y);

		glVertex2f (x, y);
	}

	glEnd ();

	glPopMatrix ();
}

//-------------------------------------------------------------------------
//  Fills an oval centered at (x_center, y_center)
//
//	The oval is bound inside a rectangle whose width is w
//	and height is h.
//
//	n represents the number of line segments used to fill the oval.
//-------------------------------------------------------------------------
void fillOval (float x_center, float y_center, float w, float h, int n)
{
	float theta, angle_increment;
	float x, y;
	
	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;

	glPushMatrix ();

	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  draw the oval using triangle fan
	glBegin (GL_TRIANGLE_FAN);

	//  specify the center
	glVertex2f (0.0f, 0.0f);
	
	for (theta = 0.0f; theta - PI_2 < 0.001; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);
		
		//  Color the vertices!
		if (color[currentShape])
			glColor3f (x, y, x*y);
			
		glVertex2f (x, y);
	}

	glEnd ();

	glPopMatrix ();
}

//-------------------------------------------------------------------------
//  Draws an arc centered at (x_center, y_center)
//
//	The arc is bound inside a rectangle whose width is w
//	and height is h.
//
//	The arc is drawn between the angles startAngle and (startAngle + arcAngle)
//
//	n represents the number of line segments used to draw the arc.
//-------------------------------------------------------------------------
void drawArc  (float x_center, float y_center, float w, float h, float startAngle, float arcAngle, int n)
{
	float theta, angle_increment;
	float x, y;
	
	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;

	glPushMatrix ();
	
	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  draw the oval using line segments
	glBegin (GL_LINE_STRIP);
	
	for (theta = startAngle; theta - (startAngle + arcAngle) < 0.001; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);
		
		//  Color the vertices!
		if (color[currentShape])
			glColor3f (x, y, x*y);

		glVertex2f (x, y);
	}

	glEnd ();

	glPopMatrix ();
}

//-------------------------------------------------------------------------
//  Fills an arc centered at (x_center, y_center)
//
//	The arc is bound inside a rectangle whose width is w
//	and height is h.
//
//	The arc is drawn between the angles startAngle and (startAngle + arcAngle)
//
//	n represents the number of line segments used to fill the arc.
//-------------------------------------------------------------------------
void fillArc  (float x_center, float y_center, float w, float h, float startAngle, float arcAngle, int n)
{
	float theta, angle_increment;
	float x, y;
	
	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;
	
	//  specify the center
	glVertex2f (0.0f, 0.0f);

	glPushMatrix ();
	
	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  fill the oval using triangle fan
	glBegin (GL_TRIANGLE_FAN);

	glVertex2f (0.0f, 0.0f);
	
	for (theta = startAngle; theta - (startAngle + arcAngle) < 0.001; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);
		
		//  Color the vertices!
		if (color[currentShape])
			glColor3f (x, y, x*y);

		glVertex2f (x, y);
	}

	glEnd ();

	glPopMatrix ();
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
//  This function is passed to the glutMouseFunc and is called 
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y)
{
	if (state != GLUT_DOWN)
		return;
	
	//  Increase number of segments
	if (button == GLUT_LEFT_BUTTON)
	{
		segments[currentShape]++;
	}
	//  Decrease number of segments
	else if (button == GLUT_RIGHT_BUTTON)
	{
		segments[currentShape]--;

		if (segments[currentShape] <= 0)
			segments[currentShape] = 1;
	}
	//  change shape
	else
	{
		currentShape++;

		if (currentShape >= shapeNum)
			currentShape = 0;
	}

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
		//  Whether to show the bounding rectangle
		case 'b':

			showBoundingRect = !showBoundingRect;

			break;

		//  Whether to color the shape
		case 'c':

			color[currentShape] = !color[currentShape];
			break;

		//  Display help message
		case 'h':
			displayHelp ();

			break;

		//  Reset the shape
		case 'r':
			
			width[currentShape] = 1.6;
			height[currentShape] = 1.6;
			segments[currentShape] = 20;
			color[currentShape] = 0;

			break;
		
		//  change the shape
		case 's':
			
			currentShape++;

			if (currentShape >= shapeNum)
				currentShape = 0;

			break;

		//  User hits ESC key
		case 27:
			exit (1);
			break;
	}

	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  This function is passed to the glutSpecialFunc and is called 
//  whenever the user hits a special key.
//-------------------------------------------------------------------------
void special (int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:

			height[currentShape] += 0.1f;

			break;
		case GLUT_KEY_DOWN:

			height[currentShape] -= 0.1f;

			break;
		case GLUT_KEY_LEFT:

			width[currentShape] -= 0.1f;

			break;
		case GLUT_KEY_RIGHT:
			
			width[currentShape] += 0.1f;

			break;
	}
	
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Display help message.
//-------------------------------------------------------------------------
void displayHelp ()
{
	printf ("\n************* \t\tHelp\t\t *************\n\n");
	
	printf ("Keyboard\n\n");

	printf ("%s\t\t%s\n", "Left Key", "Decrease Width");
	printf ("%s\t\t%s\n", "Right Key", "Increase Width");
	printf ("%s\t\t%s\n", "Down Key", "Decrease Height");
	printf ("%s\t\t%s\n", "Bottom Key", "Increase Height");
	printf ("%s\t\t\t%s\n", "b", "Show\\Hide boundary rect");
	printf ("%s\t\t\t%s\n", "c", "Color\\Uncolor current shape");
	printf ("%s\t\t\t%s\n", "h", "Display this help message");
	printf ("%s\t\t\t%s\n", "r", "Reset attributes of current shape");
	printf ("%s\t\t\t%s\n", "s", "Change current shape");

	printf ("\n\nMouse\n\n");

	printf ("%s\t\t%s\n", "Left Button", "Increase precision");
	printf ("%s\t\t%s\n", "Middle Button", "Change Current Shape");
	printf ("%s\t\t%s\n", "Right Button", "Decrease precision");

	printf ("\n\n************* \t\tHelp\t\t *************\n\n");
}

//-------------------------------------------------------------------------
//  Prints text at the specified coordinates.
//-------------------------------------------------------------------------
void printw (float x, float y, float z, char* format, ...)
{
    va_list arg_list;
    char str[256];
	int i;
    
    va_start(arg_list, format);
    vsprintf(str, format, arg_list);
    va_end(arg_list);
    
    glRasterPos3f (x, y, z);

    for (i = 0; str[i] != '\0'; i++)
        glutBitmapCharacter(font_style, str[i]);
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

	//  Set the window x and y coordinates such that the 
	//  window becomes centered
	centerOnScreen ();

    //  Create a window with the specified dimensions and position
	//  Set the display mode 
	//  Specify the window title.
	glutInitWindowSize (window_width, window_height);
	glutInitWindowPosition (window_x, window_y);
	glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow (window_title);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Set OpenGL program initial state.
	init();
	
	// Set the callback functions
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);

	//  Start GLUT event processing loop
	glutMainLoop();
}

