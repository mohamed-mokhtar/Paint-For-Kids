#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"

class CutAction:public Action
{

public:
	CutAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~CutAction(void);
};

