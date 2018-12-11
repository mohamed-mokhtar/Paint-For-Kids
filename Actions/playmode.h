#pragma once
#include"Action.h"
#include"pickshape.h"
#include"pickcolor.h"
#include"..\ApplicationManager.h"

class playmode :public Action
{
	ActionType pA;
public:
	playmode(ApplicationManager *pApp) ;	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute() ;
	virtual~playmode(void);
};

