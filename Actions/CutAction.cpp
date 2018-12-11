#include "CutAction.h"



CutAction::CutAction(ApplicationManager*pApp):Action(pApp)
{
}

void CutAction::ReadActionParameters()
{


}

void CutAction::Execute()
{
	ReadActionParameters();
	Output*pOut=pManager->GetOutput();
	if(pManager->GetSelectedFig()!=NULL)
	{
		pOut->PrintMessage("cut button: You Cut This Figure");
		CFigure * C = pManager->GetSelectedFig()->copy();
		pManager->SetClipboard(C);
		pManager->Shifting(pManager->GetSelectedFig());
		pOut->ClearDrawArea();
	}
	else 
		pOut->PrintMessage("Cut Button : Please Select A Figure First to Cut It");
}
CutAction::~CutAction(void)
{
}
