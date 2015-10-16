//*************************************************************************
//
//  File Name	: GLUTMenus
//  Author		: Ali BaderEddin
//  Created		: December 2003
//	Modified	: May 2010  
//
//  Description	: Wrold of GLUT Menus.
//  
//*************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/glut.h>

//  Initialization
void init ();

//  Callback functions
void display (void);
void reshape (int w, int h);

//  Support Functions
void centerOnScreen ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 500;
int window_height = 300;

//  variable representing the window title
char *window_title = "GLUT Menu World";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Setup the menus
void setupMenus ();

//  Display the menu item
void showMenuItem (int val);

//-------------------------------------------------------------------------
//  A version of the malloc that checks whether allocation went OK.
//-------------------------------------------------------------------------
void *xmalloc (size_t size)
{
    register void *value = malloc (size);

    if (value == 0)
    {
        fprintf (stderr, "xmalloc: virtual memory exhausted");
        exit (1);
    }

    return value;
}

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
    //  Set the frame buffer clear color to black. 
    glClearColor (0.0, 0.0, 0.0, 0.0);

    //  Set seed value of random number generator based on current time
    srand (time (NULL));

    //  Set up menus
    setupMenus ();
}

//-------------------------------------------------------------------------
//  Set up the GLUT Menus.
//-------------------------------------------------------------------------
void setupMenus ()
{
    int subMenuCount;  //  Count of sub menus
    int menuItemCount; //  Count of menu items in a submenu
    int *menuIds;      //  Submenu IDs
    char str[256];     //  The string of the current menu item
    int i, j;          //  Iterators

    //  Generate a random value for submenu count
    subMenuCount = rand() % 20;

    //  Allocate memory for the submenu IDs
    menuIds = (int *) xmalloc (subMenuCount * sizeof (int));

    //  Create all the sub menus
    for (i = 0; i < subMenuCount; i++)
        menuIds[i] = glutCreateMenu (showMenuItem);

    for (i = 1; i < subMenuCount; i++)
    {
        //  Set sub menu string
        sprintf (str, "SubMenu %d", i);

        //  Add the current submenu to previous submenu
        glutSetMenu (menuIds[i-1]);
        glutAddSubMenu (str, menuIds[i]);

        //  New menu item count for the new submenu
        menuItemCount = rand () % 20;

        //  Add menu items to the current submenu
        for (j = 1; j < menuItemCount; j++)
        {
            sprintf (str, "Menu Item %d", j);
            glutAddMenuEntry (str, j);
        }
    }

    //  Set main menu as the current menu
    glutSetMenu (menuIds[0]);

    //  Attach the menu to the RMB
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//-------------------------------------------------------------------------
//  Displays the menu item id on the console window
//-------------------------------------------------------------------------
void showMenuItem (int val)
{
    printf ("Menu Item: %d\n", val);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    //  Display Nothing

    glFlush();
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

    //  Start GLUT event processing loop
    glutMainLoop();
}

