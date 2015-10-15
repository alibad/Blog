//*************************************************************************
//
//  File Name	: GLUT Subwindow Template
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Openning an OpenGL window with multiple subwindows
//				  using GLUT library...
//  
//*************************************************************************

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Standard Input\Output C Library
#include <stdio.h>

// ***** Main Window *****//

#define GAP  25 // gap between subwindows

//  define the window position on screen
float main_window_x;
float main_window_y;

//  variables representing the window size
float main_window_w = 256 + GAP * 2;
float main_window_h = 256 + 64 + GAP * 3;

//  variable representing the window title
char *window_title = "SubWindow Template";

//  Represents the window id
int main_window;

//  Call Back Functions
void main_display (void);
void main_reshape (int w, int h);
void main_mouse (int button, int state, int x, int y);
void main_motion (int x, int y);
void main_pmotion (int x, int y);
void main_keyboard (unsigned char key, int x, int y);
void main_special (int key, int x, int y);
void main_entry (int state);

// ***** Sub Window 1 *****//

//  define the window position on screen
float subwindow1_x = GAP;
float subwindow1_y = GAP;

//  variables representing the window size
float subwindow1_w = 256;
float subwindow1_h = 256;

//  Represents the subwindow id
int subwindow_1;

//  Call Back Functions
void subwindow1_display (void);
void subwindow1_reshape (int w, int h);
void subwindow1_mouse (int button, int state, int x, int y);
void subwindow1_motion (int x, int y);
void subwindow1_pmotion (int x, int y);
void subwindow1_keyboard (unsigned char key, int x, int y);
void subwindow1_special (int key, int x, int y);

// ***** Sub Window 2 *****//

//  define the window position on screen
float subwindow2_x = GAP;
float subwindow2_y = GAP + 256 + GAP;

//  variables representing the window size
float subwindow2_w = 256;
float subwindow2_h = 64;

//  Represents the subwindow id
int subwindow_2;

//  Call Back Functions
void subwindow2_display (void);
void subwindow2_reshape (int w, int h);
void subwindow2_mouse (int button, int state, int x, int y);
void subwindow2_motion (int x, int y);
void subwindow2_pmotion (int x, int y);
void subwindow2_keyboard (unsigned char key, int x, int y);
void subwindow2_special (int key, int x, int y);

// ***** General *****//

//  Tells whether to display the window full screen or not
int full_screen = 0;

//  This function centers your window on the screen
void centerOnScreen (void);

//  Redisplay contents on the window and all the subwindows
void redisplay_all (void);

// ***** Main Window callback functions *****//

//-------------------------------------------------------------------------
//  Main Window Display Function.
//
//	Set the Window Background color to black.
//-------------------------------------------------------------------------
void main_display (void)
{
	//  Notify that we are displaying the main window
	printf ("Drawing Main Window contents...\n");

	//  Set background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

	//  Swap front and back buffers
    glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Main Window Reshape Function.
//
//	Reset the position and dimensions of subwindows when main window size
//	changes.
//-------------------------------------------------------------------------
void main_reshape (int width, int height) 
{
	//  Notify that we are reshaping the main window
	printf ("Main Window: ");
	
	//  Just take the case when the user tries
	//  to make the size of the window very small...
	if (width < GAP * 4 || height < GAP * 6)
	{
		glutSetWindow (main_window);
		glutReshapeWindow (main_window_w, main_window_h);
		return;
	}
	
	//  Change the subwindow 1 dimensions as window dimensions change
	//  main_window_w          ---> subwindow1_w
	//  main_window_w' (width) ---> ??
	//  ==> 
	subwindow1_w = (subwindow1_w * (width-GAP*2.0))/(main_window_w-GAP*2.0);
	subwindow1_h = (subwindow1_h * (height-GAP*3.0))/(main_window_h-GAP*3.0);

	//  Set subwindow 1 as current window and then reposition and resize it
    glutSetWindow (subwindow_1);
    glutPositionWindow (GAP, GAP);
    glutReshapeWindow (subwindow1_w, subwindow1_h);
	
	//  Change the subwindow 2 dimensions as window dimensions change
	subwindow2_w = (subwindow2_w * (width-GAP*2.0))/(main_window_w-GAP*2.0);
	subwindow2_h = (subwindow2_h * (height-GAP*3.0))/(main_window_h-GAP*3.0);

	//  Set subwindow 2 as current window and then reposition and resize it
    glutSetWindow (subwindow_2);
    glutPositionWindow (GAP, GAP+subwindow1_h+GAP);
    glutReshapeWindow (subwindow2_w, subwindow2_h);

	//  Stay updated with the window width and height
	main_window_w = width;
	main_window_h = height;

	//  Print current width and height on the screen
	printf ("Width: %d, Height: %d.\n", width, height);
}

//-------------------------------------------------------------------------
//  Main Window Mouse function
//
//  Tells which mouse button has been clicked on the main wondow.
//-------------------------------------------------------------------------
void main_mouse (int button, int state, int x, int y)
{
	//  Notify that we are clicking on the main window
	printf ("Main Window: ");
	
	switch (button)
	{
		//  Left Button Clicked
		case GLUT_LEFT_BUTTON:

			switch (state)
			{
				//  Pressed 
				case GLUT_DOWN:
					printf ("Mouse Left Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Left Button Released (Up)...\n");
					break;
			}

			break;

		//  Middle Button clicked
		case GLUT_MIDDLE_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Middle Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Middle Button Released (Up)...\n");
					break;
			}

			break;

		//  Right Button Clicked
		case GLUT_RIGHT_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Right Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Right Button Released (Up)...\n");
					break;
			}

			break;

	}
}

//-------------------------------------------------------------------------
//  Main Window Motion Function
//
//  Tells that the mouse is being dragged on the main window.
//-------------------------------------------------------------------------
void main_motion (int x, int y)
{
	//  Notify that we are dragging over the main window
	printf ("Main Window: ");

	//  Print the mouse drag position
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  Main Window Passive Motion Function
//
//  This function is passed to the glutPassiveMotionFunc and is called 
//  whenever the mouse is moved.
//-------------------------------------------------------------------------
void main_pmotion (int x, int y)
{
	//  Notify that we are moving the mouse over the main window
	//printf ("Main Window: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  Main Window Keyboard Function
//
//  Tells which ASCII-code key has been clicked on the main window.
//-------------------------------------------------------------------------
void main_keyboard (unsigned char key, int x, int y)
{
	//  Notify that an ASCII key is pressed on the main window
	printf ("Main Window: ");

	//  Print what key the user is hitting
	printf ("User is hitting the '%c' key.\n", key);
	printf ("ASCII code is %d.\n", key);
	
	switch (key)
	{
		//  User hits A key
		case 'a':
			
			break;

		//  User hits Shift + A key
		case 'A':
			
			break;

		//  User hits Enter
		case '\r':
			printf ("User is hitting the Return key.\n"); 
			break;

		//  User hits Space
		case ' ':
			printf ("User is hitting the Space key.\n"); 
			break;

		//  User hits back space
		case 8:
			printf ("User is hitting the Back Space key.\n"); 
			break;

		//  User hits ESC key
		case 27:
			exit (1);
			break;
	}

	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Main window special Keyboard Function
//
//  Tells which non-ASCII-Code key has being pressed on the main window.
//-------------------------------------------------------------------------
void main_special (int key, int x, int y)
{
	//  Notify that we are pressing a non-ASCII key on the main window
	printf ("Main Window: ");

	switch (key)
	{
		case GLUT_KEY_F1 :
			printf ("F1 function key.\n"); 
			break;
		case GLUT_KEY_F2 :
			printf ("F2 function key. \n");  
			break;
		case GLUT_KEY_F3 :
			printf ("F3 function key. \n");  
			break;
		case GLUT_KEY_F4 :
			printf ("F4 function key. \n");  
			break;
		case GLUT_KEY_F5 :
			printf ("F5 function key. \n");  
			break;
		case GLUT_KEY_F6 :
			printf ("F6 function key. \n");  
			break;
		case GLUT_KEY_F7 :
			printf ("F7 function key. \n");  
			break;
		case GLUT_KEY_F8 :
			printf ("F8 function key. \n");  
			break;
		case GLUT_KEY_F9 :
			printf ("F9 function key. \n");  
			break;
		case GLUT_KEY_F10 :
			printf ("F10 function key. \n");  
			break;
		case GLUT_KEY_F11 :
			printf ("F11 function key. \n");  
			break;
		case GLUT_KEY_F12 :
			printf ("F12 function key. \n");  
			break;
		case GLUT_KEY_LEFT :
			printf ("Left directional key. \n");  
			break;
		case GLUT_KEY_UP :
			printf ("Up directional key. \n");  
			break;
		case GLUT_KEY_RIGHT :
			printf ("Right directional key. \n");  
			break;
		case GLUT_KEY_DOWN :
			printf ("Down directional key. \n");  
			break;
		case GLUT_KEY_PAGE_UP :
			printf ("Page up directional key. \n");  
			break;
		case GLUT_KEY_PAGE_DOWN :
			printf ("Page down directional key. \n");  
			break;
		case GLUT_KEY_HOME :
			printf ("Home directional key. \n");  
			break;
		case GLUT_KEY_END :
			printf ("End directional key. \n");  
			break;
		case GLUT_KEY_INSERT :
			printf ("Insert directional key. \n");  
			break;
	}
	
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Main Window Entry Function.
//
//	This function is called whenever the mouse pointer enters or leaves
//  the main window.
//-------------------------------------------------------------------------
void main_entry (int state)
{
	if (state == GLUT_ENTERED)
		printf ("Mouse entered main window...\n");
	else if (state == GLUT_LEFT)
		printf ("Mouse left main window...\n");
}

// ***** SubWindow 1 callback functions *****//

//-------------------------------------------------------------------------
//  SubWindow 1 Display Function.
//
//	Set the Window Background color to blue, foreground color to yellow
//  and draw a teapot.
//-------------------------------------------------------------------------
void subwindow1_display (void)
{
	//  Notify that we are displaying subwindow 1
	printf ("Drawing SubWindow 1 contents.\n");

	//  Set background color to blue
	glClearColor(0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

	//  Set drawing color to yellow
    glColor3f (1, 1, 0);
	
	//  Draw teapot
	glutWireTeapot (0.5);

	//  Swap front and back buffers
	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  SubWindow 1 Reshape Function.
//
//	Preserve aspect ratio of viewport when subwindow is resized.
//-------------------------------------------------------------------------
void subwindow1_reshape (int width, int height) 
{
	//  Represents a side of the viewport. A viewport is intended to
	//  to take a square shape so that the aspect ratio is reserved
	int viewport_side = 0;

	//  Viewport x and y positions (Center viewport)
	int viewport_x = 0, viewport_y = 0;
	
	//  Calculate viewport side
	viewport_side = (width > height) ? height : width;

	//  Calculate viewport position
	viewport_x = (width - viewport_side) / 2;
	viewport_y = (height - viewport_side) / 2;

	//  Preserve aspect ratio
	glViewport (viewport_x, viewport_y, viewport_side, viewport_side);

	//  Set subwindow width and height
	subwindow1_w = width;
	subwindow1_h = height;

	//  Notify that we are reshaping subwindow 1
	printf ("Subwindow 1: ");

	//  Print current width and height
	printf ("Width: %d, Height: %d, Viewport Side: %d.\n", width, height, viewport_side);
}

//-------------------------------------------------------------------------
//  SubWindow 1 Mouse function
//
//  Tells which mouse button has been clicked on subwindow 1.
//-------------------------------------------------------------------------
void subwindow1_mouse (int button, int state, int x, int y)
{
	//  Notify that we are clicking on subwindow 1
	printf ("SubWindow 1: ");
	
	switch (button)
	{
		//  Left Button Clicked
		case GLUT_LEFT_BUTTON:

			switch (state)
			{
				//  Pressed 
				case GLUT_DOWN:
					printf ("Mouse Left Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Left Button Released (Up)...\n");
					break;
			}

			break;

		//  Middle Button clicked
		case GLUT_MIDDLE_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Middle Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Middle Button Released (Up)...\n");
					break;
			}

			break;

		//  Right Button Clicked
		case GLUT_RIGHT_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Right Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Right Button Released (Up)...\n");
					break;
			}

			break;

	}
}

//-------------------------------------------------------------------------
//  SubWindow 1 Motion Function
//
//  Tells that the mouse is being dragged on subwindow 1.
//-------------------------------------------------------------------------
void subwindow1_motion (int x, int y)
{
	//  Notify that we are dragging over subwindow 1
	printf ("SubWindow 1: ");

	//  Print the mouse drag position
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  SubWindow 1 Passive Motion Function
//
//  This function is passed to the glutPassiveMotionFunc and is called 
//  whenever the mouse is moved.
//-------------------------------------------------------------------------
void subwindow1_pmotion (int x, int y)
{
	//  Notify that we are moving the mouse over subwindow 1
	//printf ("SubWindow 1: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  SubWindow 1 Keyboard Function
//
//  Tells which ASCII-code key has been clicked on subwindow 1.
//-------------------------------------------------------------------------
void subwindow1_keyboard (unsigned char key, int x, int y)
{
	//  Notify that an ASCII key is pressed on subwindow 1
	printf ("SubWindow 1: ");

	//  Print what key the user is hitting
	printf ("User is hitting the '%c' key.\n", key);
	printf ("ASCII code is %d.\n", key);
	
	switch (key)
	{
		//  User hits A key
		case 'a':
			
			break;

		//  User hits Shift + A key
		case 'A':
			
			break;

		//  User hits Enter
		case '\r':
			printf ("User is hitting the Return key.\n"); 
			break;

		//  User hits Space
		case ' ':
			printf ("User is hitting the Space key.\n"); 
			break;

		//  User hits back space
		case 8:
			printf ("User is hitting the Back Space key.\n"); 
			break;

		//  User hits ESC key
		case 27:
			exit (1);
			break;
	}

	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  SubWindow 1 special Keyboard Function
//
//  Tells which non-ASCII-Code key has being pressed on subwindow 1.
//-------------------------------------------------------------------------
void subwindow1_special (int key, int x, int y)
{
	//  Notify that we are pressing a non-ASCII key on subwindow 1
	printf ("SubWindow 1: ");

	switch (key)
	{
		case GLUT_KEY_F1 :
			printf ("F1 function key.\n"); 
			break;
		case GLUT_KEY_F2 :
			printf ("F2 function key. \n");  
			break;
		case GLUT_KEY_F3 :
			printf ("F3 function key. \n");  
			break;
		case GLUT_KEY_F4 :
			printf ("F4 function key. \n");  
			break;
		case GLUT_KEY_F5 :
			printf ("F5 function key. \n");  
			break;
		case GLUT_KEY_F6 :
			printf ("F6 function key. \n");  
			break;
		case GLUT_KEY_F7 :
			printf ("F7 function key. \n");  
			break;
		case GLUT_KEY_F8 :
			printf ("F8 function key. \n");  
			break;
		case GLUT_KEY_F9 :
			printf ("F9 function key. \n");  
			break;
		case GLUT_KEY_F10 :
			printf ("F10 function key. \n");  
			break;
		case GLUT_KEY_F11 :
			printf ("F11 function key. \n");  
			break;
		case GLUT_KEY_F12 :
			printf ("F12 function key. \n");  
			break;
		case GLUT_KEY_LEFT :
			printf ("Left directional key. \n");  
			break;
		case GLUT_KEY_UP :
			printf ("Up directional key. \n");  
			break;
		case GLUT_KEY_RIGHT :
			printf ("Right directional key. \n");  
			break;
		case GLUT_KEY_DOWN :
			printf ("Down directional key. \n");  
			break;
		case GLUT_KEY_PAGE_UP :
			printf ("Page up directional key. \n");  
			break;
		case GLUT_KEY_PAGE_DOWN :
			printf ("Page down directional key. \n");  
			break;
		case GLUT_KEY_HOME :
			printf ("Home directional key. \n");  
			break;
		case GLUT_KEY_END :
			printf ("End directional key. \n");  
			break;
		case GLUT_KEY_INSERT :
			printf ("Insert directional key. \n");  
			break;
	}
	
	glutPostRedisplay ();
}

// ***** SubWindow 2 callback functions *****//

//-------------------------------------------------------------------------
//  SubWindow 2 Display Function.
//
//	Set the Window Background color to yellow, foreground color to blue
//  and draw a teapot.
//-------------------------------------------------------------------------
void subwindow2_display (void)
{
	//  Notify that we are displaying subwindow 2
	printf ("Drawing SubWindow 2 contents.\n");

	//  Set background color to yellow
	glClearColor(1.0, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

	//  Set drawing color to blue
    glColor3f (0, 0, 1);
	
	//  Draw teapot
	glutWireTeapot (0.5);

	//  Swap front and back buffers
	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  SubWindow 2 Reshape Function.
//
//	Preserve aspect ratio of viewport when subwindow is resized.
//-------------------------------------------------------------------------
void subwindow2_reshape (int width, int height) 
{
	//  Represents a side of the viewport. A viewport is intended to
	//  to take a square shape so that the aspect ratio is reserved
	int viewport_side = 0;

	//  Viewport x and y positions (Center viewport)
	int viewport_x = 0, viewport_y = 0;
	
	//  Calculate viewport side
	viewport_side = (width > height) ? height : width;

	//  Calculate viewport position
	viewport_x = (width - viewport_side) / 2;
	viewport_y = (height - viewport_side) / 2;

	//  Preserve aspect ratio
	glViewport (viewport_x, viewport_y, viewport_side, viewport_side);

	//  Set subwindow width and height
	subwindow2_w = width;
	subwindow2_h = height;

	//  Notify that we are reshaping subwindow 1
	printf ("Subwindow 2: ");

	//  Print current width and height
	printf ("Width: %d, Height: %d, Viewport Side: %d.\n", width, height, viewport_side);
}


//-------------------------------------------------------------------------
//  SubWindow 2 Mouse function
//
//  Tells which mouse button has been clicked on subwindow 2.
//-------------------------------------------------------------------------
void subwindow2_mouse (int button, int state, int x, int y)
{
	//  Notify that we are clicking on subwindow 2
	printf ("SubWindow 2: ");
	
	switch (button)
	{
		//  Left Button Clicked
		case GLUT_LEFT_BUTTON:

			switch (state)
			{
				//  Pressed 
				case GLUT_DOWN:
					printf ("Mouse Left Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Left Button Released (Up)...\n");
					break;
			}

			break;

		//  Middle Button clicked
		case GLUT_MIDDLE_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Middle Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Middle Button Released (Up)...\n");
					break;
			}

			break;

		//  Right Button Clicked
		case GLUT_RIGHT_BUTTON:
			
			switch (state)
			{
				//  Pressed
				case GLUT_DOWN:
					printf ("Mouse Right Button Pressed (Down)...\n");
					break;
				//  Released
				case GLUT_UP:
					printf ("Mouse Right Button Released (Up)...\n");
					break;
			}

			break;

	}
}

//-------------------------------------------------------------------------
//  SubWindow 2 Motion Function
//
//  Tells that the mouse is being dragged on subwindow 2.
//-------------------------------------------------------------------------
void subwindow2_motion (int x, int y)
{
	//  Notify that we are dragging over subwindow 2
	printf ("SubWindow 2: ");

	//  Print the mouse drag position
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  SubWindow 2 Passive Motion Function
//
//  This function is passed to the glutPassiveMotionFunc and is called 
//  whenever the mouse is moved.
//-------------------------------------------------------------------------
void subwindow2_pmotion (int x, int y)
{
	//  Notify that we are moving the mouse over subwindow 2
	//printf ("SubWindow 2: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  SubWindow 2 Keyboard Function
//
//  Tells which ASCII-code key has been clicked on subwindow 2.
//-------------------------------------------------------------------------
void subwindow2_keyboard (unsigned char key, int x, int y)
{
	//  Notify that an ASCII key is pressed on subwindow 2
	printf ("SubWindow 2: ");

	//  Print what key the user is hitting
	printf ("User is hitting the '%c' key.\n", key);
	printf ("ASCII code is %d.\n", key);
	
	switch (key)
	{
		//  User hits A key
		case 'a':
			
			break;

		//  User hits Shift + A key
		case 'A':
			
			break;

		//  User hits Enter
		case '\r':
			printf ("User is hitting the Return key.\n"); 
			break;

		//  User hits Space
		case ' ':
			printf ("User is hitting the Space key.\n"); 
			break;

		//  User hits back space
		case 8:
			printf ("User is hitting the Back Space key.\n"); 
			break;

		//  User hits ESC key
		case 27:
			exit (2);
			break;
	}

	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  SubWindow 2 special Keyboard Function
//
//  Tells which non-ASCII-Code key has being pressed on subwindow 2.
//-------------------------------------------------------------------------
void subwindow2_special (int key, int x, int y)
{
	//  Notify that we are pressing a non-ASCII key on subwindow 2
	printf ("SubWindow 2: ");

	switch (key)
	{
		case GLUT_KEY_F1 :
			printf ("F1 function key.\n"); 
			break;
		case GLUT_KEY_F2 :
			printf ("F2 function key. \n");  
			break;
		case GLUT_KEY_F3 :
			printf ("F3 function key. \n");  
			break;
		case GLUT_KEY_F4 :
			printf ("F4 function key. \n");  
			break;
		case GLUT_KEY_F5 :
			printf ("F5 function key. \n");  
			break;
		case GLUT_KEY_F6 :
			printf ("F6 function key. \n");  
			break;
		case GLUT_KEY_F7 :
			printf ("F7 function key. \n");  
			break;
		case GLUT_KEY_F8 :
			printf ("F8 function key. \n");  
			break;
		case GLUT_KEY_F9 :
			printf ("F9 function key. \n");  
			break;
		case GLUT_KEY_F10 :
			printf ("F10 function key. \n");  
			break;
		case GLUT_KEY_F11 :
			printf ("F11 function key. \n");  
			break;
		case GLUT_KEY_F12 :
			printf ("F12 function key. \n");  
			break;
		case GLUT_KEY_LEFT :
			printf ("Left directional key. \n");  
			break;
		case GLUT_KEY_UP :
			printf ("Up directional key. \n");  
			break;
		case GLUT_KEY_RIGHT :
			printf ("Right directional key. \n");  
			break;
		case GLUT_KEY_DOWN :
			printf ("Down directional key. \n");  
			break;
		case GLUT_KEY_PAGE_UP :
			printf ("Page up directional key. \n");  
			break;
		case GLUT_KEY_PAGE_DOWN :
			printf ("Page down directional key. \n");  
			break;
		case GLUT_KEY_HOME :
			printf ("Home directional key. \n");  
			break;
		case GLUT_KEY_END :
			printf ("End directional key. \n");  
			break;
		case GLUT_KEY_INSERT :
			printf ("Insert directional key. \n");  
			break;
	}
	
	glutPostRedisplay ();
}

//-------------------------------------------------------------------------
//  Redisplay contents of subwindow 1 and subwindow 2.
//-------------------------------------------------------------------------
void redisplay_all (void)
{
    glutSetWindow(subwindow_1);
    glutPostRedisplay();
    glutSetWindow(subwindow_2);
    glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen ()
{
	main_window_x = (glutGet (GLUT_SCREEN_WIDTH) - main_window_w)/2;
	main_window_y = (glutGet (GLUT_SCREEN_HEIGHT) - main_window_h)/2;
}

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main (int argc, char **argv)
{
	/**** Main Window *****/
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize (main_window_w, main_window_h);
	glutInitWindowPosition (main_window_x, main_window_y);
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
	
	main_window = glutCreateWindow (window_title);

    glutDisplayFunc (main_display);
	glutReshapeFunc  (main_reshape);
	glutMouseFunc (main_mouse);
	glutMotionFunc (main_motion);
	glutPassiveMotionFunc (main_pmotion);
	glutKeyboardFunc (main_keyboard);
	glutSpecialFunc (main_special);
	glutEntryFunc (main_entry);
    
	/**** Subwindow 1 *****/
    subwindow_1 = glutCreateSubWindow (main_window, subwindow1_x, subwindow1_y, subwindow1_w, subwindow1_h);
    
	glutDisplayFunc (subwindow1_display);
	glutReshapeFunc  (subwindow1_reshape);
	glutMouseFunc (subwindow1_mouse);
	glutMotionFunc (subwindow1_motion);
	glutPassiveMotionFunc (subwindow1_pmotion);
	glutKeyboardFunc (subwindow1_keyboard);
	glutSpecialFunc (subwindow1_special);
    
	/**** Subwindow 2 *****/
    subwindow_2 = glutCreateSubWindow (main_window, subwindow2_x, subwindow2_y, subwindow2_w, subwindow2_h);
    
	glutDisplayFunc (subwindow2_display);
	glutReshapeFunc  (subwindow2_reshape);
	glutMouseFunc (subwindow2_mouse);
	glutMotionFunc (subwindow2_motion);
	glutPassiveMotionFunc (subwindow2_pmotion);
	glutKeyboardFunc (subwindow2_keyboard);
	glutSpecialFunc (subwindow2_special);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Start GLUT event processing loop
	glutMainLoop();
}

