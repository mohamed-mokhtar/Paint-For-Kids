#pragma once
#include "Action.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"..\GUI\UI_Info.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"
class pickshape :public Action
{
private:
	Point p;
	CFigure**f;
	int n;
	enum type
	{
		circle,
		triangle,
		line,
		rectangle,
	}shape;
public:
	pickshape(ApplicationManager *pApp);
	pickshape();
	virtual void ReadActionParameters();
	void random(int &,int &,int &,int &);
	void numofig(int &,int &,int &,int &);
	virtual void Execute();
	void picking(int);
	void deletefig(CFigure*);
	bool getfigtype(CFigure*);
	void UpdateInterface() const;
	void print(int ,int);
	bool actiontype();
	virtual~pickshape(void);
};

