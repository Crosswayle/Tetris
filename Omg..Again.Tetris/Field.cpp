#include "stdafx.h"

using namespace std;

void Field::printField(int score)
{
	cout << "  SCORE: " << score << endl;
	for (int i = 4; i<FieldHeight; i++)
	{
		cout << "  ";
		for (int k = 0; k < FieldWidth; k++)
		{
			if (field[i][k] == 0)
			{
				SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 0);
				cout << char(177);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 6);
				cout << 'O'; //char(176)
			}

		}
		cout << endl;
	}
}

void Field::SetFigureIn(vector<COORD> figureElements, COORD currentMatrixCoords)
{
	for (auto it_coords : figureElements)
	{
		field[it_coords.Y + currentMatrixCoords.Y][it_coords.X + currentMatrixCoords.X] = true;
	}
}

void Field::deleteRow(int pos)
{
	field[pos] = { 0 };
	for (int y = pos; y > 0; y--)
	{
		field[y] = field[y - 1];
	}
	field[0] = { 0 };
}

void Field::IsSomeRowFilled()
{
	for (int y = 0; y < FieldHeight; y++)
	{
		bool IsFilled = true;
		for (int x = 0; x < FieldWidth; x++)
		{
			if (field[y][x] == false)
			{
				IsFilled = false;
				break;
			}
		}
		if (IsFilled == true)
		{
			deleteRow(y);
		}
	}
}

void Field::clearFigure(vector<COORD> figureElements, COORD currentMatrixCoords)
{
	for (auto it_coords : figureElements)
	{
		field[it_coords.Y + currentMatrixCoords.Y][it_coords.X + currentMatrixCoords.X] = false;
	}
}

void Field::figureMoove(Figure *a, char side, bool& IsFallen, int& StepsCount, bool& IsGameOver)
{
	// It helps me with finding needed elements
	array<array<bool, 4>, 4> tmpFigureMatrix = { 0 };
	for (int i = 0; i < a->GetFigureElements().size(); i++)
	{
		tmpFigureMatrix[a->GetFigureElements()[i].Y][a->GetFigureElements()[i].X] = true;
	}


	if (side == LEFT)
	{
		vector<COORD> leftElements; // needed elements coords vector
		COORD tmp;
		int vectEl_counter = 0;
		// Finding needed elements
		for (int y = FigureHeight - 1; y >= 0; y--)
		{
			bool refresh = false;
			for (int x = FigureWidth - 1; x >= 0; x--)
			{
				if (tmpFigureMatrix[y][x] == true)
				{
					tmp.X = x;
					tmp.Y = y;
					refresh = true;
				}
			}
			if (refresh == true)
			{
				leftElements.push_back(tmp);
				vectEl_counter++;
			}
		} //------------------------

		bool isPossible = true;
		for (int i = 0; i < leftElements.size(); i++)
		{
			COORD abs_coords;
			abs_coords.X = a->GetCurrentCoords().X + leftElements[i].X;
			abs_coords.Y = a->GetCurrentCoords().Y + leftElements[i].Y;
			if (abs_coords.X - 1 < 0 || field[abs_coords.Y][abs_coords.X - 1] == true)
			{
				isPossible = false;
			}
		}
		clearFigure(a->GetFigureElements(), a->GetCurrentCoords());
		if (isPossible == true)
		{
			a->GetCurrentCoords().X -= 1;
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
		else
		{
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
	}

	if (side == RIGHT)
	{
		vector<COORD> rightElements; // needed elements coords vector

		int vectEl_counter = 0;
		COORD tmp;
		// Finding needed elements
		for (int y = 0; y < FigureHeight; y++)
		{
			bool refresh = false;
			for (int x = 0; x < FigureWidth; x++)
			{

				if (tmpFigureMatrix[y][x] == true)
				{
					tmp.X = x;
					tmp.Y = y;
					refresh = true;
				}

			}
			if (refresh == true)
			{
				rightElements.push_back(tmp);
				vectEl_counter++;
			}
		} //------------------------

		bool isPossible = true;
		for (int i = 0; i < rightElements.size(); i++)
		{
			COORD abs_coords;
			abs_coords.X = a->GetCurrentCoords().X + rightElements[i].X;
			abs_coords.Y = a->GetCurrentCoords().Y + rightElements[i].Y;
			if (abs_coords.X + 1 >= FieldWidth || field[abs_coords.Y][abs_coords.X + 1] == true)
			{
				isPossible = false;
			}
		}
		clearFigure(a->GetFigureElements(), a->GetCurrentCoords());

		if (isPossible == true)
		{
			a->GetCurrentCoords().X += 1;
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
		else
		{
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
	}

	if (side == DOWN)
	{
		vector<COORD> bottomElements; // needed elements coords vector
		COORD tmp;
		int vectEl_counter = 0;
		// Finding needed elements
		for (int x = 0; x < FigureWidth; x++)
		{
			bool refresh = false;
			for (int y = 0; y <FigureHeight; y++)
			{

				if (tmpFigureMatrix[y][x] == true)
				{
					tmp.X = x;
					tmp.Y = y;
					refresh = true;
				}
			}
			if (refresh == true)
			{
				bottomElements.push_back(tmp);
				vectEl_counter++;
			}
		} //------------------------

		bool isPossible = true;

		for (int i = 0; i < bottomElements.size(); i++)
		{
			COORD abs_coords;
			abs_coords.X = a->GetCurrentCoords().X + bottomElements[i].X;
			abs_coords.Y = a->GetCurrentCoords().Y + bottomElements[i].Y;
			if (abs_coords.Y + 1 >= FieldHeight || field[abs_coords.Y + 1][abs_coords.X] == true)
			{
				isPossible = false;
				break;
			}
		}

		clearFigure(a->GetFigureElements(), a->GetCurrentCoords());

		if (isPossible == true)
		{
			StepsCount++;
			a->GetCurrentCoords().Y += 1;
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}

		else
		{
			if (StepsCount == 0)
			{
				IsGameOver = true;
			}
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			IsFallen = true;
		}
	}

	if (side == ROTATE)
	{
		//Nbyly cm u jlivfyg qcnb 716 - 720 liqm (linuncha zcaoly)
		clearFigure(a->GetFigureElements(), a->GetCurrentCoords());
		a->clearFigureElements();
		int OriginalSide = a->GetSide();
		if (a->GetSide() == 3)
		{
			OriginalSide = 0;
			a->GetSide() = -1;
		}

		a->figureElementsInit(a->GetSide() + 1);

		bool IsPossible = true;
		for (int i = 0; i < 4; i++)
		{
			COORD abs_coord;
			abs_coord.X = a->GetCurrentCoords().X + a->GetFigureElements()[i].X;
			abs_coord.Y = a->GetCurrentCoords().Y + a->GetFigureElements()[i].Y;
			if (abs_coord.X >= FieldWidth || abs_coord.X <= 0 || abs_coord.Y >= FieldHeight)
			{
				IsPossible = false;
			}

			else if (field[abs_coord.Y][abs_coord.X] == true)
			{
				IsPossible = false;

			}
		}

		if (IsPossible == true)
		{
			a->clearFigureElements();
			a->figureElementsInit(a->GetSide() += 1);
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
		else
		{
			a->clearFigureElements();
			a->figureElementsInit(OriginalSide);
			SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
		}
	}
}

auto Field::GetField()
{
	return field;
}
