#include "Menu.h";

/*
#include<iostream>
#include<windows.h>
#include<conio.h>
#define MAGIC_KEY 224


//#define UP 0
//#define DOWN 1
//#define LEFT 2
//#define RIGHT 3
#define SPACE 32
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;
*/

void Main::printMain() {
	Menu menu = Menu(50, 1); // 메뉴
	Help help; // 도움말
	WriteDiary writediary; // 일기쓰기
	LoadDiary loaddiary;

	bool isRun = true;
	bool isPrintHelp = true;
	bool isWriteDiary = true;
	bool isLoadDiary = false;

	menu.PrintMenu();
	menu.RecieveMenu();

	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu) 
		{
		case 1:
			if (!isWriteDiary) {
				writeddiary.Write();
				isWriteDiary = true;
			}
		}
	}

}

void gotoxy(int x, int y) {
	COORD Pos; //x, y를 가지고 있는 구조체 
	Pos.X = x; 
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int keyControl() {
	int temp; // getch함수는 엔터를 입력하지 않아도 바로 반환
	int x = 0;
	int y = 0;
	while (true) {
		temp = _getch();
		if (temp == MAGIC_KEY)
		{
			switch (_getch())
			{
			case UP:
				return UP;
			case DOWN:
				return DOWN;
			default:
				cout << "방향키로 이동해주세요" << endl;
			}

		}
	}
	/*
	if (temp == UP) { return UP; }
	else if (temp == DOWN) { return DOWN; }
	else if (temp == LEFT) { return LEFT; }
	else if (temp == RIGHT) { return RIGHT; }*/
}

int menu() {
	int x = 24; 
	int y = 3;

	gotoxy(45, 3);
	cout << "나의 콘솔 다이어리" << endl << endl;

	gotoxy(45, 6);
	cout << "1. 일기쓰기" << endl;
	gotoxy(45, 8);
	cout << "2. 일기목록(보기, 수정, 삭제)" << endl;
	gotoxy(45, 10);
	cout << "3. 도움말" << endl;
	gotoxy(45, 12);
	cout << "4. 종료하기" << endl << endl;
	

	int menu;
	gotoxy(45, 16);
	cout << "메뉴 입력 >> ";
	cin >> menu;
	switch (menu)
	{
	case 1: return 1;
	case 2:	return 2;
	case 3: return 3;
	case 4: return 4;
	default:
		return 0; break;
	}

}

int main() {

	int menuCode = menu();
	cout << menuCode << endl;

	return 0;
}