#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ChanDrawCol.h"
#include "Actions\ChanFillCol.h"
#include"Actions\CopyAction.h"
#include"Actions\CutAction.h"
#include"Actions\PasteAction.h"
#include"Actions\playmode.h"
#include"Actions\pickshape.h"
#include"Actions\pickcolor.h"
#include"Actions\pickboth.h"
#include "Actions\To_Draw.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	color DrawCol;
	color FillCol;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	int GetFigCount();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SaveAll(ofstream &OutFile); // Saving all figures @ SAVE files operation
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigures(int, int) ; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure*);
	CFigure* GetSelectedFig() const;
	void SetClipboard(CFigure*);
	CFigure*GetClipboard();
	void Shifting(CFigure*);
	void setFigCount(int);
	void copyarray(CFigure**&);
	void setDrawCol(color);
	void setFillCol(color);
	color getDrawCol();
	color getFillCol();
	void Exit();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif