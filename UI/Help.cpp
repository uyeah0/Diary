#include <iostream>
#include <Windows.h>
#include "Help.h"
using namespace std;

void Help::PrintHelp() {
	Main main = Main();
	
	char ch;
	system("cls");
	main.printBorder();
	MovePosition(45, 3);
	cout << "[����]" << endl;
	MovePosition(40, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY); // �۾� ���� �ٲ�
	cout << "�ܼ� �ϱ��� �Դϴ�." << endl;
	MovePosition(40, 8);
	cout << "�޴� 1���� ���� �ϱ⸦ �ۼ��մϴ�. " << endl;
	MovePosition(40, 10);
	cout << "�޴� 2���� ���� �ۼ��ߴ� �ϱ⸦ �ҷ����� �����մϴ�." << endl;
	MovePosition(40, 12);
	cout << "�޴� 4���� ���� �����մϴ�." << endl;
	MovePosition(40, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
void Help::MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
Help::Help() {

}
