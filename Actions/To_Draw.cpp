#include "To_Draw.h"


To_Draw::To_Draw(ApplicationManager * pApp):Action(pApp)
{
}
void To_Draw::ReadActionParameters()
{
}
void To_Draw:: Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("back to draw mode :)");

}
To_Draw::~To_Draw(void)
{
}
