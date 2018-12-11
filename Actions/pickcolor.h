#pragma once

#include<cstring>
#include"Action.h"
#include"..\Figures\Line.h"
#include"..\ApplicationManager.h"
#include"..\GUI\UI_Info.h"

class pickcolor:public Action
{
private:
	Point p;
	CFigure**f;
	int n;
	enum type
	{
		white,
		blue,
		red,
		green,
		black,
	}color;
public:
	pickcolor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	void random(int &,int &,int &,int &,int &);
	virtual void Execute();
	void picking(int);
	void deletefig(CFigure*);
	bool getfigtype(CFigure*);
	void UpdateInterface() const;
	void numofcolor(int & ,int & ,int & ,int & ,int& );
	void print(int ,int);
	bool actiontype();
	virtual~pickcolor(void);
};

