#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
class _Board
{

private:

	int _size;

	int _left, _top;

	_Point** _pArr;

public:
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	_Board(int, int, int);
	~_Board();
	void resetData();
	void drawBoard(); //the original
	void drawBoardTest(); //developing
	int getXO(int, int);
	int checkBoard(int, int, bool);
	int testBoard(int&, int&);
};
	int _Board::getSize() { return _size; }
	int _Board::getLeft() { return _left; }
	int _Board::getTop() { return _top; }

	int _Board::getXAt(int i, int j)
	{
		return _pArr[i][j].getX();
	}

	int _Board::getYAt(int i, int j)
	{
		return _pArr[i][j].getY();
	}

	_Board::_Board(int pSize, int pX, int pY)
	{

		_size = pSize;
		_left = pX;
		_top = pY;
		_pArr = new _Point * [pSize];
		for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
	}

	_Board::~_Board()
	{
		for (int i = 0; i < _size; i++) delete[] _pArr[i];
		delete[] _pArr;
	}

	void _Board::resetData()
	{

		if (_size == 0) return; // Firstly calling constructor before calling resetData

		for (int i = 0; i < _size; i++)
		{

			for (int j = 0; j < _size; j++)
			{
				_pArr[i][j].setX(4 * j + _left + 2); // x-value of boardgame
				_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
				_pArr[i][j].setCheck(0);
			}
		}
	}

	void _Board::drawBoard()
	{
		if (_pArr == NULL) return; // firstly call constructor

		for (int i = 0; i <= _size; i++)
		{
			for (int j = 0; j <= _size; j++)
			{
				_Common::gotoXY(_left + 4 * i, _top + 2 * j);
				printf(".");
			}
		}
		_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());//move to the 1st cell
	}

	void _Board::drawBoardTest()
	{
		if (_pArr == NULL) return; //constructor
		int left = _left;
		int top = _top;

		//Print top edge of the board
		_Common::gotoXY(left, top);
		top++;
		cout << char(218); //start top line
		for (int i = 0; i < _size - 1; i++)
		{
			cout << char(196) << char(196) << char(196) << char(194); //middle of top line
		}
		cout << char(196) << char(196) << char(196) << char(191); //end top line

		//Print the rest of board but bottom edge
		_Common::gotoXY(left, top);
		top++;
		for (int i = 0; i < _size - 1; i++) //Print two lines (1 with spaces, 1 witn crosses) => a block
		{
			//Lines with spaces
			for (int i = 0; i <= _size; i++)
			{
				cout << char(179); //start line (line with spaces)
				cout << "   ";     //spaces between block
			}
			_Common::gotoXY(left, top);
			top++;

			//Lines with crosses
			cout << char(195); //start line 
			for (int i = 0; i < _size - 1; i++)
			{
				cout << char(196) << char(196) << char(196) << char(197); //middle line with cross
			}
			cout << char(196) << char(196) << char(196) << char(180); //end line
			_Common::gotoXY(left, top);
			top++;
		}

		//Print last line of blocks
		//Print last line with spaces (line number _size-1)
		for (int i = 0; i <= _size; i++)
		{
			cout << char(179) << "   ";
		}

		//Print the bottom edge of board
		_Common::gotoXY(left, top);
		top++;
		cout << char(192); //start line
		for (int i = 0; i < _size - 1; i++)
		{
			cout << char(196) << char(196) << char(196) << char(193); //middle line
		}
		cout << char(196) << char(196) << char(196) << char(217); //end line
		//move current pointer to the first block of the board
		
		_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());
	}

	int _Board::getXO(int x, int y)
	{
		return _pArr[x][y].getCheck();
	}

	int _Board::checkBoard(int pX, int pY, bool pTurn)
	{

		for (int i = 0; i < _size; i++)
		{

			for (int j = 0; j < _size; j++)
			{


				if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
				{
					if (pTurn) _pArr[i][j].setCheck(-1);// If current turn is true: c = -1

					else _pArr[i][j].setCheck(1);// If current turn is false: c = 1
					return _pArr[i][j].getCheck();
				}
			}
		}
		return 0;
	}

	int _Board::testBoard(int& pX, int& pY)
	{
		//Recognize Draw
		bool check = true;
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (_pArr[i][j].getCheck() == 0)
				{
					check = false;
					break;
				}
			}
		}
		if (check) return 0;

		//Recognize win/ lose
		int x = 0;
		int y = 0;

		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
				{
					x = i;
					y = j;
					break;
				}
			}
		}

		int res = 0;
		int xStart = (x - 4 > 0) ? x - 4 : 0;
		int yStart = (y - 4 > 0) ? y - 4 : 0;

		int xEnd = (x + 4 >= _size) ? _size - 1 : x + 4;
		int yEnd = (y + 4 >= _size) ? _size - 1 : y + 4;

		int x1, x2, y1, y2;

		for (int i = xStart; i <= x; i++)
		{
			if (i + 4 < _size)
			{
				res = _pArr[i][y].getCheck() + _pArr[i + 1][y].getCheck() + _pArr[i + 2][y].getCheck()
					+ _pArr[i + 3][y].getCheck() + _pArr[i + 4][y].getCheck();

				x1 = i - 1 >= 0 ? i - 1 : xStart;
				y1 = y;

				x2 = i + 5 >= _size ? x + 4 : i + 5;
				y2 = y;
			}

			if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
			{
				pX = i;
				pY = y;
				return 1;
			}

			if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
			{
				pX = i;
				pY = y;
				return -1;
			}
		}

		for (int i = yStart; i <= y; i++)
		{
			if (i + 4 < _size)
			{
				res = _pArr[x][i].getCheck() + _pArr[x][i + 1].getCheck() + _pArr[x][i + 2].getCheck()
					+ _pArr[x][i + 3].getCheck() + _pArr[x][i + 4].getCheck();

				x1 = x;
				y1 = i - 1 >= 0 ? i - 1 : yStart;

				x2 = x;
				y2 = i + 5 >= _size ? y + 4 : i + 5;
			}

			if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
			{
				pX = x;
				pY = i;
				return 1;
			}
			if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
			{
				pX = x;
				pY = i;
				return -1;
			}
		}

		for (int i = xStart; i <= x; i++)
		{
			for (int j = yStart; j <= y; j++)
			{
				if (i - j == x - y && i + 4 < _size && j + 4 < _size)
				{
					res = _pArr[i][j].getCheck() + _pArr[i + 1][j + 1].getCheck() + _pArr[i + 2][j + 2].getCheck()
						+ _pArr[i + 3][j + 3].getCheck() + _pArr[i + 4][j + 4].getCheck();
					x1 = i - 1;
					y1 = j - 1;
					if (x1 < 0 || y1 < 0)
					{
						x1 = i;
						y1 = j;
					}
					x2 = i + 5;
					y2 = j + 5;
					if (x2 >= _size || y2 >= _size)
					{
						y2 = j;
						x2 = i;
					}
				}

				if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
				{
					pX = i;
					pY = j;
					return 1;
				}
				if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
				{
					pX = i;
					pY = j;
					return -1;
				}
			}
		}

		for (int i = xEnd; i >= x; i--)
		{
			for (int j = yStart; j <= y; j++)
			{
				if (i + j == x + y && j + 4 < _size && i - 4 >= 0)
				{
					res = _pArr[i][j].getCheck() + _pArr[i - 1][j + 1].getCheck() + _pArr[i - 2][j + 2].getCheck()
						+ _pArr[i - 3][j + 3].getCheck() + _pArr[i - 4][j + 4].getCheck();
					x1 = i + 1;
					y1 = j - 1;
					if (x1 >= _size || y1 < 0)
					{
						x1 = i;
						y1 = i;
					}
					x2 = i - 5;
					y2 = j + 5;
					if (x2<0 || y2>_size)
					{
						x2 = i;
						y2 = j;
					}
				}
				if (res == 5 && (_pArr[x1][y1].getCheck() != -1 || _pArr[x2][y2].getCheck() != -1))
				{
					pX = i;
					pY = j;
					return 1;
				}
				if (res == -5 && (_pArr[x1][y1].getCheck() != 1 || _pArr[x2][y2].getCheck() != 1))
				{
					pX = i;
					pY = j;
					return -1;
				}
			}
		}

		return 2; //Defaultly returns Continue
	}
