#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_COLOR,
	MODE_PLAY	//Playing mode

};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_Line,
	ITM_trin,
	ITM_CHG_DRW_CLR,
	ITM_CHG_FILL_CLR,

	ITM_Select,
	ITM_DEL,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_PM,

	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};
enum ColorMenuItem
{
	ITM_WHITE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_Fav,


	COLOR_ITM_COUNT
};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_pickCOLOR, //ITM_HIDECOLOR
	ITM_pickSHAPE, //ITM_HIDESHAPE
	ITM_pickBOTH, //ITM_HIDEBOTH
	ITM_DRAWMODE, //backtodrawmode
	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	bool isFilled;
	int PenWidth;			//width of the pen that draws shapes


							/// Add more members if needed

}UI;	//create a global object UI

#endif