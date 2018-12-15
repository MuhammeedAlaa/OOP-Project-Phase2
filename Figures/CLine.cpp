#include "Cline.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
	ID = id;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::Drawline to draw a line on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}


double CLine::GetSlope()
{
	double slope=(1.0*start.y-end.y)/(1.0*start.x-end.x);
	return slope;
}
double CLine ::GetTHEC()
{
	return start.y-start.x*1.0*GetSlope();
}

bool CLine::IsInside(int x, int y)
{
	int yline = x*GetSlope()+GetTHEC();
	if(((y<=floor(yline)&& y >= floor(yline) - 7) || (y>=ceil(yline) && y <= ceil(yline) + 7)))
		return true;
		return false;
}

int CLine::GetFillColor()
{
		return 15;
}

void CLine::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Line ID is "+to_string(ID)+", Start point is at("+to_string(start.x)+", "+to_string(start.y)+"), End point is at("+to_string(end.x)+", "+to_string(end.y)+").");
}
