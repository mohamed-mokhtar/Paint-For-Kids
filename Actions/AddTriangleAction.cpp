#include "AddTriangleAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\Triangle.h"


AddTriangleAction::AddTriangleAction(ApplicationManager *pApp) :Action(pApp)
{
}

 void AddTriangleAction::ReadActionParameters()
{

	 //Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 pOut->PrintMessage("New TRIANGLE : Click at first corner");

	 //Read 1st corner and store in point P1
	 pIn->GetPointClicked(P1.x, P1.y);

	 pOut->PrintMessage("New TRIANGLE: Click at second corner");

	 //Read 2nd corner and store in point P2
	 pIn->GetPointClicked(P2.x, P2.y);


	 pOut->PrintMessage("New TRIANGLE: Click at third corner");

	 //Read 2nd corner and store in point P2
	 pIn->GetPointClicked(P3.x, P3.y);

	 TRIGfxinfo.isFilled = UI.isFilled;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	 TRIGfxinfo.DrawClr = pOut->getCrntDrawColor();
	 TRIGfxinfo.FillClr = pOut->getCrntFillColor();

	 pOut->ClearStatusBar();
}
 void AddTriangleAction::Execute()
{
	 //This action needs to read some parameters first
	 ReadActionParameters();

	 //Create a rectangle with the parameters read from the user
	 CTriangle *T = new CTriangle(P1, P2, P3, TRIGfxinfo);

	 //Add the rectangle to the list of figures
	 pManager->AddFigure(T);

}

AddTriangleAction::~AddTriangleAction()
{
}
