#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	
	Corner1 = P1;
	Corner2 = P2;
	ID = id;
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

int CRectangle::GetFillColor()
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

void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Rectangle ID is "+to_string(ID)+",  height is "+to_string(abs(Corner1.y-Corner2.y))+", Width is "+to_string(abs(Corner1.x-Corner2.x))+".");
}







