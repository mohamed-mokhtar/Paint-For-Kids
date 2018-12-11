#pragma once
#ifndef TRI_H
#define TRI_H
#include "CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point,Point , Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file
	virtual bool Select(int, int);
	virtual CFigure* paste(int,int );
	virtual CFigure* copy();
	void PrintInfo(Output*);
	~CTriangle();
};

#endif