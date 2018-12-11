#pragma once
#include"Action.h"
#include "..\ApplicationManager.h"
#include "..\DEFS.h"
#include"..\GUI\UI_Info.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"

class pickboth :public Action
{
private:
	Point p;
	CFigure**f;
	int n;
	enum types
    {
	circle,
	triangle,
	line,
	rectangle,
   }shape;
   enum typec
	{
	white,
	blue,
	red,
	green,
	black,
	}color;
public:
	pickboth(ApplicationManager *);
	virtual void ReadActionParameters();
	virtual void Execute();
	void picking(int);
	void randoms (int &,int &,int &,int &);
	void randomc (int & ,int & ,int & ,int & ,int&);
	void numshape (int&,int&,int&,int&);
	void numcolor (int&,int&,int&,int&,int&);
	bool figtypec(CFigure*);
	bool figtypes(CFigure*);
	void print(int r,int w);
	void UpdateInterface(); 
	void deletefig(CFigure*);
	bool checkcolor();
	bool actiontype();
	virtual~pickboth(void);
};

