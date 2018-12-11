#include "ApplicationManager.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	SelectedFig = NULL;	
	Clipboard=NULL;
	UI.isFilled=false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_TRI :
		pAct = new AddTriangleAction(this);
		break;

	case CHNG_DRAW_CLR:
		pOut->ClearToolBar();
		pOut->CreateColorToolBar();
		pAct = new ChanDrawCol(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChanFillCol(this);
		break;


	case DRAW_CIRC :
		pAct = new AddCircleAction(this);
		break;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case DEL:
		pAct = new DeleteAction(this);
		break;

	case COPY:
		pAct= new CopyAction(this);
		break;

	case CUT:
		pAct= new CutAction(this);
		break;

	case PASTE:
		pAct= new PasteAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case TO_PLAY:
		pAct = new playmode(this);
		break;

	case pick_shape:
		pAct = new pickshape(this);
		break;

	case pick_color:
		pAct= new pickcolor(this);
		break;

	case pick_both:
		pAct= new pickboth(this);
		break;

	case TO_DRAW:

		pAct= new To_Draw(this);
		break;

	case EXIT:
		///create ExitAction here
		pOut->PrintMessage("Bye Bye ! :)");
		Exit();
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
int ApplicationManager::GetFigCount() 
{
	return FigCount;
}

void ApplicationManager::setFigCount(int C){
	FigCount = C;
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

void ApplicationManager::SetClipboard(CFigure* CF)
{
	if(Clipboard!=NULL)
		delete Clipboard;
	Clipboard=CF;
}
CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
}



////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SaveAll(ofstream &OutFile)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}
////////////////////////////////////////////////////////////////////////////////////


CFigure* ApplicationManager::GetFigures(int x, int y) 
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = FigCount - 1 ; i >= 0; i--){
		if(FigList[i]->Select(x, y)){
			return FigList[i] ;
		} 
	}return NULL;
}
void ApplicationManager::copyarray(CFigure**&f)
{
	for(int i=0;i<FigCount;i++)
	{
		f[i] =FigList[i];
	}
}

void ApplicationManager::SetSelectedFig(CFigure* SF){
	SelectedFig = SF;
}
CFigure* ApplicationManager::GetSelectedFig() const{
	return SelectedFig;
}

void ApplicationManager::Shifting(CFigure* DelFig){
	GetSelectedFig()->SetSelected(false);
	SetSelectedFig(NULL);
	for (int i = 0; i < FigCount; i++)
	{
		if(DelFig == FigList[i]){
			CFigure*temp = FigList[i];
			for (int j = i +1; j < FigCount ; j++)
			{
				FigList[j-1] = FigList[j]; 
			}
			FigList[FigCount-1]=temp;
			delete FigList[FigCount-1] ;

			FigCount--;
			return;
		}
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++){
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		FigList[i]->setID(i+1);
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setDrawCol(color newcol){
	DrawCol = newcol ;
}
void ApplicationManager::setFillCol(color newcol){
	FillCol = newcol ; 
}
color ApplicationManager::getDrawCol(){
	return DrawCol;
}
color ApplicationManager::getFillCol(){
	return FillCol;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Exit()
{
	for (int i = 0; i<FigCount; i++)
		delete FigList[i];
	if (Clipboard != NULL)
		delete Clipboard;
	exit(EXIT_SUCCESS);
	FigCount = 0;

}
//Destructor
ApplicationManager::~ApplicationManager()
{
	delete pIn;
	delete pOut;
	pIn = NULL;
	pOut = NULL;
}
