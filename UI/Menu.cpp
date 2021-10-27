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
	Menu menu;
	menu.MovePosition(4, 1);
	cout << "       o �� ������ ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	menu.MovePosition(4, 2);
	cout << "��  ��������������������                                                                                    �������������������������� ��";
	menu.MovePosition(4, 3);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 4);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 5);
	cout << "��                                                                                                            �� ��";
	menu.MovePosition(4, 6);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 7);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 8);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 9);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 10);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 11);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 12);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 13);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 14);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 15);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 16);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 17);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 18);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 19);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 20);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 21);
	cout << "�� ��                                                                                                             ";
	menu.MovePosition(4, 22);
	cout << "�� ��                                                                                                            ��";
	menu.MovePosition(4, 23);
	cout << "�� ��                                                                                                              ";
	menu.MovePosition(4, 24);
	cout << "�� ������������������������                                                                                    o �� ������������������ ";
	menu.MovePosition(4, 25);
	cout << " ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������      �� ������������������     ";


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �۾� �� �ٲٱ�
	MovePosition(50, 4);
	cout << "[���� �ܼ� ���̾]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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

void Menu::SPrintMenu() { // ��� �޴�
	Menu menu;
	menu.MovePosition(4, 1);
	cout << "       o �� ������ ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	menu.MovePosition(4, 2);
	cout << "��  ��������������������                                                                                    �������������������������� ��";
	menu.MovePosition(4, 3);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 4);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 5);
	cout << "��                                                                                                            �� ��";
	menu.MovePosition(4, 6);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 7);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 8);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 9);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 10);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 11);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 12);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 13);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 14);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 15);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 16);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 17);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 18);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 19);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 20);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 21);
	cout << "�� ��                                                                                                             ";
	menu.MovePosition(4, 22);
	cout << "�� ��                                                                                                            ��";
	menu.MovePosition(4, 23);
	cout << "�� ��                                                                                                              ";
	menu.MovePosition(4, 24);
	cout << "�� ������������������������                                                                                    o �� ������������������ ";
	menu.MovePosition(4, 25);
	cout << " ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������      �� ������������������     ";


	MovePosition(55, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	cout << "1. �ϱ� ����";
	
	MovePosition(55, 5);
	cout << "2. �ϱ� �����ϱ�";
	
	MovePosition(55, 7);
	cout << "3. �ϱ� �����ϱ�";
	
	MovePosition(55, 9);
	cout << "4. ����ȭ������ ���ư���";
	
	MovePosition(55, 12);
	cout << "�޴� ����==> ";
}

int Menu::GetSelectedMenu() { // �⺻ �޴� ���� �� ��������
	return selectedMenu;
}

void Menu::RecieveMenu() { // �⺻ �޴� �Է�
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::SGetSelectedMenu() {
	return selectedMenu;
}

void Menu::SRecieveMenu() {
	MovePosition(70, 17);
	cin >> selectedMenu;
}