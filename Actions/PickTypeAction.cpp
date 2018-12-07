#include "PickTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <cstdlib>
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
		Output* pOut = pManager->GetOutput();
		ReadActionParameters();
		CFigure *H= pManager->GetFigure(HIDE.x,HIDE.y);
			CFigure **Copy= pManager->GetFigures();
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{
			if(H==Copy[i])
				*Copy=H;
		}
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
					for (int i = 0; i < pManager->GetFigureCount(); i++)
					{
						
						pOut->PrintMessage(" Pick a Figure ");
						if(dynamic_cast<CRectangle*>( pManager-> GetFigure(HIDE.x,HIDE.y))&& X==1)
						{
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						pManager->GetFigure(HIDE.x,HIDE.y)->Draw(pOut);
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(BLACK);
						}
					
						if(dynamic_cast<CTriangle*>( pManager-> GetFigure(HIDE.x,HIDE.y))&&X==2)
						{
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(BLACK);
						}
						if(dynamic_cast<CLine*>( pManager-> GetFigure(HIDE.x,HIDE.y))&&X==3)
						{
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(BLACK);
						}
						if(dynamic_cast<CElipse*>(pManager-> GetFigure(HIDE.x,HIDE.y))&&X==4)
						{
						pManager->GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(BLACK);
						}

						if(dynamic_cast<CRhombus*>(pManager-> GetFigure(HIDE.x,HIDE.y))&&X==5)
						{
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(LIGHTGOLDENRODYELLOW);
						pManager-> GetFigure(HIDE.x,HIDE.y)->Draw(pOut);	
						pManager-> GetFigure(HIDE.x,HIDE.y)->ChngDrawClr(BLACK);
						}
						ReadActionParameters();
					}
}



PickTypeAction::~PickTypeAction(void)
{
}

