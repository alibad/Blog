//*************************************************************************
//
//  File Name	: vertex.h
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Linked List of Vertexs, where a Vertex is represented 
//				  by its (x, y, x) coordinates.
//  
//*************************************************************************

#ifndef _VERTEX_H_
#define _VERTEX_H_

//  Support for memory functions such as malloc and free (and NULL)
#include <stdlib.h>

//  Represents a vertex data structure that has coordinates and a 
//  Vertexer to the previous and next vertex in the list of vertices.
typedef struct Vertex
{
	float x, y, z;
	float r, g, b;
	struct Vertex * pp, *np;    //  previous and next Vertices
	int vertex_num;             //  number representing the Vertex
} Vertex;

//  Adds a Vertex to the list of Vertices
void addVertex (Vertex **headPtr, Vertex **tailPtr, 
				float x, float y, float z,
				float r, float g, float b);

//  Deletes the last Vertex in the list
void deleteVertex (Vertex **headPtr, Vertex **tailPtr);

//  Clears all Vertices in the list
void clearVertices (Vertex **headPtr, Vertex **tailPtr);

#endif