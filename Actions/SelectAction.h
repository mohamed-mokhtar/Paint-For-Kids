#ifndef Select_H
#define Select_H

#include "Action.h"
#include "..\ApplicationManager.h"


class SelectAction:public Action{
	int SelectCount;   //Bonus
	Point P1;
public:
	SelectAction(ApplicationManager*);
	void getSelectedFig(CFigure*);
	virtual void ReadActionParameters();
	virtual void Execute() ;

	~SelectAction(void);
};
#endif