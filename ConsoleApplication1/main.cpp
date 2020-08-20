#include <iostream>
#include <conio.h>

#include "_Common.h"
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"


using namespace std;
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
