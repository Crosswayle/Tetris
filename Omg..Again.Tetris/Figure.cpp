#include "stdafx.h"

using namespace std;

int& Figure::GetStepsCount()
{
	return stepsCount;
}

COORD& Figure::GetCurrentCoords()
{
	return currentCoords;
}

int& Figure::GetSide()
{
	return side;
}