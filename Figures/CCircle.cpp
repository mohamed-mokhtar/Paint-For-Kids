#include "CCircle.h"
#include <iostream>
#include <fstream>
using namespace std;


CCircle::CCircle(Point point1, int radius , GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = point1;
	R = radius;
}
bool CCircle::Select(int x, int y){
	int Distance = sqrt((P1.x-x)*(P1.x-x)+(P1.y-y)*(P1.y-y));
	if( Distance <= R){
		return true;
	}return false ;
}

CFigure* CCircle::copy()
{
	CFigure* Circ = new CCircle (P1, R,  FigGfxInfo);
	return Circ;

}
CFigure* CCircle::paste(int x,int y)
{
	Point p1;
	p1.x=x;
	p1.y=y;
	
	CFigure* Circ = new CCircle (p1, R,  FigGfxInfo);
	return Circ;
}

//---------------------------------------------// Save And Load
void CCircle::Save(ofstream &OutFile)
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

	// NAME _ ID _ Center _ Radius  _ COLOR _FILL OR NOT
	OutFile << "Circle" << " " << ID;
	OutFile << " " << P1.x << " " << P1.y << " " << R << " ";
	OutFile << color << " " << fill << endl;

}	//Save the figure parameters to the file
void CCircle::Load(ifstream &Infile)
{
	Infile >> ID >> P1.x >> P1.y >> R;
	string drawcolor, fillcolor;
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
}
//---------------------------------------------//

void CCircle::PrintInfo(Output* pOut){
	pOut->PrintMessage("ID = "+to_string( ID)+"Circle : Center(" + to_string(P1.x) + "," + to_string(P1.y) + ") Raduis = "+ to_string(R));
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(P1, P2, R, FigGfxInfo, Selected);
}

CCircle::~CCircle()
{
}
