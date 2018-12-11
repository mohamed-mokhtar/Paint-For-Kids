#include "CRectangle.h"
#include <iostream>
#include <fstream>
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
bool CRectangle::Select(int X , int Y){
	int BigX, SmallX, BigY, SmallY;
	if(Corner2.x < Corner1.x){
		BigX = Corner1.x;
		SmallX = Corner2.x;
	}else if(Corner2.x > Corner1.x){
		BigX = Corner2.x;
		SmallX = Corner1.x;
	}
	
	if(Corner2.y < Corner1.y){
		BigY= Corner1.y;
		SmallY = Corner2.y;
	}else if(Corner2.y > Corner1.y){
		BigY = Corner2.y;
		SmallY = Corner1.y;
	}

		if(((X <= BigX) &&( X >= SmallX) )&&( (Y <= BigY )&& (Y >= SmallY))){
			return true;
	}
	return false;
}

CFigure* CRectangle::copy()
{
    CFigure* Rect = new CRectangle (Corner1, Corner2,  FigGfxInfo);
	return Rect;
}
CFigure* CRectangle::paste(int x,int y)
{
	
	Point p1,p2;
	p1.x=x;
	p1.y=y;
	
	p2.x=x+(abs(Corner2.x-Corner1.x));
	p2.y=abs(y+(abs(Corner2.y-Corner1.y)));
	CFigure* Rect = new CRectangle (p1, p2,  FigGfxInfo);
	return Rect;
}
void CRectangle::Save(ofstream &OutFile)
{
	string color;
	string fill;
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		color = "BLACK";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		color = "RED";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 0)
		color = "GREEN";
	if (int(FigGfxInfo.DrawClr.ucRed) == 0 && int(FigGfxInfo.DrawClr.ucGreen) == 0 && int(FigGfxInfo.DrawClr.ucBlue) == 255)
		color = "BLUE";
	if (int(FigGfxInfo.DrawClr.ucRed) == 255 && int(FigGfxInfo.DrawClr.ucGreen) == 255 && int(FigGfxInfo.DrawClr.ucBlue) == 255)
		color = "WHITE";
	//----------------------------------------//
	if (FigGfxInfo.isFilled)
	{
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			fill = "BLACK";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			fill = "RED";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 0)
			fill = "GREEN";
		if (int(FigGfxInfo.FillClr.ucRed) == 0 && int(FigGfxInfo.FillClr.ucGreen) == 0 && int(FigGfxInfo.FillClr.ucBlue) == 255)
			fill = "BLUE";
		if (int(FigGfxInfo.FillClr.ucRed) == 255 && int(FigGfxInfo.FillClr.ucGreen) == 255 && int(FigGfxInfo.FillClr.ucBlue) == 255)
			fill = "WHITE";
	}
	else
		fill = "NO_FILL";

	// NAME _ID_ CORNERS _ COLOR _FILL OR NOT

	OutFile << "Rectangle" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << color << " " << fill << endl;

}	//Save the figure parameters to the file
void CRectangle::Load(ifstream &Infile)
{
	string drawcolor;
	string fillcolor;
	Infile >> ID;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Infile >> drawcolor >> fillcolor;
	if (drawcolor == "BLACK")
	{
		FigGfxInfo.DrawClr = BLACK;
	}
	else if (drawcolor == "RED")
	{
		FigGfxInfo.DrawClr = RED;
	}
	else if (drawcolor == "GREEN")
	{
		FigGfxInfo.DrawClr = GREEN;
	}
	else if (drawcolor == "BLUE")
	{
		FigGfxInfo.DrawClr = BLUE;
	}
	else
	{
		FigGfxInfo.DrawClr = WHITE;
	}

	if (fillcolor == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		if (fillcolor == "BLACK")
		{
			FigGfxInfo.FillClr = BLACK;
		}
		else if (fillcolor == "RED")
		{
			FigGfxInfo.FillClr = RED;
		}
		else if (fillcolor == "GREEN")
		{
			FigGfxInfo.FillClr = GREEN;
		}
		else if (fillcolor == "BLUE")
		{
			FigGfxInfo.FillClr = BLUE;
		}
		else
		{
			FigGfxInfo.FillClr = WHITE;
		}

	}
}	//Load the figure parameters to the file

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut){
	pOut->PrintMessage("ID = "+to_string( ID)+"Rectangle : Width = " + to_string(abs(Corner1.x - Corner2.x))+ "Height = " + to_string(abs(Corner1.y - Corner2.y)));
}