#include "PickTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <cstdlib>
#include <ctime>
#include "..\Figures\CEllipse.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"
#include "..\Figures\CRhombus.h"


PickTypeAction::PickTypeAction(ApplicationManager* pApp):Action(pApp)
{
}


void PickTypeAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input  Interfaces
	Input* pIn = pManager->GetInput();

	
	pIn->GetPointClicked(HIDE.x,HIDE.y);


}
void PickTypeAction::Execute()
{
	int RectCount = 0, ElpsCount = 0, LineCount = 0, RhomCount = 0, TriCount = 0, ShapeCount = 0;
	int X; //random number
	Output* pOut = pManager->GetOutput();
	//ReadActionParameters();
	//CFigure *H= pManager->GetFigure(HIDE.x,HIDE.y);
	CFigure **Copy= pManager->GetFigures();
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		if(dynamic_cast<CRectangle*>(Copy[i]))
			RectCount++;
		else if(dynamic_cast<CTriangle*>(Copy[i]))
			TriCount++;
		else if(dynamic_cast<CLine*>(Copy[i]))
			LineCount++;
		else if(dynamic_cast<CElipse*>(Copy[i]))
			ElpsCount++;
		else if(dynamic_cast<CRhombus*>(Copy[i]))
			RhomCount++;
	}
	srand(time(NULL));
	while (true)
	{
		X=rand()%6;
		if(X == 1 && RectCount != 0)
			{
				ShapeCount = RectCount;
				break;
			}
			if(X == 2 && TriCount != 0)
			{
				ShapeCount = TriCount;
				break;
			}
			if(X == 3 && LineCount != 0)
			{
				ShapeCount = LineCount;
				break;
			}
			if(X == 4 && ElpsCount != 0)
			{
				ShapeCount = ElpsCount;
				break;
			}
			if(X == 5 && RhomCount != 0)
			{
				ShapeCount = RhomCount;
				break;
			}
	}
	if(X == 1)			
		pOut->PrintMessage(" Pick all the rectangles ");
	else if(X == 2)
		pOut->PrintMessage(" Pick all the triangles ");
	else if(X == 3)
		pOut->PrintMessage(" Pick all the lines ");
	else if(X == 4)
		pOut->PrintMessage(" Pick all the ellipses ");
	else
		pOut->PrintMessage(" Pick all the Rhombuses ");
	/*if(dynamic_cast<CRectangle*>(H))
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
			X=5;*/
	int WrongCount = 0;
	int RightCount = 0;
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{	
		ReadActionParameters();
		if(dynamic_cast<CRectangle*>( pManager-> GetFigure(HIDE.x,HIDE.y))&& X==1)
		{
			pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
			pManager->GetFigure(HIDE.x,HIDE.y)->Draw(pOut);
			pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(pOut->getCrntDrawColor());
			RightCount++;
			ShapeCount--;

		}
					
		else if(dynamic_cast<CTriangle*>(pManager-> GetFigure(HIDE.x,HIDE.y))&& X==2)
		{
			pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
			pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);
			pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(pOut->getCrntDrawColor());
			RightCount++;
			ShapeCount--;
		}
		else if(dynamic_cast<CLine*>( pManager-> GetFigure(HIDE.x,HIDE.y)) && X==3)
		{
			pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
			pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
			pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(pOut->getCrntDrawColor());
			RightCount++;
			ShapeCount--;
		}
		else if(dynamic_cast<CElipse*>(pManager-> GetFigure(HIDE.x,HIDE.y)) && X==4)
		{
			pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
			pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
			pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(pOut->getCrntDrawColor());
			RightCount++;
			ShapeCount--;
		}

		else if(dynamic_cast<CRhombus*>(pManager-> GetFigure(HIDE.x,HIDE.y))&&X==5)
		{
			pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
			pManager->GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
			pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(pOut->getCrntDrawColor());
			RightCount++;
			ShapeCount--;
		}
		else
			WrongCount++;
		if (ShapeCount == 0)
		{
			break;
		}
		

	}
	pOut->PrintMessage("number of wrong picks : " + to_string(WrongCount)+"   number of right picks : " + to_string(RightCount) + ", Press anywhere to continue");
	ReadActionParameters();
	pOut->ClearStatusBar();
	}



PickTypeAction::~PickTypeAction(void)
{
	
}

