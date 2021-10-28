#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define MENU_WRITE_DIARY 1
#define MENU_READ_DIARY 2
#define MENU_EXIT 3

class Menu {
private:
	int selectedMenu;	//������ �޴� ����

public:
	Menu(int x, int y); //������
	Menu();
	void MovePosition(int x, int y);
	void PrintMenu(); // �⺻�޴� ���
	// void LPrintMenu(); // ��� ���

	int GetSelectedMenu(); // �޴� ����
	void FPrintMenu(); // �⺻ �޴� 
	void RecieveMenu(); // �޴� �Է� �ޱ�
	int FGetSelectedMenu(); // �޴� �� �ޱ�
	void FRecieveMenu(); // selectMenu �Է� �ޱ�

};