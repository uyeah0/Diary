#pragma once
#include<iostream>
#include "Main.h"
using namespace std;

class Help{
public :
	void PrintHelp() {
		Main main = Main();
		cout << "[����]" << endl;
		MovePosition(40, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �۾� ���� �ٲ�
		cout << "�ܼ� �ϱ��� �Դϴ�." << endl;
		MovePosition(40, 8);
		cout << "�޴� 1���� ���� �ϱ⸦ �ۼ��մϴ�. " << endl;
		MovePosition(40, 10);
		cout << "�޴� 2���� ���� �ۼ��ߴ� �ϱ⸦ �ҷ��ɴϴ�." << endl;
		MovePosition(40, 12);
		cout << "�޴� 4���� ���� �����մϴ�." << endl;
		MovePosition(40, 16);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	}
	void MovePosition(int x, int y) {
		
	}
}
