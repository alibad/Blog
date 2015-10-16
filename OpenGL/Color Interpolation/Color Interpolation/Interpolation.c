//*************************************************************************
//
//  File Name	: Interpolation
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: May 2010  
//
//  Description	: How would color interpolation be implemented by OpenGL?
//  
//*************************************************************************

#include <stdlib.h>
#include <gl/glut.h>
#include "GLText.h"

//  Avoid showing up the console window
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//  Initialization
void init ();

//  Callback functions
void display (void);
void mouse (int button, int state, int x, int y);
void reshape (int w, int h);

//  Support Functions
void centerOnScreen ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 522;
int window_height = 256;

//  Represents the separator width
int separatorWidth = 10;

//  variable representing the window title
char *window_title = "OpenGL Interpolation";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Define the point data structure
typedef struct Point
{
    float x;                  //  x position of the point
    float y;                  //  y position of the point
    float z;                  //  z position of the point
    float r;                  //  red color component of the point
    float g;                  //  green color component of the point
    float b;                  //  blue color component of the point
    float a;                  //  alpha color component of the point
} Point;

//  represents the number of points the line consists of
#define N 250

//  Declare the end points
Point v0A, v1A, v0M, v1M;

//  Declare the array of points
Point linePoints[N];

//  1 if user specified none or two points.. 0 if user specified only one point.
int lineComplete = 1;

//  Represents the width of the line
float lineWidth = 5.0f;

//  Draws the line
void drawLine (int manual, Point v0, Point v1);

//  Interpolate automatically
void drawAuto (Point v0, Point v1);

//  Interpolate Manually
void drawManual (Point v0, Point v1);

//  Draws the separator line
void drawSeparator();

// Update the manual end points based on auto points
void updateEndPoints ();

// menu callback functions declarations
void point1Menu (int value);
void point2Menu (int value);

//  Sets up menus
void setupMenus (void);

// menu IDs declarations
int mainMenuId;
int point1MenuId;
int point2MenuId;

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
    //  Set the clear color
    glClearColor (1.0, 1.0, 1.0, 0.0);

    //  Set the data of the first point
    v0A.x = 100;
    v0A.y = 200;
    v0A.r = 1.0;
    v0A.g = 0.0;
    v0A.b = 0.0;

    //  Set the data of the second point
    v1A.x = 200;
    v1A.y = 100;
    v1A.r = 0.0;
    v1A.g = 0.0;
    v1A.b = 1.0;

    //  Update the v0M and v1M based on V0A and V1A
    updateEndPoints();

    //  Set the point size in pixels
    glPointSize (lineWidth + 5);

    //  Set the width of the line
    glLineWidth (lineWidth);

    //  Set up menus
    setupMenus ();
}

//-------------------------------------------------------------------------
// Update the manual end points based on auto points
//-------------------------------------------------------------------------
void updateEndPoints ()
{
    //  Set the data of the first point
    v0M.x = v0A.x + ((window_width - separatorWidth) / 2);
    v0M.y = v0A.y;
    v0M.r = v0A.r;
    v0M.g = v0A.g;
    v0M.b = v0A.b;

    //  Set the data of the second point
    v1M.x = v1A.x + ((window_width - separatorWidth) / 2);
    v1M.y = v1A.y;
    v1M.r = v1A.r;
    v1M.g = v1A.g;
    v1M.b = v1A.b;
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    drawLine(0, v0A, v1A);    //  auto
    drawSeparator();
    drawLine(1, v0M, v1M);    //  manual

    glFlush ();
}

//-------------------------------------------------------------------------
//  Draws the line
//-------------------------------------------------------------------------
void drawLine (int manual, Point v0, Point v1)
{
    //  Represents the location where to draw the edge points labels
    float label_x0, label_y0, label_x1, label_y1;

    //  show whether interpolation is manual or automatic
    glColor3f (0, 0, 0);
    if(manual)
    {
        printw (20 + ((window_width - separatorWidth) / 2), 
            20, 
            0, "Interpolation: Manual");
    }
    else
    {
        printw (20, 
            20, 
            0, "Interpolation: Automatic");
    }

    //  In case there are two points
    if (lineComplete)
    {	
        //  draw the two points
        glBegin (GL_POINTS);

        glColor3f  (v0.r, v0.g, v0.b);
        glVertex2f (v0.x, v0.y);
        glColor3f  (v1.r, v1.g, v1.b);
        glVertex2f (v1.x, v1.y);

        glEnd ();

        //  draw labels of points at good positions
        glColor3f (0, 0, 0);

        if (v0.x < v1.x)
        {
            label_x0 = v0.x - 10;
            label_x1 = v1.x + 10;
        }
        else
        {
            label_x0 = v0.x + 10;
            label_x1 = v1.x - 10;
        }

        if (v0.y < v1.y)
        {
            label_y0 = v0.y - 30;
            label_y1 = v1.y + 10;
        }
        else
        {
            label_y0 = v0.y + 10;
            label_y1 = v1.y - 30;
        }

        printw (label_x0, label_y0, 0, "V0");
        printw (label_x1, label_y1, 0, "V1");

        //  Draw line using smooth shading
        if (!manual)
        {
            glShadeModel (GL_SMOOTH);
            drawAuto (v0, v1);
        }
        //  draw line using flat shading... But trying to
        //  do smooth effect by implementing interpolation ourselves
        else
        {
            glShadeModel (GL_FLAT);
            drawManual (v0, v1);
        }
    }
    else
    {
        //  draw the first point
        glBegin (GL_POINTS);

        glColor3f  (v0.r, v0.g, v0.b);
        glVertex2f (v0.x, v0.y);

        glEnd ();

        label_x0 = v0.x - 10;
        label_y0 = v0.y - 30;
        glColor3f  (0, 0, 0);
        printw (label_x0, label_y0, 0, "V0");
    }
}

//-------------------------------------------------------------------------
//  Interpolate automatically
//-------------------------------------------------------------------------
void drawAuto (Point v0, Point v1)
{
    //  draw the line
    glBegin (GL_LINES);

    glColor3f  (v0.r, v0.g, v0.b);
    glVertex2f (v0.x, v0.y);
    glColor3f  (v1.r, v1.g, v1.b);
    glVertex2f (v1.x, v1.y);

    glEnd ();
}

//-------------------------------------------------------------------------
//  Interpolate Manually
//-------------------------------------------------------------------------
void drawManual (Point v0, Point v1)
{
    //  The value passed to P(u) or C(u) where P (u) = (1 - u) * v0 + u * v1 
    float u;

    int i;

    //  Location and color interpolation
    for (i = 0; i < N; i++)
    {
        u = (float)i/(N - 1);

        linePoints[i].x = v0.x * (1.0 - u) + v1.x * u;
        linePoints[i].y = v0.y * (1.0 - u) + v1.y * u;
        linePoints[i].z = v0.z * (1.0 - u) + v1.z * u;
        linePoints[i].r = v0.r * (1.0 - u) + v1.r * u;
        linePoints[i].g = v0.g * (1.0 - u) + v1.g * u;
        linePoints[i].b = v0.b * (1.0 - u) + v1.b * u;
        linePoints[i].a = v0.a * (1.0 - u) + v1.a * u;	
    }

    //  Change point size to line width
    glPointSize (lineWidth);

    //  draw line
    glBegin (GL_POINTS);

    for (i = 0; i < N; i++)
    {
        glColor4f  (linePoints[i].r, linePoints[i].g, linePoints[i].b, linePoints[i].a);
        glVertex3f (linePoints[i].x, linePoints[i].y, linePoints[i].z);
    }

    glEnd ();

    //  Reset point size
    glPointSize (lineWidth + 5);
}

//-------------------------------------------------------------------------
//  Draws the separator line
//-------------------------------------------------------------------------
void drawSeparator()
{
    glColor3f (0, 0, 0);

    glBegin (GL_LINES);

    glVertex2f ((window_width + separatorWidth) / 2, 0);
    glVertex2f ((window_width + separatorWidth) / 2, window_height);

    glEnd ();
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMouseFunc and is called 
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(x < window_width / 2 || x > window_width / 2 + separatorWidth)
        {
            if(x > window_width / 2 + separatorWidth)
            {
                x -= window_width / 2;
            }

            //  Set the position of the first point
            if (lineComplete)
            {
                v0A.x = x;
                v0A.y = window_height - y;
            }
            //  Set the position of the second point
            else
            {
                v1A.x = x;
                v1A.y = window_height - y;
            }

            lineComplete = !lineComplete;
            updateEndPoints ();
            glutPostRedisplay ();
        }
    }
}

//-------------------------------------------------------------------------
//  This function is passed to the glutReshapeFunc and is called 
//  whenever the window is resized.
//-------------------------------------------------------------------------
void reshape (int w, int h)
{
    window_width = w;
    window_height = h;

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glViewport (0, 0, w, h);
    gluOrtho2D (0, w, 0 ,h);

    glMatrixMode (GL_MODELVIEW);

    updateEndPoints();
    glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Setup main menu
//-------------------------------------------------------------------------
void setupMenus ()
{
    //  create menus
    mainMenuId = glutCreateMenu (NULL);
    point1MenuId = glutCreateMenu (point1Menu);
    point2MenuId = glutCreateMenu (point2Menu);

    //  Add the menus' entries
    glutSetMenu(mainMenuId);      //  select main menu,

    glutAddSubMenu ("Point 1 Color", point1MenuId);
    glutAddSubMenu ("Point 2 Color", point2MenuId);

    //  Ad menu entries to point 1 menu
    glutSetMenu (point1MenuId);

    glutAddMenuEntry ("Black", 1);
    glutAddMenuEntry ("Blue", 2);
    glutAddMenuEntry ("Cyan", 3);
    glutAddMenuEntry ("Dark Grey", 4);
    glutAddMenuEntry ("Grey", 5);
    glutAddMenuEntry ("Green", 6);
    glutAddMenuEntry ("Light Grey", 7);
    glutAddMenuEntry ("Magenta", 8);
    glutAddMenuEntry ("Orange", 9);
    glutAddMenuEntry ("Pink", 10);
    glutAddMenuEntry ("Red", 11);
    glutAddMenuEntry ("White", 12);
    glutAddMenuEntry ("Yellow", 13);

    //  Ad menu entries to point 2 menu
    glutSetMenu (point2MenuId);

    glutAddMenuEntry ("Black", 1);
    glutAddMenuEntry ("Blue", 2);
    glutAddMenuEntry ("Cyan", 3);
    glutAddMenuEntry ("Dark Grey", 4);
    glutAddMenuEntry ("Grey", 5);
    glutAddMenuEntry ("Green", 6);
    glutAddMenuEntry ("Light Grey", 7);
    glutAddMenuEntry ("Magenta", 8);
    glutAddMenuEntry ("Orange", 9);
    glutAddMenuEntry ("Pink", 10);
    glutAddMenuEntry ("Red", 11);
    glutAddMenuEntry ("White", 12);
    glutAddMenuEntry ("Yellow", 13);

    //  Attach the main menu to the RMB
    glutSetMenu (mainMenuId);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//-------------------------------------------------------------------------
//  Setup menu for point 1
//-------------------------------------------------------------------------
void point1Menu (int value)
{
    switch (value)
    {
        //  Select black color
    case 1:
        v0A.r = 0/255.0;
        v0A.g = 0/255.0;
        v0A.b = 0/255.0;
        break;
        //  Select blue color_1
    case 2:
        v0A.r = 0/255.0;
        v0A.g = 0/255.0;
        v0A.b = 255/255.0;
        break;
        //  Select cyan color
    case 3:	
        v0A.r = 0/255.0;
        v0A.g = 255/255.0;
        v0A.b = 255/255.0;
        break;
        //  Select dark grey color
    case 4:
        v0A.r = 64/255.0;
        v0A.g = 64/255.0;
        v0A.b = 64/255.0;
        break;
        //  Select grey color
    case 5:
        v0A.r = 128/255.0;
        v0A.g = 128/255.0;
        v0A.b = 128/255.0;
        break;
        //  Select green color
    case 6:
        v0A.r = 0/255.0;
        v0A.g = 255/255.0;
        v0A.b = 0/255.0;
        break;
        //  Select light gray color
    case 7:
        v0A.r = 192/255.0;
        v0A.g = 192/255.0;
        v0A.b = 192/255.0;
        break;
        //  Select magenta color
    case 8:
        v0A.r = 192/255.0;
        v0A.g = 64/255.0;
        v0A.b = 192/255.0;
        break;
        //  Select orange color
    case 9:
        v0A.r = 255/255.0;
        v0A.g = 192/255.0;
        v0A.b = 64/255.0;
        break;
        //  Select pink color
    case 10:
        v0A.r = 255/255.0;
        v0A.g = 0/255.0;
        v0A.b = 255/255.0;
        break;
        //  Select red color
    case 11:
        v0A.r = 255/255.0;
        v0A.g = 0/255.0;
        v0A.b = 0/255.0;
        break;
        //  Select white color
    case 12:
        v0A.r = 255/255.0;
        v0A.g = 255/255.0;
        v0A.b = 255/255.0;
        break;
        //  Select yellow color
    case 13:
        v0A.r = 255/255.0;
        v0A.g = 255/255.0;
        v0A.b = 0/255.0;
        break;
    }

    updateEndPoints();
    glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Setup menu for point 2
//-------------------------------------------------------------------------
void point2Menu (int value)
{
    switch (value)
    {
        //  Select black color
    case 1:
        v1A.r = 0/255.0;
        v1A.g = 0/255.0;
        v1A.b = 0/255.0;
        break;
        //  Select blue color
    case 2:
        v1A.r = 0/255.0;
        v1A.g = 0/255.0;
        v1A.b = 255/255.0;
        break;
        //  Select cyan color
    case 3:	
        v1A.r = 0/255.0;
        v1A.g = 255/255.0;
        v1A.b = 255/255.0;
        break;
        //  Select dark grey color
    case 4:
        v1A.r = 64/255.0;
        v1A.g = 64/255.0;
        v1A.b = 64/255.0;
        break;
        //  Select grey color
    case 5:
        v1A.r = 128/255.0;
        v1A.g = 128/255.0;
        v1A.b = 128/255.0;
        break;
        //  Select green color
    case 6:
        v1A.r = 0/255.0;
        v1A.g = 255/255.0;
        v1A.b = 0/255.0;
        break;
        //  Select light gray color
    case 7:
        v1A.r = 192/255.0;
        v1A.g = 192/255.0;
        v1A.b = 192/255.0;
        break;
        //  Select magenta color
    case 8:
        v1A.r = 192/255.0;
        v1A.g = 64/255.0;
        v1A.b = 192/255.0;
        break;
        //  Select orange color
    case 9:
        v1A.r = 255/255.0;
        v1A.g = 192/255.0;
        v1A.b = 64/255.0;
        break;
        //  Select pink color
    case 10:
        v1A.r = 255/255.0;
        v1A.g = 0/255.0;
        v1A.b = 255/255.0;
        break;
        //  Select red color
    case 11:
        v1A.r = 255/255.0;
        v1A.g = 0/255.0;
        v1A.b = 0/255.0;
        break;
        //  Select white color
    case 12:
        v1A.r = 255/255.0;
        v1A.g = 255/255.0;
        v1A.b = 255/255.0;
        break;
        //  Select yellow color
    case 13:
        v1A.r = 255/255.0;
        v1A.g = 255/255.0;
        v1A.b = 0/255.0;
        break;
    }

    updateEndPoints();
    glutPostRedisplay ();
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
    glutInitDisplayMode (GLUT_RGB);

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
    glutMouseFunc (mouse);

    //  Start GLUT event processing loop
    glutMainLoop();
}

