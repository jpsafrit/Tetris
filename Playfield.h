#pragma once
//#include "Game.h"
#include "pch.h"


class Playfield
{
public:
	Playfield();
	~Playfield();
	static void Update(sf::RenderWindow &window);
	static int square_state[FIELD_WIDTH][FIELD_HEIGHT];
	static sf::Sprite squaresprite[FIELD_WIDTH][FIELD_HEIGHT];
	
private:
	static int w;
	static int h;
	static int i;
	
	static sf::Texture tetratom;
	//static int square_state[FIELD_WIDTH][FIELD_HEIGHT]; //0 for empty, 1 for 
	//an old block is there, 2 for is an active piece's block there
	//can add colors later as higher numbers

	
};
