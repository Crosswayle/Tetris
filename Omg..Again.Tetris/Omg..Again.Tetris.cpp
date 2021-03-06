// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

#pragma once
#include <Game.h>
#include <Field.h>
#include <Figure.h>
#include <I.h>
#include <S.h>
#include <Z.h>
#include <L.h>
#include <J.h>
#include <Q.h>
#include <T.h>

int main()
{

	system("color 0F");
	srand(time(0));


	system("mode con:cols=34 lines=5");
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 5);
	cout << " W - rotate figure" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
	cout << " A - moove left" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 2);
	cout << " S - moove down" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 8);
	cout << " D - moove right" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 5);
	cout << " > Press any key to start game" << endl;
	_getch();

	system("mode con:cols=18 lines=22");
	Game& Tetris = Game::GetInstance();
	Tetris.TetrisGame();


	//figure.PrintFigure();
	//figure.PrintFigureElements();


	return 0;
}
