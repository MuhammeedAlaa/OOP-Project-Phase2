#include "CTriangle.h"


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	vertix1 = P1;
	vertix2 = P2;
	vertix3 = P3;
	
}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTRI to draw a triangle on the screen	
	pOut->DrawTri(vertix1, vertix2, vertix3, FigGfxInfo, Selected);
}

Point CTriangle::GetV1()
{
	return vertix1;
}




Point CTriangle::GetV2()
{
	return vertix2;
}
Point CTriangle::GetV3()
{
	return vertix3;
}




