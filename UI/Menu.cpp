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
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); // 글씨 색 바꾸기
	MovePosition(50, 4);
	cout << "[나의 콘솔 다이어리]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	MovePosition(46, 8);
	cout << "1. 일기쓰기" << endl;
	MovePosition(46, 10);
	cout << "2. 일기목록(보기, 수정, 삭제)" << endl;
	MovePosition(46, 12);
	cout << "3. 도움말" << endl;
	MovePosition(46, 14);
	cout << "4. 종료하기" << endl << endl;

	MovePosition(46, 17);
	cout << "메뉴 선택 >> ";
	
}

void Menu::FPrintMenu() { // 기능 메뉴
	Menu menu = Menu();
	Main main = Main();
	main.printBorder();

	MovePosition(46, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
	cout << "1. 일기 보기";
	
	MovePosition(46, 10);
	cout << "2. 일기 수정하기";
	
	MovePosition(46, 12);
	cout << "3. 일기 삭제하기";
	
	MovePosition(46, 14);
	cout << "4. 메인화면으로 돌아가기";
	
	MovePosition(46, 17);
	cout << "메뉴 선택==> ";
}

int Menu::GetSelectedMenu() { // 기본 메뉴 선택 값 가져오기
	return selectedMenu;
}

void Menu::RecieveMenu() { // 기본 메뉴 입력
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::FGetSelectedMenu() {
	return selectedMenu;
}

void Menu::FRecieveMenu() { // 기능 메뉴 입력
	MovePosition(60, 17);
	cin >> selectedMenu;
}