#pragma once
#include "Main.h"

Menu::Menu(int x, int y) {
	MovePosition(x, y);
}
Menu::Menu() {
	selectedMenu = 0;
}
void Menu::MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
void Menu::PrintMenu() {
	system("cls");
	Main main = Main();
	main.printBorder();
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); // �۾� �� �ٲٱ�
	MovePosition(50, 4);
	cout << "[���� �ܼ� ���̾]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	MovePosition(46, 8);
	cout << "1. �ϱ⾲��" << endl;
	MovePosition(46, 10);
	cout << "2. �ϱ���(����, ����, ����)" << endl;
	MovePosition(46, 12);
	cout << "3. ����" << endl;
	MovePosition(46, 14);
	cout << "4. �����ϱ�" << endl << endl;

	MovePosition(46, 17);
	cout << "�޴� ���� >> ";
	
}

void Menu::FPrintMenu() { // ��� �޴�
	Menu menu = Menu();
	Main main = Main();
	main.printBorder();

	MovePosition(46, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
	cout << "1. �ϱ� ����";
	
	MovePosition(46, 10);
	cout << "2. �ϱ� �����ϱ�";
	
	MovePosition(46, 12);
	cout << "3. �ϱ� �����ϱ�";
	
	MovePosition(46, 14);
	cout << "4. ����ȭ������ ���ư���";
	
	MovePosition(46, 17);
	cout << "�޴� ����==> ";
}

int Menu::GetSelectedMenu() { // �⺻ �޴� ���� �� ��������
	return selectedMenu;
}

void Menu::RecieveMenu() { // �⺻ �޴� �Է�
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::FGetSelectedMenu() {
	return selectedMenu;
}

void Menu::FRecieveMenu() { // ��� �޴� �Է�
	MovePosition(60, 17);
	cin >> selectedMenu;
}