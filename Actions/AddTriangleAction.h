#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\Figures\CFigure.h"

#pragma once
class AddTriangleAction : public Action
{
	Point P1, P2 , P3 ; //tri Corners
	GfxInfo TRIGfxinfo;
public:
	AddTriangleAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	~AddTriangleAction();
};

