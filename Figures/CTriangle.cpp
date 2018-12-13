#include "CTriangle.h"


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	ID = id;
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

float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool CTriangle:: IsInside(int x,int y)
{
	float A=area(vertix1.x,vertix1.y,vertix2.x,vertix2.y,vertix3.x,vertix3.y);
	float A1=area(x,y,vertix2.x,vertix2.y,vertix3.x,vertix3.y);
	float A2=area(vertix1.x,vertix1.y,x,y,vertix3.x,vertix3.y);
	float A3=area(vertix1.x,vertix1.y,vertix2.x,vertix2.y,x,y);
			if(A==(A1+A2+A3))
			{
				return true;
				
			}
			return false;



}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Triangle ID is "+to_string(ID)+", corners are at ("+to_string(vertix1.x)+", "+to_string(vertix1.y)+")  ("+to_string(vertix2.x)+", "+to_string(vertix2.y)+")  ("+to_string(vertix3.x)+", "+to_string(vertix3.y)+").");
}



