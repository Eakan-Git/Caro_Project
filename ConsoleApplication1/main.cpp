#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

#include "_Common.h"
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"


using namespace std;

_Game g(BOARD_SIZE, LEFT, TOP);

bool checkExist(string*, int, string);
void letPlay();
void Menu(int choose);
void LoadGame();
void showLoadList(string, string&);
void Save(string);


bool checkExist(string* arr, int n, string name)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].compare(name) == 0)
		{
			_Common::gotoXY(20, 16);
			cout << "File name exitsing, please choose another name!!!";
			return false;
		}
	}
	return true;
}

void ShowLoadList(string Filename, string& Fileload)
{
	_Common::invisibleCursorMode();
	system("cls");
	fstream f(Filename, ios::in || ios::out);
	if (!f.is_open())
	{
		_Common::gotoXY(50, 12);
		cout << "Error, can't find load list !!!" << endl;
		return;
	}
	int numofsaves;
	f >> numofsaves;
	f.seekg(2, ios::cur);
	string* ArrOfSaves = new string[numofsaves];
	for (int i = 0; i < numofsaves; i++)
	{
		f >> ArrOfSaves[i];
	}
	_Common::gotoXY(50, 6);
	cout << "Choose the file you want to load!!!";
	string name;
	bool check = true;
	int choose = 0;
	while (check)
	{
		for (int i = 0; i < numofsaves; i++)
		{
			_Common::gotoXY(50, 10 + i * 2);
			cout << ArrOfSaves[i];
		}

		_Common::gotoXY(50, 10 + numofsaves * 2 + 2);
		cout << "Go to back";

		_Common::TextColor(ColorCode_Red);

		for (int i = 0; i <= numofsaves; i++)
		{
			if (choose == i && i != numofsaves)
			{
				_Common::gotoXY(50, 10 + i * 2);
				cout << ArrOfSaves[i];
				break;
			}

			if (choose == numofsaves)
			{
				_Common::gotoXY(50, 10 + numofsaves * 2 + 2);
				cout << "Go to back";
				break;
			}

		}
		_Common::TextColor(default_ColorCode);

		char key = -1;
		if (_kbhit()) key = toupper(_getch());
		switch (key)
		{
		case 27:
			choose = numofsaves;
			break;
		case 13: case 32:
			if (choose == numofsaves) return;
			else
			{
				Fileload = ArrOfSaves[choose];
				return;
			}
			break;
		case 'W': case 72:
			choose--;
			break;
		case 'S': case 80:
			choose++;
			break;
		}
		if (choose < 0) choose = numofsaves;
		if (choose > numofsaves) choose = 0;

		Sleep(50);

	}

	f.close();
	delete[] ArrOfSaves;
}

void  LoadGame()
{
	string LoadFile = "";
	ShowLoadList("LoadList.txt", LoadFile);
	fstream f(LoadFile, ios::in);
	if (!f.is_open())
	{
		_Common::gotoXY(50, 19);
		cout << "Error, cant open" << endl;
		return;
	}
	int x, y, turn, loop,value;
	f >> turn >> loop >> x >> y;
	f.seekg(2, ios::cur);
	for (int i = 0; i < g.getBoard()->getSize(); i++)
	{
		for (int j = 0; j < g.getBoard()->getSize(); j++)
		{
			f >> value;
			g.getBoard()->setValue(i, j, value);
		}
	}
	g.setLoop(loop);
	g.setTurn(turn);
	g.setX(x);
	g.setY(y);
	_Common::invisibleCursorMode();
	system("cls");
	g.showXOBoard();
	_Common::gotoXY(g.getX(), g.getY());
	_Common::visibleCursorMode();
	f.close();
	g.setLoad();
	letPlay();
}

void SaveGame(string FileName)
{
	fstream f(FileName, ios::in || ios::out);
	if (!f.is_open())
	{
		system("cls");
		_Common::gotoXY(50, 17);
		cout << "Error,can't open save data !!!" << endl;
		system("pause");
		return;
	}
	int numofsaves;
	f >> numofsaves;
	string* ArrOfSaves = new string[numofsaves + 1];
	f.seekg(2, ios::cur);
	for (int i = 0; i < numofsaves; i++)
	{
		getline(f, ArrOfSaves[i]);
	}
	string name;
	system("cls");
	_Common::gotoXY(50, 10);
	cout << "***Save Game***" ; 
	_Common::gotoXY(50, 12);
	cout << "Save as : ";
	_Common::visibleCursorMode();
	do 
	{
		getline(cin, name);
		name.append(".txt");
	} 
	while (!checkExist(ArrOfSaves, numofsaves, name));
	ArrOfSaves[numofsaves] = name;
	numofsaves += 1;

	f.close();

	fstream fsavelist(FileName, ios::out);

	if (!fsavelist.is_open())
	{
		_Common::gotoXY(30, 16);
		cout << "Error, cant open save file !!!";
		return;
	}
	
	fsavelist << numofsaves << endl;

	for (int i = 0; i < numofsaves; i++)
	{
		fsavelist << ArrOfSaves[i] << endl;
	}

	fsavelist.close();
	fstream fsavegame(name, ios::out);
	bool Turn = g.getTurn();
	bool Loop = g.getLoop();
	int x, y;
	x = g.getX();
	y = g.getY();
	fsavegame << Turn << " " << Loop << " " << x << " " << y << endl;
	for (int i = 0; i < g.getBoard()->getSize(); i++)
	{
		for (int j = 0; j < g.getBoard()->getSize(); j++)
		{
			fsavegame << g.getBoard()->getXO(i,j) << " ";
		}
	}

	fsavegame.close();
	delete[] ArrOfSaves;
}

void letPlay()
{	
	_Common::visibleCursorMode();
	if (!g.getLoad())
	{
		g.startGame();
	}
	while (g.isContinue())
	{
		g.waitKeyBoard();

		if (g.getCommand() == 27) g.exitGame();

		else {

			switch (g.getCommand())
			{
			case 'L':
				_Common::invisibleCursorMode();
				system("cls");
				SaveGame("LoadList.txt");
				g.showXOBoard();
				_Common::gotoXY(g.getX(), g.getY());
				break;
			case 'T':
				LoadGame();
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

void Menu(int choose)
{

	_Common::invisibleCursorMode();

	system("cls");

	//Display
	//Draw box
	_Common::gotoXY(32, 4);
	for (int i = 20; i <= 70; i++)
	{
		if (i == 20) putchar(201);
		else if (i == 70) putchar(187);
		else putchar(205);
	}
	for (int i = 5; i <= 10; i++)
	{
		_Common::gotoXY(32, i); putchar(186);
		_Common::gotoXY(82, i); putchar(186);
	}
	_Common::gotoXY(32, 10);
	for (int i = 20; i <= 70; i++)
	{
		if (i == 20) putchar(200);
		else if (i == 70) putchar(188);
		else putchar(205);
	}

	_Common::gotoXY(36, 5);
	cout << "XXX   XXX     OOOOOOO";
	_Common::gotoXY(36, 6);
	cout << " XXX XXX     OOO   OOO";
	_Common::gotoXY(36, 7);
	cout << "  XXXXX      OOO   OOO        GROUP I";
	_Common::gotoXY(36, 8);
	cout << " XXX XXX     OOO   OOO";
	_Common::gotoXY(36, 9);
	cout << "XXX   XXX     OOOOOOO";


	bool check = true;
	while (check)
	{
		_Common::TextColor(ColorCode_Black);

		_Common::gotoXY(55, 15);
		cout << "New Game";
		_Common::gotoXY(55, 17);
		cout << "Load Game";
		_Common::gotoXY(55, 19);
		cout << "Options";
		_Common::gotoXY(55, 21);
		cout << "About";
		_Common::gotoXY(55, 23);
		cout << "Help";
		_Common::gotoXY(55, 25);
		cout << "Exit";

		_Common::TextColor(ColorCode_Red);
		switch (choose)
		{
		case 0:
			_Common::gotoXY(55, 15);
			cout << "New Game";
			break;
		case 1:
			_Common::gotoXY(55, 17);
			cout << "Load Game";
			break;
		case 2:
			_Common::gotoXY(55, 19);
			cout << "Options";
			break;
		case 3:
			_Common::gotoXY(55, 21);
			cout << "About";
			break;
		case 4:
			_Common::gotoXY(55, 23);
			cout << "Help";
			break;
		case 5:
			_Common::gotoXY(55, 25);
			cout << "Exit";
			break;
		}

		_Common::TextColor(ColorCode_Black);

		//Controler
		char key = -1;
		if (_kbhit()) key = toupper(_getch());
		switch (key)
		{
		case 27:
			choose = 5;
			break;
		case 'A': case 75:
			break;
		case 'W': case 72:
			choose--;
			break;
		case 'S': case 80:
			choose++;
			break;
		case 'D': case 77:
			break;
		case 13: case 32:
			check = false;
			switch (choose)
			{
			case 0:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< NEW GAME >>";
				letPlay();
				Menu(0);
				break;
			case 1:
				//Load Game
				LoadGame();
				Menu(1);
				break;
			case 2:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< OPTIONS >>";
				//options
				Menu(2);
				break;
			case 3:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< ABOUT >>";
				_Common::gotoXY(40, 10);
				cout << "BASE ON: MR.TRUONG TOAN THINH'S SOURCE CODE";
				_Common::gotoXY(40, 12);
				cout << "DESIGN: GROUP I";
				_Common::gotoXY(40, 14);
				cout << "YEAR: 2020";
				_Common::gotoXY(40, 17);
				system("pause");
				Menu(3);
				break;
			case 4:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< HELP >>";
				_Common::gotoXY(35, 10);
				cout << "A/ LEFT ARROW KEY\t:\tMOVE LEFT";
				_Common::gotoXY(35, 12);
				cout << "D/ RIGHT ARROW KEY\t:\tMOVE RIGHT";
				_Common::gotoXY(35, 14);
				cout << "W/ UP ARROW KEY\t:\tMOVE UP";
				_Common::gotoXY(35, 16);
				cout << "S/ DOWN ARROW KEY\t:\tMOVE DOWN";
				_Common::gotoXY(35, 18);
				cout << "SPACE BAR/ ENTER\t:\tCHOOSE/ DRAW";

				_Common::gotoXY(35, 22);
				system("pause");
				Menu(4);
				break;
			case 5:
				system("cls");
				_Common::gotoXY(50, 12);
				cout << "THANKS FOR USED!";
				_Common::gotoXY(50, 14);
				break;
			}
		}
		//Loop Menu When Move To Top/ End
		if (choose < 0) choose = 5;
		if (choose > 5) choose = 0;
		Sleep(50);
	}

}



int main()
{
	system("color 70");
	_Common::MaximizeWindow();
	_Common::fixConsoleWindow();
	Menu(0);
	return 0;
}
