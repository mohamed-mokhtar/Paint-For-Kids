#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"


class PasteAction: public Action
{
	Point p1;
public:
	PasteAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PasteAction(void);
};
