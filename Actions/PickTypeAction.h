#pragma once
#include "..\Actions\Action.h"
#include "..\Figures\CFigure.h"

class PickTypeAction:public Action
{
	Point HIDE;

public:
	PickTypeAction(ApplicationManager *);
	void ReadActionParameters();
	void HideFigure(CFigure**, CFigure*, int);
	virtual void Execute();
	~PickTypeAction(void);
};

