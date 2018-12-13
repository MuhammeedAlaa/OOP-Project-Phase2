#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp):Action(pApp)
{}
void AddRhombusAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Rhombus with the parameters read from the user
	CRhombus *R=new CRhombus(P1, RectGfxInfo, pManager->GetFigureCount() + 1);

	//Add the Rhombus to the list of figures
	pManager->AddFigure(R);
}

