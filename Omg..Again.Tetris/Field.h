#include "stdafx.h"


using namespace std;

class Field
{
private:
	array<array<bool, FieldWidth>, FieldHeight> field = { 0 };

public:
	void printField(int score);

	void SetFigureIn(vector<COORD> figureElements, COORD currentMatrixCoords);

	void deleteRow(int pos);

	void IsSomeRowFilled();

	void clearFigure(vector<COORD> figureElements, COORD currentMatrixCoords);

	void figureMoove(Figure *a, char side, bool& IsFallen, int& StepsCount, bool& IsGameOver);

	auto GetField();
};