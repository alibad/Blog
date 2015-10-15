//*************************************************************************
//
//  File Name	: color.h
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Represents color data type and functions.
//  
//*************************************************************************

#ifndef _COLOR_H_
#define _COLOR_H_

//  Represents the color
typedef enum
{
	BLACK,
	BLUE,
	CYAN,
	DARK_GREY,
	GREY,
	GREEN,
	LIGHT_GREY,
	MAGENTA,
	ORANGE,
	PINK,
	RED,
	WHITE,
	YELLOW,
	COLOR_COUNT
} Color;

//  Loads random color into array
void loadRandomColor(float color[]);

//  Sets the color RGB components of the array based on color id.
void setColor(float color[], int value);

#endif