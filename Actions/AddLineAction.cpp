#include "AddLineAction.h"


AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{

}
 void AddLineAction::ReadActionParameters()
{
	 //Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 pOut->PrintMessage("New Line: Click at first corner");

	 //Read 1st corner and store in point P1
	 pIn->GetPointClicked(P1.x, P1.y);

	 pOut->PrintMessage("New Line : Click at second corner");

	 //Read 2nd corner and store in point P2
	 pIn->GetPointClicked(P2.x, P2.y);

	 LineGfxinfo.isFilled =false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	 LineGfxinfo.DrawClr = pOut->getCrntDrawColor();
	 LineGfxinfo.FillClr = pOut->getCrntFillColor();

	 pOut->ClearStatusBar();
}
 void AddLineAction::Execute()
{
	 //This action needs to read some parameters first
	 ReadActionParameters();

	 //Create a line with the parameters read from the user
	 CLine *L = new CLine(P1, P2, LineGfxinfo);

	 //Add the line to the list of figures
	 pManager->AddFigure(L);
}
AddLineAction::~AddLineAction()
{
}
