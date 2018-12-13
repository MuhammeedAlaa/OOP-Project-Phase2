#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo, int id );
	Point GetC1();
	Point GetC2();
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int ,int);
	void PrintInfo(Output* pOut);



};



#endif