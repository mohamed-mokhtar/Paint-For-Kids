#include "PasteAction.h"


PasteAction::PasteAction(ApplicationManager*pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn= pManager->GetInput();
	if(pManager->GetClipboard()!=NULL)
	{
		pOut->PrintMessage("Paste Button: Click Where you want to paste the figure");
		pIn->GetPointClicked(p1.x,p1.y);
		pOut->ClearStatusBar();
	}
	else 
	{
		pOut->PrintMessage("Paste Button: Please Copy or Cut a Figure First");
	}
}
void PasteAction::Execute()
{
	Output * pOut =  pManager->GetOutput();
	ReadActionParameters();

	if(pManager->GetClipboard()!=NULL)
	{
		CFigure* c =pManager->GetClipboard()->paste(p1.x, p1.y );
		pManager->AddFigure(c);
	}
	else 
	{
		pOut->PrintMessage("Paste Button: Please Copy or Cut a Figure First");
	}
}


PasteAction::~PasteAction(void)
{
}
