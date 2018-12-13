#pragma once
#include "CFigure.h"
class CRhombus :public CFigure
{
private:
	Point center;
public:
	CRhombus(Point ,GfxInfo FigureGfxInfo, int id);

	Point GetCenter();
	virtual void Draw(Output* pOut) const;
	float area(int , int , int , int , int , int ) ;
	virtual bool IsInside(int ,int);
	void PrintInfo(Output* pOut);

};


