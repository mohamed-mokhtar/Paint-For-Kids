#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }
bool CFigure::IsSelected() const
{	return Selected; }
void CFigure::setID(int id){
	ID = id;
}
color CFigure::getfillcol ()
{
	if(FigGfxInfo.isFilled == true)
	{
		return FigGfxInfo.FillClr;
	}
	else 
	{
		return UI.BkGrndColor;
	}
}
color CFigure::getdrawcol ()
{
	return FigGfxInfo.DrawClr;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


