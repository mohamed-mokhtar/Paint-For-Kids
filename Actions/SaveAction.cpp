#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager *pApp) : Action (pApp)
{

}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save Action , Please Enter the file name :");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open("Saved//" + FileName + ".txt", ios::out);
	color C;
	string DrawColor;
	string Fillcolor;
	int r_Draw, g_Draw, b_Draw;
	int r_Fill, g_Fill, b_Fill;
	r_Draw =(int)UI.DrawColor.ucRed;
	g_Draw = (int)UI.DrawColor.ucGreen;
	b_Draw = (int)UI.DrawColor.ucBlue;
	//-------------------------------//
	r_Fill = (int)UI.FillColor.ucRed;
	g_Fill = (int)UI.FillColor.ucGreen;
	b_Fill = (int)UI.FillColor.ucBlue;
	//------------------------------//
	if (r_Draw == 0 && g_Draw == 0 && b_Draw == 0)
		DrawColor = "BLACK";
	if (r_Draw == 255 && g_Draw == 0 && b_Draw == 0)
		DrawColor = "RED";
	if (r_Draw == 0 && g_Draw == 255 && b_Draw == 0)
		DrawColor = "GREEN";
	if (r_Draw == 0 && g_Draw == 0 && b_Draw == 255)
		DrawColor = "BLUE";
	if (r_Draw == 255 && g_Draw == 255 && b_Draw == 255)
		DrawColor = "WHITE";
	//------------------------------//
	if (r_Fill == 0 && g_Fill == 0 && b_Fill == 0)
		Fillcolor = "BLACK";
	if (r_Fill == 255 && g_Fill == 0 && b_Fill == 0)
		Fillcolor = "RED";
	if (r_Fill == 0 && g_Fill == 255 && b_Fill == 0)
		Fillcolor = "GREEN";
	if (r_Fill == 0 && g_Fill == 0 && b_Fill == 255)
		Fillcolor = "BLUE";
	if (r_Fill == 255 && g_Fill == 255 && b_Fill == 255)
		Fillcolor = "WHITE";
	OutFile << DrawColor << " " << Fillcolor << endl;
	OutFile << pManager->GetFigCount()<<endl ;
	pManager->SaveAll(OutFile);
	OutFile.close();
}




SaveAction::~SaveAction()
{
}
