//*************************************************************************
//
//  File Name	: skeleton.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: skeleton code to run the generated code for geometric primitives.
//			 The generated code will replace the first HTML comment found.
//  
//*************************************************************************

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Standard Input\Output C Library
#include <stdio.h>

//  Initialization
void init ();

//  Callback functions
void display (void);
void reshape (int w, int h);
void mouse (int button, int state, int x, int y);
void motion (int x, int y);
void pmotion (int x, int y);
void keyboard (unsigned char key, int x, int y);
void special (int key, int x, int y);

//  Support Functions
void centerOnScreen ();
void drawObject ();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size (Set them as original program that generates the geometric primitives)
int window_width = 512;
int window_height = 512;

//  variable representing the window title
char *window_title = "Geometric Primitives";

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Set the frame buffer clear color to black. 
	glClearColor (0.0, 0.0, 0.0, 0.0);
	
	//  Set World Coordinates the same as original program that draws the geometric primitives
	gluOrtho2D (0.0, 22.0, 0.0, 26.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear (GL_COLOR_BUFFER_BIT);
	
	//  Draw object
	drawObject ();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers ();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject ()
{
		//  Set the drawing color
	glColor3f(0.00, 0.00, 1.00);

	//  Display geometric primitives
	glBegin(GL_LINES);
		glVertex2f(1.26, 0.96);
		glVertex2f(1.72, 1.48);
		glVertex2f(1.72, 1.48);
		glVertex2f(1.60, 1.86);
		glVertex2f(2.75, 1.09);
		glVertex2f(2.63, 1.86);
		glVertex2f(4.12, 1.09);
		glVertex2f(3.89, 1.99);
		glVertex2f(8.35, 0.96);
		glVertex2f(9.15, 1.99);
		glVertex2f(9.15, 0.96);
		glVertex2f(9.96, 1.99);
		glVertex2f(21.28, 0.96);
		glVertex2f(20.94, 3.02);
		glVertex2f(9.04, 1.99);
		glVertex2f(9.96, 3.02);
		glVertex2f(9.96, 1.99);
		glVertex2f(10.64, 3.02);
		glVertex2f(1.49, 1.99);
		glVertex2f(1.37, 2.63);
		glVertex2f(1.37, 2.63);
		glVertex2f(2.06, 3.14);
		glVertex2f(2.63, 1.99);
		glVertex2f(2.06, 3.27);
		glVertex2f(3.89, 2.12);
		glVertex2f(4.00, 3.14);
		glVertex2f(2.06, 3.14);
		glVertex2f(1.95, 4.17);
		glVertex2f(3.89, 3.02);
		glVertex2f(4.35, 4.11);
		glVertex2f(10.64, 3.08);
		glVertex2f(11.44, 3.98);
		glVertex2f(9.96, 3.08);
		glVertex2f(10.53, 4.11);
		glVertex2f(10.30, 3.85);
		glVertex2f(8.47, 3.98);
		glVertex2f(20.83, 3.08);
		glVertex2f(20.71, 3.98);
		glVertex2f(1.95, 4.11);
		glVertex2f(2.17, 5.13);
		glVertex2f(4.23, 3.98);
		glVertex2f(4.58, 5.01);
		glVertex2f(6.41, 5.01);
		glVertex2f(8.35, 3.98);
		glVertex2f(10.53, 3.98);
		glVertex2f(11.21, 5.01);
		glVertex2f(11.44, 3.98);
		glVertex2f(13.27, 5.01);
		glVertex2f(20.71, 3.98);
		glVertex2f(20.71, 3.98);
		glVertex2f(20.37, 5.01);
		glVertex2f(20.71, 3.98);
		glVertex2f(10.87, 4.62);
		glVertex2f(8.93, 5.01);
		glVertex2f(2.29, 5.13);
		glVertex2f(2.98, 6.03);
		glVertex2f(4.46, 5.01);
		glVertex2f(4.35, 6.03);
		glVertex2f(4.58, 5.01);
		glVertex2f(5.03, 6.03);
		glVertex2f(6.41, 5.13);
		glVertex2f(5.61, 5.90);
		glVertex2f(8.93, 5.01);
		glVertex2f(6.64, 6.03);
		glVertex2f(10.53, 3.47);
		glVertex2f(11.90, 5.01);
		glVertex2f(11.90, 5.01);
		glVertex2f(13.27, 6.03);
		glVertex2f(11.21, 5.13);
		glVertex2f(12.13, 6.03);
		glVertex2f(13.27, 5.01);
		glVertex2f(14.99, 6.03);
		glVertex2f(20.37, 5.13);
		glVertex2f(19.34, 6.03);
		glVertex2f(20.37, 5.26);
		glVertex2f(20.14, 6.03);
		glVertex2f(3.09, 6.03);
		glVertex2f(3.66, 7.06);
		glVertex2f(4.35, 6.03);
		glVertex2f(4.46, 7.06);
		glVertex2f(5.03, 6.03);
		glVertex2f(5.26, 7.06);
		glVertex2f(5.49, 5.90);
		glVertex2f(5.15, 6.67);
		glVertex2f(6.52, 6.16);
		glVertex2f(5.84, 7.19);
		glVertex2f(12.13, 6.03);
		glVertex2f(13.73, 7.06);
		glVertex2f(12.70, 6.55);
		glVertex2f(12.82, 7.06);
		glVertex2f(13.27, 6.03);
		glVertex2f(16.94, 7.06);
		glVertex2f(18.88, 7.06);
		glVertex2f(16.94, 7.19);
		glVertex2f(18.77, 7.06);
		glVertex2f(20.14, 6.16);
		glVertex2f(14.99, 6.03);
		glVertex2f(16.25, 6.55);
		glVertex2f(16.25, 6.55);
		glVertex2f(18.31, 6.67);
		glVertex2f(18.42, 6.67);
		glVertex2f(19.22, 6.03);
		glVertex2f(18.88, 7.19);
		glVertex2f(18.31, 8.09);
		glVertex2f(16.02, 7.83);
		glVertex2f(13.73, 7.19);
		glVertex2f(13.04, 8.09);
		glVertex2f(12.82, 7.06);
		glVertex2f(7.21, 7.96);
		glVertex2f(6.52, 7.57);
		glVertex2f(5.72, 7.32);
		glVertex2f(6.41, 7.44);
		glVertex2f(5.61, 7.44);
		glVertex2f(5.26, 7.19);
		glVertex2f(4.69, 8.09);
		glVertex2f(4.46, 7.19);
		glVertex2f(4.23, 8.09);
		glVertex2f(3.66, 7.19);
		glVertex2f(18.31, 8.09);
		glVertex2f(17.62, 8.47);
		glVertex2f(15.91, 7.96);
		glVertex2f(17.51, 8.47);
		glVertex2f(17.62, 8.47);
		glVertex2f(17.39, 9.11);
		glVertex2f(12.93, 7.96);
		glVertex2f(13.16, 8.60);
		glVertex2f(13.16, 8.86);
		glVertex2f(13.04, 9.11);
		glVertex2f(7.21, 7.96);
		glVertex2f(7.44, 8.98);
		glVertex2f(4.69, 8.21);
		glVertex2f(5.15, 8.98);
		glVertex2f(4.12, 8.09);
		glVertex2f(4.69, 8.34);
		glVertex2f(5.15, 8.98);
		glVertex2f(5.49, 10.01);
		glVertex2f(7.44, 8.86);
		glVertex2f(8.01, 10.01);
		glVertex2f(13.04, 9.24);
		glVertex2f(12.82, 10.14);
		glVertex2f(17.39, 9.24);
		glVertex2f(17.05, 10.14);
		glVertex2f(17.05, 10.14);
		glVertex2f(16.36, 11.04);
		glVertex2f(12.70, 10.27);
		glVertex2f(12.70, 10.91);
		glVertex2f(8.01, 10.01);
		glVertex2f(9.04, 10.65);
		glVertex2f(9.04, 10.65);
		glVertex2f(9.27, 11.17);
		glVertex2f(5.49, 9.88);
		glVertex2f(5.72, 11.04);
		glVertex2f(5.72, 11.04);
		glVertex2f(4.92, 10.91);
		glVertex2f(5.03, 10.91);
		glVertex2f(4.00, 11.17);
		glVertex2f(4.00, 11.04);
		glVertex2f(3.32, 10.91);
		glVertex2f(3.32, 10.91);
		glVertex2f(2.63, 11.29);
		glVertex2f(2.63, 11.29);
		glVertex2f(2.17, 11.42);
		glVertex2f(2.17, 11.42);
		glVertex2f(1.60, 11.29);
		glVertex2f(1.60, 11.29);
		glVertex2f(1.14, 11.04);
		glVertex2f(1.14, 11.04);
		glVertex2f(0.80, 10.91);
		glVertex2f(0.80, 10.91);
		glVertex2f(0.34, 10.52);
		glVertex2f(0.23, 10.52);
		glVertex2f(0.11, 10.27);
		glVertex2f(5.61, 11.17);
		glVertex2f(5.38, 12.19);
		glVertex2f(9.15, 11.17);
		glVertex2f(9.04, 12.19);
		glVertex2f(12.70, 10.91);
		glVertex2f(12.82, 12.06);
		glVertex2f(16.36, 11.29);
		glVertex2f(16.13, 12.06);
		glVertex2f(16.13, 11.81);
		glVertex2f(17.28, 12.58);
		glVertex2f(17.28, 12.58);
		glVertex2f(17.74, 12.58);
		glVertex2f(17.74, 12.58);
		glVertex2f(18.42, 12.32);
		glVertex2f(18.42, 12.32);
		glVertex2f(19.00, 12.32);
		glVertex2f(18.88, 12.32);
		glVertex2f(19.91, 11.55);
		glVertex2f(19.91, 11.55);
		glVertex2f(20.94, 10.78);
		glVertex2f(20.94, 10.78);
		glVertex2f(21.40, 10.78);
		glVertex2f(21.51, 10.78);
		glVertex2f(21.86, 10.52);
		glVertex2f(21.86, 10.52);
		glVertex2f(22.54, 10.52);
		glVertex2f(16.25, 12.06);
		glVertex2f(16.02, 12.96);
		glVertex2f(12.93, 12.06);
		glVertex2f(12.70, 13.09);
		glVertex2f(9.04, 12.19);
		glVertex2f(8.93, 12.83);
		glVertex2f(5.38, 12.19);
		glVertex2f(5.15, 13.09);
		glVertex2f(16.02, 12.96);
		glVertex2f(15.91, 14.12);
		glVertex2f(12.70, 13.09);
		glVertex2f(12.82, 13.99);
		glVertex2f(11.33, 13.99);
		glVertex2f(9.96, 13.09);
		glVertex2f(9.96, 13.09);
		glVertex2f(8.81, 12.96);
		glVertex2f(8.81, 12.96);
		glVertex2f(7.67, 13.99);
		glVertex2f(5.15, 13.09);
		glVertex2f(5.15, 14.12);
		glVertex2f(5.15, 14.12);
		glVertex2f(3.89, 13.99);
		glVertex2f(3.89, 13.99);
		glVertex2f(3.55, 13.35);
		glVertex2f(3.55, 13.35);
		glVertex2f(2.98, 13.35);
		glVertex2f(2.98, 13.35);
		glVertex2f(1.95, 12.71);
		glVertex2f(1.95, 12.71);
		glVertex2f(1.26, 12.71);
		glVertex2f(1.26, 12.71);
		glVertex2f(0.92, 11.94);
		glVertex2f(0.92, 11.94);
		glVertex2f(0.11, 11.42);
		glVertex2f(9.38, 14.37);
		glVertex2f(9.04, 14.25);
		glVertex2f(9.04, 14.25);
		glVertex2f(8.58, 14.37);
		glVertex2f(5.15, 14.12);
		glVertex2f(5.15, 14.89);
		glVertex2f(7.55, 13.99);
		glVertex2f(7.21, 15.02);
		glVertex2f(11.33, 14.12);
		glVertex2f(12.24, 15.02);
		glVertex2f(12.82, 13.99);
		glVertex2f(13.04, 15.02);
		glVertex2f(15.91, 14.12);
		glVertex2f(15.79, 15.02);
		glVertex2f(8.24, 15.02);
		glVertex2f(8.93, 14.76);
		glVertex2f(9.38, 15.02);
		glVertex2f(9.04, 14.89);
		glVertex2f(9.38, 15.02);
		glVertex2f(9.96, 15.14);
		glVertex2f(5.15, 15.02);
		glVertex2f(5.26, 16.04);
		glVertex2f(13.04, 15.02);
		glVertex2f(13.04, 16.04);
		glVertex2f(15.79, 15.02);
		glVertex2f(15.56, 16.04);
		glVertex2f(15.91, 14.50);
		glVertex2f(16.48, 14.63);
		glVertex2f(16.48, 14.63);
		glVertex2f(16.94, 14.50);
		glVertex2f(16.94, 14.50);
		glVertex2f(17.97, 14.50);
		glVertex2f(17.97, 14.50);
		glVertex2f(18.88, 14.50);
		glVertex2f(18.88, 14.50);
		glVertex2f(19.57, 14.50);
		glVertex2f(20.14, 14.76);
		glVertex2f(19.68, 14.50);
		glVertex2f(20.14, 14.63);
		glVertex2f(20.94, 15.02);
		glVertex2f(20.94, 15.02);
		glVertex2f(21.40, 15.53);
		glVertex2f(21.40, 15.53);
		glVertex2f(21.86, 15.53);
		glVertex2f(21.97, 15.53);
		glVertex2f(22.43, 15.40);
		glVertex2f(7.21, 15.02);
		glVertex2f(6.98, 16.17);
		glVertex2f(6.98, 16.30);
		glVertex2f(6.75, 17.07);
		glVertex2f(5.26, 16.04);
		glVertex2f(5.26, 16.94);
		glVertex2f(13.04, 16.04);
		glVertex2f(13.04, 16.04);
		glVertex2f(13.04, 16.04);
		glVertex2f(12.93, 16.94);
		glVertex2f(15.56, 16.04);
		glVertex2f(15.33, 16.94);
		glVertex2f(9.61, 16.30);
		glVertex2f(9.38, 15.79);
		glVertex2f(9.04, 15.79);
		glVertex2f(9.38, 15.79);
		glVertex2f(9.04, 15.79);
		glVertex2f(9.04, 15.79);
		glVertex2f(9.04, 15.79);
		glVertex2f(8.70, 15.66);
		glVertex2f(8.70, 15.66);
		glVertex2f(8.24, 16.04);
		glVertex2f(8.24, 16.04);
		glVertex2f(8.35, 16.94);
		glVertex2f(8.35, 16.94);
		glVertex2f(8.47, 17.97);
		glVertex2f(6.75, 17.07);
		glVertex2f(6.87, 17.97);
		glVertex2f(5.26, 16.94);
		glVertex2f(5.49, 17.97);
		glVertex2f(12.93, 16.94);
		glVertex2f(12.70, 17.97);
		glVertex2f(15.33, 16.94);
		glVertex2f(15.22, 17.97);
		glVertex2f(22.31, 16.56);
		glVertex2f(21.40, 16.56);
		glVertex2f(21.40, 16.56);
		glVertex2f(20.94, 16.81);
		glVertex2f(20.94, 16.81);
		glVertex2f(20.02, 16.43);
		glVertex2f(20.02, 16.43);
		glVertex2f(19.00, 16.30);
		glVertex2f(19.00, 16.30);
		glVertex2f(17.62, 16.94);
		glVertex2f(17.62, 16.94);
		glVertex2f(17.05, 17.45);
		glVertex2f(17.05, 17.45);
		glVertex2f(16.82, 17.97);
		glVertex2f(16.82, 17.97);
		glVertex2f(16.48, 18.99);
		glVertex2f(16.48, 18.99);
		glVertex2f(15.22, 17.71);
		glVertex2f(15.22, 18.10);
		glVertex2f(14.99, 19.12);
		glVertex2f(12.70, 17.97);
		glVertex2f(12.36, 19.12);
		glVertex2f(6.87, 18.10);
		glVertex2f(6.87, 19.12);
		glVertex2f(5.49, 17.97);
		glVertex2f(5.38, 18.99);
		glVertex2f(8.47, 18.10);
		glVertex2f(8.58, 18.48);
		glVertex2f(8.58, 18.48);
		glVertex2f(8.35, 18.99);
		glVertex2f(8.35, 18.99);
		glVertex2f(7.90, 19.12);
		glVertex2f(7.90, 19.12);
		glVertex2f(7.55, 19.12);
		glVertex2f(7.55, 19.12);
		glVertex2f(7.32, 18.87);
		glVertex2f(5.26, 17.07);
		glVertex2f(4.58, 17.97);
		glVertex2f(4.58, 17.97);
		glVertex2f(3.55, 17.58);
		glVertex2f(3.55, 17.58);
		glVertex2f(2.40, 19.12);
		glVertex2f(2.40, 19.12);
		glVertex2f(1.83, 19.64);
		glVertex2f(1.83, 19.64);
		glVertex2f(1.03, 19.76);
		glVertex2f(1.03, 19.76);
		glVertex2f(0.11, 20.53);
		glVertex2f(5.38, 19.12);
		glVertex2f(5.61, 20.02);
		glVertex2f(6.87, 19.12);
		glVertex2f(6.75, 20.02);
		glVertex2f(12.36, 19.12);
		glVertex2f(12.13, 20.02);
		glVertex2f(14.99, 19.12);
		glVertex2f(14.88, 20.02);
		glVertex2f(7.32, 18.48);
		glVertex2f(7.67, 18.74);
		glVertex2f(7.67, 18.74);
		glVertex2f(8.12, 18.74);
		glVertex2f(7.67, 18.48);
		glVertex2f(7.90, 18.35);
		glVertex2f(7.67, 18.35);
		glVertex2f(7.90, 18.61);
		glVertex2f(9.73, 18.74);
		glVertex2f(10.30, 18.99);
		glVertex2f(10.30, 18.99);
		glVertex2f(10.76, 18.99);
		glVertex2f(10.76, 18.99);
		glVertex2f(10.99, 18.74);
		glVertex2f(9.96, 18.48);
		glVertex2f(10.30, 18.61);
		glVertex2f(10.53, 18.61);
		glVertex2f(10.87, 18.48);
		glVertex2f(10.30, 18.48);
		glVertex2f(10.41, 18.22);
		glVertex2f(10.53, 18.35);
		glVertex2f(10.30, 18.35);
		glVertex2f(5.61, 20.02);
		glVertex2f(6.18, 21.05);
		glVertex2f(6.75, 20.15);
		glVertex2f(6.98, 20.92);
		glVertex2f(12.13, 20.02);
		glVertex2f(11.90, 20.92);
		glVertex2f(14.88, 20.02);
		glVertex2f(14.65, 20.92);
		glVertex2f(6.18, 21.05);
		glVertex2f(6.52, 21.95);
		glVertex2f(6.98, 20.92);
		glVertex2f(7.32, 21.95);
		glVertex2f(11.90, 20.92);
		glVertex2f(11.44, 21.95);
		glVertex2f(14.65, 20.92);
		glVertex2f(14.19, 21.95);
		glVertex2f(6.52, 21.93);
		glVertex2f(6.87, 22.99);
		glVertex2f(7.32, 21.93);
		glVertex2f(8.01, 22.46);
		glVertex2f(8.01, 22.46);
		glVertex2f(8.70, 23.13);
		glVertex2f(8.70, 23.13);
		glVertex2f(9.96, 22.99);
		glVertex2f(9.96, 22.99);
		glVertex2f(10.87, 22.73);
		glVertex2f(10.87, 22.73);
		glVertex2f(11.44, 21.93);
		glVertex2f(14.19, 22.06);
		glVertex2f(13.62, 23.13);
		glVertex2f(8.70, 23.13);
		glVertex2f(9.15, 24.06);
		glVertex2f(6.87, 23.13);
		glVertex2f(8.12, 24.06);
		glVertex2f(13.62, 23.13);
		glVertex2f(12.47, 24.06);
		glVertex2f(8.01, 24.05);
		glVertex2f(8.93, 24.61);
		glVertex2f(8.93, 24.61);
		glVertex2f(9.27, 24.47);
		glVertex2f(9.38, 24.47);
		glVertex2f(9.96, 24.75);
		glVertex2f(9.96, 24.75);
		glVertex2f(10.99, 24.75);
		glVertex2f(10.99, 24.75);
		glVertex2f(12.42, 24.12);
	glEnd();


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

	//  Print current width and height on the screen
	printf ("Window Width: %d, Window Height: %d.\n", window_width, window_height);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMouseFunc and is called 
//  whenever the mouse is clicked.
//-------------------------------------------------------------------------
void mouse (int button, int state, int x, int y)
{
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
//  This function is passed to the glutMotionFunc and is called 
//  whenever the mouse is dragged.
//-------------------------------------------------------------------------
void motion (int x, int y)
{
	//  Print the mouse drag position
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutPassiveMotionFunc and is called 
//  whenever the mouse is moved.
//-------------------------------------------------------------------------
void pmotion (int x, int y)
{
	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
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
//  This function is passed to the glutSpecialFunc and is called 
//  whenever the user hits a special key.
//-------------------------------------------------------------------------
void special (int key, int x, int y)
{
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
			printf ("Inset directional key. \n");  
			break;
	}
	
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
	//  Set the window x and y coordinates such that the 
	//  window becomes centered
	centerOnScreen ();

	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
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
	glutReshapeFunc  (reshape);
	glutMouseFunc (mouse);
	glutMotionFunc (motion);
	glutPassiveMotionFunc (pmotion);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);

	//  Start GLUT event processing loop
	glutMainLoop();
}

