#include <iostream>;
#include <my_global.h>
#include<mysql.h>
#pragma comment(lib, "libmySQL.lib");
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD Pos; //x, y�� ������ �ִ� ����ü 
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printMain() {
	gotoxy(45, 3);
	cout << "���� �ܼ� ���̾" << endl << endl;

	gotoxy(45, 6);
	cout << "1. �ϱ⾲��" << endl;
	gotoxy(45, 8);
	cout << "2. �ϱ���(����, ����, ����)" << endl;
	gotoxy(45, 10);
	cout << "3. ����" << endl;
	gotoxy(45, 12);
	cout << "4. �����ϱ�" << endl << endl;

}


int menu() {
	int menu;
	gotoxy(45, 16);
	cout << "�޴� �Է� >> ";
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
	MYSQL mysql;
	mysql_init(&mysql);
	printMain();
	int menuCode = menu();
	cout << menuCode << endl;

	cout << mysql_get_client_info();
	return 0;
}