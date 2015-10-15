//*************************************************************************
//
//  File Name	: GLUI Window Template
//  Author		: Ali BaderEddin
//  Created		: December 2003
//  Modified	: July 2007
//  
//  Description	: Openning an OpenGL GLUT window along with a GLUI window
//				  containing controls to manipulate objects in the OpenGL
//				  graphics context.
//  
//*************************************************************************

//  Include windows library in order to use the Sleep function
#include <windows.h>

//  For sqrt
#include <math.h>

//  Include GLUI, GLUT, OpenGL, and GLU libraries
#include <gl/glui.h>

//*************************************************************************
//  GLUT Declarations
//*************************************************************************

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
void entry (int state);

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 512;
int window_height = 512;

//  variable representing the window title
char *window_title = "GLUI Window Template";

//  The id of the main window
GLuint main_window;

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//*************************************************************************
//  GLUI Declarations
//*************************************************************************

//  pointer to the GLUI window
GLUI * glui_window;

//  Declare live variables (related to GLUI)
int wireframe = 1;			//  Related to Wireframe Check Box
int draw = 1;				//  Related to Draw Check Box
int listbox_item_id = 12;	//  Id of the selected item in the list box
int radiogroup_item_id = 0; //  Id of the selcted radio button
float rotation_matrix[16]	//  Rotation Matrix Live Variable Array
							= { 1.0, 0.0, 0.0, 0.0, 
								0.0, 1.0, 0.0, 0.0,
								0.0, 0.0, 1.0, 0.0, 
								0.0, 0.0, 0.0, 1.0 };	
float translate_xy[2]		//  Translation XY Live Variable
							= {0, 0};			
float translate_z = 0;		//  Translation Z Live Variable
float scale = 1;			//  Spinner Scale Live Variable

// an array of RGB components
float color[] = { 1.0, 1.0, 1.0 };

//  Set up the GLUI window and its components
void setupGLUI ();

//  Idle callack function
void idle ();

//  Declare callbacks related to GLUI
void glui_callback (int arg);

//  Declare the IDs of controls generating callbacks
enum
{
	COLOR_LISTBOX = 0,
	OBJECTYPE_RADIOGROUP,
	TRANSLATION_XY,
	TRANSLATION_Z,
	ROTATION,
	SCALE_SPINNER,
	QUIT_BUTTON
};

//  The different GLUT shapes
enum GLUT_SHAPES
{
	GLUT_WIRE_CUBE = 0,
	GLUT_SOLID_CUBE,
	GLUT_WIRE_SPHERE,
	GLUT_SOLID_SPHERE,
	GLUT_WIRE_CONE,
	GLUT_SOLID_CONE,
	GLUT_WIRE_TORUS,
	GLUT_SOLID_TORUS,
	GLUT_WIRE_DODECAHEDRON,
	GLUT_SOLID_DODECAHEDRON,
	GLUT_WIRE_OCTAHEDRON,
	GLUT_SOLID_OCTAHEDRON,
	GLUT_WIRE_TETRAHEDRON,
	GLUT_SOLID_TETRAHEDRON,
	GLUT_WIRE_ICOSAHEDRON,
	GLUT_SOLID_ICOSAHEDRON,
	GLUT_WIRE_TEAPOT,
	GLUT_SOLID_TEAPOT
};

//  Support Functions
void centerOnScreen ();
void drawObject ();
void printMatrixf (float *matrix);

//*************************************************************************
//  GLUT Functions.
//*************************************************************************

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init ()
{	
	//  Set the frame buffer clear color to black. 
	glClearColor (0.0, 0.0, 0.0, 0.0);
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
//  Function to print matrix on command prompt.
//-------------------------------------------------------------------------
void printMatrixf (float *matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf ("%f%\t", matrix[i*4 + j]);
		}

		printf ("\n");
	}
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display (void)
{
	//  Notify that this is a GLUT Callback
	//printf ("GLUT: ");

	//  Show when are displaying an object
	//printf ("Displaying object...\n");

	//  Clear the window 
	glClear (GL_COLOR_BUFFER_BIT);

	//  Set the color
	glColor3fv (color);
	
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
	//  Draw the object only if the Draw check box is selected
	if (draw)
	{
		//  Push the current matrix into the model view stack
		glPushMatrix ();

		//  Apply the translation
		glTranslatef (translate_xy[0], translate_xy[1], -translate_z);

		//  Apply the rotation matrix
		glMultMatrixf (rotation_matrix);

		//  Apply the scaling
		glScalef (scale, scale, scale);

		//  Get the id of the selected object
		int selected_object = (radiogroup_item_id * 2) + 1 - wireframe;

		switch (selected_object)
        {
            //  draw glut wire cube
            case GLUT_WIRE_CUBE:
                
                glutWireCube (0.5);

                break;
            //  draw glut solid cube
            case GLUT_SOLID_CUBE:
                
                glutSolidCube (0.5);

                break;
            //  draw glut wire sphere
            case GLUT_WIRE_SPHERE:

                glutWireSphere (0.5, 50, 50);

                break;
            //  draw glut solid sphere
            case GLUT_SOLID_SPHERE:

                glutSolidSphere (0.5, 50, 50);

                break;
            //  draw glut wire Cone
            case GLUT_WIRE_CONE:

                glutWireCone (0.5, 0.5, 50, 50);

                break;
            //  draw glut solid cone
            case GLUT_SOLID_CONE:

                glutSolidCone (0.5, 0.5, 50, 50);

                break;
            //  draw glut wire Torus
            case GLUT_WIRE_TORUS:
                
                glutWireTorus (0.15, 0.25, 20, 20);

                break;
            ///  draw glut solid Torus
            case GLUT_SOLID_TORUS:

                glutSolidTorus (0.15, 0.25, 20, 20);

                break;
            //  draw a wire dodecahedron.. The reason why I'm dividing
            //  by 2 * radical (3) when I'm scaling it because I want to fit
            //  the dodecahedron which is centered at the modeling 
            //    coordinates origin with a radius of radical (3).
            case GLUT_WIRE_DODECAHEDRON:
                
                glScalef (1 / sqrt (12), 1 / sqrt (12), 1 / sqrt (12));
                glutWireDodecahedron ();

                break;
            //  draw a solid dodecahedron
            case GLUT_SOLID_DODECAHEDRON:
                glScalef (1 / sqrt (12), 1 / sqrt (12), 1 / sqrt (12));
                glutSolidDodecahedron ();

                break;
            //  draw a wire octahedron.. The reason why I'm dividing
            //  by 2 when I'm scaling is because I want to fit
            //  the octahedron which is centered at the modeling 
            //    coordinates origin with a radius of 1.
            case GLUT_WIRE_OCTAHEDRON:
                
                glScalef (0.5, 0.5, 0.5);
                glutWireOctahedron ();

                break;
            //  draw a solid tetrahedron
            case GLUT_SOLID_OCTAHEDRON:
                glScalef (0.5, 0.5, 0.5);
                glutSolidOctahedron ();

                break;
            //  draw a wire tetrahedron.. 
            case GLUT_WIRE_TETRAHEDRON:
                
                glScalef (1 / sqrt(6), 1 / sqrt(6), 1 / sqrt(6));
                glutWireTetrahedron ();

                break;
            //  draw a solid tetrahedron
            case GLUT_SOLID_TETRAHEDRON:
                glScalef (1 / sqrt(6), 1 / sqrt(6), 1 / sqrt(6));
                glutSolidTetrahedron ();

                break;
            //  draw a wire icosahedron.. The reason why I'm dividing
            //  by 2 when I'm scaling is because I want to fit
            //  the icosahedron which is centered at the modeling 
            //    coordinates origin with a radius of 1.
            case GLUT_WIRE_ICOSAHEDRON:
                
                glScalef (0.5, 0.5, 0.5);
                glutWireIcosahedron ();

                break;
            //  draw a solid icosahedron
            case GLUT_SOLID_ICOSAHEDRON:
                glScalef (0.5, 0.5, 0.5);
                glutSolidIcosahedron ();

                break;
            //  draw Wire Teapot
            case GLUT_WIRE_TEAPOT:
                
                glutWireTeapot (0.5);

                break;
            //  draw a solid Teapot
            case GLUT_SOLID_TEAPOT:

                glutSolidTeapot (0.5);

                break;
            //  Do Nothing
            default:
                break;
        }

		//  Pop our matrix from the model view stack after we finish drawing
		glPopMatrix ();
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutReshapeFunc and is called 
//  whenever the window is resized.
//-------------------------------------------------------------------------
void reshape (int w, int h)
{
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

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
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

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
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

	//  Print the mouse drag position
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutPassiveMotionFunc and is called 
//  whenever the mouse is moved.
//-------------------------------------------------------------------------
void pmotion (int x, int y)
{
	//  Notify that this is a GLUT Callback
	//printf ("GLUT: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

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
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

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
void entry (int state)
{
	//  Notify that this is a GLUT Callback
	printf ("GLUT: ");

	//  Notify theat we entered the window
	if (state == GLUT_ENTERED)
		printf ("Mouse entered GLUT window...\n");
	//  Notify that we left the window
	else if (state == GLUT_LEFT)
		printf ("Mouse left GLUT window...\n");
}

//*************************************************************************
//  GLUI Functions.
//*************************************************************************

//-------------------------------------------------------------------------
//  Setup GLUI stuff.
//-------------------------------------------------------------------------
void setupGLUI ()
{
	//  Set idle function
	GLUI_Master.set_glutIdleFunc (idle);
	
	//  Create GLUI window
	glui_window = GLUI_Master.create_glui ("Options", 0, window_x - 235, window_y);
	
	//---------------------------------------------------------------------
	// 'Object Properties' Panel
	//---------------------------------------------------------------------

	//  Add the 'Object Properties' Panel to the GLUI window
	GLUI_Panel *op_panel = glui_window->add_panel ("Object Properties");

	//  Add the Draw Check box to the 'Object Properties' Panel
	glui_window->add_checkbox_to_panel (op_panel, "Draw", &draw );

	//  Add the Wireframe Check box to the 'Object Properties' Panel
	glui_window->add_checkbox_to_panel (op_panel, "Wireframe", &wireframe );

	//  Add a separator
	glui_window->add_separator_to_panel (op_panel);

	//  Add the Color listbox to the 'Object Properties' Panel
	GLUI_Listbox *color_listbox = glui_window->add_listbox_to_panel (op_panel, 
									"Color", &listbox_item_id, COLOR_LISTBOX, glui_callback);
	
	//  Add the items to the listbox
	color_listbox->add_item (1, "Black");
	color_listbox->add_item (2, "Blue");
	color_listbox->add_item (3, "Cyan");
	color_listbox->add_item (4, "Dark Grey");
	color_listbox->add_item (5, "Grey");
	color_listbox->add_item (6, "Green");
	color_listbox->add_item (7, "Light Grey");
	color_listbox->add_item (8, "Magenta");
	color_listbox->add_item (9, "Orange");
	color_listbox->add_item (10, "Pink");
	color_listbox->add_item (11, "Red");
	color_listbox->add_item (12, "White");
	color_listbox->add_item (13, "Yellow");

	//  Select the White Color by default
	color_listbox->set_int_val (12);

	//---------------------------------------------------------------------
	// 'Object Type' Panel
	//---------------------------------------------------------------------
	
	//  Add the 'Object Type' Panel to the GLUI window
	GLUI_Rollout *ot_rollout = glui_window->add_rollout ("Object Type");

	//  Create radio button group
	GLUI_RadioGroup *ot_group = glui_window->add_radiogroup_to_panel 
								(ot_rollout, &radiogroup_item_id, OBJECTYPE_RADIOGROUP, glui_callback);
 	
	//  Add the radio buttons to the radio group
	glui_window->add_radiobutton_to_group( ot_group, "Cube" );
	glui_window->add_radiobutton_to_group( ot_group, "Sphere" );
	glui_window->add_radiobutton_to_group( ot_group, "Cone" );
	glui_window->add_radiobutton_to_group( ot_group, "Torus" );
	glui_window->add_radiobutton_to_group( ot_group, "Dodecahedron" );
	glui_window->add_radiobutton_to_group( ot_group, "Octahedron" );
	glui_window->add_radiobutton_to_group( ot_group, "Tetrahedron" );
	glui_window->add_radiobutton_to_group( ot_group, "Icosahedron" );
	glui_window->add_radiobutton_to_group( ot_group, "Teapot" );

	//---------------------------------------------------------------------
	// 'Transformation' Panel
	//---------------------------------------------------------------------

	//  Add the 'Transformation' Panel to the GLUI window
	GLUI_Panel *transformation_panel = glui_window->add_panel ("Transformation");

	//  Create transformation panel 1 that will contain the Translation controls
	GLUI_Panel *transformation_panel1 = glui_window->add_panel_to_panel (transformation_panel, "");

	//  Add the xy translation control
	GLUI_Translation *translation_xy = glui_window->add_translation_to_panel (transformation_panel1, "Translation XY", GLUI_TRANSLATION_XY, translate_xy, TRANSLATION_XY, glui_callback );
	
	//  Set the translation speed
	translation_xy->set_speed( 0.005 );

	//  Add column, but don't draw it
	glui_window->add_column_to_panel (transformation_panel1, false);

	//  Add the z translation control
	GLUI_Translation *translation_z = glui_window->add_translation_to_panel (transformation_panel1, "Translation Z", GLUI_TRANSLATION_Z, &translate_z, TRANSLATION_Z, glui_callback );

	//  Set the translation speed
	translation_z->set_speed( 0.005 );

	//  Create transformation panel 2 that will contain the rotation and spinner controls
	GLUI_Panel *transformation_panel2 = glui_window->add_panel_to_panel (transformation_panel, "");

	//  Add the rotation control
	glui_window->add_rotation_to_panel (transformation_panel2, "Rotation", rotation_matrix, ROTATION, glui_callback);
	
	//  Add separator
	glui_window->add_separator_to_panel (transformation_panel2);

	//  Add the scale spinner
	GLUI_Spinner *spinner = glui_window->add_spinner_to_panel (transformation_panel2, "Scale", GLUI_SPINNER_FLOAT, &scale, SCALE_SPINNER, glui_callback);
	
	//  Set the limits for the spinner
	spinner->set_float_limits ( -4.0, 4.0 );

	//---------------------------------------------------------------------
	// 'Quit' Button
	//---------------------------------------------------------------------

	//  Add the Quit Button
	glui_window->add_button ("Quit", QUIT_BUTTON, glui_callback);

	//  Let the GLUI window know where its main graphics window is
	glui_window->set_main_gfx_window( main_window );
}

//-------------------------------------------------------------------------
//  GLUI callback function.
//-------------------------------------------------------------------------
void glui_callback (int control_id)
{
	//  Notify that this is a GLUI Callback
	printf ("GLUI: ");

	//  Behave based on control ID
	switch (control_id)
	{
		//  Color Listbox item changed
		case COLOR_LISTBOX:

			printf ("Color List box item changed: ");

			switch (listbox_item_id)
			{
				//  Select black color
				case 1:
					color[0] = 0/255.0;
					color[1] = 0/255.0;
					color[2] = 0/255.0;
					break;
				//  Select blue color
				case 2:
					color[0] = 0/255.0;
					color[1] = 0/255.0;
					color[2] = 255/255.0;
					break;
				//  Select cyan color
				case 3:	
					color[0] = 0/255.0;
					color[1] = 255/255.0;
					color[2] = 255/255.0;
					break;
				//  Select dark grey color
				case 4:
					color[0] = 64/255.0;
					color[1] = 64/255.0;
					color[2] = 64/255.0;
					break;
				//  Select grey color
				case 5:
					color[0] = 128/255.0;
					color[1] = 128/255.0;
					color[2] = 128/255.0;
					break;
				//  Select green color
				case 6:
					color[0] = 0/255.0;
					color[1] = 255/255.0;
					color[2] = 0/255.0;
					break;
				//  Select light gray color
				case 7:
					color[0] = 192/255.0;
					color[1] = 192/255.0;
					color[2] = 192/255.0;
					break;
				//  Select magenta color
				case 8:
					color[0] = 192/255.0;
					color[1] = 64/255.0;
					color[2] = 192/255.0;
					break;
				//  Select orange color
				case 9:
					color[0] = 255/255.0;
					color[1] = 192/255.0;
					color[2] = 64/255.0;
					break;
				//  Select pink color
				case 10:
					color[0] = 255/255.0;
					color[1] = 0/255.0;
					color[2] = 255/255.0;
					break;
				//  Select red color
				case 11:
					color[0] = 255/255.0;
					color[1] = 0/255.0;
					color[2] = 0/255.0;
					break;
				//  Select white color
				case 12:
					color[0] = 255/255.0;
					color[1] = 255/255.0;
					color[2] = 255/255.0;
					break;
				//  Select yellow color
				case 13:
					color[0] = 255/255.0;
					color[1] = 255/255.0;
					color[2] = 0/255.0;
					break;
			}

			printf ("Item %d selected.\n", listbox_item_id);

		break;

		//  A Radio Button in the radio group is selected
		case OBJECTYPE_RADIOGROUP:

			printf ("Radio Button %d selected.\n", radiogroup_item_id);

		break;

		//  Translation XY control
		case TRANSLATION_XY:

			printf ("Translating X and Y coordinates: ");
			printf ("X: %f, Y: %f.\n", translate_xy[0], translate_xy[1]);

			break;

		//  Translation Z control
		case TRANSLATION_Z:

			printf ("Translating Z coordinate: ");
			printf ("Z: %f.\n", translate_z);

			break;

		//  rotation control is being rotated
		case ROTATION:

			printf ("Rotating archball!\n");
			printMatrixf (rotation_matrix);

		break;

		//  Scaling
		case SCALE_SPINNER:

			printf ("Scaling Object: %f.\n", scale);

		break;

		//  Quit Button clicked
		case QUIT_BUTTON:
		
			printf ("Quit Button clicked... Exit!\n");

			exit (1);

		break;

	}
}

//-------------------------------------------------------------------------
//  Idle Callback function.
//
//  Set the main_window as the current window to avoid sending the
//  redisplay to the GLUI window rather than the GLUT window. 
//  Call the Sleep function to stop the GLUI program from causing
//  starvation.
//-------------------------------------------------------------------------
void idle ()
{
	glutSetWindow (main_window);
	glutPostRedisplay ();
	Sleep (50);
}


//*************************************************************************
//  Program Main method.
//*************************************************************************
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
	main_window = glutCreateWindow (window_title);

	//  View in full screen if the full_screen flag is on
	if (full_screen)
		glutFullScreen ();

	//  Set OpenGL context initial state.
	init();
	
	// Set the GLUT callback functions
	glutDisplayFunc (display);
	glutReshapeFunc  (reshape);
	glutMouseFunc (mouse);
	glutMotionFunc (motion);
	glutPassiveMotionFunc (pmotion);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);
	glutEntryFunc (entry);

	//  Setup all GLUI stuff
	setupGLUI ();

	//  Start GLUT event processing loop
	glutMainLoop();
}

