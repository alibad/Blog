//*************************************************************************
//
//  File Name	: Camera.c
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: May 2010  
//
//  Description	: Positioning the camera and setting its view vector.
//  
//*************************************************************************

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <gl/glut.h>

//  Represents gaps between subwindows
#define GAP  25

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 200 * 3 + 4 * GAP;
int window_height = 200 * 2 + 3 * GAP;

//  variable representing the window title
char *window_title = "OpenGL Camera";

//  IDs of main windows and all 6 subwindows
int main_window, subwindow_1, subwindow_2, subwindow_3, subwindow_4, subwindow_5, subwindow_6;

//  Are true if corresponding buttons clicked, and false otherwise
int leftButton = 0;
int middleButton = 0;
int rightButton = 0;

// variables to translating and rotating the objects in the scene
float translate_x = 0.0f, translate_y = 0.0f, translate_z = 0.0f;
float rot_x = 0.0f, rot_y = 0.0f, rot_z = 0.0f;
float scale_x = 1.0f, scale_y = 1.0f, scale_z = 1.0f;
float previousX = 0.0f, previousY = 0.0f, previousZ = 0.0f;

//  Camera position, look at position, up vector
double eyeX = 0, eyeY = 0, eyeZ = 0;
double centerX = 0, centerY = 0, centerZ = 0;
double upX = 0, upY = 1, upZ = 0;

// Subwindows Variables
float subwindow1_x;
float subwindow1_y;
float subwindow1_w = 200;
float subwindow1_h = 200;
float subwindow2_x;
float subwindow2_y;
float subwindow2_w = 200;
float subwindow2_h = 200;
float subwindow3_x;
float subwindow3_y;
float subwindow3_w = 200;
float subwindow3_h = 200;
float subwindow4_x;
float subwindow4_y;
float subwindow4_w = 200;
float subwindow4_h = 200;
float subwindow5_x;
float subwindow5_y;
float subwindow5_w = 200;
float subwindow5_h = 200;
float subwindow6_x;
float subwindow6_y;
float subwindow6_w = 200;
float subwindow6_h = 200;

// Main Window callback functions
void main_display (void);
void main_reshape (int w, int h);
void keyboard (unsigned char key, int x, int y);

// SubWindows Display Functions
void display_1 (void);
void display_2 (void);
void display_3 (void);
void display_4 (void);
void display_5 (void);
void display_6 (void);
void display (int id);
void redisplayAll ();
void mouse (int, int, int, int);
void motion (int, int);

//  Initialization
void init ();

//  Support Functions
void centerOnScreen ();
void drawObject ();

//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;

//  printf prints to file. printw prints to window
void printw (float x, float y, float z, char* format, ...);

//-------------------------------------------------------------------------
//  Reset Object Transformations in the scene
//-------------------------------------------------------------------------
void reset()
{
    translate_x = translate_y = translate_z = 0.0f;
    rot_x = rot_y = rot_z = 0.0f;
    scale_x = scale_y = scale_z = 1.0f;
    previousX = previousY = previousZ = 0;
    redisplayAll();
}

//-------------------------------------------------------------------------
//  Main Window Display Function
//-------------------------------------------------------------------------
void main_display (void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Main window reshape function
//-------------------------------------------------------------------------
void main_reshape (int w, int h)
{
    //  Disallow window re-sizing
    glutReshapeWindow (window_width, window_height);
}

//-------------------------------------------------------------------------
//  Main window reshape function
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r':
        reset();
        break;
    }
}

//-------------------------------------------------------------------------
// Redisplays all subwindows
//-------------------------------------------------------------------------
void redisplayAll ()
{
    glutSetWindow (subwindow_1);
    glutPostRedisplay ();
    glutSetWindow (subwindow_2);
    glutPostRedisplay ();
    glutSetWindow (subwindow_3);
    glutPostRedisplay ();
    glutSetWindow (subwindow_4);
    glutPostRedisplay ();
    glutSetWindow (subwindow_5);
    glutPostRedisplay ();
    glutSetWindow (subwindow_6);
    glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Call display on the subwindow with the passed ID
//-------------------------------------------------------------------------
void display (int id)
{
    //  Clear subwindow
    glClearColor(1, 1, 1, 1);
    glClear (GL_COLOR_BUFFER_BIT);

    //  Set Perspective
    glMatrixMode (GL_PROJECTION);
    glOrtho(-1, 1, -1, 1, -2, 2);

    //  Set camera position and view vector
    glMatrixMode (GL_MODELVIEW);
    gluLookAt (eyeX, eyeY, eyeZ,
        centerX, centerY, centerZ,
        upX, upY, upZ);

    //  apply translation
    glTranslatef (translate_x, translate_y, translate_z);

    // apply rotation
    glRotatef (rot_x, 1.0f, 0.0f, 0.0f);
    glRotatef (rot_y, 0.0f, 1.0f, 0.0f);
    glRotatef (rot_z, 0.0f, 0.0f, 1.0f);

    //  Apply scaling
    glScalef (scale_x, scale_y, scale_z);

    //  Draw Object
    drawObject ();

    //  Make the current ModelView matrix an identity matrix
    glLoadIdentity ();

    //  Make the current Projection matrix an identity matrix
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    //  Label the subwindow
    switch (id)
    {
        //  Front
    case 1:
        printw (-0.9, -0.9, 0, "Front");
        break;
        //  Top
    case 2:
        printw (-0.9, -0.9, 0, "Top");
        break;
        //  Left
    case 3:
        printw (-0.9, -0.9, 0, "Left");
        break;
        //  Back
    case 4:
        printw (-0.9, -0.9, 0, "Back");
        break;
        //  Bottom
    case 5:
        printw (-0.9, -0.9, 0, "Bottom");
        break;
        //  Right
    case 6:
        printw (-0.9, -0.9, 0, "Right");
        break;	
    }

    glutSwapBuffers ();
}

//-------------------------------------------------------------------------
// Front
//-------------------------------------------------------------------------
void display1 (void)
{
    glColor3f (1, 0, 0);
    eyeX = 0;
    eyeY = 0;
    eyeZ = 1;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (1);
}

//-------------------------------------------------------------------------
// Top
//-------------------------------------------------------------------------
void display2 (void)
{
    glColor3f (0, 1, 0);
    eyeX = 0;
    eyeY = 1;
    eyeZ = 0;
    upX = 0;
    upY = 0;
    upZ = -1;
    display (2);
}

//-------------------------------------------------------------------------
//  Left
//-------------------------------------------------------------------------
void display3 (void)
{
    glColor3f (0, 0, 1);
    eyeX = -1;
    eyeY = 0;
    eyeZ = 0;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (3);
}

//-------------------------------------------------------------------------
// Back
//-------------------------------------------------------------------------
void display4 (void)
{
    glColor3f (1, 0, 0);
    eyeX = 0;
    eyeY = 0;
    eyeZ = -1;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (4);
}

//-------------------------------------------------------------------------
// Bottom
//-------------------------------------------------------------------------
void display5 (void)
{
    glColor3f (0, 1, 0);
    eyeX = 0;
    eyeY = -1;
    eyeZ = 0;
    upX = 0;
    upY = 0;
    upZ = 1;
    display (5);
}

//-------------------------------------------------------------------------
// Right
//-------------------------------------------------------------------------
void display6 (void)
{
    glColor3f (0, 0, 1);
    eyeX = 1;
    eyeY = 0;
    eyeZ = 0;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (6);
}

//-------------------------------------------------------------------------
//  Draw the object
//-------------------------------------------------------------------------
void drawObject ()
{
    glutWireTeapot (0.5);
}

//-------------------------------------------------------------------------
// Mouse function that lets the user rotate or translate the object
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y) 
{	
    //  checks if the user presses the left button
    if (button == GLUT_LEFT_BUTTON) 
    {
        leftButton = state == GLUT_DOWN;
    } 
    // this is used to move the object with relative to the Z axis
    else if (button == GLUT_MIDDLE_BUTTON) 
    {
        // if the mouse is pressed
        middleButton = state == GLUT_DOWN;
    } 
    // if the user presses the right button
    else if (button == GLUT_RIGHT_BUTTON) 
    {
        rightButton = state == GLUT_DOWN;
    }

    previousX = x;
    previousY = y;
    previousZ = y;
}

//-------------------------------------------------------------------------
// function used when the user is dragging the mouse
//-------------------------------------------------------------------------
void motion (int x, int y) 
{
    //  Translate
    if (rightButton) 
    {
        translate_x += (x - previousX) * 0.005;
        translate_y -= (y - previousY) * 0.005;
    }

    //  Scale
    if (middleButton) 
    {
        scale_x -= (y - previousZ) * 0.005;
        scale_y -= (y - previousZ) * 0.005;
        scale_z -= (y - previousZ) * 0.005;
    }

    //  Rotate
    if (leftButton) 
    {
        if ((y - previousY) >= 0)
            rot_x += (y - previousY);
        else 
            rot_x += (y - previousY);
        if ((x - previousX) >= 0)
            rot_y += (x - previousX);
        else
            rot_y += (x - previousX);
    }	

    // reset the previousX, previousY, and previousZ to the current position of the mouse
    previousX = (float)x;
    previousY = (float)y;
    previousZ = (float)y;

    redisplayAll ();
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
    glutInitWindowSize (window_width, window_height);

    //  Set the window x and y coordinates such that the 
    //  window becomes centered
    centerOnScreen ();

    //  Position Window
    glutInitWindowPosition (window_x, window_y);

    //  Set Display mode
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);

    //  Create window with the specified title
    main_window = glutCreateWindow (window_title);

    // Set the callback functions for main window
    glutDisplayFunc (main_display);
    glutReshapeFunc  (main_reshape);
    glutKeyboardFunc (keyboard);

    //  Set the position and dimensions of subwindows!
    subwindow_1 = glutCreateSubWindow (main_window, GAP, GAP, 200, 200);
    glutDisplayFunc (display1);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_2 = glutCreateSubWindow (main_window, 200 + GAP*2, GAP, 200, 200);
    glutDisplayFunc (display2);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_3 = glutCreateSubWindow (main_window, 400 + GAP*3, GAP, 200, 200);
    glutDisplayFunc (display3);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_4 = glutCreateSubWindow (main_window, GAP, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display4);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_5 = glutCreateSubWindow (main_window, 200 + GAP*2, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display5);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_6 = glutCreateSubWindow (main_window, 400 + GAP*3, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display6);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);

    //  Start GLUT event processing loop
    glutMainLoop();
}

