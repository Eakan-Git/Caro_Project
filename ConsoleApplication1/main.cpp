#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
//#include <vld.h>

#include "_Common.h"
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"
#include "_Player.h"


using namespace std;

_Game g(BOARD_SIZE, LEFT, TOP);

bool checkExist(string*, int, string);
void letPlay();
void Menu(int choose);
void LoadGame();
void showLoadList(string, string&);
void Save(string);
void Options();

void drawX(int left, int top)
{
	_Common::TextColor(ColorCode_Red);
	int tmpTop = top;

	_Common::gotoXY(left, tmpTop++); printf("    %c%c%c%c%c%c%c%c%c                   %c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("      %c%c%c%c%c%c%c%c%c               %c%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c%c%c%c           %c%c%c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("          %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("            %c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c          ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("             %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("             %c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("            %c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c          ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("          %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c%c%c%c           %c%c%c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("      %c%c%c%c%c%c%c%c%c               %c%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("    %c%c%c%c%c%c%c%c%c                   %c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);



	_Common::TextColor(ColorCode_Black);
}
void drawO(int left, int top)
{
	_Common::TextColor(ColorCode_Blue);
	int tmpTop = top;

	_Common::gotoXY(left, tmpTop++); printf("                %c%c%c%c%c%c%c%c%c%c%c%c%c%c                ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("           %c%c%c%c                %c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("         %c%c%c%c%c                  %c%c%c%c%c         ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c%c%c                  %c%c%c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("         %c%c%c%c%c                  %c%c%c%c%c         ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("           %c%c%c%c                %c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("             %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("                %c%c%c%c%c%c%c%c%c%c%c%c%c%c                ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

	_Common::TextColor(ColorCode_Black);
}
void drawCaro(int left, int top)
{
	int tmpTop = top;


	_Common::gotoXY(left, tmpTop++); printf("       %c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("  %c%c%c%c%c%c     %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c%c         %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c               ", 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c               ", 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c               ", 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c               ", 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c%c         %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("  %c%c%c%c%c%c     %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("       %c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219);


	left += 21;
	tmpTop = top;
	_Common::gotoXY(left, tmpTop++); printf("           %c%c%c           ", 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("          %c%c%c%c%c          ", 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("         %c%c%c%c%c%c%c         ", 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("        %c%c%c%c %c%c%c%c        ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("       %c%c%c%c   %c%c%c%c       ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("      %c%c%c%c     %c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("   %c%c%c%c%c%c       %c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("  %c%c%c%c%c%c         %c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c%c%c           %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c%c             %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);


	left += 27;
	tmpTop = top;
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c       %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c         %c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c         %c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c       %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c      %c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c       %c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c        %c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c         %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219);


	left += 19;
	tmpTop = top;
	_Common::gotoXY(left, tmpTop++); printf("      %c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c%c%c     %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c         %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c           %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c           %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c           %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c           %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("%c%c%c%c%c         %c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf(" %c%c%c%c%c%c     %c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	_Common::gotoXY(left, tmpTop++); printf("      %c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219);
}
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
	if (numofsaves == 0)
	{
		_Common::gotoXY(40, 6);
		cout << "There's no file to load!";
		_Common::gotoXY(40, 8);
		system("pause");
		f.close();
		return;
	}
	f.seekg(2, ios::cur);
	string* ArrOfSaves = new string[numofsaves];
	for (int i = 0; i < numofsaves; i++)
	{
		f >> ArrOfSaves[i];
	}
	_Common::gotoXY(40, 6);
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

		_Common::TextColor(ColorCode_Red);

		for (int i = 0; i < numofsaves; i++)
		{
			if (choose == i && i != numofsaves)
			{
				_Common::gotoXY(50, 10 + i * 2);
				cout << ArrOfSaves[i];
				break;
			}


		}
		_Common::TextColor(default_ColorCode);

		char key = -1;
		if (_kbhit()) key = toupper(_getch());
		switch (key)
		{
		case 27:
			check = false;
			break;
		case 13: case 32:		
			Fileload = ArrOfSaves[choose];
			check = false;
			break;
		case 'W': case 72:
			choose--;
			break;
		case 'S': case 80:
			choose++;
			break;
		}
		if (choose < 0) choose = 0;
		if (choose > numofsaves - 1) choose = 0;

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
	int x, y, turn, loop, value, player1step, player2step;
	string player1name, player2name;
	f >> turn >> loop >> x >> y >> player1name >> player2name >> player1step >> player2step;
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
	g.getUser1().setName(player1name);
	g.getUser2().setName(player2name);
	g.getUser1().setStep(player1step);
	g.getUser2().setStep(player2step);
	_Common::invisibleCursorMode();
	system("cls");
	g.showXOBoard();
	_Common::gotoXY(g.getX(), g.getY());
	_Common::visibleCursorMode();
	f.close();
	g.setLoad(true);
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
	string player1name = g.getUser1().getName();
	string player2name = g.getUser2().getName();
	int player1step = g.getUser1().getStep();
	int player2step = g.getUser2().getStep();
	int x, y;
	x = g.getX();
	y = g.getY();
	fsavegame << Turn << " " << Loop << " " << x << " " << y << " " << player1name << " " << player2name << " " << player1step << " " << player2step << endl;
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
	g.setTurn(g.getTurn()); //change turn if Player2 play first
	g.showPlayerInfo();
	while (g.isContinue())
	{
		g.waitKeyBoard();

		if (g.getCommand() == 27)
		{
			g.setLoad(false);
			g.exitGame();
			break;
		}

		else {
			switch (g.getCommand())
			{
			case 'L':
				_Common::invisibleCursorMode();
				system("cls");
				SaveGame("LoadList.txt");
				g.showXOBoard();
				g.showPlayerInfo();
				_Common::gotoXY(g.getX(), g.getY());
				break;
			case 'T':
				LoadGame();
				return;
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
					g.showPlayerInfo();
					switch (g.processFinish())
					{

					case -1: case 1: case 0:

						_Common::gotoXY(93, 20);
						cout << "TRY AGAIN?";
						_Common::gotoXY(85, 22);
						cout << "[Y] YES\t\t[N] NO";
						{
							switch (g.askContinue())
							{
							case 'Y':
								g.setLoad(false);
								letPlay();
							case 'N':
								g.exitGame();
							}
						}

					}
					
				}
			}

		}

	}
	g.setLoop(true);//set lai loop de co the newgame trong lan choi tiep theo
}

void Menu(int choose)
{

	_Common::invisibleCursorMode();

	system("cls");

	drawCaro(12, 2);
	drawX(3, 16);
	drawO(70, 16);
	bool check = true;
	while (check)
	{
		_Common::TextColor(ColorCode_Black);

		_Common::gotoXY(55, 17);
		cout << "NEW GAME";
		_Common::gotoXY(55, 19);
		cout << "SAVED GAME";
		_Common::gotoXY(55, 21);
		cout << "OPTIONS";
		_Common::gotoXY(55, 23);
		cout << "ABOUT";
		_Common::gotoXY(55, 25);
		cout << "HELP";
		_Common::gotoXY(55, 27);
		cout << "EXIT";

		_Common::TextColor(ColorCode_Red);
		switch (choose)
		{
		case 0:
			_Common::gotoXY(55, 17);
			cout << "NEW GAME";
			break;
		case 1:
			_Common::gotoXY(55, 19);
			cout << "SAVED GAME";
			break;
		case 2:
			_Common::gotoXY(55, 21);
			cout << "OPTIONS";
			break;
		case 3:
			_Common::gotoXY(55, 23);
			cout << "ABOUT";
			break;
		case 4:
			_Common::gotoXY(55, 25);
			cout << "HELP";
			break;
		case 5:
			_Common::gotoXY(55, 27);
			cout << "EXIT";
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
				_Common::gotoXY(40, 10);
				cout << "Input name Player 1: ";
				_Common::visibleCursorMode();
				_Common::TextColor(ColorCode_Red);
				g.getUser1().inputName();
				_Common::TextColor(ColorCode_Black);
				_Common::gotoXY(40, 12);
				cout << "Input name Player 2: ";
				_Common::TextColor(ColorCode_Blue);
				g.getUser2().inputName();
				_Common::TextColor(ColorCode_Black);
				letPlay();
				Menu(0);
				break;
			case 1:
				LoadGame();
				Menu(1);
				break;
			case 2:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< OPTIONS >>";
				Options();
				Menu(2);
				break;
			case 3:
				system("cls");
				_Common::gotoXY(50, 7);
				cout << "<< ABOUT >>";
				_Common::gotoXY(40, 10);
				cout << "BASED ON: MR.TRUONG TOAN THINH'S SOURCE CODE";
				_Common::gotoXY(40, 12);
				cout << "DESIGN: GROUP I";
				_Common::gotoXY(40, 14);
				cout << "PHAM CHI BAO - 19127339";
				_Common::gotoXY(40, 16);
				cout << "TRAN KHAC HUNG - 19127413";
				_Common::gotoXY(40, 18);
				cout << "PHAM QUOC TOAN - 19127585";
				_Common::gotoXY(40, 20);
				cout << "NGUYEN QUANG TRUONG - 19127608";




				_Common::gotoXY(40, 22);
				cout << "YEAR: 2020";
				_Common::gotoXY(40, 24);
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
				cout << "TRY TO CHECK YOURS AND HAVE 5 MARKS IN A ROW";
				_Common::gotoXY(35, 24);
				cout << "    DON'T LET YOUR OPPONENT DO THAT, TOO";
				_Common::gotoXY(35, 28);
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

void Options()
{
	bool check = true;
	int choose = 0;
	while (check)
	{
		_Common::gotoXY(40, 9);

		cout << "First Player:";

		switch (choose)
		{
		case 0: 
			_Common::gotoXY(55, 9);
			_Common::TextColor(ColorCode_Red);
			cout << "X";
			_Common::TextColor(ColorCode_Black);
			break;
		case 1:
			_Common::gotoXY(55, 9);
			_Common::TextColor(ColorCode_Blue);
			cout << "O";
			_Common::TextColor(ColorCode_Black);
			break;
		}
		//Controler
		char key = -1;
		if (_kbhit()) key = toupper(_getch());
		switch (key)
		{
		case 27:
			return;
		case 'A': case 75:
			choose--;
			break;
		case 'D': case 77:
			choose++;
			break;
		case 13: case 32:
			check = false;
			switch (choose)
			{
			case 0:
				g.setTurn(true);
				break;
			case 1:
				g.setTurn(false);
				break;
			}
		}
		//Loop Menu When Move To Top/ End
		if (choose < 0) choose = 1;
		if (choose > 1) choose = 0;
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
