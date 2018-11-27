#pragma once

#include "Action.h"
class AddRhombusAction:public Action
{
private:
	Point P1; // Rhombus center
	GfxInfo RectGfxInfo;
public:
	public:
	AddRhombusAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};
