#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int x, int y) const
{
	if(x==0&&y==0)
	{
		pWind->WaitMouseClick(x, y);
	}
		//Get the coordinates of the user click
	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_Line: return DRAW_LINE;
			case ITM_trin: return DRAW_TRI;
			case ITM_CHG_DRW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_Select: return SELECT;
			case ITM_DEL: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
				
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE:return PASTE;
			//case ITM_RESIZE:return RESIZE;
			//case ITM_ROTATE:return ROTATE;
			case ITM_PM: return TO_PLAY;
			case ITM_EXIT: return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else
		if (UI.InterfaceMode == MODE_COLOR)
		{
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		
				switch (ClickedItemOrder)
				{
				case ITM_WHITE: return WHITEcol;
				case ITM_RED: return REDcol;
				case ITM_GREEN: return GREENcol;
				case ITM_BLUE: return BLUEcol;
				case ITM_Fav: return BLACKcol;



				default: return EMPTY;
				}
				
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}


	if (UI.InterfaceMode == MODE_PLAY)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			
			switch (ClickedItemOrder)
			{

			case ITM_pickCOLOR: return pick_color;
			case ITM_pickSHAPE: return pick_shape;
			case ITM_pickBOTH: return pick_both;
			case ITM_DRAWMODE: return TO_DRAW;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		

		//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}

	}

/////////////////////////////////

Input::~Input()
{

}
