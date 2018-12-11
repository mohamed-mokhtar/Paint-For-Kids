#include "AddCircleAction.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp) :Action(pApp)
{

}
void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the orgin");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Circle : Click at second point to get R");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	R = sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));
	LineGfxinfo.isFilled = UI.isFilled;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LineGfxinfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxinfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a line with the parameters read from the user
	CCircle *C = new CCircle(P1, R , LineGfxinfo);

	//Add the line to the list of figures
	pManager->AddFigure(C);
}

AddCircleAction::~AddCircleAction()
{

}
