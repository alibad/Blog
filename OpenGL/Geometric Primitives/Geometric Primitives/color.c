//*************************************************************************
//
//  File Name	: color.c
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Represents color data type and functions.
//  
//*************************************************************************

#include "color.h"

//  For rand()
#include <stdlib.h>

//-------------------------------------------------------------------------
//  Loads random colors into passed array
//-------------------------------------------------------------------------
void loadRandomColor(float color[])
{
	color[0] = (rand() % 256)/255.0f;
	color[1] = (rand() % 256)/255.0f;
	color[2] = (rand() % 256)/255.0f;
}

//-------------------------------------------------------------------------
//  Sets the color RGB components of the array based on color id.
//-------------------------------------------------------------------------
void setColor(float color[], int value)
{
	switch(value)
	{
		//  Select black color
		case BLACK:
			color[0] = 0/255.0f;
			color[1] = 0/255.0f;
			color[2] = 0/255.0f;
			break;
		//  Select blue color
		case BLUE:
			color[0] = 0/255.0f;
			color[1] = 0/255.0f;
			color[2] = 255/255.0f;
			break;
		//  Select cyan color
		case CYAN:	
			color[0] = 0/255.0f;
			color[1] = 255/255.0f;
			color[2] = 255/255.0f;
			break;
		//  Select dark grey color
		case DARK_GREY:
			color[0] = 64/255.0f;
			color[1] = 64/255.0f;
			color[2] = 64/255.0f;
			break;
		//  Select grey color
		case GREY:
			color[0] = 128/255.0f;
			color[1] = 128/255.0f;
			color[2] = 128/255.0f;
			break;
		//  Select green color
		case GREEN:
			color[0] = 0/255.0f;
			color[1] = 255/255.0f;
			color[2] = 0/255.0f;
			break;
		//  Select light gray color
		case LIGHT_GREY:
			color[0] = 192/255.0f;
			color[1] = 192/255.0f;
			color[2] = 192/255.0f;
			break;
		//  Select magenta color
		case MAGENTA:
			color[0] = 192/255.0f;
			color[1] = 64/255.0f;
			color[2] = 192/255.0f;
			break;
		//  Select orange color
		case ORANGE:
			color[0] = 255/255.0f;
			color[1] = 192/255.0f;
			color[2] = 64/255.0f;
			break;
		//  Select pink color
		case PINK:
			color[0] = 255/255.0f;
			color[1] = 0/255.0f;
			color[2] = 255/255.0f;
			break;
		//  Select red color
		case RED:
			color[0] = 255/255.0f;
			color[1] = 0/255.0f;
			color[2] = 0/255.0f;
			break;
		//  Select white color
		case WHITE:
			color[0] = 255/255.0f;
			color[1] = 255/255.0f;
			color[2] = 255/255.0f;
			break;
		//  Select yellow color
		case YELLOW:
			color[0] = 255/255.0f;
			color[1] = 255/255.0f;
			color[2] = 0/255.0f;
			break;
	}
}