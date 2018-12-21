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
void CLine::save(ofstream& file) {
	string Fillcolour;
	string Drawcolour;
	if (FigGfxInfo.isFilled == false)
		Fillcolour = "15";
	if (FigGfxInfo.FillClr == BLACK)
		Fillcolour = "CBLACK";
	if (FigGfxInfo.FillClr == RED)
		Fillcolour = "CRED";
	if (FigGfxInfo.FillClr == GREEN)
		Fillcolour = "CGREEN";
	if (FigGfxInfo.FillClr == WHITE)
		Fillcolour = "CWHITE";
	if (FigGfxInfo.FillClr == BLUE)
		Fillcolour = "CBLUE";
	if (FigGfxInfo.FillClr == MAGENTA)
		Fillcolour = "CMAGENTA";
	if (FigGfxInfo.DrawClr == BLACK)
		Drawcolour = "CBLACK";
	if (FigGfxInfo.DrawClr == RED)
		Drawcolour = "CRED";
	if (FigGfxInfo.DrawClr == GREEN)
		Drawcolour = "CGREEN";
	if (FigGfxInfo.DrawClr == WHITE)
		Drawcolour = "CWHITE";
	if (FigGfxInfo.DrawClr == BLUE)
		Drawcolour = "CBLUE";
	file << "LINE " << ID << " " << start.x << " " << start.y << " " << end.x << " " << end.y <<" " << Drawcolour << " " << Fillcolour << endl;
}