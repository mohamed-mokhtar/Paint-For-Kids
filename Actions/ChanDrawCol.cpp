#include "ChanDrawCol.h"

ChanDrawCol::ChanDrawCol(ApplicationManager*pApp) :Action(pApp)
{
}
void ChanDrawCol::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change Draw Color Button : Choose A Color");
	Color = pManager->GetUserAction();
	pOut->ClearStatusBar();

}
void ChanDrawCol::Execute(){

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	if(pManager->GetSelectedFig()!=NULL){
		switch(Color){
		case WHITEcol:
			(pManager->GetSelectedFig())->ChngDrawClr(WHITE);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);

			break;


		case BLUEcol:
			(pManager->GetSelectedFig())->ChngDrawClr(BLUE);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);

			break;


		case BLACKcol:
			(pManager->GetSelectedFig())->ChngDrawClr(BLACK);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);

			break;


		case REDcol:
			(pManager->GetSelectedFig())->ChngDrawClr(RED);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);
			break;


		case GREENcol:
			(pManager->GetSelectedFig())->ChngDrawClr(GREEN);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->SetSelectedFig(NULL);

			break;

		}
	}
	else{

		switch(Color){
		case WHITEcol:
			UI.DrawColor = WHITE;
			break;


		case BLUEcol:
			UI.DrawColor = BLUE;
			break;


		case BLACKcol:
			UI.DrawColor = BLACK;

			break;


		case REDcol:
			UI.DrawColor = RED;
			break;


		case GREENcol:
			UI.DrawColor = GREEN;

			break;


		}
	}
	pManager->UpdateInterface();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();

}

ChanDrawCol::~ChanDrawCol(){
}

