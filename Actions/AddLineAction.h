#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\Line.h" 
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\Figures\CFigure.h"

#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

//Add LINE Action class
class AddLineAction : public Action
{
private:
	Point P1, P2; //LINE Corners
	GfxInfo LineGfxinfo;
public:
	AddLineAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	~AddLineAction();
};

#endif