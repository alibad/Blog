//*************************************************************************
//
//  File Name	: PixGen.c
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: March 2010  
//
//  Description	: Generate new image with random colors on mouse click.
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

// Generate random value
#include <time.h>

//  Avoid showing up the console window
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//  constants representing the window size
#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512

//  contant representing max value for a color
#define COLOR_MAX 256

//  Initialization
void init ();

//  Callback functions
void display (void);
void mouse (int button, int state, int x, int y);
void keyboard (unsigned char key, int x, int y);
void special(int key, int x, int y);

//  Support Functions
void centerOnScreen ();

// display Help Message
void displayHelp();

//  define the window position on screen
int window_x;
int window_y;

// Begin and end of color space
int color_begin = 0, color_end = COLOR_MAX;

// pivot (if 0, pivot by row, if 1, pivot by column, 2 no pivot
int pivot = 2;

//  variable representing the window title
char *window_title = "Image Generator";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

// Generates a random integer within a range
unsigned int randr(unsigned int min, unsigned int max);

//  Generates a random image...
void generateImage ();

//  Just a pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style;

//  printf prints to file. printw prints to window
void printw(float x, float y, float z, char* format, ...);

//  Color Table Enum
enum ColorTable
{
	GRAY = 0,
	RB,
	RGB,
	HOT,
	COLD,
	RANDOM,
	ROYGBV,
	ROYGBV_2,
	ROYGBV_4,
	ROYGBV_8,
	ROYGBV_16,
	ROYGBV_32,
	TABLE_COUNT
};

//  Color Tables
unsigned char gray[256][3];
unsigned char rb[256][3];
unsigned char rgb[256][3];
unsigned char roygbv[256][3];
unsigned char roygbv_2[256][3];
unsigned char roygbv_4[256][3];
unsigned char roygbv_8[256][3];
unsigned char roygbv_16[256][3];
unsigned char roygbv_32[256][3];
unsigned char hot[256][3];
unsigned char cold[256][3];
unsigned char random[256][3];

//  Current color table
enum ColorTable colorTable = ROYGBV_2;

//  Generates the color tables
void generateColorTables();

// Builds roygbv color table
void build_roygbv(unsigned char arr[][3], int totalSize);

//  Draws the current color table
void drawColorTable();

//  Sets the current color based on the selected color table
void setColor(unsigned char value, unsigned char* r, unsigned char* g, unsigned char* b);

//  Represents the pixel buffer in memory
GLubyte buffer[WINDOW_WIDTH][WINDOW_HEIGHT][3];

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Display help message
	displayHelp();

	//  Generate the color tables
	generateColorTables();

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	srand (time(NULL));
    generateImage();
}

//-------------------------------------------------------------------------
//  Generates the color tables
//-------------------------------------------------------------------------
void generateColorTables()
{
	int i = 0;

	//  Gray
	for (i = 0; i < 256; i++)
	{
		gray[i][0] = i;		//  R
		gray[i][1] = i;		//	G
		gray[i][2] = i;		//	B
	}

	//  RB
	for (i = 0; i < 256; i++)
	{
		rb[i][0] = 255 - i;	//  R
		rb[i][1] = 0;		//	G
		rb[i][2] = i;		//	B
	}

	//  RGB
	for (i = 0; i < 128; i++)
	{
		rgb[i][0] = 255 - 2 * i; // R
		rgb[i][1] = 2 * i;		 //	G
		rgb[i][2] = 0;			 //	B
	}

	for (; i < 256; i++)
	{
		rgb[i][0] = 0;			 // R
		rgb[i][1] = 255 - 2 * i; //	G
		rgb[i][2] = 2 * i;		 //	B
	}

	//  ROYGBV
	build_roygbv(roygbv, 256);
	build_roygbv(roygbv_2, 2);
	build_roygbv(roygbv_4, 4);
	build_roygbv(roygbv_8, 8);
	build_roygbv(roygbv_16, 16);
	build_roygbv(roygbv_32, 32);

	//  Hot
	for (i = 0; i < 85; i++)
	{
		hot[i][0] = i * 3;
		hot[i][1] = 0;
		hot[i][2] = 0;
	}

	for (; i < 170; i++)
	{
		hot[i][0] = 255;
		hot[i][1] = (i - 85) * 3;
		hot[i][2] = 0;
	}

	for (; i < 256; i++)
	{
		hot[i][0] = 255;
		hot[i][1] = 255;
		hot[i][2] = (i - 170) * 3;
	}

	//  Cold
	for (i = 0; i < 256; i++)
	{
		cold[i][0] = i;
		cold[i][1] = 255 - i;
		cold[i][2] = 255;
	}

	//  Random
	for (i = 0; i < 256; i++)
	{
		random[i][0] = rand() % 256;
		random[i][1] = rand() % 256;
		random[i][2] = rand() % 256;
	}
}

void build_roygbv(unsigned char arr[][3], int totalSize)
{
	int i = 0;
	unsigned char r, g, b;

	int increment = 256 / totalSize;

	while (i < 64)
	{
		if (i % increment == 0)
		{
			r = 255;
			g = i * 4;
			b = 0;
		}

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
		i++;
	}

	while (i < 128)
	{
		if (i % increment == 0)
		{
			r = 255 - (i * 4);
			g = 255;
			b = 0;
		}

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
		i++;
	}

	while (i < 192)
	{
		if (i % increment == 0)
		{
			r = 0;
			g = 255 - (i * 4);
			b = i * 4;
		}

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
		i++;
	}

	while (i < 256)
	{
		if (i % increment == 0)
		{
			r = i * 4;
			g = 0;
			b = 255;
		}

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
		i++;
	}
}

//-------------------------------------------------------------------------
//  Set color based on currently selected table and content.
//-------------------------------------------------------------------------
void setColor(unsigned char value, unsigned char* r, unsigned char* g, unsigned char* b)
{
	//  Set content color
	switch (colorTable)
	{
	case GRAY:
		*r = gray[value][0];
		*g = gray[value][1];
		*b = gray[value][2];
		break;
	case RB:
		*r = rb[value][0];
		*g = rb[value][1];
		*b = rb[value][2];
		break;
	case RGB:
		*r = rgb[value][0];
		*g = rgb[value][1];
		*b = rgb[value][2];
		break;
	case HOT:
		*r = hot[value][0];
		*g = hot[value][1];
		*b = hot[value][2];
		break;
	case COLD:
		*r = cold[value][0];
		*g = cold[value][1];
		*b = cold[value][2];
		break;
	case RANDOM:
		*r = random[value][0];
		*g = random[value][1];
		*b = random[value][2];
		break;
	case ROYGBV:
		*r = roygbv[value][0];
		*g = roygbv[value][1];
		*b = roygbv[value][2];
		break;
	case ROYGBV_2:
		*r = roygbv_2[value][0];
		*g = roygbv_2[value][1];
		*b = roygbv_2[value][2];
		break;
	case ROYGBV_4:
		*r = roygbv_4[value][0];
		*g = roygbv_4[value][1];
		*b = roygbv_4[value][2];
		break;
	case ROYGBV_8:
		*r = roygbv_8[value][0];
		*g = roygbv_8[value][1];
		*b = roygbv_8[value][2];
		break;
	case ROYGBV_16:
		*r = roygbv_16[value][0];
		*g = roygbv_16[value][1];
		*b = roygbv_16[value][2];
		break;
	case ROYGBV_32:
		*r = roygbv_32[value][0];
		*g = roygbv_32[value][1];
		*b = roygbv_32[value][2];
		break;
	}
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB,
					GL_UNSIGNED_BYTE, buffer);
	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  Draws the current color table
//-------------------------------------------------------------------------
void drawColorTable()
{
	//  Draw Headers
	font_style = GLUT_BITMAP_HELVETICA_12;
	glColor3ub(0, 0, 1);
	printw(1.0, 1.0, 0.0, "Color");
	font_style = GLUT_BITMAP_TIMES_ROMAN_10;

	float x = 5.0;
	unsigned char r, g, b;

	//  Draw the color table
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int i = 0; i < 256; i++)
	{
		setColor(i, &r, &g, &b);
		glColor3ub(r, g, b);

		glRectf(x, 1, x, 2);
		x += 1;
	}

	//  Draw color table boundary
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0, 0, 0);
	// glRectf(5.0, 1, GRID_WIDTH - 1.5, 2);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMouseFunc and is called 
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		generateImage ();
		glutPostRedisplay ();
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
	int colorTableInt = colorTable;

	switch (key)
	{
		case 'g':
			generateImage ();
			glutPostRedisplay ();
			break; 
		case 'p':
			pivot++;

			if (pivot > 2)
			{
				pivot = 0;
			}

			generateImage();
			glutPostRedisplay();
			break;
		//  Display help message
		case 'h':
		case 'H':
			displayHelp();
			break;

		//  Change Color Table
		case 'c':
		case 'C':
			colorTableInt++;

			if (colorTableInt >= TABLE_COUNT)
			{
				colorTableInt = 0;
			}

			colorTable = (ColorTable)colorTableInt;

			generateImage();
			glutPostRedisplay();

			break;
		case 27:
			exit (0);
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutSpecialFunc and is called 
//  whenever the user hits a special key.
//-------------------------------------------------------------------------
void special(int key, int x, int y)
{
	//  To increase/decrease the begin point of a color
	if (key == GLUT_KEY_LEFT)
	{
		color_begin--;

		if (color_begin < 0)
			color_begin = 0;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		color_begin++;

		if (color_begin >= color_end)
			color_begin = color_end - 1;
	}

	//  To increase/decrease the end point of a color
	else if (key == GLUT_KEY_UP)
	{
		color_end++;

		if (color_end > COLOR_MAX)
			color_end = COLOR_MAX;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		color_end--;

		if (color_end <= color_begin)
			color_end = color_begin + 1;
	}

	//  Call the display function
	generateImage();
	glutPostRedisplay();
}


//-------------------------------------------------------------------------
//  Display help message.
//-------------------------------------------------------------------------
void displayHelp()
{
	printf("\n************* \t\tHelp\t\t *************\n\n");

	printf("Keyboard\n\n");

	printf("%s\t\t%s\n", "p", "Pivot by column, row or nonw");
	printf("%s\t\t%s\n", "c", "Change color table");
	printf("%s\t\t%s\n", "h", "Display this help message");

	printf("\n\n************* \t\tHelp\t\t *************\n\n");
}

//-------------------------------------------------------------------------
//  Draws a string at the specified coordinates.
//-------------------------------------------------------------------------
void printw(float x, float y, float z, char* format, ...)
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
	glRasterPos3f(x, y, z);

	//  Draw the characters one by one
	for (i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(font_style, text[i]);

	//  Free the allocated memory for the string
	free(text);
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen ()
{
	window_x = (glutGet (GLUT_SCREEN_WIDTH) - WINDOW_WIDTH)/2;
	window_y = (glutGet (GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT)/2;
}

//-------------------------------------------------------------------------
//  Generate new image with random colors
//-------------------------------------------------------------------------
void generateImage ()
{
    int i, j;
	unsigned char r, g, b;

	// by column
	if (pivot == 0)
	{
		for (i = 0; i < WINDOW_HEIGHT; i++)
		{
			int rand = (randr(color_begin, color_end));
			setColor(rand, &r, &g, &b);

			for (j = 0; j < WINDOW_WIDTH; j++)
			{
				buffer[j][i][0] = r;
				buffer[j][i][1] = g;
				buffer[j][i][2] = b;
			}
		}
	}
	// by row
	else if(pivot == 1)
	{
		for (i = 0; i < WINDOW_WIDTH; i++)
		{
			int rand = (randr(color_begin, color_end));
			setColor(rand, &r, &g, &b);

			for (j = 0; j < WINDOW_HEIGHT; j++)
			{
				buffer[i][j][0] = r;
				buffer[i][j][1] = g;
				buffer[i][j][2] = b;
			}
		}	
	}
	else
	{
		for (i = 0; i < WINDOW_WIDTH; i++)
		{
			for (j = 0; j < WINDOW_HEIGHT; j++)
			{
				int rand = (randr(color_begin, color_end));
				setColor(rand, &r, &g, &b);

				buffer[i][j][0] = r;
				buffer[i][j][1] = g;
				buffer[i][j][2] = b;
			}
		}
	}
}

//-------------------------------------------------------------------------
//  Get a random value in a range.
//-------------------------------------------------------------------------
unsigned int randr(unsigned int min, unsigned int max)
{
	int value_in_range = max - min;
	int r = rand() % value_in_range;
	return min + r;
}

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main (int argc, char **argv)
{
	//  Connect to the windowing system
	glutInit(&argc, argv);

	//  create a window with the specified dimensions
	glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);

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
    glutKeyboardFunc (keyboard);
    glutMouseFunc (mouse);
	glutSpecialFunc(special);

	//  Start GLUT event processing loop
	glutMainLoop();
}

