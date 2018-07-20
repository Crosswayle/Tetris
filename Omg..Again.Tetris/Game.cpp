#include "stdafx.h"

using namespace std;

Game::Game(){}
Game::~Game(){}
Game::Game(const Game&){}
Game Game::operator=(const Game&){}

Figure* Game::randFigure()
{
	int random = rand() % 7 + 1;
	if (random == 1)
	{
		return new I();
	}
	else if (random == 2)
	{
		return new L();
	}
	else if (random == 3)
	{
		return new J();
	}
	else if (random == 4)
	{
		return new S();
	}
	else if (random == 5)
	{
		return new Z();
	}
	else if (random == 6)
	{
		return new Q();
	}
	else if (random == 7)
	{
		return new T();
	}
}

void Game::SetScore(int k = 1)
{
	score += k;
}

static Game& GetInstance()
{
	static Game Tetris;
	return Tetris;
}

int Game::GetScore()
{
	return score;
}

void Game::GameOverPrint()
{
	system("mode con:cols=60 lines=10");
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 0);
	cout << "  _____   ___  ___  ___ _____   _____  _   _ ___________" << endl;
	cout << " |  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\" << endl;
	cout << " | |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /" << endl;
	cout << " | |_\\ \\| | | || |\\/| || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ " << endl;
	cout << "  \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 4);
	cout << "                    YOUR SCORE: ";
	Sleep(5000);
	cout << GetScore() << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 7);
	cout << endl << endl;
}

int& Game::GetFigureMoovingSpeed()
{
	return FigureMoovingSpeed;
}

void Game::MoovingSpeedEditing()
{
	if (GetScore() % 15 == 0 && FigureMoovingSpeed>5)
	{
		FigureMoovingSpeed--;
	}
}

void Game::TetrisGame()
{
	bool IsFallen = false;
	bool IsStart = true;
	bool IsGameOver = false;
	Field glass;
	Figure *figure = randFigure();
	char side;
	int CycleRoundsCounter = 0;
	while (IsGameOver == false)
	{
		if (IsFallen == true || IsStart == true)
		{
			SetScore();
			IsStart = false;
			IsFallen = false;
			figure = randFigure();
			figure->figureElementsInit();
			figure->GetCurrentCoords().X = rand() % 11;
			figure->GetCurrentCoords().Y = 0;
			figure->GetStepsCount() = 0;
		}


		glass.SetFigureIn(figure->GetFigureElements(), figure->GetCurrentCoords());

		glass.printField(GetScore());

		Sleep(30);
		if (_kbhit() == true)
		{
			side = _getch();
			glass.figureMoove(figure, side, IsFallen, figure->GetStepsCount(), IsGameOver);
		}


		if (CycleRoundsCounter%GetFigureMoovingSpeed() == 0)
		{
			glass.figureMoove(figure, DOWN, IsFallen, figure->GetStepsCount(), IsGameOver);
		}
		if (IsFallen == true)
		{
			glass.IsSomeRowFilled();
		}
		CycleRoundsCounter++;
		MoovingSpeedEditing();
		system("cls");
	}

	GameOverPrint();
}