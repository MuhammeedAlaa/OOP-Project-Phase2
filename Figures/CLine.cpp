#include "Cline.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::Drawline to draw a line on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}


float CLine::GetSlope()
{
	float slope=(1.0*start.y-end.y)/(1.0*start.x-end.x);
	return slope;
}
float CLine ::GetTHEC()
{
	return start.y-start.x*1.0*GetSlope();
}

