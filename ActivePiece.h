#pragma once
//#include "Game.h"
#include "pch.h"

class ActivePiece
{
	public:
		ActivePiece();
		~ActivePiece();
		
		int Rotate();
		void Move(int dir); //0 right, 1 hard drop, 2 left; 3 soft drop?
		static bool isBottomedOut();
		static sf::Vector2i mino_loc(int index);
		static void Respawn();
		static int z;
		
		enum pieceType { none, I, L, J, Z, S, T, O };
		static pieceType type;
		static sf::Vector2i centerLoc;
		
private:
		int x1; int y1; int x2; int y2; int x3; int y3; int x4; int y4;
		void RotateMath(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
		static int rotState;
		static sf::Vector2i mino_loc_array[4];
		

};