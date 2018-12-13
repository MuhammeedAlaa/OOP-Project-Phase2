#pragma once
#include "CFigure.h"
class CLine : public CFigure
{
private:
	Point start;	
	Point end;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo, int id);
	float GetSlope();
	float GetTHEC();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	void PrintInfo(Output* pOut);

};