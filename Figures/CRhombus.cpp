#include "CRhombus.h"


CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo)
{
	ID = id;
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

double CRhombus::area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool CRhombus::IsInside(int x, int y)
{
	float A=area(center.x-100,center.y,center.x,center.y+50,center.x+100,center.y)*2;
			float A1=area(x,y,center.x,center.y+50,center.x+100,center.y);
			float A2=area(x,y,center.x,center.y+50,center.x-100,center.y);
			float A3=area(x,y,center.x,center.y-50,center.x+100,center.y);
			float A4=area(x,y,center.x,center.y-50,center.x-100,center.y);
			if(A==(A1+A2+A3+A4))
			 return true ;
			return false;
}

int CRhombus::GetFillColor()
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

void CRhombus::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The Rhombus ID is "+to_string(ID)+", Center is at("+to_string(center.x)+", "+to_string(center.y)+"), Height is 100, Width is 200.");
}