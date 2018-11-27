#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Figures\CRectangle.h"
#include "Figures\CEllipse.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddTriAction.h"
#include "Figures\CTriangle.h"
#include "Actions\AddLineAction.h"
#include "Figures\Cline.h"
#include "Actions\AddRhomAction.h"
#include "Figures\CRhombus.h"
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
				pOut->PrintMessage("Action: Switch to Play Mode, Creating Design toolbar");
				pOut->ClearToolBar();
				pOut->CreatePlayToolBar();
				pOut->ClearDrawArea();
				break;
				
		case DRAW_CUT:
				pOut->PrintMessage("Action: a Click on Cut, Click anywhere");
				break;

		case DRAW_COPY:
			{
				pOut->PrintMessage("Action: a Click on Copy, Click anywhere");
				break;
			}
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
				pOut->PrintMessage("Action: Switch to Draw Mode, Creating simualtion toolbar");
				pOut->ClearToolBar();
				pOut->CreateDrawToolBar();
				break;

		case DRAW_RESIZE:
				pOut->PrintMessage("Action: a Click on Resize, Click anywhere");
				break;

		case SELECT:
				{pOut->PrintMessage("Action: a Click on Select, Click anywhere");
				Point P;
				pIn->GetPointClicked(P.x,P.y);
				if(GetFigure(P.x,P.y))
				GetFigure(P.x,P.y)->SetSelected(true);
				SelectedFig=NULL;
				break;
				}

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
				{
					UpdateInterface();
					Point P;
					pOut->PrintMessage("Action: a Click on Pick by type, Click anywhere");
					CFigure *H= FigList[rand()%FigCount];
					int X=0;
					if(dynamic_cast<CRectangle*>(H))
						X=1;
					else
						if(dynamic_cast<CTriangle*>(H))
							X=2;
					else
					if(dynamic_cast<CLine*>(H))
						X=3;
					else
					if(dynamic_cast<CElipse*>( H))
					X=4;
					else
					if(dynamic_cast<CRhombus*>(H))
						X=5;
					for (int i = 0; i < FigCount; i++)
					{
						pIn->GetPointClicked(P.x,P.y);
						if(dynamic_cast<CRectangle*>( GetFigure(P.x,P.y))&& X==1)
						{GetFigure(P.x,P.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						GetFigure(P.x,P.y)->Draw(pOut);	}
					
						if(dynamic_cast<CTriangle*>( GetFigure(P.x,P.y))&&X==2)
							{GetFigure(P.x,P.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						GetFigure(P.x,P.y)->Draw(pOut);	}
						if(dynamic_cast<CLine*>( GetFigure(P.x,P.y))&&X==3)
							{GetFigure(P.x,P.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						GetFigure(P.x,P.y)->Draw(pOut);	}
						if(dynamic_cast<CElipse*>( GetFigure(P.x,P.y))&&X==4)
							{GetFigure(P.x,P.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						GetFigure(P.x,P.y)->Draw(pOut);	}

						if(dynamic_cast<CRhombus*>( GetFigure(P.x,P.y))&&X==5)
						{GetFigure(P.x,P.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						GetFigure(P.x,P.y)->Draw(pOut);	}			
					}
					

				break;
				}

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

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
//a function to get the area of a triangle

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CRectangle *R;
	CTriangle *T;
	CLine *L;
	CRhombus *RH;
	CElipse *E;
	
	for (int i = 0; i < FigCount; i++)
	{
		if(dynamic_cast<CRectangle*>(FigList[i]))
		{	R=dynamic_cast<CRectangle*>(FigList[i]);
		if((R->GetC1().x>x&&R->GetC2().x<x||R->GetC1().x<x&&R->GetC2().x>x)&&(R->GetC1().y>y&&R->GetC2().y<y||R->GetC1().y<y&&R->GetC2().y>y))
		{
			SelectedFig=R;
		}
		}
		if(dynamic_cast<CTriangle*>(FigList[i]))
		{
			T=dynamic_cast<CTriangle*>(FigList[i]);
			float A=area(T->GetV1().x,T->GetV1().y,T->GetV2().x,T->GetV2().y,T->GetV3().x,T->GetV3().y);
			float A1=area(x,y,T->GetV2().x,T->GetV2().y,T->GetV3().x,T->GetV3().y);
			float A2=area(T->GetV1().x,T->GetV1().y,x,y,T->GetV3().x,T->GetV3().y);
			float A3=area(T->GetV1().x,T->GetV1().y,T->GetV2().x,T->GetV2().y,x,y);
			if(A==(A1+A2+A3))
			{
				SelectedFig=T;
				
			}
		}

		if(dynamic_cast<CLine*>(FigList[i]))
		{	L=dynamic_cast<CLine*>(FigList[i]);
		float M=L->GetSlope();
		float C=L->GetTHEC();
		float H=ceil(M*x+C);
		if(y==H)
		{
			SelectedFig=L;
		
		}
				
		}
		if(dynamic_cast<CRhombus*>(FigList[i]))
		{
			RH=	dynamic_cast<CRhombus*>(FigList[i]);
			float A=area(RH->GetCenter().x-100,RH->GetCenter().y,RH->GetCenter().x,RH->GetCenter().y+50,RH->GetCenter().x+100,RH->GetCenter().y)*2;
			float A1=area(x,y,RH->GetCenter().x,RH->GetCenter().y+50,RH->GetCenter().x+100,RH->GetCenter().y);
			float A2=area(x,y,RH->GetCenter().x,RH->GetCenter().y+50,RH->GetCenter().x-100,RH->GetCenter().y);
			float A3=area(x,y,RH->GetCenter().x,RH->GetCenter().y-50,RH->GetCenter().x+100,RH->GetCenter().y);
			float A4=area(x,y,RH->GetCenter().x,RH->GetCenter().y-50,RH->GetCenter().x-100,RH->GetCenter().y);
			if(A==(A1+A2+A3+A4))
			{
				SelectedFig=RH;
			
			}

		}

		if (dynamic_cast<CElipse*>(FigList[i]))
		{
			E=dynamic_cast<CElipse*>(FigList[i]);
			float H=(1.0*(x-E->GetFocus().x)*(x-E->GetFocus().x))/(10000)+(1.0*(y-E->GetFocus().y)*(y-E->GetFocus().y))/(50*50);
			if(H<=1)
				{
					SelectedFig=E;
					
				}

		}
		

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
