#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define MENU_WRITE_DIARY 1
#define MENU_READ_DIARY 2
#define MENU_EXIT 3

#define UP 0
#define DOWN 1
#define SUBMIT 2

class Menu {
private:
	int selectedMenu;	//������ �޴� ����

public:
	Menu(int x, int y); //������
	Menu();
	void MovePosition(int x, int y);

	int SPrintMenu(); // ���� �޴� ��� ���� �Է�
	
	void RecieveMenu(); // �⺻ �޴� �Է� �ޱ�
	int GetSelectedMenu(); // �⺻ �޴� �� �ֱ�

	void PrintMenu(); //  ��� �޴� ���
	void FPrintMenu(); // �� ��� �޴� function print menu
	void FRecieveMenu(); // ��� �Է� �ޱ�
	int FGetSelectedMenu(); // ��� �޴� �� �ޱ�

	int keyControl();
	void bgDraw();
};