#pragma once
#include <stdio.h>
#include <conio.h>

#define BOARD_SIZE 19
#define LEFT 1
#define TOP 1
#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7
#define default_Background		0
#define White_Background		240
class _Game
{

	_Board* _b;// a board game

	bool _turn;// turn: true for the 1st player and false for the 2nd player

	int _x, _y; // current position of cursor

	int _command; // input-key from the players

	bool _loop; // decision bool variable to exit game or not

public:
	_Game(int, int, int);
	~_Game();
	int getCommand();
	bool isContinue();
	char waitKeyBoard();
	char askContinue();
	void startGame();
	void exitGame();
	bool processCheckBoard();
	int processFinish();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
};

	_Game::_Game(int pSize, int pLeft, int pTop)
	{
		_b = new _Board(pSize, pLeft, pTop);
		_loop = _turn = true;
		_command = -1; // Assign turn and default key
		_x = pLeft; _y = pTop;
	}

	_Game::~_Game() { delete _b; }

	int _Game::getCommand() { return _command; }
	bool _Game::isContinue() { return _loop; }
	char _Game::waitKeyBoard()
	{
		_command = toupper(_getch());
		return _command;
	}
	char _Game::askContinue()
	{
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
		return waitKeyBoard();
	}

	void _Game::startGame()
	{

		system("cls");
		_b->resetData(); // Setting the original data
		_b->drawBoardTest(); // Draw board
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
	}
	void _Game::exitGame()
	{
		system("cls");
		//Maybe save game before stopping
		_loop = false;
	}

	bool _Game::processCheckBoard()
	{
		switch (_b->checkBoard(_x, _y, _turn))
		{
		case -1:
			_Common::TextColor(ColorCode_Red);
			printf("X");
			_Common::TextColor(ColorCode_Black);
			break;
		case 1:
			_Common::TextColor(ColorCode_DarkBlue);
			printf("O");
			_Common::TextColor(ColorCode_Black);
			break;
		case 0: return false; // Tick the cell marked
		}
		return true;
	}

	int _Game::processFinish()
	{
		// Move to the reasonable place to print string win/lose/draw
		_Common::gotoXY(90, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) - 25);
		int pWhoWin = _b->testBoard(_x, _y);
		switch (pWhoWin)
		{
		case -1:
			printf("THE PLAYER %d WON\n", true);//won and the player %d lost\n", true, false);
			break;
		case 1:
			printf("THE PLAYER %d WON\n", false);//and the player% d lost\n", false, true);
			break;
		case 0:
			printf("DRAW\n");
			break;
		case 2:
			_turn = !_turn; // change turn if nothing happen
		}
		_Common::gotoXY(_x, _y);// Return the current position of cursor
		return pWhoWin;
	}
	void _Game::moveRight()
	{
		if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
		{
			_x += 4;
			_Common::gotoXY(_x, _y);
		}
	}
	void _Game::moveLeft()
	{
		if (_x > _b->getXAt(0, 0)) {
			_x -= 4;
			_Common::gotoXY(_x, _y);
		}
	}
	void _Game::moveDown()
	{
		if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
		{
			_y += 2;
			_Common::gotoXY(_x, _y);
		}
	}
	void _Game::moveUp()
	{
		if (_y > _b->getYAt(0, 0))
		{
			_y -= 2;
			_Common::gotoXY(_x, _y);
		}
	}

	void letPlay()
	{
		_Common::visibleCursorMode();
		_Game g(BOARD_SIZE, LEFT, TOP);
		g.startGame();
		while (g.isContinue())
		{
			g.waitKeyBoard();

			if (g.getCommand() == 27) g.exitGame();

			else {

				switch (g.getCommand())
				{
				case 'A': case 75:

					g.moveLeft();

					break;

				case 'W': case 72:

					g.moveUp();

					break;

				case 'S': case 80:

					g.moveDown();

					break;

				case 'D': case 77:

					g.moveRight();

					break;
				case 13: case ' ':

					//Mark the board, then check and process win/lose/draw/continue

					if (g.processCheckBoard())
					{
						switch (g.processFinish())
						{

						case -1: case 1: case 0:
							if (g.askContinue() != 'Y') g.exitGame();

							else g.startGame();

						}
					}
				}

			}

		}
	}
