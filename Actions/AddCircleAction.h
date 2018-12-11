#pragma once
#ifndef ADD_Circle_ACTION_H
#define ADD_Circle_ACTION_H

#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CCircle.h"

class AddCircleAction : public Action
{
	Point P1, P2; //LINE Corners
	int R;
	GfxInfo LineGfxinfo;
public:

	AddCircleAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddCircleAction();
};

#endif