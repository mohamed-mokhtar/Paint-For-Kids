#include "SelectAction.h"



SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp){
}

void SelectAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Button : Select A Figure");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	CFigure* SF = pManager->GetFigures(P1.x,P1.y);

	if(pManager->GetSelectedFig() != NULL){
		if(SF == NULL){
			pOut->PrintMessage("NO Figure");
		}
		else if(pManager->GetSelectedFig() != SF){
			pManager->GetSelectedFig()->SetSelected(false);
			pManager->SetSelectedFig(SF);
			pManager->GetSelectedFig()->PrintInfo(pOut);
		}
	}else{
		pManager->SetSelectedFig(pManager->GetFigures(P1.x,P1.y));
	}
	if (pManager->GetSelectedFig()!= NULL && !(pManager->GetSelectedFig())->IsSelected())
	{
		pManager->GetSelectedFig()->PrintInfo(pOut);
		pManager->GetSelectedFig()->SetSelected(true); 
	}
	else if (pManager->GetSelectedFig()!= NULL && (pManager->GetSelectedFig())->IsSelected() && SF != NULL){
		pManager->GetSelectedFig()->SetSelected(false);
		pOut->PrintMessage("UNSelect The Figure ");
		pManager->SetSelectedFig(NULL);


	}else{
		pOut->PrintMessage("No Figure");
	}
}

SelectAction::~SelectAction(){
}
