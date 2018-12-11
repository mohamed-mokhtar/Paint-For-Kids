#include"CopyAction.h"


CopyAction::CopyAction(ApplicationManager*pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters() {


}


void CopyAction::Execute()
{
	ReadActionParameters();
	Output* pOut= pManager->GetOutput();
	if(pManager->GetSelectedFig()!=NULL)
	{
		CFigure * C = pManager->GetSelectedFig()->copy();
		pManager->SetClipboard(C);
		pOut->PrintMessage("Copy Button : You Copied This Figure");
	}
	else 
		pOut->PrintMessage("Copy Button : Please select a figure first to copy it ");

}

CopyAction::~CopyAction()
{
}
