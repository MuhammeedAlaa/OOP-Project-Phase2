#pragma once

#include "Action.h"
class AddEllipseAction:public Action
{
private:
	Point P1; //one of the Elipse's focuses
	GfxInfo EllpsGfxInfo;
public:
	public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads Elipse parameters
	virtual void ReadActionParameters();
	
	//Add Elipse to the ApplicationManager
	virtual void Execute() ;
	
};