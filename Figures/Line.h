#pragma once
#ifndef LINE_H
#define LINE_H
#include "CFigure.h"

class CLine : public CFigure
{
private :
	Point Corner1, Corner2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file
	virtual bool Select(int, int);
	void PrintInfo(Output*);
	virtual CFigure* paste(int,int );
	virtual CFigure* copy();
	~CLine();
};

#endif