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

bool CElipse::IsInside(int x ,int y)
{
	float H=(1.0*(x-focus.x)*(x-focus.x))/(10000)+(1.0*(y-focus.y)*(y-focus.y))/(50*50);
			if(H<=1)
				return true;
			return false ;
}
