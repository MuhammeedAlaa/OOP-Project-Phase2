#include "CEllipse.h"


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	focus = P1;
	
}
Point CElipse::GetFocus()
{
	return focus;
}


	

void CElipse::Draw(Output* pOut) const
{
	//Call Output::Drawelipse to draw a line on the screen	
	pOut->DrawElipse(focus, FigGfxInfo, Selected);
}