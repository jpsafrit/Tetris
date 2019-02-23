#pragma once
#include "pch.h"
#include "Game.h"
#include "Playfield.h"
#include "ActivePiece.h"

Playfield::Playfield() 
{
	tetratom.loadFromFile("tetratom.png");
	//int h, w;
	for (h = 0; h < FIELD_HEIGHT; h++) //for each row
	{
		for (w = 0; w < FIELD_WIDTH; w++)
		{
			square_state[w][h] = 0;
			squaresprite[w][h].setTexture(tetratom);
			squaresprite[w][h].setPosition(w * 25, h * 25);
		}
	}
		
}

Playfield::~Playfield()
{
	std::cout << "Playfield destructor called\n";
}


void Playfield::Update(sf::RenderWindow &window)
{
	window.clear(sf::Color(0, 0, 0, 255));
	window.draw(Game::scoreboard);

	if (Game::_gameState == Game::GameState::Playing)
	{
		if (ActivePiece::isBottomedOut())
		{
			//if (Game::_gameState == Game::GameState::LastMove)
				Game::_gameState = Game::GameState::Clearing;	
				for (i = 0; i <= 3; i++) //previously cementActiveBlock()
				{
					if (Playfield::square_state[ActivePiece::mino_loc(i).x][ActivePiece::mino_loc(i).y] == 1)
					{
						Game::_gameState = Game::GameState::GameOver;
						//i = 4; //break out of for loop
					} 
					Playfield::square_state[ActivePiece::mino_loc(i).x][ActivePiece::mino_loc(i).y] = 1;
					window.draw(Playfield::squaresprite[ActivePiece::mino_loc(i).x][ActivePiece::mino_loc(i).y]);
				}
				
		}
		else
		{
			for (h = 0; h < FIELD_HEIGHT; h++) //for each row
			{
				for (w = 0; w < FIELD_WIDTH; w++)
				{
					for (i = 0; i <= 3; i++)
					{
						if ((ActivePiece::mino_loc(i).x == w && ActivePiece::mino_loc(i).y == h))
						{
							//Playfield::square_state[w][h] = 1; //if the block has an active piece there, light it up
							window.draw(squaresprite[w][h]);
						}
						if (square_state[w][h] == 1)
						{
							window.draw(squaresprite[w][h]);
						}
					}
				}
			}
			
		}
	}
	if (Game::_gameState == Game::GameState::Clearing)
	{
		for (h = 0; h < FIELD_HEIGHT; h++) 
		{
			for (w = 0; w < FIELD_WIDTH; w++)
			{
				if (square_state[w][h] == 1)
				{
					window.draw(squaresprite[w][h]);
				}

			}
		}
		window.display();
	}

}

 int Playfield::w;
 int Playfield::h;
 int Playfield::i;
 sf::Sprite Playfield::squaresprite[FIELD_WIDTH][FIELD_HEIGHT];
 sf::Texture Playfield::tetratom;
 int Playfield::square_state[FIELD_WIDTH][FIELD_HEIGHT];
 