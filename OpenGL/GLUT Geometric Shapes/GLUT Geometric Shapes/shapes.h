//*************************************************************************
//
//  File Name	: shapes.h
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Class containing drawing functions for GLUT shape and
//				  its description.
//  
//*************************************************************************

#ifndef _SHAPE_H_
#define _SHAPE_H_

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
	GLUT_SOLID_TEAPOT,
	SHAPE_COUNT
};

//  Draws a GLUT shape
void drawShape(int shapeId, float shapeSize);

//  Draws the description of a GLUT shape
void drawShapeDescription(int shapeId, float x, float y);

#endif