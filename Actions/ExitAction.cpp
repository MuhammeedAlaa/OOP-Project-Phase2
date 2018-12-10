#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{
}

void ExitAction:: ReadActionParameters()
{
	Output*pOut	=pManager->GetOutput();	
	pOut->PrintMessage("Exit From Paint For Kides Hope You Enjoyed With Us  ");
	Input*Input=pManager->GetInput();
	Input->GetPointClicked(Exit.x,Exit.y);
}
void ExitAction:: Execute() 
{
	ReadActionParameters();

}


ExitAction::~ExitAction(void)
{
}

