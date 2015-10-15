//*************************************************************************
//
//  File Name	: vertex.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Linked List of vertices, where a vertex is represented 
//				  by its (x, y, x) coordinates.
//  
//*************************************************************************

#include "vertex.h"

//-------------------------------------------------------------------------
//  Adds a vertex to the list of vertices
//-------------------------------------------------------------------------
void addVertex (Vertex **headPtr, Vertex **tailPtr, 
				float x, float y, float z,
				float r, float g, float b)
{
	Vertex *head, *tail;
	head = *headPtr;
	tail = *tailPtr;

	if (head == NULL)
	{
		head = (Vertex *) malloc (sizeof (Vertex));

		head->x = x;
		head->y = y;
		head->z = z;
		head->r = r;
		head->g = g;
		head->b = b;
		head->vertex_num = 1;

		head->pp = NULL;
		head->np = NULL;
		tail = head;
	}
	else
	{
		tail->np = (Vertex *) malloc (sizeof (Vertex));
		tail->np->pp = tail;

		tail = tail->np;

		tail->x = x;
		tail->y = y;
		tail->z = z;
		tail->r = r;
		tail->g = g;
		tail->b = b;
		tail->vertex_num = tail->pp->vertex_num + 1;
		tail->np = NULL;
	}

	*headPtr = head;
	*tailPtr = tail;
}

//-------------------------------------------------------------------------
//  deletes the last vertex in the list
//-------------------------------------------------------------------------
void deleteVertex (Vertex **headPtr, Vertex **tailPtr)
{
	Vertex * temp;
	Vertex *head, *tail;
	head = *headPtr;
	tail = *tailPtr;

	if (tail != NULL)
	{
		temp = tail;

		tail = temp->pp;

		if (tail != NULL)
			tail->np = NULL;
		else
			head = NULL;

		free (temp);
	}

	*headPtr = head;
	*tailPtr = tail;
}

//-------------------------------------------------------------------------
//  clears all vertices in the list
//-------------------------------------------------------------------------
void clearVertices (Vertex **headPtr, Vertex **tailPtr)
{
	while (*tailPtr != NULL)
		deleteVertex (headPtr, tailPtr);
}