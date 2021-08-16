#include<iostream>
#include<windows.h>
#include<conio.h>
#define MAGIC_KEY 224
#define SPACE 32
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

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
	gotoxy(24, 1);
	cout << "나의 일기장" << endl;
	cout << endl << endl;

	gotoxy(22-1, 3);
	cout << "> 일기쓰기" << endl;
	gotoxy(22, 4);
	cout << "일기보기/수정" << endl;
	gotoxy(22, 5);
	cout << "일기삭제" << endl;
	gotoxy(22, 6);
	cout << "도움말" << endl;
	gotoxy(22, 7);
	cout << "종료" << endl;
	while (1) {
		int n = keyControl();
		switch (n)
		{
		case UP: {
			if (y > 3) { // 3~7까지 이동
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 7) { // 최대 7
				cout << " ";
				gotoxy(x - 1, ++y);
				cout << ">";
			}
			break;
		}
		case SPACE: {
			return y - 3;
		}
		}
	}
}

int main() {

	int menuCode = menu();


	return 0;
}
