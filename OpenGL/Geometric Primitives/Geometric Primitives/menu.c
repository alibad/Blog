//*************************************************************************
//
//  File Name	: menu.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Represents right click popup menu.
//  
//*************************************************************************

#include "menu.h"

//  For GLUT menu functions
#include <gl/glut.h>

// menu IDs declarations
int mainMenuId, 
	primitiveMenuId, primitivePointMenuId, primitiveLineMenuId, primitivePolygonMenuId,
	primitiveTypeMenuId, primitiveColorMenuId, primitivePolygonColorMenuId,
	vertexMenuId, vertexSizeMenuId, vertexColorMenuId, vertexRateMenuId,
	gridMenuId, gridRowMenuId, gridColumnMenuId, gridLineWidthMenuId, gridColorMenuId,
	backColorMenuId;

//-------------------------------------------------------------------------
//  Sets up menus
//-------------------------------------------------------------------------
void setupMenus()
{
	//  create menus
	mainMenuId = glutCreateMenu(mainMenu);
	primitiveMenuId = glutCreateMenu(primitiveMenu);
	primitiveTypeMenuId = glutCreateMenu(primitiveTypeMenu);
	primitiveColorMenuId = glutCreateMenu(primitiveColorMenu);
	primitivePointMenuId = glutCreateMenu(primitivePointMenu);
	primitiveLineMenuId = glutCreateMenu(primitiveLineMenu);
	primitivePolygonMenuId = glutCreateMenu(primitivePolygonMenu);
	primitivePolygonColorMenuId = glutCreateMenu(primitivePolygonColorMenu);
	vertexMenuId = glutCreateMenu(vertexMenu);
	vertexSizeMenuId = glutCreateMenu(vertexSizeMenu);
	vertexColorMenuId = glutCreateMenu(vertexColorMenu);
	vertexRateMenuId = glutCreateMenu(vertexRateMenu);
	gridMenuId = glutCreateMenu(gridMenu);
	gridRowMenuId = glutCreateMenu(gridRowMenu);
	gridColumnMenuId = glutCreateMenu(gridColumnMenu);
	gridColorMenuId = glutCreateMenu(gridColorMenu);
	gridLineWidthMenuId = glutCreateMenu(gridLineWidthMenu);
	backColorMenuId = glutCreateMenu(backColorMenu);

	//  Add the menus' entries
    glutSetMenu(mainMenuId);      //  select main menu,
	
	glutAddSubMenu("Primitive", primitiveMenuId);
	glutAddSubMenu("Vertex", vertexMenuId);
	glutAddSubMenu("Grid", gridMenuId);
	glutAddSubMenu("Back Color", backColorMenuId);
	glutAddMenuEntry("Generate Code", 1);

	//  Add the primitive submenus and menu items
	glutSetMenu(primitiveMenuId);
	
	glutAddSubMenu("Type", primitiveTypeMenuId);
	glutAddSubMenu("Color", primitiveColorMenuId);
	glutAddSubMenu("Point Size", primitivePointMenuId);
	glutAddSubMenu("Line Width", primitiveLineMenuId);
	glutAddSubMenu("Polygon", primitivePolygonMenuId);

	//  Add the primitive type menu items
	glutSetMenu(primitiveTypeMenuId);
	glutAddMenuEntry("GL_POINTS", GL_POINTS);
	glutAddMenuEntry("GL_LINES", GL_LINES);
	glutAddMenuEntry("GL_LINE_STRIP", GL_LINE_STRIP);
	glutAddMenuEntry("GL_LINE_LOOP", GL_LINE_LOOP);
	glutAddMenuEntry("GL_TRIANGLES", GL_TRIANGLES);
	glutAddMenuEntry("GL_TRIANGLE_STRIP", GL_TRIANGLE_STRIP);
	glutAddMenuEntry("GL_TRIANGLE_FAN", GL_TRIANGLE_FAN);
	glutAddMenuEntry("GL_QUADS", GL_QUADS);
	glutAddMenuEntry("GL_QUAD_STRIP", GL_QUAD_STRIP);
	glutAddMenuEntry("GL_POLYGON", GL_POLYGON);

	//  Add the primitive Color Menu items
	glutSetMenu(primitiveColorMenuId);
	addColorMenuItems();

	//  Add the primitive Point Menu items
	glutSetMenu(primitivePointMenuId);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);

	//  Add the primitive Line Menu items
	glutSetMenu(primitiveLineMenuId);
	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);

	//  Add the primitive Polygon Menu items
	glutSetMenu(primitivePolygonMenuId);
	glutAddMenuEntry("Show\\Hide Border", 1);
	glutAddSubMenu("Border Color", primitivePolygonColorMenuId);

	//  Add the primitive Polygon Color Menu items
	glutSetMenu(primitivePolygonColorMenuId);
	addColorMenuItems();

	//  Add the vertex submenus and menu items
	glutSetMenu(vertexMenuId);

	glutAddMenuEntry("Generate Vertices", 1);
	glutAddSubMenu("Generation Rate", vertexRateMenuId);
	glutAddMenuEntry("Delete Vertices", 2);
	glutAddMenuEntry("Show\\Hide Vertices", 3);
	glutAddMenuEntry("Show\\Hide Numbers", 4);
	glutAddSubMenu("Vertex Size", vertexSizeMenuId);
	glutAddSubMenu("Vertex Color", vertexColorMenuId);
	
	//  Add the Generation Rate Menu Items
	glutSetMenu(vertexRateMenuId);

	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);

	//  Add the point size menu items
	glutSetMenu(vertexSizeMenuId);

	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);

	//  Add the point color menu items
	glutSetMenu(vertexColorMenuId);

	addColorMenuItems();

	//  Set the Grid submenus and menu items
	glutSetMenu(gridMenuId);

	glutAddMenuEntry("Show\\Hide Grid", 1);
	glutAddMenuEntry("Auto Plotting On/Off", 2);
	glutAddSubMenu("Row", gridRowMenuId);
	glutAddSubMenu("Column", gridColumnMenuId);
	glutAddSubMenu("Line Width", gridLineWidthMenuId);
	glutAddSubMenu("Color", gridColorMenuId);
	
	//  Add the Grid row Menu Items
	glutSetMenu(gridRowMenuId);

	glutAddMenuEntry("Add", 1);
	glutAddMenuEntry("Remove", 2);

	//  Add the Grid column Menu Items
	glutSetMenu(gridColumnMenuId);

	glutAddMenuEntry("Add", 1);
	glutAddMenuEntry("Remove", 2);

	//  Add the Grid Line width Menu Items
	glutSetMenu(gridLineWidthMenuId);

	glutAddMenuEntry("+", 1);
	glutAddMenuEntry("-", 2);

	//  Add the grid color menu items
	glutSetMenu(gridColorMenuId);

	addColorMenuItems();

	//  Add the back color menu items
	glutSetMenu(backColorMenuId);

	addColorMenuItems();

	// This was supposed to be an Easter Egg for typing (markour.net) on keyboard, 
	// but I just removed. Nobody has time these days.
	addExtraMenuItems();

	//  Attach the main menu to the RMB
    glutSetMenu(mainMenuId);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//-------------------------------------------------------------------------
//  Add Color Menu Items
//-------------------------------------------------------------------------
void addColorMenuItems()
{
	glutAddMenuEntry("Black", BLACK);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Cyan", CYAN);
	glutAddMenuEntry("Dark Grey", DARK_GREY);
	glutAddMenuEntry("Grey", GREY);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Light Grey", LIGHT_GREY);
	glutAddMenuEntry("Magenta", MAGENTA);
	glutAddMenuEntry("Orange", ORANGE);
	glutAddMenuEntry("Pink", PINK);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("White", WHITE);
	glutAddMenuEntry("Yellow", YELLOW);
}

//-------------------------------------------------------------------------
//  Adds extra menu items
//-------------------------------------------------------------------------
void addExtraMenuItems()
{
	glutSetMenu(primitiveMenuId);
	glutAddMenuEntry("Smooth Shading", 1);

	glutSetMenu(mainMenuId);
	glutAddMenuEntry("Get Mona Lisa", 2);
	glutAddMenuEntry("Get Random Colors", 3);
	glutAddMenuEntry("Drag Enabled", 4);
}