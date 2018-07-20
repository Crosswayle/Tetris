#include "stdafx.h"
#include "Figure.h"
using namespace std;

class T : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	T();

	void figureElementsInit(int figurePosition = 0);

	void clearFigureElements();

	vector<COORD>& GetFigureElements();
}; 