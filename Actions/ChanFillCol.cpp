#include "ChanFillCol.h"

ChanFillCol::ChanFillCol(ApplicationManager*pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateColorToolBar();
}

void ChanFillCol::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Draw Color Button : Choose A Color");
	Color = pManager->GetUserAction();
	pOut->ClearStatusBar();

}
void ChanFillCol::Execute(){

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	if (dynamic_cast<CLine*>(pManager->GetSelectedFig()) != NULL)
	{
		(pManager->GetSelectedFig())->SetSelected(false);
		pManager->SetSelectedFig(NULL);
		pOut->PrintMessage("Line Don't Have A FillColor");
	}

	else if(pManager->GetSelectedFig()!=NULL){
		switch(Color){

		case WHITEcol:
			(pManager->GetSelectedFig())->ChngFillClr(WHITE);
			break;


		case BLUEcol:
			(pManager->GetSelectedFig())->ChngFillClr(BLUE);
			break;


		case BLACKcol:
			(pManager->GetSelectedFig())->ChngFillClr(BLACK);
			break;

		case REDcol:
			(pManager->GetSelectedFig())->ChngFillClr(RED);
			break;


		case GREENcol:
			(pManager->GetSelectedFig())->ChngFillClr(GREEN);
			break;

		}
		(pManager->GetSelectedFig())->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}

	else{

		UI.isFilled=true;
		switch(Color){

		case WHITEcol:
			UI.FillColor = WHITE;
			break;

		case BLUEcol:
			UI.FillColor = BLUE;
			break;

		case BLACKcol:
			UI.FillColor = BLACK;
			break;

		case REDcol:
			UI.FillColor = RED;
			break;

		case GREENcol:
			UI.FillColor = GREEN;
			break;
		}
	}

	pManager->UpdateInterface();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();

}

ChanFillCol::~ChanFillCol(){

}