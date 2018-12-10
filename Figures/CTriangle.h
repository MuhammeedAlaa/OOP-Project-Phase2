#pragma once
#include "CFigure.h"
class CTriangle :
	public CFigure
{
public:
private:
	Point vertix1;	
	Point vertix2;
	Point vertix3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	Point GetV1();
	Point GetV2();
	Point GetV3();
	
	virtual void Draw(Output* pOut) const;
	float area(int , int , int , int , int , int ) ;
	virtual bool IsInside(int ,int);
};


