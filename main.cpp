#include "ApplicationManager.h"


int main()
{


	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
		int X=0;
	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);
		

		//Update the interface
		if(ActType!=TO_PLAY)
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);
	

	
	return 0;
}

