#include <iostream>;
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD Pos; //x, y�� ������ �ִ� ����ü 
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	gotoxy(2, 1);
	string date;
	cout << "��¥(yyyymmdd) : ";
	cin >> date;
	
	gotoxy(50, 1);
	string weather;
	cout << "���� : ";
	cin >> weather;

	
	gotoxy(2, 3);
	string title;
	cout << "���� (30���̳�) : ";
	cin >> title;

	gotoxy(50, 3);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������.";

	gotoxy(2, 5);
	string body;
	cout << "���� : ( enter ���� �� '***' �Է� �� ����)";
	gotoxy(2, 6);
	cin >> body;

	return 0;
}