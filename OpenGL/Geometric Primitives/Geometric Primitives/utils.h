//*************************************************************************
//
//  File Name	: utils.h
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: A set of utility functions.
//  
//*************************************************************************

#ifndef _UTILS_H_
#define _UTILS_H_

//  Behaves exactly the same as printf, but draws 
//  its contents on an OpenGL window at the specified coordinates.
void printw(float x, float y, char* format, ...);

//  Rounds a numberto the nearest value knowing that standard C doesn't 
//  support the round function in its math.h library. It only supports
//  floor (round down) and ceil (round up) functions.
int round(double number);

#endif