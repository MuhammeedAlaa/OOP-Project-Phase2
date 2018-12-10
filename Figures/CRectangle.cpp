#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


Point CRectangle::GetC1()
{
	return Corner1;
}
Point CRectangle::GetC2()
{
	return Corner2;
}


bool CRectangle::IsInside(int x,int y)
{
	if((Corner1.x>x&&Corner2.x<x||Corner1.x<x&&Corner2.x>x)&&(Corner1.y>y&&Corner2.y<y||Corner1.y<y&&Corner2.y>y))
		{
			return true;
		}
		return false;
}









