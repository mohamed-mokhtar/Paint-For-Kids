#include "Triangle.h"
#include <iostream>
#include <fstream>
using namespace std; 


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
bool CTriangle::Select(int x, int y) {
	float A1, A2, A3, Area;
	Area =abs( (Corner1.x*(Corner2.y - Corner3.y)) +( Corner2.x*(Corner3.y - Corner1.y)) + (Corner3.x*(Corner1.y-Corner2.y)))/2.0;
	A1 = abs((x*(Corner2.y - Corner3.y)) + (Corner2.x*(Corner3.y - y)) + (Corner3.x*(y-Corner2.y)))/2.0;
	A2 = abs((Corner1.x*(y - Corner3.y)) +( x*(Corner3.y - Corner1.y) )+ (Corner3.x*(Corner1.y-y)))/2.0;
	A3 = abs((Corner1.x*(Corner2.y - y)) +( Corner2.x*(y - Corner1.y)) +( x*(Corner1.y-Corner2.y)))/2.0;

	return (Area == A1+ A2+ A3);
}
 void CTriangle::Draw(Output* pOut) const
{
	 pOut->DrawTriang(Corner1, Corner2, Corner3, FigGfxInfo, Selected);

}

 CFigure* CTriangle::copy()
 {
	 CFigure* tri=new CTriangle(Corner1,Corner2,Corner3, FigGfxInfo);
	return tri;
 }

  CFigure* CTriangle::paste(int x,int y)
{

	Point p1,p2,p3,center,dis;
	center.x=(Corner1.x+Corner2.x+Corner3.x)/3;
	center.y=(Corner1.y+Corner2.y+Corner3.y)/3;
dis.x=x-center.x;
	dis.y=y-center.y;
	p1.x=(dis.x+Corner1.x);
	p1.y=(dis.y+Corner1.y);
	p2.x=(dis.x+Corner2.x);
	p2.y=(dis.y+Corner2.y);
	p3.x=(dis.x+Corner3.x);
	p3.y=(dis.y+Corner3.y);
	CFigure* tri=new CTriangle(p1,p2,p3, FigGfxInfo);
	return tri;
}


 void CTriangle::Save(ofstream &OutFile)
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

	 // NAME _ ID_ CORNERS _ COLOR _FILL OR NOT
	 OutFile << "Triangle" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
	 OutFile << color << " " << fill << endl;

 }
 //Save the figure parameters to the file
 void CTriangle::Load(ifstream &Infile)
 {

	 Infile >> ID;
	 Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
 //Load the figure parameters to the file

void CTriangle::PrintInfo(Output* pOut){
	pOut->PrintMessage("ID = "+to_string( ID)+"Triangle : Point1(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") Point2(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ") Point3(" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")" );
}

CTriangle::~CTriangle()
{
}
