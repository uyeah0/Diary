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
	cout << "       o ━ ━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	menu.MovePosition(4, 2);
	cout << "♥  ━━━━━━━━━━                                                                                    ────────────┐ ┃";
	menu.MovePosition(4, 3);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 4);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 5);
	cout << "┃                                                                                                            │ ┃";
	menu.MovePosition(4, 6);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 7);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 8);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 9);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 10);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 11);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 12);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 13);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 14);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 15);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 16);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 17);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 18);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 19);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 20);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 21);
	cout << "┃ │                                                                                                             ";
	menu.MovePosition(4, 22);
	cout << "┃ │                                                                                                            ┃";
	menu.MovePosition(4, 23);
	cout << "┃ │                                                                                                              ";
	menu.MovePosition(4, 24);
	cout << "┃ └───────────                                                                                    o ━ ━━━━━━━━━ ";
	menu.MovePosition(4, 25);
	cout << " ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━      ♥ ━━━━━━━━━     ";


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 글씨 색 바꾸기
	MovePosition(50, 4);
	cout << "[나의 콘솔 다이어리]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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

void Menu::SPrintMenu() { // 기능 메뉴
	Menu menu;
	menu.MovePosition(4, 1);
	cout << "       o ━ ━━━ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	menu.MovePosition(4, 2);
	cout << "♥  ━━━━━━━━━━                                                                                    ────────────┐ ┃";
	menu.MovePosition(4, 3);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 4);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 5);
	cout << "┃                                                                                                            │ ┃";
	menu.MovePosition(4, 6);
	cout << "                                                                                                             │ ┃";
	menu.MovePosition(4, 7);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 8);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 9);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 10);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 11);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 12);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 13);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 14);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 15);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 16);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 17);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 18);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 19);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 20);
	cout << "┃                                                                                                              ┃";
	menu.MovePosition(4, 21);
	cout << "┃ │                                                                                                             ";
	menu.MovePosition(4, 22);
	cout << "┃ │                                                                                                            ┃";
	menu.MovePosition(4, 23);
	cout << "┃ │                                                                                                              ";
	menu.MovePosition(4, 24);
	cout << "┃ └───────────                                                                                    o ━ ━━━━━━━━━ ";
	menu.MovePosition(4, 25);
	cout << " ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━      ♥ ━━━━━━━━━     ";


	MovePosition(55, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
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

int Menu::GetSelectedMenu() { // 기본 메뉴 선택 값 가져오기
	return selectedMenu;
}

void Menu::RecieveMenu() { // 기본 메뉴 입력
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