//*************************************************************************
//
//  File Name	: shapes.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Class containing drawing functions for GLUT shape and
//				  its description.
//  
//*************************************************************************

#include "shapes.h"
#include "utils.h"

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Math Library
#include <math.h>

//-------------------------------------------------------------------------
//  Draws a GLUT shape
//-------------------------------------------------------------------------
void drawShape(int shapeId, float shapeSize)
{
	switch (shapeId)
	{
		//  draw glut wire cube
		case GLUT_WIRE_CUBE:
			glutWireCube (shapeSize/2);
			break;
		//  draw glut solid cube
		case GLUT_SOLID_CUBE:
			glutSolidCube (shapeSize/2);
			break;
		//  draw glut wire sphere
		case GLUT_WIRE_SPHERE:
			glutWireSphere (shapeSize/2, (GLint)(shapeSize * 10), (GLint)(shapeSize * 10));
			break;
		//  draw glut solid sphere
		case GLUT_SOLID_SPHERE:
			glutSolidSphere (shapeSize/2, (GLint)(shapeSize * 10), (GLint)(shapeSize * 10));
			break;
		//  draw glut wire Cone
		case GLUT_WIRE_CONE:
			glutWireCone (shapeSize/2, shapeSize/2, (GLint)(shapeSize * 10), (GLint)(shapeSize * 10));
			break;
		//  draw glut solid cone
		case GLUT_SOLID_CONE:
			glutSolidCone (shapeSize/2, shapeSize/2, (GLint)(shapeSize * 10), (GLint)(shapeSize * 10));
			break;
		//  draw glut wire Torus
		case GLUT_WIRE_TORUS:	
			glutWireTorus (shapeSize/5, shapeSize/2 - shapeSize/5, (GLint)(shapeSize * 20), (GLint)(shapeSize * 20));
			break;
		///  draw glut solid Torus
		case GLUT_SOLID_TORUS:
			glutSolidTorus (shapeSize/7, shapeSize/2 - shapeSize/7, (GLint)(shapeSize * 20), (GLint)(shapeSize * 20));
			break;
		//  draw a wire dodecahedron.. The reason why I'm dividing
		//  by 2 * radical (3) when I'm scaling is because I want to fit
		//  the dodecahedron which is centered at the modeling 
		//	coordinates origin with a radius of radical (3).
		case GLUT_WIRE_DODECAHEDRON:	
			glScalef (shapeSize / sqrt (12), shapeSize / sqrt (12), shapeSize / sqrt (12));
			glutWireDodecahedron ();
			break;
		//  draw a solid dodecahedron
		case GLUT_SOLID_DODECAHEDRON:
			glScalef (shapeSize / sqrt (12), shapeSize / sqrt (12), shapeSize / sqrt (12));
			glutSolidDodecahedron ();
			break;
		//  draw a wire octahedron.. The reason why I'm dividing
		//  by 2 when I'm scaling is because I want to fit
		//  the octahedron which is centered at the modeling 
		//	coordinates origin with a radius of 1.
		case GLUT_WIRE_OCTAHEDRON:
			glScalef (shapeSize / 2, shapeSize / 2, shapeSize / 2);
			glutWireOctahedron ();
			break;
		//  draw a solid tetrahedron
		case GLUT_SOLID_OCTAHEDRON:
			glScalef (shapeSize / 2, shapeSize / 2, shapeSize / 2);
			glutSolidOctahedron ();
			break;
		//  draw a wire tetrahedron.. 
		case GLUT_WIRE_TETRAHEDRON:
			
			glScalef (shapeSize / sqrt(6), shapeSize / sqrt(6), shapeSize / sqrt(6));
			glutWireTetrahedron ();
			break;
		//  draw a solid tetrahedron
		case GLUT_SOLID_TETRAHEDRON:
			glScalef (shapeSize / sqrt(6), shapeSize / sqrt(6), shapeSize / sqrt(6));
			glutSolidTetrahedron ();
			break;
		//  draw a wire icosahedron.. The reason why I'm dividing
		//  by 2 when I'm scaling is because I want to fit
		//  the icosahedron which is centered at the modeling 
		//	coordinates origin with a radius of 1.
		case GLUT_WIRE_ICOSAHEDRON:
			glScalef (shapeSize / 2, shapeSize / 2, shapeSize / 2);
			glutWireIcosahedron ();
			break;
		//  draw a solid icosahedron
		case GLUT_SOLID_ICOSAHEDRON:
			glScalef (shapeSize / 2, shapeSize / 2, shapeSize / 2);
			glutSolidIcosahedron ();
			break;
		//  draw Wire Teapot
		case GLUT_WIRE_TEAPOT:
			glutWireTeapot (shapeSize/4);
			break;
		//  draw a solid Teapot
		case GLUT_SOLID_TEAPOT:
			glutSolidTeapot (shapeSize/4);
			break;
		//  Do Nothing
		default:
			break;
	}
}

//-------------------------------------------------------------------------
//  Draws the description of a GLUT shape
//-------------------------------------------------------------------------
void drawShapeDescription(int shapeId, float x, float y)
{
	switch (shapeId)
	{
		case GLUT_WIRE_CUBE:
			printw (x, y, "Wire Cube");
			break;
		case GLUT_SOLID_CUBE:
			printw (x, y, "Solid Cube");
			break;
		case GLUT_WIRE_SPHERE:
			printw (x, y, "Wire Sphere");
			break;
		case GLUT_SOLID_SPHERE:
			printw (x, y, "Solid Sphere");
			break;
		case GLUT_WIRE_CONE:
			printw (x, y, "Wire Cone");
			break;
		case GLUT_SOLID_CONE:
			printw (x, y, "Solid Cone");
			break;
		case GLUT_WIRE_TORUS:
			printw (x, y, "Wire Torus");
			break;
		case GLUT_SOLID_TORUS:
			printw (x, y, "Solid Torus");
			break;
		case GLUT_WIRE_DODECAHEDRON:
			printw (x, y, "Wire Dodecahedron");
			break;
		case GLUT_SOLID_DODECAHEDRON:
			printw (x, y, "Solid Dodecahedron");
			break;
		case GLUT_WIRE_OCTAHEDRON:
			printw (x, y, "Wire Octahedron");
			break;
		case GLUT_SOLID_OCTAHEDRON:
			printw (x, y, "Solid Octahedron");
			break; 
		case GLUT_WIRE_TETRAHEDRON:
			printw (x, y, "Wire Tetrahedron");
			break;
		case GLUT_SOLID_TETRAHEDRON:
			printw (x, y, "Solid Tetrahedron");
			break;
		case GLUT_WIRE_ICOSAHEDRON:
			printw (x, y, "Wire Icosahedron");
			break;
		case GLUT_SOLID_ICOSAHEDRON:
			printw (x, y, "Solid Icosahedron");
			break;
		case GLUT_WIRE_TEAPOT:
			printw (x, y, "Wire Teapot");
			break;
		case GLUT_SOLID_TEAPOT:
			printw (x, y, "Solid Teapot");
			break;
		default:
			break;
	}
}