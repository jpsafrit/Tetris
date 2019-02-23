#include "pch.h"
#include "Game.h"
#include "Playfield.h"
#include "ActivePiece.h"

void Game::Start()
{
	srand(time(NULL));
	Game::window.create(sf::VideoMode(FIELD_WIDTH * 25, FIELD_HEIGHT * 25), "Tetris!");

	sf::Clock clock = sf::Clock::Clock();
	clock.restart();

	sf::Texture background;
	background.loadFromFile("background.png");

	sf::Texture gameOverScreen;
	gameOverScreen.loadFromFile("gameOver.png");

	sf::Sprite sprite(background);
	sf::Sprite GOS(gameOverScreen);

	if (Game::font.loadFromFile("arial.ttf"))	std::cout << "Error loading font";

	Game::scoreboard = sf::Text(std::to_string(score),font); 
	scoreboard.setPosition(20, 20);
	scoreboard.setCharacterSize(20);
	scoreboard.setOutlineColor(sf::Color::White);
	scoreboard.setFillColor(sf::Color::White);


	sf::Event currentEvent;
	window.pollEvent(currentEvent);

	srand(time(NULL));
	window.clear();
	

	window.draw(sprite);

	window.display();
	
	ActivePiece _activePiece = ActivePiece::ActivePiece();
	Playfield playfield = Playfield();
	_gameState = Playing;
	playfield.Update(window);

	window.draw(scoreboard);
	window.display();
	
	while (!IsExiting())
	{
		GameLoop(_activePiece, clock, playfield, currentEvent);
		//display game over screen if state == gameover
	}
	if (_gameState == Game::GameOver)
	{
		window.draw(GOS);
		window.display();
		sf::Event currentEvent;
		bool endGame = false;
		while (endGame == false) {
			while (window.pollEvent(currentEvent))
			{
				if (currentEvent.type == sf::Event::EventType::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Key::Escape)
					{
						endGame = true;
					}
				}
				//break;
			}
		}
	}
}

void Game::GameLoop(ActivePiece &_activePiece, sf::Clock &clock, Playfield &playfield, sf::Event currentEvent)
{
		

	switch (_gameState)
	{
		case Game::GameOver:
		{
			
		}
		case Game::Playing:
		{
			timerExp = false;
			if (clock.getElapsedTime().asMilliseconds() >= 1000)
			{
				std::cout << clock.restart().asMilliseconds() << "\n";

				_activePiece.Move(3);
				playfield.Update(window);

				window.display();
				timerExp = true;
			}
			while (window.pollEvent(currentEvent) && (timerExp == false))
			{
				
				if (currentEvent.type == sf::Event::EventType::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Key::Left) {
						_activePiece.Move(2);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Right) {
						_activePiece.Move(1);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Down) {
						_activePiece.Move(3);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Up) {
						_activePiece.Rotate();
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Escape)
					{
						_gameState = Exiting;
					}
					
				}
			}
			break;
		}
		case Game::Clearing:
		{	
			
			timerExp = false;
			if (clock.getElapsedTime().asMilliseconds() >= 1000)
			{
				clock.restart();
				//std::cout << clock.restart().asMilliseconds();
				_activePiece.Move(3);
				playfield.Update(window);
				window.display();
				timerExp = true;
			}
			while (window.pollEvent(currentEvent) && (timerExp == false))
			{
				if (currentEvent.type == sf::Event::EventType::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Key::Left) {
						_activePiece.Move(2);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Right) {
						_activePiece.Move(1);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Down) {
						_activePiece.Move(3);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Up) {
						_activePiece.Rotate();
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Escape)
					{
						_gameState = Exiting;
					}

				}
			} 
			
			//check for completed rows and clear them
			rowsCleared = 0;
			for (j = 0; j < FIELD_HEIGHT; j++)
			{
				for (k = 0; k < FIELD_WIDTH; k++)
				{
					if (playfield.square_state[k][j] == 0)
					{
						k = FIELD_WIDTH;
						//if we run into a blank, can't be a full row, so skip rest of row
					}
					
					if (k == FIELD_WIDTH - 1)
					{
						for (k = 0; k < FIELD_WIDTH; k++)
						{
							playfield.square_state[k][j] = 0; // if none of the squares in the row are empty, clear that row
						}
						rowsCleared++;
						//std::cout << "rowsCleared: " << rowsCleared << "\n";
					
					}
				}
			}
			
			switch (rowsCleared)
			{
				case 0:	break;
				case 1: score += 100; break;
				case 2: score += 200; break;
				case 3: score += 400; break;
				case 4: score += 800; break;
			}
			Game::scoreboard.setString(std::to_string(Game::score));
			window.draw(Game::scoreboard);
			

			//settle blocks to fill empty rows
			while (rowsCleared > 0)
			{
				for (j = (FIELD_HEIGHT - 1); j >= 0; j--) //do all rows, bottom to top
					{
						for (k = 0; k < FIELD_WIDTH; k++)
						{
							if (playfield.square_state[k][j] == 1)
							{
								k = FIELD_WIDTH; //if we run into a square, can't be an empty row, so skip rest of row
							}
							if (k == FIELD_WIDTH - 1) //if we get to end and havent broken yet, row is empty
							{
								clearedARow = true;
								for (capL = j; capL > 0; capL--)
								{
									for (k = 0; k < FIELD_WIDTH; k++)
									{
										playfield.square_state[k][capL] = playfield.square_state[k][capL - 1];
										// playfield.square_state[k][j] = playfield.square_state[j - 1][k]; 
										//playfield.square_state[j - 1][k] = 0;
										
									}
								}
								
								playfield.Update(window);
							
							}
						}
				}
				if (clearedARow) { rowsCleared--; clearedARow = false; }
				std::cout << "rowsCleared: " << rowsCleared << "\n";
			}
			//restart active piece
			_activePiece.Respawn();
			window.display();
			_gameState = Playing;
			break;
		}
		/*
		case Game::LastMove:
		{
			timerExp = false;
			if (clock.getElapsedTime().asMilliseconds() >= 1000)
			{
				//std::cout << clock.restart().asMilliseconds();
				//_activePiece.Move(3);
				playfield.Update(window);
				window.display();
				timerExp = true;
			}
			while (window.pollEvent(currentEvent) && (timerExp == false))
			{
				if (currentEvent.type == sf::Event::EventType::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Key::Left) {
						_activePiece.Move(2);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Right) {
						_activePiece.Move(1);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Down) {
						//_activePiece.Move(3);
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Up) {
						_activePiece.Rotate();
						playfield.Update(window);
						window.display();
					}
					if (currentEvent.key.code == sf::Keyboard::Key::Escape)
					{
						_gameState = Exiting;
					}

				}
			}
			//_gameState = Clearing;
			break;
			
		}*/	
		case Game::Exiting:
		{
			window.close();
			break;
		}
	}
	
};

bool Game::IsExiting()
{
	if ((_gameState == Game::Exiting) || (_gameState == Game::GameOver))
		return true;
	else
		return false;
}

Game::pieceType Game::randomPiece() 
{
	return Game::pieceType::I; //chosed carefully. guaranteed to be random
};

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::window;
sf::Font Game::font;
sf::Text Game::scoreboard;

int Game::j = 0;
int Game::k = 0;
int Game::capL = 0;
int Game::rowsCleared = 0;
int Game::score = 0;
bool Game::clearedARow;
bool Game::timerExp = false;
