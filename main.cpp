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

void gotoxy(int x, int y) {
	COORD Pos; //x, y�� ������ �ִ� ����ü 
	Pos.X = x; 
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int keyControl() {
	int temp; // getch�Լ��� ���͸� �Է����� �ʾƵ� �ٷ� ��ȯ
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
				cout << "����Ű�� �̵����ּ���" << endl;
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
	cout << "���� �ϱ���" << endl;
	cout << endl << endl;

	gotoxy(22-1, 3);
	cout << "> �ϱ⾲��" << endl;
	gotoxy(22, 4);
	cout << "�ϱ⺸��/����" << endl;
	gotoxy(22, 5);
	cout << "�ϱ����" << endl;
	gotoxy(22, 6);
	cout << "����" << endl;
	gotoxy(22, 7);
	cout << "����" << endl;
	while (1) {
		int n = keyControl();
		switch (n)
		{
		case UP: {
			if (y > 3) { // 3~7���� �̵�
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 7) { // �ִ� 7
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
	

	/*int menu;
	cout << "�޴� �Է� >> ";
	cin >> menu;
	switch (menu)
	{
	case 1:  cout << "1��" << endl;  break;
	case 2:	cout << "2��" << endl;  break;
	case 3 : cout << "3��" << endl;  break;
	case 4 :cout << "4��" << endl;  break;
	default:
		break;
	}*/

	return 0;
}