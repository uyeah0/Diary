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
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ); // �۾� �� �ٲٱ�
	MovePosition(45, 3);
	cout << "���� �ܼ� ���̾" << endl << endl;

	MovePosition(45, 6);
	cout << "1. �ϱ⾲��" << endl;
	MovePosition(45, 8);
	cout << "2. �ϱ���(����, ����, ����)" << endl;
	MovePosition(45, 10);
	cout << "3. ����" << endl;
	MovePosition(45, 12);
	cout << "4. �����ϱ�" << endl << endl;

	MovePosition(45, 16);
	cout << "�޴� ���� >> ";
	
}

void Menu::SPrintMenu() { 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	//cout << "[���]";
	MovePosition(55, 3);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);*/
	cout << "1. �ϱ� ����";
	
	MovePosition(55, 5);
	cout << "2. �ϱ� �����ϱ�";
	
	MovePosition(55, 7);
	cout << "3. �ϱ� �����ϱ�";
	
	MovePosition(55, 9);
	cout << "4. ����ȭ������ ���ư���";
	
	MovePosition(55, 11);
	cout << "�޴� ����==> ";
}

int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(60, 16);
	cin >> selectedMenu;
}

int Menu::SGetSelectedMenu() {
	return selectedMenu;
}

void Menu::SRecieveMenu() {
	MovePosition(70, 11);
	cin >> selectedMenu;
}


