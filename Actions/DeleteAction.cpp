#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}

void DeleteAction:: ReadActionParameters()
{	
	Output*pOut	=pManager->GetOutput();	
	pOut->PrintMessage("Click on the figure you want to delete.");
	Input*Input=pManager->GetInput();
	Input->GetPointClicked(Delete.x, Delete.y); 
}
void DeleteAction:: Execute() 
{
	ReadActionParameters();
	CFigure* DelFigure = pManager->GetFigure(Delete.x, Delete.y);
	pManager->DeleteFigure(DelFigure);
}


DeleteAction::~DeleteAction(void)
{
}

