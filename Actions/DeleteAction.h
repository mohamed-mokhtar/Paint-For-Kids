#ifndef Del_Action_H
#define Del_Action_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\ApplicationManager.h"

class DeleteAction: public Action
{
	Point P; 
private:

public:
	DeleteAction(ApplicationManager* );
	void ReadActionParameters();
	void Execute();
	~DeleteAction();
};
#endif