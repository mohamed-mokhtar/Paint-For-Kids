#pragma once
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\Figures\CFigure.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
class CopyAction:public Action
{
public:
	CopyAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute() ;
	~CopyAction();
};
