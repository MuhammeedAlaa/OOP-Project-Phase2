#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\PickTypeAction.h"
#include "Actions\PickColorAction.h"
#include "Actions\ExitAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\ChngDrwClrAction.h"
#include "Actions\ChngFilClrAction.h"
#include <cstdlib>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
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
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);

	}
	//According to Action Type, create the corresponding action object
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
				pAct = new ChngDrwClrAction(this);
				break ;

		case DRAW_TOfill:
				pAct = new ChngFilClrAction(this);
				break ;

		case PICKTYPE:	
				pAct=new PickTypeAction (this);
				break;
		case PICKCOLOR:
				pAct=new PickColorAction (this);
				break;
		case DEL:
				pAct = new DeleteAction(this); 
				break;
		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case EXIT:
			///create ExitAction here
				pAct=new ExitAction(this);			
				break;
		case DRAWING_AREA:
			
		case STATUS:	//a click on the status bar ==> no action
			return;
		default:
			{
			UpdateInterface();
			pOut->ClearStatusBar();
			}
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

// to get the figure list	for play mode
 CFigure** ApplicationManager::GetFigures()
{
	return FigList;
 }

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;

}

// to get the selected figure to change its color
CFigure* ApplicationManager::GetSelected()
{
	return SelectedFig;
}
//to UnSelect figures
void ApplicationManager::UnSelect(CFigure* C)
{
	if(SelectedFig!=NULL)
	{
		C->SetSelected(false);
		UpdateInterface();
		SelectedFig=NULL;
	}
}



//delete a figure from the list, it had to be implemented here because deleting a figure has effect on the figure list and only the app manager has access to it
void ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if(SelectedFig == FigList[i])
		{	
			delete FigList[i];
			SelectedFig = NULL;
			for (i ; i < FigCount - 1; i++)
			{
				FigList[i] = FigList[i+1];
			}
			FigList[FigCount - 1] = NULL;
			FigCount--;
			UpdateInterface();
			return;
		}
	}
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
		if(FigList[i] != NULL)
			if(FigList[i]->IsInside(x,y))
				SelectedFig=FigList[i];
	}

	return SelectedFig;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
		
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
	{	if(!FigList[i])
			continue;
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
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
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
