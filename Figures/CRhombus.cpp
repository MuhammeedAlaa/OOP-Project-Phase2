#include "CRhombus.h"


CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P1;
	
}
Point CRhombus::GetCenter()
{
	return center;
}




void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a line on the screen	
	pOut->DrawRhombus(center, FigGfxInfo, Selected);
}
