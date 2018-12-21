#pragma once
#include "Actions/Action.h"
class savebytype :
	public Action
{
public:
	savebytype(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
	~savebytype();
};

