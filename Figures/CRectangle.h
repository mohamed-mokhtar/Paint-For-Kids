#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file
	virtual bool Select(int, int) ;
	virtual CFigure* paste(int,int );
	virtual CFigure* copy();
	void PrintInfo(Output*);
};

#endif