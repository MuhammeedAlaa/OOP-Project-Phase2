#pragma once
#include "CFigure.h"
class CEllipse:public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point ,GfxInfo FigureGfxInfo, int id);

	Point GetCenter();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	virtual int GetFillColor();
	void PrintInfo(Output* pOut);
};