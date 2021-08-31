#pragma once
#include<iostream>
#include "Main.h"
using namespace std;

class Help{
public :
	void PrintHelp() {
		char ch = "";
		Main main = Main();
		cout << "[도움말]" << endl;
		MovePosition(40, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 글씨 색을 바꿈
		cout << "콘솔 일기장 입니다." << endl;
		MovePosition(40, 8);
		cout << "메뉴 1번을 통해 일기를 작성합니다. " << endl;
		MovePosition(40, 10);
		cout << "메뉴 2번을 통해 작성했던 일기를 불러옵니다." << endl;
		MovePosition(40, 12);
		cout << "메뉴 4번을 눌러 종료합니다." << endl;
		MovePosition(40, 16);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
	}
	void MovePosition(int x, int y) {
		
	}
}
