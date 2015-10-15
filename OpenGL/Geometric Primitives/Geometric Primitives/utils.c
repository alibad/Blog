//*************************************************************************
//
//  File Name	: utils.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: A set of utility functions.
//  
//*************************************************************************

#include "utils.h"

//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>

//  Support for variable number of arguments
#include <stdarg.h>

//  Standard Input\Output C Library (For vsprintf)
#include <stdio.h>

//  Just a pointer to a font style..
//  Fonts supported by GLUT are: GLUT_BITMAP_8_BY_13, 
//  GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, 
//  GLUT_BITMAP_TIMES_ROMAN_24, GLUT_BITMAP_HELVETICA_10,
//  GLUT_BITMAP_HELVETICA_12, and GLUT_BITMAP_HELVETICA_18.
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_10;

//-------------------------------------------------------------------------
//  Behaves exactly the same as printf, but draws 
//  its contents on an OpenGL window at the specified coordinates.
//-------------------------------------------------------------------------
void printw(float x, float y, char* format, ...)
{
    va_list arg_list;
    char str[256];
	int i;
    
    va_start(arg_list, format);
    vsprintf(str, format, arg_list);
    va_end(arg_list);
    
    glRasterPos2f (x, y);

    for (i = 0; str[i] != '\0'; i++)
        glutBitmapCharacter(font_style, str[i]);
}

//-------------------------------------------------------------------------
//  Rounds a number to the nearest value knowing that standard C doesn't 
//  support the round function in its math.h library. It only supports
//  floor (round down) and ceil (round up) functions.
//-------------------------------------------------------------------------
int round(double number)
{
	return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}


