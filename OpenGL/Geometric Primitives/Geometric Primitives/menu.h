//*************************************************************************
//
//  File Name	: menu.h
//  Author		: Ali BaderEddin
//  Date		: December 2003
//  
//  Description	: Represents right click popup menu.
//  
//*************************************************************************

#ifndef _MENU_H_
#define _MENU_H_

#include "color.h"

//  Sets up menus
void setupMenus();

//  Add Color Menu Items
void addColorMenuItems();

//  Adds extra menu items
void addExtraMenuItems();

// menu callback functions declarations
void mainMenu(int value);
void primitiveMenu(int value);
void primitiveTypeMenu(int value);
void primitiveColorMenu(int value);
void primitivePointMenu(int value);
void primitiveLineMenu(int value);
void primitivePolygonMenu(int value);
void primitivePolygonColorMenu(int value);
void vertexRateMenu(int value);
void vertexMenu(int value);
void vertexSizeMenu(int value);
void vertexColorMenu(int value);
void gridMenu(int value);
void gridRowMenu(int value);
void gridColumnMenu(int value);
void gridLineWidthMenu(int value);
void gridColorMenu(int value);
void backColorMenu(int value);

#endif