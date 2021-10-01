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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 글씨 색 바꾸기
	MovePosition(88, 3);
	cout << "[나의 콘솔 다이어리]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	MovePosition(85, 6);
	cout << "1. 일기쓰기" << endl;
	MovePosition(85, 8);
	cout << "2. 일기목록(보기, 수정, 삭제)" << endl;
	MovePosition(85, 10);
	cout << "3. 도움말" << endl;
	MovePosition(85, 12);
	cout << "4. 종료하기" << endl << endl;

	MovePosition(85, 16);
	cout << "메뉴 선택 >> ";
	
}

void Menu::SPrintMenu() { 
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	//cout << "[기능]";
	MovePosition(55, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "1. 일기 보기";
	
	MovePosition(55, 5);
	cout << "2. 일기 수정하기";
	
	MovePosition(55, 7);
	cout << "3. 일기 삭제하기";
	
	MovePosition(55, 9);
	cout << "4. 메인화면으로 돌아가기";
	
	MovePosition(55, 12);
	cout << "메뉴 선택==> ";
}

int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(100, 16);
	cin >> selectedMenu;
}

int Menu::SGetSelectedMenu() {
	return selectedMenu;
}

void Menu::SRecieveMenu() {
	MovePosition(70, 12);
	cin >> selectedMenu;
}