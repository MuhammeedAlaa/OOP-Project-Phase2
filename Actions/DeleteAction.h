#pragma once
#include "..\Actions\Action.h"

class DeleteAction:public Action
{
	Point Delete;
public:
	DeleteAction(ApplicationManager *pApp);	
	virtual void ReadActionParameters();
	virtual void Execute() ;
	~DeleteAction(void);
};
