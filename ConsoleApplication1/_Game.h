#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "_Player.h"

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

#define default_ColorCode		16
#define default_Background		23
#define White_Background		240
class _Game
{
	_Board* _b;// a board game

	bool _turn;// turn: true for the 1st player and false for the 2nd player

	int _x, _y; // current position of cursor

	int _command; // input-key from the players

	bool _loop; // decision bool variable to exit game or not
	
	bool _load ;

	_Player user1;

	_Player user2;

public:
	_Game(int, int, int);
	~_Game();
	bool getLoad();
	void setLoad(bool);
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
	bool getTurn();
	int getX();
	int getY();
	_Board* getBoard();
	bool getLoop();
	void setX(int);
	void setY(int);
	void setTurn(bool);
	void setLoop(bool);
	void showXOBoard();
	_Player& getUser1();
	_Player& getUser2();
	void showPlayerInfo();
};

	void _Game::setLoad(bool load)
	{
		_load = load;
	}

	bool _Game::getLoad()
	{
		return _load;
	}
	void _Game::showXOBoard()
	{
		_b->drawBoardTest();
		for (int i = 0; i < _b->getSize(); i++)
		{
			for (int j = 0; j < _b->getSize(); j++)
			{
				_Common::gotoXY(j * 4 + _b->getLeft() + 2, i * 2 + _b->getTop() + 1);
				switch (_b->getXO(i, j))
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
				case 0: break;
				}
			}
		}
	}

	void _Game::setX(int x)
	{
	_x = x;
	}

	void _Game::setY(int y)
	{
		_y = y;
	}

	void _Game::setTurn(bool turn)
	{
		_turn = turn;
	}

	void _Game::setLoop(bool loop)
	{
		_loop = loop;
	}

	bool _Game::getLoop()
	{
	return _loop;
	}


	_Board* _Game::getBoard()
	{
		return _b;
	}

	int _Game::getX()
	{
		return _x;
	}

	int _Game::getY()
	{
		return _y;
	}

	bool _Game::getTurn()
	{
		return _turn;
	}

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
		setTurn(true);
		getUser1().setStep(0);
		getUser2().setStep(0);
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
	}
	void _Game::exitGame()
	{
		system("cls");
		_loop = false;
	}

	bool _Game::processCheckBoard()
	{
		switch (_b->checkBoard(_x, _y, _turn))
		{
		case -1:
			getUser1().increaseStep();
			_Common::TextColor(ColorCode_Red);
			printf("X");
			_Common::TextColor(ColorCode_Black);
			break;
		case 1:
			getUser2().increaseStep();
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
			_Common::gotoXY(92, 18);
			cout << getUser1().getName() << " WON!!! ";//won and the player %d lost\n", true, false);
			break;
		case 1:
			_Common::gotoXY(92, 18);
			cout << getUser2().getName() << " WON!!! ";//and the player% d lost\n", false, true);
			break;
		case 0:
			cout << "DRAW";
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

	_Player& _Game::getUser1()
	{
	return user1;
	}

	_Player& _Game::getUser2()
	{
	return user2;
	}

	void _Game::showPlayerInfo()
	{
		_Common::invisibleCursorMode();
		_Common::gotoXY(83, 29);
		cout << "Player 1: " << getUser1().getName();
		_Common::gotoXY(104, 29);
		cout << "Steps: " << getUser1().getStep();
		_Common::gotoXY(83, 35);
		cout << "Player 2: " << getUser2().getName();
		_Common::gotoXY(104, 35);
		cout << "Steps: " << getUser2().getStep();
		_Common::gotoXY(_x, _y);
		_Common::visibleCursorMode();
	}