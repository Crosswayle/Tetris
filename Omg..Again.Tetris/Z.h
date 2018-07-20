#include "stdafx.h"
#include "Figure.h"
using namespace std;

class Z : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	Z();

	void figureElementsInit(int figurePosition = 0);

	void clearFigureElements();

	vector<COORD>& GetFigureElements();
}; 