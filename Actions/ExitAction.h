#pragma once
#include "..\Actions\Action.h"

class ExitAction:public Action
{
	Point Exit;
public:
	ExitAction(ApplicationManager *pApp);	
	//Add rectangle to the ApplicationManager
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~ExitAction(void);
};

