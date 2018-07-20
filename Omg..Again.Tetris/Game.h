#pragma once
#include "stdafx.h"


using namespace std;

class Game
{
private:
	Game();
	~Game();
	Game(const Game&);
	Game operator=(const Game&);
	//----------------------------------
	int FigureMoovingSpeed = 9;
	Figure* randFigure();

	int score = 0 - 1;

public:
	void SetScore(int k = 1);

	static Game& GetInstance();

	int GetScore();

	void GameOverPrint();

	int& GetFigureMoovingSpeed();

	void MoovingSpeedEditing();

	// Main method, there is playing process
	void TetrisGame(); 
};