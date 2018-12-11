#pragma once
#include"Action.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class ChanDrawCol : public Action
{
	ActionType Color;
private:

public:
	ChanDrawCol(ApplicationManager* );
	void ReadActionParameters();
	void Execute();
	~ChanDrawCol();

};
