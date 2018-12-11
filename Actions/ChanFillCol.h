#pragma once
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"


class ChanFillCol : public Action
{
	ActionType Color;

public:
	ChanFillCol(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	~ChanFillCol(void);
};