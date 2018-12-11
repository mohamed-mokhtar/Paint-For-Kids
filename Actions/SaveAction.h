#ifndef Save_Action_H
#define Save_Action_H

#include <iostream>
#include <fstream>
#include "Action.h"
#include <iostream>
#include "..\ApplicationManager.h"

using namespace std;

class SaveAction : public Action
{
	string FileName;

public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveAction();
};
#endif

