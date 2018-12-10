#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\PickTypeAction.h"
#include "Actions\ExitAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SwitchToPlayAction.h"
#include <cstdlib>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
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
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
	}


	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct= new AddLineAction(this);
			
			break;

		case DRAW_TRI:
			pAct =new AddTriangleAction(this);
		break;

		case DRAW_RHOMBUS:
			pAct =new AddRhombusAction(this);
			break;
		case DRAW_ELLIPSE:
			pAct =new AddEllipseAction(this);
			break;

		case TO_PLAY:
				pAct=new SwitchToPlayAction(this);			
				break;
				
		case DRAW_CUT:
				pOut->PrintMessage("Action: a Click on Cut, Click anywhere");
				break;

		case DRAW_COPY:
				pOut->PrintMessage("Action: a Click on Copy, Click anywhere");
				break;

		case DRAW_PASTE:
				pOut->PrintMessage("Action: a click on Paste, Click anywhere");
				break;

		case SAVE:							  
				pOut->PrintMessage("Action: a Click on Save graph, Click anywhere");
				break;

		case SAVE_BY_TYPE:
				pOut->PrintMessage("Action: a Click on Save by type, Click anywhere");
				break;
		
		case LOAD:
				pOut->PrintMessage("Action: a Click on Load, Click anywhere");
				break;
		
		case TO_DRAW:
				pAct=new SwitchToDrawAction(this);
				break;

		case DRAW_RESIZE:
				pOut->PrintMessage("Action: a Click on Resize, Click anywhere");
				break;

		case SELECT:
				pAct=new SelectAction(this);
				break;

		case DRAW_Todrawcolor:
				pOut->PrintMessage("Action: to select a drawing  color  , Click anywhere");
				pOut->ClearToolBar() ;
				pOut->CreatecolorToolBar() ;
				break ;

		case DRAW_TOfill:
				pOut->PrintMessage("Action: to select a fill  color  , Click anywhere");
				pOut->ClearToolBar() ;
				pOut->CreatecolorToolBar() ;
				break ;

		case DRAW_RED:
				pOut->PrintMessage("Action: a Click on Red Color, Click anywhere");
				pOut->CreateDrawToolBar() ;
				break;

		case DRAW_WHITE:
				pOut->PrintMessage("Action: a Click on White Color, Click anywhere");
					pOut->CreateDrawToolBar() ;
				break;

		case DRAW_BLACK:
				pOut->PrintMessage("Action: a Click on Black Color, Click anywhere");
				pOut->CreateDrawToolBar() ;
				break;

		case DRAW_BLUE:						  
				pOut->PrintMessage("Action: a Click on Blue Color, Click anywhere");
				pOut->CreateDrawToolBar() ;
				break;

		case DRAW_GREEN:
				pOut->PrintMessage("Action: a Click on Green Color, Click anywhere");
				pOut->CreateDrawToolBar() ;
				break;

		case PICKTYPE:	
				pOut->PrintMessage("Action: a Click on Pick by type, Click anywhere");
				pAct=new PickTypeAction (this);
				break;
		case PICKCOLOR:
				pOut->PrintMessage("Action: a Click on Pick by color, Click anywhere");
				break;
		case DEL:
				pOut->PrintMessage("Action: a Click on Delete, Click anywhere");
				break;
		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case EXIT:
			///create ExitAction here
				pAct=new ExitAction(this);			
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

 CFigure** ApplicationManager::GetFigures()const
{
	CFigure *F [MaxFigCount];
	for(int i = 0; i < FigCount; i++)
	{
		F[i] = FigList[i];
	}
	return F;
 }

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

int ApplicationManager::GetFigureCount ()const
{
	return FigCount; 
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	SelectedFig=NULL;
	
	for (int i = 0; i < FigCount; i++)
	{
		
		if(FigList[i]->IsInside(x,y))
			SelectedFig=FigList[i];
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	if(SelectedFig==NULL)
		return NULL;
	else
		return SelectedFig;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
