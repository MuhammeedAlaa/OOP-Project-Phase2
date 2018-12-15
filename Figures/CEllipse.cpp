#include "CEllipse.h"


CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	Center = P1;
	ID = id;
	
}
Point CEllipse::GetCenter()
{
	return Center;
}


	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::Drawelipse to draw a line on the screen	
	pOut->DrawElipse(Center, FigGfxInfo, Selected);
}

bool CEllipse::IsInside(int x ,int y)
{
	double H=(1.0*(x-Center.x)*(x-Center.x))/(10000)+(1.0*(y-Center.y)*(y-Center.y))/(50*50);
			if(H<=1)
				return true;
			return false ;
}

int CEllipse::GetFillColor()
{
	if(FigGfxInfo.isFilled == false)
		return 15;
	if(FigGfxInfo.FillClr == BLACK)
		return CBLACK;
	if(FigGfxInfo.FillClr == RED)
		return CRED;
	if(FigGfxInfo.FillClr == GREEN)
		return CGREEN;
	if(FigGfxInfo.FillClr == WHITE)
		return CWHITE;
	return CBLUE;

}


void CEllipse::PrintInfo(Output* pOut)
{
	// need to put the figure id
	pOut->PrintMessage("The Ellipse ID is "+to_string(ID)+", Center is at("+to_string(Center.x)+", "+to_string(Center.y)+"), Height is 100, Width is 200.");
}

