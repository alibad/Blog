//*************************************************************************
//
//  File Name	: MemViz
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: April 2010  
//
//  Description	: Visualizing memory.
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

//  Imagine window as grid of boxes
#define GRID_WIDTH  17
#define GRID_HEIGHT 32
#define BOX_SIZE    15

//  Initialization
void init (unsigned char * start);

//  Callback functions
void display (void);
void keyboard (unsigned char key, int x, int y);
void special (int key, int x, int y);
void reshape (int w, int h);

//  Support Functions
void centerOnScreen ();

// display Help Message
void displayHelp ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = GRID_WIDTH * BOX_SIZE;
int window_height = GRID_HEIGHT * BOX_SIZE;

//  variable representing the window title
char *window_title = "Memory Visualization";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Just a pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style;

//  printf prints to file. printw prints to window
void printw (float x, float y, float z, char* format, ...);

//  represents the starting address of my memory
unsigned char *start_address;

//  Represents the top of the entries that are currently visible
unsigned char *top_entry;

//  Declare the pointer that will represent the current address in memory
unsigned char *currentAddress;

//  The content of the current memory location
unsigned char currentValue;

//  Determines by how many addresses we move when the user
//  presses and the Up and Down keys
int address_increment = 1;

//  Color Table Enum
enum ColorTable
{
	GRAY = 0,
	RB,
	RGB,
	ROYGBV,
	HOT,
	COLD,
	RANDOM,
	TABLE_COUNT,
};

//  Color Tables
unsigned char gray[256][3];
unsigned char rb[256][3];
unsigned char rgb[256][3];
unsigned char roygbv[256][3];
unsigned char hot[256][3];
unsigned char cold[256][3];
unsigned char random[256][3];

//  Current color table
enum ColorTable colorTable = HOT;

//  Generates the color tables
void generateColorTables();

//  Draws the current color table
void drawColorTable();

//  Sets the current color based on the selected color table
void setColor(unsigned char value);

//  Sets the inverse of the current color
void setInvertedColor();

//  Drawing functions
void drawHeaders();
void drawRects(bool fill);
void drawContent(bool av);

//  Converts byte to binary
char* byteToBin(unsigned char byte);

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init (unsigned char * start)
{	
	//  Display help message
	displayHelp();

	//  Generate the color tables
	generateColorTables();

	//  Clear the background to white
	glClearColor (1.0, 1.0, 1.0, 0.0);

	//  Set the current address
	start_address = start;
	top_entry = start_address;

	//  Set the orthographic view
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, GRID_WIDTH, 0.0, GRID_HEIGHT);

	//  Set back the Model View stack as the current stack
	glMatrixMode (GL_MODELVIEW);
}

//-------------------------------------------------------------------------
//  Generates the color tables
//-------------------------------------------------------------------------
void generateColorTables()
{
	int i = 0;

	//  Gray
	for(i = 0; i < 256; i++)
	{
		gray[i][0] = i;		//  R
		gray[i][1] = i;		//	G
		gray[i][2] = i;		//	B
	}

	//  RB
	for(i = 0; i < 256; i++)
	{
		rb[i][0] = 255 - i;	//  R
		rb[i][1] = 0;		//	G
		rb[i][2] = i;		//	B
	}

	//  RGB
	for(i = 0; i < 128; i++)
	{
		rgb[i][0] = 255 - 2 * i; // R
		rgb[i][1] = 2 * i;		 //	G
		rgb[i][2] = 0;			 //	B
	}

	for(; i < 256; i++)
	{
		rgb[i][0] = 0;			 // R
		rgb[i][1] = 255 - 2 * i; //	G
		rgb[i][2] = 2 * i;		 //	B
	}

	//  ROYGBV
	for(i = 0; i < 64; i++)
	{
		roygbv[i][0] = 255;
		roygbv[i][1] = i * 4;
		roygbv[i][2] = 0;
	}

	for(; i < 128; i++)
	{
		roygbv[i][0] = 255 - (i * 4);
		roygbv[i][1] = 255;
		roygbv[i][2] = 0;
	}

	for(; i < 192; i++)
	{
		roygbv[i][0] = 0;
		roygbv[i][1] = 255 - (i * 4);
		roygbv[i][2] = i * 4;
	}

	for(; i < 256; i++)
	{
		roygbv[i][0] = i * 4;
		roygbv[i][1] = 0;
		roygbv[i][2] = 255;
	}

	//  Hot
	for(i = 0; i < 85; i++)
	{
		hot[i][0] = i * 3;
		hot[i][1] = 0;
		hot[i][2] = 0;
	}

	for(; i < 170; i++)
	{
		hot[i][0] = 255;
		hot[i][1] = (i - 85) * 3;
		hot[i][2] = 0;
	}

	for(; i < 256; i++)
	{
		hot[i][0] = 255;
		hot[i][1] = 255;
		hot[i][2] = (i - 170) * 3;
	}

	//  Cold
	for(i = 0; i < 256; i++)
	{
		cold[i][0] = i;
		cold[i][1] = 255 - i;
		cold[i][2] = 255;
	}

	//  Random
	for(i = 0; i < 256; i++)
	{
		random[i][0] = rand() % 256;
		random[i][1] = rand() % 256;
		random[i][2] = rand() % 256;
	}
}

//-------------------------------------------------------------------------
//  Set color based on currently selected table and content.
//-------------------------------------------------------------------------
void setColor(unsigned char value)
{
	//  Set content color
	switch(colorTable)
	{
		case GRAY:
			glColor3ub(gray[value][0], gray[value][1], gray[value][2]);
			break;
		case RB:
			glColor3ub(rb[value][0], rb[value][1], rb[value][2]);
			break;
		case RGB:
			glColor3ub(rgb[value][0], rgb[value][1], rgb[value][2]);
			break;
		case ROYGBV:
			glColor3ub(roygbv[value][0], roygbv[value][1], roygbv[value][2]);
			break;
		case HOT:
			glColor3ub(hot[value][0], hot[value][1], hot[value][2]);
			break;
		case COLD:
			glColor3ub(cold[value][0], cold[value][1], cold[value][2]);
			break;
		case RANDOM:
			glColor3ub(random[value][0], random[value][1], random[value][2]);
			break;
	}
}

//-------------------------------------------------------------------------
//  Sets the inverse of the current color
//-------------------------------------------------------------------------
void setInvertedColor()
{
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR, currentColor);
	currentColor[0] = 1.0 - currentColor[0];
	currentColor[1] = 1.0 - currentColor[1];
	currentColor[2] = 1.0 - currentColor[2];
	glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	//  Clear the frame buffer with the clear color
	glClear (GL_COLOR_BUFFER_BIT);

	//  Draw Headers
	drawHeaders();

	//  Display color of some of the entries in main memory
	for (currentAddress = top_entry; currentAddress < top_entry + 24; currentAddress++)
	{
		//  Try to get the contents of the current memory address
		//  to see if we get an access violation exception
		bool av = false;
		try
		{
			currentValue = *currentAddress;
		}
		catch(...)
		{
			av = true;
		}

		//  draw address
		glColor3f (0, 0, 1);
		printw (1.0, 
			    GRID_HEIGHT - (currentAddress - top_entry + 3.75), 
				0.0, 
				"%#x", currentAddress);

		//  Set color based on currently selected table and content.
		setColor(currentValue);

		//  draw the rectangle containing address content
		drawRects(true);

		//  Invert color
		setInvertedColor();

		//  Draw border
		//drawRects(false);

		//  draw address content
		drawContent(av);
	}

	//  Draw the color table
	drawColorTable();

	glFlush ();
}

//-------------------------------------------------------------------------
//  Draws headers
//-------------------------------------------------------------------------
void drawHeaders()
{
	font_style = GLUT_BITMAP_HELVETICA_12;
	glColor3ub (0, 0, 1);
	printw (1.0, GRID_HEIGHT - 2, 0.0, "Address");
	printw (5.0, GRID_HEIGHT - 2, 0.0, "Dec");
	printw (7.5, GRID_HEIGHT - 2, 0.0, "Char");
	printw (10.0, GRID_HEIGHT - 2, 0.0, "Hex");
	printw (12.0, GRID_HEIGHT - 2, 0.0, "Binary");
	font_style = GLUT_BITMAP_TIMES_ROMAN_10;
}

//-------------------------------------------------------------------------
//  Draws the address content in different formats, and shows '?' in all
//  formats in case of access violation.
//-------------------------------------------------------------------------
void drawContent(bool av)
{
	float x = 5.5, y = GRID_HEIGHT - (currentAddress - top_entry + 3.75);

	if(av)
	{
		printw (x, y, 0.0, "%c", '?');
		x += 3;
		printw (x, y, 0.0, "%c", '?');
		x += 2;
		printw (x, y, 0.0, "%c", '?');
		x += 2;
		printw (x, y, 0.0, "%c", '?');
	}
	else
	{
		printw (x, y, 0.0, "%d", currentValue);
		x += 3;
		printw (x, y, 0.0, "%c", currentValue);
		x += 2;
		printw (x, y, 0.0, "%X", currentValue);
		x += 2;
		printw (x, y, 0.0, "%s", byteToBin(currentValue));
	}
}

//-------------------------------------------------------------------------
//  Draws rectangles surrounding address content
//-------------------------------------------------------------------------
void drawRects(bool fill)
{
	float x = 5.0, y = GRID_HEIGHT - (currentAddress - top_entry + 3);

	glPolygonMode (GL_FRONT_AND_BACK, (fill) ? GL_FILL : GL_LINE);

	glRectf (x,	y, x + 2, y - 1);
	x += 2.5;
	glRectf (x,	y, x + 2, y - 1);
	x += 2.5;
	glRectf (x,	y, x + 1.5,	y - 1);
	x += 2;
	glRectf (x,	y, x + 3.5, y - 1);
}

//-------------------------------------------------------------------------
//  Draws the current color table
//-------------------------------------------------------------------------
void drawColorTable()
{
	//  Draw Headers
	font_style = GLUT_BITMAP_HELVETICA_12;
	glColor3ub (0, 0, 1);
	printw(1.0, 3.0, 0.0, "Increment %d", address_increment);
	printw (1.0, 1.0, 0.0, "Color");
	font_style = GLUT_BITMAP_TIMES_ROMAN_10;

	float x = 5.0;
	float xIncrement = (GRID_WIDTH - 6.5) / 256.0;

	//  Draw the color table
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for(int i = 0; i < 256; i++)
	{
		setColor(i);
		
		glRectf(x, 1, x + xIncrement, 2);
		x += xIncrement;
	}

	//  Draw color table boundary
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0, 0, 0);
	glRectf(5.0, 1, GRID_WIDTH - 1.5, 2);
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
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
	int i = colorTable;

	switch (key)
	{
		//  Go to address 0x00000000
		case '0':
			top_entry = 0;
			break;

		//  Display help message
		case 'h':
		case 'H':
			displayHelp();
			break;

		//  Change Color Table
		case 'c':
		case 'C':
			i++;

			if(i >= TABLE_COUNT)
			{
				i = 0;
			}

			colorTable = (ColorTable) i;

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
		case GLUT_KEY_DOWN:
			
			top_entry += address_increment;
			glutPostRedisplay ();
			
			break;

		case GLUT_KEY_UP:

			top_entry -= address_increment;

			if(top_entry < 0)
			{
				top_entry = 0;
			}

			glutPostRedisplay ();

			break;

		case GLUT_KEY_LEFT:

			address_increment--;

			if(address_increment < 1)
			{
				address_increment = 1;
			}

			glutPostRedisplay ();

			break;

		case GLUT_KEY_RIGHT:

			address_increment++;
			glutPostRedisplay ();

			break;

		case GLUT_KEY_HOME:

			top_entry = start_address;
			glutPostRedisplay ();

			break;
	}
}

//-------------------------------------------------------------------------
//  Converts byte to binary
//-------------------------------------------------------------------------
char* byteToBin(unsigned char byte)
{
	char * binary = new char[9];
	binary[8] = '\0';

	for(int i = 7; i > 0; i--)
	{
		binary[i] = (byte % 2) ? '1' : '0';
		byte = byte / 2;
	}

	return binary;
}

//-------------------------------------------------------------------------
//  Display help message.
//-------------------------------------------------------------------------
void displayHelp ()
{
	printf ("\n************* \t\tHelp\t\t *************\n\n");
	
	printf ("Keyboard\n\n");

	printf ("%s\t\t%s\n", "Up Key", "Move 'N' addresses up");
	printf ("%s\t%s\n", "Down Key", "Move 'N' addresses down");
	printf ("%s\t%s\n", "Right Key", "Increase address increment 'N'");
	printf ("%s\t%s\n", "Left Key", "Decrease address increment 'N'");
	printf ("%s\t\t%s\n", "Home", "Get back to the start address");
	printf ("%s\t\t%s\n", "0", "Move to address 0");
	printf ("%s\t\t%s\n", "c", "Change color table");
	printf ("%s\t\t%s\n", "h", "Display this help message");

	printf ("\n\n************* \t\tHelp\t\t *************\n\n");
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
	text = (char *) malloc(len * sizeof(char));

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
	glutInitDisplayMode (GLUT_RGB);

	//  Create window with the specified title
	glutCreateWindow (window_title);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Set OpenGL program initial state.
	init((unsigned char *)&argc);
	
	// Set the callback functions
	glutDisplayFunc (display);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);
	glutReshapeFunc  (reshape);

	//  Start GLUT event processing loop
	glutMainLoop();
}

