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
	if(!Pointcheck(Delete))
		Delete.y = Delete.x = 0;
}
void DeleteAction:: Execute() 
{
	Output*pOut	=pManager->GetOutput();
	ReadActionParameters();

	if(!Delete.y)
	{
		pOut->PrintMessage("Deleting has terminated, Choose another icon from the tool bar");
		return;
	}

	CFigure* DelFigure = pManager->GetFigure(Delete.x, Delete.y);
	pManager->DeleteFigure(DelFigure);
	{
		pOut->PrintMessage("A figure was deleted successfully, Choose another icon from the tool bar");
	}
	
}


DeleteAction::~DeleteAction(void)
{
}

