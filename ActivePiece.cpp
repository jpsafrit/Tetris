#pragma once
#include "Game.h"
#include "pch.h"
#include "ActivePiece.h"
#include "Playfield.h"

ActivePiece::ActivePiece()
{
	type = pieceType::J;
	centerLoc.x = 5;
	centerLoc.y = 0;
	switch ((rand() % 7) + 1) //random number 1-7
	{
		case 1:
		{
			type = pieceType::I;
			break;
		}
		case 2:
		{
			type = pieceType::L;
			break;
		}
		case 3:
		{
			type = pieceType::J;
			break;
		}
		case 4:
		{
			type = pieceType::Z;
			break;
		}
		case 5:
		{	
			type = pieceType::S;
			break;
		}
		case 6:
		{
			type = pieceType::T;
			break;
		}
		case 7:
		{
			type = pieceType::O;
			break;
		}
	}

	//type = pieceType::J; //debug piecetype jumper
	
	switch(type)
	{
		case pieceType::O: 
		{
			mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
			mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y - 1;
			mino_loc_array[2].x = centerLoc.x - 1; mino_loc_array[2].y = centerLoc.y;
			mino_loc_array[3].x = centerLoc.x;     mino_loc_array[3].y = centerLoc.y;
			break;
		}
		case pieceType::I:
		{
			mino_loc_array[0].x = centerLoc.x - 2;     mino_loc_array[0].y = centerLoc.y;
			mino_loc_array[1].x = centerLoc.x - 1;     mino_loc_array[1].y = centerLoc.y;
			mino_loc_array[2].x = centerLoc.x;         mino_loc_array[2].y = centerLoc.y;
			mino_loc_array[3].x = centerLoc.x + 1;     mino_loc_array[3].y = centerLoc.y;
			break;
		}
		case pieceType::J:
		{
			mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
			mino_loc_array[1].x = centerLoc.x - 1; mino_loc_array[1].y = centerLoc.y;
			mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y;
			mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y;
			break;
		}
		case pieceType::L:
		{
			mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y;
			mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
			mino_loc_array[2].x = centerLoc.x + 1;	   mino_loc_array[2].y = centerLoc.y;
			mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y-1;
			break;
		}
		case pieceType::S:
		{
			mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y;
			mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
			mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y - 1;
			mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y - 1;
			break;
		}
		case pieceType::Z:
		{
			mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
			mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y - 1;
			mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y;
			mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y;
			break;
		}
		case pieceType::T:
		{
			mino_loc_array[0].x = (centerLoc.x - 1); mino_loc_array[0].y = (centerLoc.y);
			mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
			mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y =(centerLoc.y - 1);
			mino_loc_array[3].x = (centerLoc.x + 1); mino_loc_array[3].y = centerLoc.y;
			break;
		}
	}


}

ActivePiece::~ActivePiece()
{
	std::cout << "ActivePiece Destructor called";
}

void ActivePiece::Respawn()
{
	centerLoc.x = 5;
	centerLoc.y = 0;
	rotState = 0;
	switch ((rand() % 7) + 1) //random number 1-7
	//switch(7)
	{
	case 1:
	{
		type = pieceType::I;
		break;
	}
	case 2:
	{
		type = pieceType::L;
		break;
	}
	case 3:
	{
		type = pieceType::J;
		break;
	}
	case 4:
	{
		type = pieceType::Z;
		break;
	}
	case 5:
	{
		type = pieceType::S;
		break;
	}
	case 6:
	{
		type = pieceType::T;
		break;
	}
	case 7:
	{
		type = pieceType::O;
		break;
	}
	}

	//ActivePiece::type = pieceType;
	//switch(pieceType)
	switch (type)
	{
	case pieceType::O:
	{
		mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
		mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y - 1;
		mino_loc_array[2].x = centerLoc.x - 1; mino_loc_array[2].y = centerLoc.y;
		mino_loc_array[3].x = centerLoc.x;     mino_loc_array[3].y = centerLoc.y;
		break;
	}
	case pieceType::I:
	{
		mino_loc_array[0].x = centerLoc.x - 2;     mino_loc_array[0].y = centerLoc.y;
		mino_loc_array[1].x = centerLoc.x - 1;     mino_loc_array[1].y = centerLoc.y;
		mino_loc_array[2].x = centerLoc.x;         mino_loc_array[2].y = centerLoc.y;
		mino_loc_array[3].x = centerLoc.x + 1;     mino_loc_array[3].y = centerLoc.y;
		break;
	}
	case pieceType::J:
	{
		mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
		mino_loc_array[1].x = centerLoc.x - 1; mino_loc_array[1].y = centerLoc.y;
		mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y;
		mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y;
		break;
	}
	case pieceType::L:
	{
		mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y;
		mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
		mino_loc_array[2].x = centerLoc.x + 1;	   mino_loc_array[2].y = centerLoc.y;
		mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y - 1;
		break;
	}
	case pieceType::S:
	{
		mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y;
		mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
		mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y - 1;
		mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y - 1;
		break;
	}
	case pieceType::Z:
	{
		mino_loc_array[0].x = centerLoc.x - 1; mino_loc_array[0].y = centerLoc.y - 1;
		mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y - 1;
		mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = centerLoc.y;
		mino_loc_array[3].x = centerLoc.x + 1; mino_loc_array[3].y = centerLoc.y;
		break;
	}
	case pieceType::T:
	{
		mino_loc_array[0].x = (centerLoc.x - 1); mino_loc_array[0].y = (centerLoc.y);
		mino_loc_array[1].x = centerLoc.x;     mino_loc_array[1].y = centerLoc.y;
		mino_loc_array[2].x = centerLoc.x;	   mino_loc_array[2].y = (centerLoc.y - 1);
		mino_loc_array[3].x = (centerLoc.x + 1); mino_loc_array[3].y = centerLoc.y;
		break;
	}
	}


}

int ActivePiece::Rotate()
{

	if (rotState == 3) { rotState = 0; }
	else { rotState++; }
	if (type == pieceType::O)
	{
		return 1; //done, report that rotation worked
	}

	//sub function that takes in centerLoc and a set of 4 (dx,dy) points and does the appropriate things to make mino_loc_array right? 
	//then, list here each case for each pieceType
	switch (type)
	{
		case pieceType::O:
		{
			return 1;
		}
		case pieceType::I:
		{
			switch (rotState)
			{
			case 0: { RotateMath(-2, 0, -1, 0, 0, 0, 1, 0); break; }
			case 1: { RotateMath(0, -2, 0, -1, 0, 0, 0, 1); break; }
			case 2: { RotateMath(-2, 0, -1, 0, 0, 0, 1, 0); break; }
			case 3: { RotateMath(0, -2, 0, -1, 0, 0, 0, 1); break; }
			}
			return 1;
		}
		case pieceType::J:
		{
			switch (rotState)
			{
				case 0: { RotateMath(-1, -1, -1, 0, 0, 0, 1, 0); break; }
				case 1: { RotateMath(1, -1, 0, -1, 0, 0, 0, 1); break; }
				case 2: { RotateMath(1,1,1,0,0,0,-1,0); break; }
				case 3: { RotateMath(-1,1,0,1,0,0,0,-1); break; }
			}
			return 1;
		}
		case pieceType::L:
		{
			switch (rotState)
			{
			case 0: { RotateMath(-1, 0, 0, 0, 1, 0, 1, -1); break; }
			case 1: { RotateMath(0, -1, 0, 0, 0, 1, 1, 1); break; }
			case 2: { RotateMath(1, 0, 0, 0, -1, 0, -1, 1); break; }
			case 3: { RotateMath(0, 1, 0, 0, 0, -1, -1, -1); break; }
			}
			return 1;
		}
		case pieceType::S:
		{
			switch (rotState)
			{
			case 0: { RotateMath(-1,0,0,0,0,-1,1,-1); break; }
			case 1: { RotateMath(0,-1,0,0,1,0,1,1); break; }
			case 2: { RotateMath(1,0,0,0,0,1,-1,1); break; }
			case 3: { RotateMath(0,1,0,0,-1,0,-1,-1); break; }
			}
			return 1;
		}
		case pieceType::T:
		{
			switch (rotState)
			{
			case 0: { RotateMath(-1,0,0,0,0,-1,1,0); break; }
			case 1: { RotateMath(0,-1,0,0,0,1,1,0); break; }
			case 2: { RotateMath(-1,0,0,0,1,0,0,1); break; }
			case 3: { RotateMath(-1,0,0,0,0,-1,0,1); break; }
			}
			return 1;
		}
		case pieceType::Z:
		{
			switch (rotState)
			{
			case 0: { RotateMath(-1,-1,0,-1,0,0,1,0); break; }
			case 1: { RotateMath(1,-1,0,0,1,0,0,1); break; }
			case 2: { RotateMath(-1,0,0,0,0,1,1,1); break; }
			case 3: { RotateMath(-1,1,-1,0,0,0,0,-1); break; }
			}
			return 1;
		}
	}
	return 0;	
		
};

void ActivePiece::RotateMath(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	mino_loc_array[0].x = centerLoc.x + x1; mino_loc_array[0].y = centerLoc.y + y1;
	mino_loc_array[1].x = centerLoc.x + x2; mino_loc_array[1].y = centerLoc.y + y2;
	mino_loc_array[2].x = centerLoc.x + x3; mino_loc_array[2].y = centerLoc.y + y3;
	mino_loc_array[3].x = centerLoc.x + x4; mino_loc_array[3].y = centerLoc.y + y4;
};

void ActivePiece::Move(int dir)
{

	switch (dir)
	{
	case 1: //right
	{
		for (z = 0; z <= 3; z++)
		{
			if (mino_loc_array[z].x == FIELD_WIDTH - 1)
			{
				return;
			}
			if ( (Playfield::square_state[mino_loc_array[z].x - 1][mino_loc_array[z].y] == 1) || (Playfield::square_state[mino_loc_array[z].x + 1][mino_loc_array[z].y] == 1))
			{
				return;
			}
		}
		for (z = 0; z <= 3; z++)
		{
			ActivePiece::mino_loc_array[z].x++;
		}
		ActivePiece::centerLoc.x++;;
		break;
	}
	case 2: //left
	{
		for (z = 0; z <= 3; z++)
		{
			if (mino_loc_array[z].x == 0)
			{
				return;
			}
			if ((Playfield::square_state[mino_loc_array[z].x - 1][mino_loc_array[z].y] == 1) || (Playfield::square_state[mino_loc_array[z].x + 1][mino_loc_array[z].y] == 1))
			{
				return;
			}
		}
		for (z = 0; z <= 3; z++)
		{
			ActivePiece::mino_loc_array[z].x--;
		}
		ActivePiece::centerLoc.x--;
		break;
	}
	case 3: //soft drop or move down because game tick 
	{
		//if (mino_loc_array[z].y == FIELD_HEIGHT - 1) return;
		
		for (z = 0; z <= 3; z++)
		{
			ActivePiece::mino_loc_array[z].y++;
		}
		ActivePiece::centerLoc.y++;
		break;
	}
	}
}


sf::Vector2i ActivePiece::mino_loc(int index)
{
	return ActivePiece::mino_loc_array[index];
};

bool ActivePiece::isBottomedOut()
{
	for (int z = 0; z <= 3; z++)
	{
		if (Playfield::square_state[ActivePiece::mino_loc(z).x][ActivePiece::mino_loc(z).y + 1] == 1)
		{
			return true;
		}
		if (ActivePiece::mino_loc(z).y == FIELD_HEIGHT - 1)
		{
			return true;
		}
	}
	return false;
}
ActivePiece::pieceType ActivePiece::type = ActivePiece::pieceType::J;
sf::Vector2i ActivePiece::mino_loc_array[4];
sf::Vector2i ActivePiece::centerLoc;
int ActivePiece::z;
int ActivePiece::rotState = 0;