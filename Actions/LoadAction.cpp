#include "LoadAction.h"


LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{
}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Action , Please Enter the file name :");
	Filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void LoadAction::Execute()
{

	ReadActionParameters();
	ifstream Infile;
	Infile.open("Saved//" + Filename + ".txt", ios::in);
	if (!Infile)
	{
		pManager->GetOutput()->PrintMessage("File Not Found");
	}
	else
	{
		Output *pOut = pManager->GetOutput();
		pManager->setFigCount(0);
		pOut->ClearDrawArea();
		Point emptyP = Point();
		GfxInfo emptyGFX;
		string drawcolor;
		string fillcolor;
		Infile >> drawcolor;
		if (drawcolor == "BLACK")
		{
			UI.DrawColor.ucRed = 0;
			UI.DrawColor.ucGreen = 0;
			UI.DrawColor.ucBlue = 0;
		}
		else if (drawcolor == "RED")
		{
			UI.DrawColor.ucRed = 255;
			UI.DrawColor.ucGreen = 0;
			UI.DrawColor.ucBlue = 0;
		}
		else if (drawcolor == "GREEN")
		{
			UI.DrawColor.ucRed = 0;
			UI.DrawColor.ucGreen = 255;
			UI.DrawColor.ucBlue = 0;
		}
		else if (drawcolor == "BLUE")
		{
			UI.DrawColor.ucRed = 0;
			UI.DrawColor.ucGreen = 0;
			UI.DrawColor.ucBlue = 255;
		}
		else 
		{
			UI.DrawColor.ucRed = 255;
			UI.DrawColor.ucGreen = 255;
			UI.DrawColor.ucBlue = 255;
		}
		Infile >> fillcolor;

		if (fillcolor == "NO_FILL")
		{
			UI.isFilled = false;
		}
		else
		{
			UI.isFilled = true ;

			if (fillcolor == "BLACK")
			{
				UI.FillColor.ucRed = 0;
				UI.FillColor.ucGreen = 0;
				UI.FillColor.ucBlue = 0;
			}
			else if (fillcolor == "RED")
			{
				UI.FillColor.ucRed = 255;
				UI.FillColor.ucGreen = 0;
				UI.FillColor.ucBlue = 0;
			}
			else if (fillcolor == "GREEN")
			{
				UI.FillColor.ucRed = 0;
				UI.FillColor.ucGreen = 255;
				UI.FillColor.ucBlue = 0;
			}
			else if (fillcolor == "BLUE")
			{
				UI.FillColor.ucRed = 0;
				UI.FillColor.ucGreen = 0;
				UI.FillColor.ucBlue = 255;
			}
			else 
			{
				UI.FillColor.ucRed = 255;
				UI.FillColor.ucGreen = 255;
				UI.FillColor.ucBlue = 255;
			}
		}
		int FigCount;
		Infile >> FigCount;
		string FigType;
		for (int i =0 ; i<FigCount ; i++)
		{
			Infile >> FigType;
			if (FigType == "Rectangle") {
				CRectangle* rec = new CRectangle(emptyP, emptyP, emptyGFX);
				rec->Load(Infile);
				pManager->AddFigure(rec);
			}
			if (FigType == "Triangle") {
				CTriangle* trig = new CTriangle(emptyP, emptyP, emptyP, emptyGFX);
				trig->Load(Infile);
				pManager->AddFigure(trig);
			}
			if (FigType == "Circle") {
				CCircle* circ = new CCircle(emptyP, 0, emptyGFX);
				circ->Load(Infile);
				pManager->AddFigure(circ);
			}
			if (FigType == "Line") {
				CLine * line = new CLine(emptyP, emptyP, emptyGFX);
				line->Load(Infile);
				pManager->AddFigure(line);
			}
		}

		Infile.close();

	}





}
LoadAction::~LoadAction()
{

}
