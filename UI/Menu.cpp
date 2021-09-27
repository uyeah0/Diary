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
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ); // 글씨 색 바꾸기
	MovePosition(45, 3);
	cout << "나의 콘솔 다이어리" << endl << endl;

	MovePosition(45, 6);
	cout << "1. 일기쓰기" << endl;
	MovePosition(45, 8);
	cout << "2. 일기목록(보기, 수정, 삭제)" << endl;
	MovePosition(45, 10);
	cout << "3. 도움말" << endl;
	MovePosition(45, 12);
	cout << "4. 종료하기" << endl << endl;

	MovePosition(45, 16);
	cout << "메뉴 선택 >> ";
	//MovePosition(40, 19);
	
}

void Menu::SPrintMenu() { 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	/*cout << "[기능]";
	MovePosition(55, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);*/
	cout << "1. 일기 보기";
	cout << endl;
	//MovePosition(55, 4);
	cout << "2. 일기 수정하기";
	cout << endl;
	//MovePosition(55, 6);
	cout << "3. 일기 삭제하기";
	cout << endl;
	//MovePosition(55, 8);
	cout << "4. 메인화면으로 돌아가기";
	cout << endl;
	//MovePosition(55, 10);
	cout << "메뉴 선택==> ";
}

int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(60, 16);
	cin >> selectedMenu;
}

int Menu::LGetSelectedMenu() {
	return selectedMenu;
}

void Menu::LRecieveMenu() {
	MovePosition(70, 10);
	cin >> selectedMenu;
}


