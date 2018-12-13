#pragma once

#include "AddEllipseAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp):Action(pApp)
{}



void AddEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Elipse: Click at the Center");
	
	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	EllpsGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllpsGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllpsGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a elipse with the parameters read from the user
	CEllipse *E=new CEllipse(P1, EllpsGfxInfo, pManager->GetFigureCount() + 1);
	//Add the triangle to the list of figures
	pManager->AddFigure(E);
}
