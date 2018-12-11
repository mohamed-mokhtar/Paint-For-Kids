#include "Line.h"
#include <iostream>
#include <fstream>
using namespace std;

CLine::CLine (Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	FigGfxInfo.isFilled=false;
}
bool CLine::Select(int x, int y){
	float distance = abs(sqrt((Corner1.x-Corner2.x)*(Corner1.x-Corner2.x)+(Corner1.y-Corner2.y)*(Corner1.y-Corner2.y)));
	if(abs(sqrt((Corner1.x-x)*(Corner1.x-x) + (Corner1.y-y)*(Corner1.y-y)) + sqrt((Corner2.x-x)*(Corner2.x-x) + (Corner2.y-y)*(Corner2.y-y))) - distance < 0.05){
		return true;
	}
	return false;
}

CFigure* CLine::copy()
{
	CFigure* Line = new CLine (Corner1, Corner2,  FigGfxInfo);
	return Line;
}
CFigure* CLine::paste(int x,int y)
{
	Point p1,p2;
	
	
	if((Corner1.x>Corner2.x&&Corner1.y<Corner2.y)||(Corner1.x<Corner2.x&&Corner1.y>Corner2.y))
	{
		p1.x=x+abs(((Corner1.x-((Corner1.x+Corner2.x)/2))));
		p1.y=y-abs((-Corner1.y+((Corner1.y+Corner2.y)/2)));
		p2.x=x-(abs((Corner2.x-((Corner1.x+Corner2.x)/2))));
		p2.y=y+(abs((Corner2.y-((Corner1.y+Corner2.y)/2))));
		
	}
	else if((Corner1.x<Corner2.x&&Corner1.y<Corner2.y)||(Corner1.x>Corner2.x&&Corner1.y>Corner2.y))
	{
		p1.x=x+abs(((Corner1.x-((Corner1.x+Corner2.x)/2))));
		p1.y=y+abs((Corner1.y-((Corner1.y+Corner2.y)/2)));
		p2.x=x-(abs((Corner2.x-((Corner1.x+Corner2.x)/2))));
		p2.y=y-(abs((Corner2.y-((Corner1.y+Corner2.y)/2))));
    }
	CFigure* Line = new CLine (p1, p2,  FigGfxInfo);
	return Line;
}


void CLine::Save(ofstream &OutFile)
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
	// NAME _ID_ CORNERS _ COLOR  
	OutFile << "Line" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << color << endl;;
}
//Save the figure parameters to the file
void CLine::Load(ifstream &Infile)
{

	string type;
	string col;
	Infile >> ID;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	string drawcolor;
	Infile >> drawcolor;
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
	FigGfxInfo.isFilled = false;


}
//Load the figure parameters to the file
void CLine:: Draw(Output* pOut) const
{
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);

}

void CLine::PrintInfo(Output* pOut){
	pOut->PrintMessage("ID = "+to_string( ID) +"Line : Start(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")" + "End(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")" + "Length = "+ to_string(sqrt((Corner1.x-Corner2.x)*(Corner1.x-Corner2.x)+(Corner1.y-Corner2.y)*(Corner1.y-Corner2.y))));
}
CLine::~CLine()
{
}
