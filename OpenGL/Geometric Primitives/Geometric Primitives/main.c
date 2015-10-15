//*************************************************************************
//
//  File Name	: OpenGL_Geometric_Primitives.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Explore OpenGL Geometric Primitives through this 
//				  interactive program.
//  
//*************************************************************************

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Standard Input\Output C Library
#include <stdio.h>

//  For strcpy and strcat
#include<string.h>

//  For time function
#include <time.h>

//  Include supporting modules
#include "vertex.h"
#include "utils.h"
#include "color.h"
#include "menu.h"

//  Initialization
void init();

//  Callback functions
void display(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);
void motion (int x, int y);
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);

//  Support Functions
void centerOnScreen();
void drawObject();
void drawGrid();
void drawPrimitive();
void drawPolygonBorder();
void drawVertices();
void addRowToGrid(int n);
void addColumnToGrid(int n);
void displayHelp();
void generateCode();
void generateVertices();
void changePointSize(float *pointSize, float step);
void changeLineWidth(float *lineWidth, float step);
void changePrimitiveColor(int step);
void changePrimitiveMode(int step);
const char * modeToString(int mode);
void setMode(int value);
void getMonaLisa();
void getRandomColors();
void getNextKey(unsigned char key);

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 512;
int window_height = 512;

//  variable representing the window title
const char *window_title = "OpenGL Geometric Primitives";
char current_title[256];

//  Tells whether to display the window full screen or not
//  Press Alt + Esc to exit a full screen.
int full_screen = 0;

//  Represents the width and height of the world coordinate system
GLdouble world_width, world_height;

//  Specifies the primitive or primitives that will be created from 
//  vertices presented between glBegin and the subsequent glEnd. 
//  Ten symbolic constants are accepted: GL_POINTS, GL_LINES, GL_LINE_STRIP,
//  GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, 
//  GL_QUAD_STRIP, and GL_POLYGON.
int mode;

//  Represents the primitive type, which can be Point, Line, or Polygon
typedef enum
{
	DOT,
	LINE,
	POLYGON
} PrimitiveType;

PrimitiveType type;

// Represent the colors of the differnet objects displayed
GLfloat primitiveColor[3];
GLfloat vertexColor[3];
GLfloat gridColor[3];
GLfloat backColor[3];
GLfloat borderColor[3];

//  Represent the head and tail of the linked list of vertices
Vertex *head, *tail;

//  Booleans that tells whether to display a vertex or its number
int displayVertex = 1, displayVertexNum = 1;

//  Boolean that tells whether to display the grid
int displayGrid = 1;

//  Tells whether to display border of polygon
int displayBorder = 1;

//  tells whether smooth shading is on or off
int smoothShading = 0;

//  Represents the vertex size
float vertexSize = 4;

//  Represents the Point Primitive size
float pointSize = 4;

//  Represents the supported point size range
float pointSizeRange[2]; 

//  Represents the supported point size increments
float pointSizeIncrement; 

//  Represents the Grid Line Width
float gridLineWidth = 1;

//  Represents the line primitive width
float lineWidth = 4;

//  Represents the supported line width range
float lineWidthRange[2]; 

//  Represents the supported line width increments
float lineWidthIncrement; 

//  Represents the maximum number of vertices to be generated randomly
int generationRate = 20;

//  Tells whether to auto palce a point on the grid
int autoPlot = 1;

//  represent current primitive and current primitive color
int primitiveColorId;

//  Tells whether dragging is enabled
int dragEnabled = 0;

//  Represents the name of skeleton file and name of file to generate
char *skeletonFileName = "skeleton.c";
char *programFileName = "program.c";

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init()
{	
	//  Set the world coordinates. 
	//  gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
	//  The default world coordinates are between -1 and 1. 
	//  So it is as if you're calling
	//  gluOrtho2D(-1.0, 1.0, -1.0, 1.0)
	world_width = world_height = 5.0;
	gluOrtho2D(0.0, world_width, 0.0, world_height);
	
	//  Initially, there are no vertices in the vertex list.
	head = tail = NULL;
	
	// Get supported point size range and step size
	glGetFloatv(GL_POINT_SIZE_RANGE, pointSizeRange);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY,&pointSizeIncrement);

	//  Get supported line width range and step size
	glGetFloatv(GL_LINE_WIDTH_RANGE, lineWidthRange);
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY,&lineWidthIncrement);

	//  Set the mode intially to GL_LINE_STRIP
	setMode (GL_LINE_STRIP);

	//  Set the primitive color to orange
	primitiveColorId = ORANGE;
	setColor(primitiveColor, primitiveColorId);

	//  Set the remaining colors
	setColor(vertexColor, BLACK);
	setColor(gridColor, BLUE);
	setColor(backColor, WHITE);
	setColor(borderColor, LIGHT_GREY);
	
	//  Set seed for random generation
	srand(time(NULL));

	//  Set up menus
	setupMenus();

	//  display help message to the user
	displayHelp();
}

//-------------------------------------------------------------------------
//  Listener to Main Menu Items
//-------------------------------------------------------------------------
void mainMenu(int value)
{
	switch(value)
	{
		//  Generate Code
		case 1:
			generateCode();
			break;
		case 2:
			getMonaLisa();
			break;
		case 3:
			getRandomColors();
			break;
		case 4:
			dragEnabled = !dragEnabled;
	}
	
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Primitive Menu Items
//-------------------------------------------------------------------------
void primitiveMenu(int value)
{
	switch (value)
	{
		//  Smooth Shading On\Off
		case 1:
			smoothShading = !smoothShading;
			break;
	}
}

//-------------------------------------------------------------------------
//  Listener to Primitive Type Menu Items
//-------------------------------------------------------------------------
void primitiveTypeMenu(int value)
{
	setMode(value);
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Set the primitive mode based on identifier
//-------------------------------------------------------------------------
void setMode(int value)
{
	mode = value;

	switch(value)
	{
		case GL_POINTS:
			type = DOT;
			break;

		case GL_LINES:
		case GL_LINE_STRIP:
		case GL_LINE_LOOP:
			type = LINE;
			break;

		case GL_TRIANGLES:
		case GL_TRIANGLE_STRIP:
		case GL_TRIANGLE_FAN:
		case GL_QUADS:
		case GL_QUAD_STRIP:
		case GL_POLYGON:
			type = POLYGON;
			break;
	}

	//  Set current title
	strcpy(current_title, window_title);
	strcat(current_title, modeToString(mode));
	glutSetWindowTitle(current_title);
}

//-------------------------------------------------------------------------
//  Helper function that convertes mode to string.
//-------------------------------------------------------------------------
const char * modeToString(int mode)
{
	switch(mode)
	{
		case GL_POINTS:
			return " - GL_POINTS";
			break;

		case GL_LINES:
			return " - GL_LINES";
			break;

		case GL_LINE_STRIP:
			return " - GL_LINE_STRIP";
			break;

		case GL_LINE_LOOP:
			return " - GL_LINE_LOOP";
			break;

		case GL_TRIANGLES:
			return " - GL_TRIANGLES";
			break;

		case GL_TRIANGLE_STRIP:
			return " - GL_TRIANGLE_STRIP";
			break;

		case GL_TRIANGLE_FAN:
			return " - GL_TRIANGLE_FAN";
			break;

		case GL_QUADS:
			return " - GL_QUADS";
			break;

		case GL_QUAD_STRIP:
			return " - GL_QUAD_STRIP";
			break;

		case GL_POLYGON:
			return " - GL_POLYGON";
			break;
	}

	return "";
}

//-------------------------------------------------------------------------
//  Listener to Primitive Color Menu Items
//-------------------------------------------------------------------------
void primitiveColorMenu(int value)
{
	primitiveColorId = value;
	setColor(primitiveColor, primitiveColorId);
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Primitive Point Size Menu
//-------------------------------------------------------------------------
void primitivePointMenu(int value)
{
	switch(value)
	{
		//  +
		case 1:
			changePointSize(&pointSize, pointSizeIncrement);
			break;
		//  -
		case 2:
			changePointSize(&pointSize, pointSizeIncrement);
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Primitive Line Width Menu
//-------------------------------------------------------------------------
void primitiveLineMenu(int value)
{
	switch(value)
	{
		//  +
		case 1:
			changeLineWidth(&lineWidth, lineWidthIncrement);
			break;
		//  -
		case 2:
			changeLineWidth(&lineWidth, -lineWidthIncrement);
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Primitive Polygon Menu
//-------------------------------------------------------------------------
void primitivePolygonMenu(int value)
{
	switch(value)
	{
		//  Show\Hide border
		case 1:
			displayBorder = !displayBorder;
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Primitive Polygon Color Menu
//-------------------------------------------------------------------------
void primitivePolygonColorMenu(int value)
{
	setColor(borderColor, value);

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Vertex Menu Items
//-------------------------------------------------------------------------
void vertexMenu(int value)
{
	switch(value)
	{
		//  Generate Vertices
		case 1:
			generateVertices();
			break;
		//  Delete Vertices
		case 2:
			clearVertices(&head, &tail);
			break;
		//  Show\Hide Points
		case 3:
			displayVertex = !displayVertex;
			break;
		//  Show\Hide Numbers
		case 4:
			displayVertexNum = !displayVertexNum;
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Vertex Generation Rate Menu Items.
//-------------------------------------------------------------------------
void vertexRateMenu(int value)
{
	switch(value)
	{
		//  +
		case 1:
			generationRate += 10;
			break;
		//  -
		case 2:
			generationRate -= 10;

			if (generationRate <= 10)
				generationRate = 10;

			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Vertex Size Menu Items.
//-------------------------------------------------------------------------
void vertexSizeMenu(int value)
{
	switch(value)
	{
		//  +
		case 1:
			changePointSize(&vertexSize, pointSizeIncrement);
			break;
		//  -
		case 2:
			changePointSize(&vertexSize, -pointSizeIncrement);
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Changes the value of the vertex size between the range of allowed
//  values.
//-------------------------------------------------------------------------
void changePointSize(float *pointSize, float step)
{
	//  change size
	*pointSize += step;


	//  check against min boundary
	if (*pointSize < pointSizeRange[0])
		*pointSize = pointSizeRange[0];

	//  check against max boundary
	if (*pointSize > pointSizeRange[1])
		*pointSize = pointSizeRange[1];
}

//-------------------------------------------------------------------------
//  Listener to Vertex color Menu Items.
//-------------------------------------------------------------------------
void vertexColorMenu(int value)
{
	setColor(vertexColor, value);

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Grid Menu Items.
//-------------------------------------------------------------------------
void gridMenu(int value)
{
	switch(value)
	{
		//  Show\Hide Grid
		case 1:
			displayGrid = !displayGrid;
			break;
		//  Enable/Disable Auto Plotting
		case 2:
			autoPlot = !autoPlot;
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Adds\removes n rows to\from the Grid.
//-------------------------------------------------------------------------
void addRowToGrid(int n)
{
	world_height += n;

	if (world_height < 1)
		world_height = 1;

	glLoadIdentity();
	gluOrtho2D(0.0, world_width, 0.0, world_height);
}

//-------------------------------------------------------------------------
//  Listener to Grid Row Menu Items.
//-------------------------------------------------------------------------
void gridRowMenu(int value)
{
	switch(value)
	{
		//  Add
		case 1:
			addRowToGrid(1);
			break;
		//  Remove
		case 2:
			addRowToGrid(-1);
			break;
	}

	glLoadIdentity();
	gluOrtho2D(0.0, world_width, 0.0, world_height);
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Adds\removes n column to\from the Grid.
//-------------------------------------------------------------------------
void addColumnToGrid(int n)
{
	world_width += n;

	if (world_width < 1)
		world_width = 1;

	glLoadIdentity();
	gluOrtho2D(0.0, world_width, 0.0, world_height);
}

//-------------------------------------------------------------------------
//  Listener to Grid Column Menu Items.
//-------------------------------------------------------------------------
void gridColumnMenu(int value)
{
	switch(value)
	{
		//  Add
		case 1:
			addColumnToGrid(1);
			break;
		//  Remove
		case 2:
			addColumnToGrid(-1);
			break;
	}

	glLoadIdentity();
	gluOrtho2D(0.0, world_width, 0.0, world_height);
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Grid Line Width Menu Items.
//-------------------------------------------------------------------------
void gridLineWidthMenu(int value)
{
	switch(value)
	{
		//  +
		case 1:
			changeLineWidth(&gridLineWidth, lineWidthIncrement);
			break;
		// -
		case 2:
			changeLineWidth(&gridLineWidth, -lineWidthIncrement);
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Changes the value of the grid line width between the range of allowed
//  values.
//-------------------------------------------------------------------------
void changeLineWidth(float *lineWidth, float step)
{
	//  change size
	*lineWidth += step;

	//  check against min boundary
	if (*lineWidth < lineWidthRange[0])
		*lineWidth = lineWidthRange[0];

	//  check against max boundary
	if (*lineWidth > lineWidthRange[1])
		*lineWidth = lineWidthRange[1];
}

//-------------------------------------------------------------------------
//  Listener to Grid Color Menu Items.
//-------------------------------------------------------------------------
void gridColorMenu(int value)
{
	setColor(gridColor, value);

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Listener to Back Color Menu Items.
//-------------------------------------------------------------------------
void backColorMenu(int value)
{
	setColor(backColor, value);

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  displays help to the user
//-------------------------------------------------------------------------
void displayHelp()
{
	printf("\n***************** \t\tHelp\t\t *****************\n\n");
	
	printf("Keyboard\n\n");

	printf(" %s\t\t%s\n", "Left\\Right", "Change Geometric Primitive");
	printf(" %s\t\t%s\n", "Up\\Down", "Change Primitive Color");
	printf("\n");
	printf(" %s\t\t\t%s\n", "a", "Turn On\\Off auto-plotting on grid");
	printf(" %s\t\t\t%s\n", "C\\c", "Add\\Remove column from Grid");
	printf(" %s\t\t\t%s\n", "d", "Delete all vertices");
	printf(" %s\t\t\t%s\n", "g", "Show\\Hide Grid");
	printf(" %s\t\t\t%s\n", "h", "Display this help message");
	printf(" %s\t\t\t%s\n", "L\\l", "Increase\\Decrease Line Width");
	printf(" %s\t\t\t%s\n", "n", "Show\\Hide Numbers");
	printf(" %s\t\t\t%s\n", "p", "Show\\Hide Points");
	printf(" %s\t\t\t%s\n", "R\\r", "Add\\Remove Row From Grid");
	printf(" %s\t\t\t%s\n", "S\\s", "Increase\\Decrease point size");
	printf(" %s\t\t\t%s\n", "T\\t", "Increase\\Decrease Generation Rate for vertices");
	printf(" %s\t\t\t%s\n", "v", "Generate Vertices");
	printf(" %s\t\t\t%s\n", "W\\w", "Increase\\Decrease Grid Line Width");
	printf(" %s\t\t\t%s\n", "X\\x", "Increase\\Decrease vertex size");
	printf(" %s\t\t\t%s\n", "z", "Remove the last inserted vertex");

	printf("\n\nMouse\n\n");

	printf(" %s\t\t%s\n", "Left Button", "Add a vertex");
	printf(" %s\t\t%s\n", "Middle Button", "Remove a vertex");
	printf(" %s\t\t%s\n", "Right Button", "Display menu");


	printf("\n\n***************** \t\tHelp\t\t *****************\n\n");
}

//-------------------------------------------------------------------------
//  Generates random colors
//-------------------------------------------------------------------------
void getRandomColors()
{
	Vertex *temp;

	//  Set random colors
	loadRandomColor(primitiveColor);
	loadRandomColor(vertexColor);
	loadRandomColor(gridColor);
	loadRandomColor(backColor);
	loadRandomColor(borderColor);

	//  Set points random colors
	for(temp = head; temp != NULL; temp = temp->np)
	{
		temp->r = (rand() % 256)/255.0;
		temp->g = (rand() % 256)/255.0;
		temp->b = (rand() % 256)/255.0;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Draws Mona Lisa
//-------------------------------------------------------------------------
void getMonaLisa()
{
	//  Declarations
	FILE *f_input;		//  Input and Output File handles
	float x, y;			//  x and y coordinates

	//  Open File to read points
	f_input = fopen("mona.p", "r");

	//  If we can't open file, then return
	if(f_input == NULL)
		return;	

	//  Clear all vertices
	clearVertices(&head, &tail);

	//  Set current primitive to GL_LINES
	setMode(GL_LINES);

	//  Hide vertex numbers
	displayVertexNum = 0;

	//  reset the world coordinates
	glLoadIdentity();
	world_width = 22;
	world_height = 26;
	gluOrtho2D(0.0, world_width, 0.0, world_height);

	//  Add all the vertices
	while (!feof(f_input))
	{
		fscanf(f_input, "%f, %f", &x, &y);
		addVertex(&head, &tail, x, y, 0.0, primitiveColor[0], primitiveColor[1], primitiveColor[2]);
	}

	//  Redisplay
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Generates openGL code for the primitives drawn.
//  The program looks into the skeleton file for the first HTML comment 
//  placed(i.e. <!-- comment here -->, and replaces it with the generated
//  code of the geometric primitives. If thre is no skeleton file or 
//  there is no HTML comment, then the code segment is generated as is
//  to the new file.
//-------------------------------------------------------------------------
void generateCode()
{
	//  Declarations
	FILE *f_output, *f_input;  //  Input and Output File handles
	Vertex * temp;			   //  Temp Vertex
	char cc;				   //  Current Character
	char pc;				   //  Previous Character
	int commentFound = 0;	   //  Tells whether the HTML comment was found
	int useSkeletonFile = 1;   //  Tells whether to use skeleton file or not

	//  Open File to find HTML comment inside it
	f_input = fopen(skeletonFileName, "r");

	//  If we can't open file, then don't use it
	if(f_input == NULL)
		useSkeletonFile = 0;
	
	//  Open File to write code to it
	f_output = fopen(programFileName, "w");

	//  Don't continue if failed to create file for writing
	if(f_output == NULL)
		return;
	
	if(useSkeletonFile)
	{
		//  Search for the HTML comment <!-- whatever here --> in the skeleton file.
		do
		{
			//  Get character
			cc = fgetc(f_input);

			//  Try to find comment
			if(cc == '<')
			{
				pc = cc;
				cc = fgetc(f_input);
				
				if(cc == '!')
				{
					cc = fgetc(f_input);

					if(cc == '-')
					{
						cc = fgetc(f_input);

						if(cc == '-')
						{
							do
							{
								cc = fgetc(f_input);

								if(cc == '-')
								{
									cc = fgetc(f_input);

									if(cc == '-')
									{
										cc = fgetc(f_input);

										if(cc == '>')
										{
											commentFound = 1;
										}
									}
								}
							}
							while(cc != EOF && !commentFound);
						}
					}
				}
				else
				{
					fputc(pc, f_output);
					fputc(cc, f_output);
				}
			}
			else
			{
				fputc(cc, f_output);
			}
		}
		while(cc != EOF && !commentFound);

		if(!commentFound)
		{
			useSkeletonFile = 0;

			//  Close input file and clear output file
			fclose(f_input);
			f_output = freopen(programFileName, "w", f_output);
		}
	}

	//  Start writing out generated code
	fprintf(f_output, "\t//  Set shading model\n");
	if (smoothShading)
		fprintf(f_output, "\tglShadeModel(GL_SMOOTH);\n");
	else
		fprintf(f_output, "\tglShadeModel(GL_FLAT);\n");
	fprintf(f_output, "\n");
	fprintf(f_output, "\t//  Set the primitive color\n");
	fprintf(f_output, "\tglColor3f(%.2f, %.2f, %.2f);\n", 
		    primitiveColor[0], primitiveColor[1], primitiveColor[2]);
	fprintf(f_output, "\n");
	
	if (type == DOT)
	{
		fprintf(f_output, "\t//  Set the point size\n");
		fprintf(f_output, "\tglPointSize(%.2f);\n", pointSize);
		fprintf(f_output, "\n");
	}
	
	if (type == LINE)
	{
		fprintf(f_output, "\t//  Set the line width\n");
		fprintf(f_output, "\tglLineWidth(%.2f);\n", lineWidth);
		fprintf(f_output, "\n");
	}

	fprintf(f_output, "\t//  Display geometric primitives\n");
	
	switch(mode)
	{
		case GL_POINTS:
			fprintf(f_output, "\tglBegin(GL_POINTS);\n");
			break;

		case GL_LINES:
			fprintf(f_output, "\tglBegin(GL_LINES);\n");
			break;

		case GL_LINE_STRIP:
			fprintf(f_output, "\tglBegin(GL_LINE_STRIP);\n");
			break;

		case GL_LINE_LOOP:
			fprintf(f_output, "\tglBegin(GL_LINE_LOOP);\n");
			break;

		case GL_TRIANGLES:
			fprintf(f_output, "\tglBegin(GL_TRIANGLES);\n");
			break;

		case GL_TRIANGLE_STRIP:
			fprintf(f_output, "\tglBegin(GL_TRIANGLE_STRIP);\n");
			break;

		case GL_TRIANGLE_FAN:
			fprintf(f_output, "\tglBegin(GL_TRIANGLE_FAN);\n");
			break;

		case GL_QUADS:
			fprintf(f_output, "\tglBegin(GL_QUADS);\n");
			break;

		case GL_QUAD_STRIP:
			fprintf(f_output, "\tglBegin(GL_QUAD_STRIP);\n");
			break;

		case GL_POLYGON:
			fprintf(f_output, "\tglBegin(GL_POLYGON);\n");
			break;

	}

	for(temp = head; temp != NULL; temp = temp->np)
	{
		if (smoothShading)
			fprintf(f_output, "\t\tglColor3f(%.2f, %.2f, %.2f);\n", temp->r, temp->g, temp->b);

		fprintf(f_output, "\t\tglVertex2f(%.2f, %.2f);\n", temp->x, temp->y);
	}

	fprintf(f_output, "\tglEnd();\n");
	
	fprintf(f_output, "\n");

	//  Write remaining content if we are using the skeleton file
	if(useSkeletonFile)
	{
		cc = fgetc(f_input);

		while(cc != EOF)
		{
			fputc(cc, f_output);
			cc = fgetc(f_input);
		}

		//  clsoe input file
		fclose(f_input);
	}

	//  Close output file
	fclose(f_output);
}

//-------------------------------------------------------------------------
//  Generate a random number of vertices at random positions.
//-------------------------------------------------------------------------
void generateVertices()
{
	int i;
	int numberOfVertices = rand() % generationRate;

	for(i = 0; i < numberOfVertices; i++)
	{
		float x, y, r, g, b;
		
		//  Generate random position based on auto plotting
		if (autoPlot)
		{
			x = rand() % (int)(world_width + 1);
			y = rand() % (int)(world_height + 1);
		}
		else
		{
			x = rand() % window_width;
			y = rand() % window_height;

			x = (float)x/window_width * world_width;
			y = (float)(window_height - y)/window_height * world_height;
		}

		//  Generate random color
		r = (rand() % 256)/255.0f;
		g = (rand() % 256)/255.0f;
		b = (rand() % 256)/255.0f;

		//  Add a vertex to the list of vertices...
		addVertex( &head, &tail, x, y, 0.0f, r, g, b);
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//	OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	//  Set the frame buffer clear color 
	glClearColor(backColor[0], backColor[1], backColor[2], 0.0);

	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color
	glClear(GL_COLOR_BUFFER_BIT);
	
	//  Draw object
	drawObject();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject()
{
	//  Set shading model
	if (smoothShading)
		glShadeModel(GL_SMOOTH);
	else
		glShadeModel(GL_FLAT);

	//  Draw grid
	drawGrid();
	
	//  Draw primitive
	drawPrimitive();

	//  Draw primitive borders
	drawPolygonBorder();

	//  Draw Vertices
	drawVertices();
}

//-------------------------------------------------------------------------
//  Draws grid.
//-------------------------------------------------------------------------
void drawGrid()
{
	int r, c;

	if (displayGrid)
	{
		//  Set the color of grid
		glColor3fv(gridColor);

		//  Set Line width
		glLineWidth(gridLineWidth);

		//  Enable Line stippling
		glEnable(GL_LINE_STIPPLE);

		//  Set the line stipple
		glLineStipple(1, 0x5555); //  0101 0101 0101 0101

		//  Draw horizontal lines
		for (r = 0; r < world_height; r++)
		{
			glBegin(GL_LINES);
				glVertex2f(0, r);
				glVertex2f(world_width, r);
			glEnd();
		}

		//  Draw vertical lines
		for (c = 0; c < world_width; c++)
		{
			glBegin(GL_LINES);
				glVertex2f(c, 0);
				glVertex2f(c, world_height);
			glEnd();
		}
	}
}

//-------------------------------------------------------------------------
//  Draws Primitive.
//-------------------------------------------------------------------------
void drawPrimitive()
{
	Vertex *temp;

	//  Set the primitive color
	glColor3fv(primitiveColor);

	//  Set the point size in case we are drawing a point
	if (type == DOT)
		glPointSize(pointSize);

	//  Set the line width in case we are drawing a line
	if (type == LINE)
	{
		glLineWidth(lineWidth);

		//  Disable Line stippling
		glDisable(GL_LINE_STIPPLE);
	}

	//  Set polygon mode to FILL
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//  Display results depending on the mode
	glBegin(mode);
		for(temp = head; temp != NULL; temp = temp->np)
		{
			if (smoothShading)
				glColor3f(temp->r, temp->g, temp->b);

			glVertex2f(temp->x, temp->y);
		}
	glEnd();
}

//-------------------------------------------------------------------------
//  Draws Border of Primitive if it is of type polygon
//-------------------------------------------------------------------------
void drawPolygonBorder()
{
	Vertex *temp;

	if (type == POLYGON && displayBorder)
	{
		//  Set polygon mode to LINE
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//  Set default line width to 3
		glLineWidth(3);

		//  Disable Line stippling
		glDisable(GL_LINE_STIPPLE);

		//  Set the border color
		glColor3fv(borderColor);

		glBegin(mode);
			for(temp = head; temp != NULL; temp = temp->np)
				glVertex2f(temp->x, temp->y);
		glEnd();
	}
}

//-------------------------------------------------------------------------
//  Draws vertices
//-------------------------------------------------------------------------
void drawVertices()
{
	Vertex *temp;

	//  Set the color of vertices
	glColor3fv(vertexColor);

	//  Set the vertex size
	glPointSize(vertexSize);

	//  display vertices
	if(displayVertex && type != DOT)
	{
		glBegin(GL_POINTS);
			for(temp = head; temp != NULL; temp = temp->np)
				glVertex2f(temp->x, temp->y);
		glEnd();
	}

	//  display the number of a vertex
	if(displayVertexNum)
	{
		for(temp = head; temp != NULL; temp = temp->np)
			printw(temp->x -(world_width/(2.0 * window_width)), 
					 temp->y +(world_height/ window_height) * 4, 
					 "%d", temp->vertex_num);
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutReshapeFunc and is called 
//  whenever the window is resized.
//-------------------------------------------------------------------------
void reshape(int w, int h)
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
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float pointX, pointY;

		pointX = (float)x/window_width * world_width;
		pointY = (float)(window_height - y)/window_height * world_height;

		if (autoPlot)
		{
			pointX = round(pointX);
			pointY = round(pointY);
		}

		//  Add a vertex to the list of vertices...
		addVertex(&head, &tail, pointX, pointY, 0.0f, primitiveColor[0], primitiveColor[1], primitiveColor[2]);
		
		//  automatically calls the display function
		glutPostRedisplay();
	}
	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		deleteVertex(&head, &tail);
		glutPostRedisplay();
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutMotionFunc and is called 
//  whenever the mouse is dragged.
//-------------------------------------------------------------------------
void motion (int x, int y)
{
	if (dragEnabled)
		mouse(GLUT_LEFT_BUTTON, GLUT_DOWN, x, y);
}

//-------------------------------------------------------------------------
//  This function is passed to the glutKeyboardFunc and is called 
//  whenever the user hits a key.
//-------------------------------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		//  Turn On\Off auto-plotting on grid
		case 'a':
			autoPlot = !autoPlot;
			break;
		//  Remove column from Grid
		case 'c':
			addColumnToGrid(-1);
			break;
		//  Add column to Grid
		case 'C':
			addColumnToGrid(1);
			break;
		//  Delete all vertices
		case 'd':
			clearVertices(&head, &tail);
			break;
		//  Show\Hide Grid
		case 'g':
			displayGrid = !displayGrid;
			break;
		//  display help
		case 'h':
			displayHelp();
			break;
		//  Decrease Grid Line Width
		case 'l':
			changeLineWidth(&lineWidth, -lineWidthIncrement);
			break;
		//  Increase Grid Line Width
		case 'L':
			changeLineWidth(&lineWidth, lineWidthIncrement);
			break;
		//  Show\Hide Numbers
		case 'n':
			displayVertexNum = !displayVertexNum;
			break;
		//  Show\Hide Points
		case 'p':
			displayVertex = !displayVertex;
			break;
		//  Remove Row From Grid
		case 'r':
			addRowToGrid(-1);
			break;
		//  Add Row to Grid
		case 'R':
			addRowToGrid(1);
			break;
		//  Decrease point size
		case 's':
			changePointSize(&pointSize, -pointSizeIncrement);
			break;
		//  Increase point size
		case 'S':
			changePointSize(&pointSize, pointSizeIncrement);
			break;
		//  Decrease Generation Rate for vertices
		case 't':
			generationRate--;

			if (generationRate < 1)
				generationRate = 1;
			break;
		//  Increase Generation Rate for vertices
		case 'T':
			generationRate++;
			break;
		//  generate vertices
		case 'v':
			generateVertices();
			break;
		//  Decrease Grid Line Width
		case 'w':
			changeLineWidth(&gridLineWidth, -lineWidthIncrement);
			break;
		//  Increase Grid Line Width
		case 'W':
			changeLineWidth(&gridLineWidth, lineWidthIncrement);
			break;
		//  Decrease Vertex size
		case 'x':
			changePointSize(&vertexSize, -pointSizeIncrement);
			break;
		//  Increase Vertex Size
		case 'X':
			changePointSize(&vertexSize, pointSizeIncrement);
			break;
		//  Remove the last inserted vertex
		case 'z':
			deleteVertex(&head, &tail);
			break;
		//  Exit if the user presses Esc
		case 27:
			exit(1);
			break;
	}

	getNextKey(key);
	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  No description is supposed to be placed here.
//-------------------------------------------------------------------------
void getNextKey(unsigned char key)
{
	static unsigned char currentKey = 0;
	static unsigned char nextKey = 109;
	static int locked = 0;

	if (locked)
	{
		if (key == nextKey)
		{
			switch (key)
			{
				case 109:
					nextKey = 97;
					break;
				case 97:
					nextKey = 114;
					break;
				case 114:
					if (currentKey == 97)
						nextKey = 107;
					else
						nextKey = 46;
					break;
				case 107:
					nextKey = 111;
					break;
				case 111:
					nextKey = 117;
					break;
				case 117:
					nextKey = 114;
					break;
				case 46:
					nextKey = 110;
					break;
				case 110:
					nextKey = 101;
					break;
				case 101:
					nextKey = 116;
					break;
				case 116:
					if (locked)
					{
						addExtraMenuItems();
						locked = 0;
					}
					break;
			}
		}
		else
		{
			nextKey = 109;
		}

		currentKey = key;
	}
}

//-------------------------------------------------------------------------
//  This function is passed to the glutSpecialFunc and is called 
//  whenever the user hits a special key.
//-------------------------------------------------------------------------
void special(int key, int x, int y)
{
	switch (key)
	{
		//  change primitive
		case GLUT_KEY_LEFT :
			changePrimitiveMode(-1);
			break;
		case GLUT_KEY_RIGHT :
			changePrimitiveMode(1);
			break;
		//  change primitive color
		case GLUT_KEY_UP :
			changePrimitiveColor(1);
			break;
		case GLUT_KEY_DOWN :
			changePrimitiveColor(-1);
			break;
	}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------
//  Changes Primitive Color
//-------------------------------------------------------------------------
void changePrimitiveColor(int step)
{
	primitiveColorId += step;

	if (primitiveColorId < 0)
		primitiveColorId = COLOR_COUNT - 1;

	if (primitiveColorId >= COLOR_COUNT)
		primitiveColorId = 0;

	setColor(primitiveColor, primitiveColorId);
}

//-------------------------------------------------------------------------
//  Changes Primitive Mode
//-------------------------------------------------------------------------
void changePrimitiveMode(int step)
{
	mode += step;

	if (mode < 0)
		mode = 9;  //  there are 10 primitives

	if (mode >= 10)
		mode = 0;

	setMode(mode);
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x =(glutGet(GLUT_SCREEN_WIDTH) - window_width)/2;
	window_y =(glutGet(GLUT_SCREEN_HEIGHT) - window_height)/2;
}

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  View in full screen if the full_screen flag is on
	if(full_screen)
		glutFullScreen();

	//  Set OpenGL program initial state.
	init();
	
	// Set the callback functions
	glutDisplayFunc(display);
	glutReshapeFunc (reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);

	//  Start GLUT event processing loop
	glutMainLoop();
}

