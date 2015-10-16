//*************************************************************************
//
//  File Name	: Resolution.c
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: March 2010  
//
//  Description	: Shows the screen resolution in pixels 
//                and its dimensions in milli meters.
//  
//*************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <gl/glut.h>

//  Avoid showing up the console window
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//  Initialization
void init ();

//  Callback functions
void display (void);
void keyboard (unsigned char key, int x, int y);

//  Support Functions
void centerOnScreen();

//  variables representing the window size
int window_width = 512;
int window_height = 128;

//  variable representing the window title
char *window_title = "Screen Resolution";

//  font style..
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;

//  printf prints to file. printw prints to window
void printw (float x, float y, float z, char* format, ...);

//  draw pixels
void drawPixels ();

//  draw string telling the resolution of your screen
void drawResolutionStr ();

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
    glClearColor (1.0, 1.0, 1.0, 1.0);

    gluOrtho2D (
		0, 
		window_width,
        0, 
		window_height);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    // drawPixels ();
    drawResolutionStr ();

    glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  Draw the pixels
//-------------------------------------------------------------------------
void drawPixels ()
{
    int i, j;

	for (i = 0; i < glutGet (GLUT_SCREEN_WIDTH); i++)
	{
        glColor3f (1, 1, 1);
		for (j = 0; j < glutGet (GLUT_SCREEN_HEIGHT); j+=2)
		{
			glBegin (GL_POINTS);
				glVertex2f (i, j);
			glEnd ();
		}

        glColor3f (0, 0, 0);
        for (j = 1; j < glutGet (GLUT_SCREEN_HEIGHT); j+=2)
		{
			glBegin (GL_POINTS);
				glVertex2f (i, j);
			glEnd ();
		}
	}
}

//-------------------------------------------------------------------------
//  Draw string representing the resolution of your screen
//-------------------------------------------------------------------------
void drawResolutionStr ()
{
    glColor3f (0, 0, 1);

    printw (20, 20, 0,
            "Resolution: %d x %d pixels, %d x %d mm", 
            glutGet (GLUT_SCREEN_WIDTH), glutGet (GLUT_SCREEN_HEIGHT),
            glutGet (GLUT_SCREEN_WIDTH_MM), glutGet (GLUT_SCREEN_HEIGHT_MM));

    glColor3f (1, 0, 0);

    printw (20, 45, 0,
            "Pixel Dimensions: %.4f x %.4f mm", 
            (float)glutGet (GLUT_SCREEN_WIDTH_MM) / glutGet (GLUT_SCREEN_WIDTH), 
            (float)glutGet (GLUT_SCREEN_HEIGHT_MM) / glutGet (GLUT_SCREEN_HEIGHT));
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit (1);
    }
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
    text = malloc(len * sizeof(char));

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
	glutInitWindowSize(window_width, window_height);

    //  Set Display mode
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);

    //  Create window with the specified title
    glutCreateWindow (window_title);

    //  View in full screen 
    // glutFullScreen ();

    // Set the callback functions
    glutDisplayFunc (display);
    glutKeyboardFunc (keyboard);

    //  Set OpenGL program initial state.
    init();

    //  Start GLUT event processing loop
    glutMainLoop();
}

