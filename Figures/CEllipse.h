#pragma once
#include "CFigure.h"
class CElipse:public CFigure
{
private:
	Point focus;
public:
	CElipse(Point ,GfxInfo FigureGfxInfo);

	Point GetFocus();
	virtual void Draw(Output* pOut) const;
};