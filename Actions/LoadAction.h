#pragma once
#include <iostream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "..\ApplicationManager.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\Triangle.h "
#include "..\Figures\Line.h"
#include "..\GUI\input.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\output.h"
#include "SaveAction.h"

class LoadAction :public Action
{
	string Filename;
public:
	LoadAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~LoadAction();
};

