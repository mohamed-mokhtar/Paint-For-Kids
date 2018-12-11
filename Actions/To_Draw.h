#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"

class To_Draw:public Action
{
public:
	To_Draw(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	void Execute();
	~To_Draw();
};

