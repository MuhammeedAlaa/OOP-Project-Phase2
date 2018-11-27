#pragma once
#include "CFigure.h"
class CLine : public CFigure
{
private:
	Point start;	
	Point end;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	float GetSlope();
	float GetTHEC();

	virtual void Draw(Output* pOut) const;
};