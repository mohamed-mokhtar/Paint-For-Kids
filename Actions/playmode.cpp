#include "playmode.h"


playmode::playmode(ApplicationManager *pApp): Action(pApp)
{}	//constructor

void playmode::ReadActionParameters() 
{

	pA=pManager->GetUserAction();
}
void playmode::Execute() 
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Switch to Play Mode:choose a type :)");
	pOut->CreatePlayToolBar();
	ReadActionParameters();
	

		switch(pA)
		{
		case pick_shape:
			pManager->ExecuteAction(pick_shape);
			pManager->UpdateInterface();
			
			break;
		case pick_color:
			pManager->ExecuteAction(pick_color);
			pManager->UpdateInterface();
			
			break;
		case pick_both:
			pManager->ExecuteAction(pick_both);
			pManager->UpdateInterface();
			
			break;
		case TO_DRAW:
			pManager->ExecuteAction(TO_DRAW);
			break;
		}
		
	
	
	
	
	
}
playmode::~playmode(void)
{
}
