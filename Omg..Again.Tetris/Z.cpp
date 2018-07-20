#include "stdafx.h"

using namespace std;

Z::Z()
{
	//Vertical
	figureMatrix[0][0][2] = 1;
	figureMatrix[0][1][2] = 1;
	figureMatrix[0][1][1] = 1;
	figureMatrix[0][2][1] = 1;

	figureMatrix[2][0][2] = 1;
	figureMatrix[2][1][2] = 1;
	figureMatrix[2][1][1] = 1;
	figureMatrix[2][2][1] = 1;

	//Horisontal
	figureMatrix[1][1][0] = 1;
	figureMatrix[1][1][1] = 1;
	figureMatrix[1][2][1] = 1;
	figureMatrix[1][2][2] = 1;

	figureMatrix[3][1][0] = 1;
	figureMatrix[3][1][1] = 1;
	figureMatrix[3][2][1] = 1;
	figureMatrix[3][2][2] = 1;
}

void Z::figureElementsInit(int figurePosition = 0)
{
	COORD tmp;
	for (int y = 0; y < FigureHeight; y++)
	{
		for (int x = 0; x < FigureWidth; x++)
		{
			if (figureMatrix[figurePosition][y][x] == 1)
			{
				tmp.X = x;
				tmp.Y = y;
				figureElement.push_back(tmp);
			}
		}
	}
}

void Z::clearFigureElements()
{
	figureElement.resize(0);
}

vector<COORD>& Z::GetFigureElements()
{
	return figureElement;
}