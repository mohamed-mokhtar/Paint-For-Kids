#include "DeleteAction.h"


DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp){

}

void DeleteAction::ReadActionParameters() 
{

}

void DeleteAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if(pManager->GetSelectedFig() != NULL ){
		pManager->Shifting(pManager->GetSelectedFig());
		pOut->PrintMessage("The Figure is Deleted");

	}else{
		pOut->PrintMessage("Delete button: Select A Figure First");
	}
	pOut->ClearDrawArea();
	
}

DeleteAction::~DeleteAction(){
}