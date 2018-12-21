#pragma once
#include "CFigure.h"
#include <fstream>
class CLine : public CFigure
{
private:
	Point start;	
	Point end;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo, int id);
	double GetSlope();
	double GetTHEC();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	void PrintInfo(Output* pOut);
	virtual void save(ofstream&);


};