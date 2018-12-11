#pragma once
#include "..\Figures\CFigure.h" 
class CCircle :public CFigure 
{
	Point P1,P2;
	int R;
public:
	CCircle(Point , int , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file
	virtual bool Select(int, int);
	virtual CFigure* paste(int,int );
	virtual CFigure* copy();
	void PrintInfo(Output*);
	
	~CCircle();

};

//void Output::DrawCircle(Point P1, Point P2, int radius, GfxInfo RectGfxInfo, bool selected)