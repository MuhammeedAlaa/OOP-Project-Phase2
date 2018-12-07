#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Select a Figure ");
	Input* pIn = pManager->GetInput();

	
	pIn->GetPointClicked(Select.x, Select.y);


}

//Execute the action
void SelectAction::Execute() 
{

	//This action needs to read some parameters first
	ReadActionParameters();

		if(this->pManager->GetFigure(Select.x,Select.y))
	this->pManager->GetFigure(Select.x,Select.y)->SetSelected(true);
		this->pManager->UpdateInterface();
}



SelectAction::~SelectAction(void)
{	
	delete this;
}
