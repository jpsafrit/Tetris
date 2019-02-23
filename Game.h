#pragma once
#include "pch.h"
#include "Playfield.h"
#include "ActivePiece.h"

class Game 
{
public:
	static void Start();
	static bool IsExiting();
	
	enum pieceType {none, I, L, J, Z, S, T, O};

	static sf::Font font;
	static sf::Text scoreboard;
	static sf::RenderWindow window;
	static Game::pieceType randomPiece();
	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, LastMove, Clearing, Exiting, GameOver	
	};
	static GameState _gameState;
	static void GameLoop(ActivePiece &_activePiece, sf::Clock &clock, Playfield &playfield, sf::Event currentEvent);
	
	static int j;
	static int k;
	static int capL;
	static int rowsCleared;
	static int score;
	static bool clearedARow;
	static bool timerExp;
};
