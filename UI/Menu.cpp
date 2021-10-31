#pragma once
#include "Main.h"
//#include "Start.h"

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

int Menu::SPrintMenu() {
	//Start start = Start();
	Main main = Main();
	Menu menu = Menu();
	int x = 51;
	int y = 19;


	main.printBorder();
	bgDraw();
	menu.MovePosition(x - 4, y); // 원래 51, >를 출력해야하기 때문에 -4
	cout << ">     시 작 하 기";
	menu.MovePosition(x, y + 2); // 51
	cout << "비 밀 번 호 설 정";
	menu.MovePosition(x, y + 4);
	cout << "  종 료 하 기";

	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n)
		{
		case UP: { // 입력된 값이 UP인 경우
			if (y > 19) {
				menu.MovePosition(x - 4, y);
				cout << " ";
				y -= 2;
				menu.MovePosition(x - 4, y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 23) {
				menu.MovePosition(x - 4, y);
				cout << " ";
				y += 2;
				menu.MovePosition(x - 4, y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 19;
		}
		}
	}
}


void Menu::PrintMenu() { // 기능 메뉴 
	system("cls");
	Main main = Main();
	main.printBorder();
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); // 글씨 색 바꾸기
	MovePosition(50, 4);
	cout << "[나의 콘솔 다이어리]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	MovePosition(46, 8);
	cout << "1. 일기 쓰기" << endl;
	MovePosition(46, 10);
	cout << "2. 일기 보기(목록, 수정)" << endl;
	MovePosition(46, 12);
	cout << "3. 도움말" << endl;
	MovePosition(46, 14);
	cout << "4. 종료하기" << endl << endl;

	MovePosition(46, 17);
	cout << "메뉴 선택 >> ";
	
}

void Menu::FPrintMenu() { // 상세 기능 메뉴
	Menu menu = Menu();
	Main main = Main();
	main.printBorder();

	MovePosition(46, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
	cout << "1. 일기 목록";
	
	MovePosition(46, 10);
	cout << "2. 일기 검색";

	MovePosition(46, 12);
	cout << "3. 일기 수정";

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

void Menu::FRecieveMenu() { // 상세 기능 메뉴 입력
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::keyControl() {
	char c;
	while (1) {
		if (_kbhit()) {               // 2. while문안에서 키보드 눌렸을 시 if문이 실행된다.
			c = _getch();           // 3. 방향키가 입력됬을 때 224 00 이 버퍼에 있다. 224부터 빼준다. 
			if (c == 32) {
				return SUBMIT;
			}
			if (c == -32) {
				c = _getch();
				switch (c)
				{
				case 72:
					return UP;
				case 80:
					return DOWN;
				}
			}
		}
	}
}

void Menu::bgDraw() {
	system("mode con:cols=120 lines=28");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

	Menu menu = Menu();
	Main main = Main();
	main.printBorder();

	menu.MovePosition(35, 4);
	cout << "                         _   ";
	menu.MovePosition(35, 5);
	cout << "  ___  ___  ___ _ __ ___| |_ ";
	menu.MovePosition(35, 6);
	cout << " / __|/ _ \\/ __| '__/ _ \\ __|";
	menu.MovePosition(35, 7);
	cout << " \\__ \\  __/ (__| | |  __/ |_ ";
	menu.MovePosition(35, 8);
	cout << " |___/\\___|\\___|_|  \\___|\\__|";

	menu.MovePosition(43, 9);
	cout << " ___    ____   ____  ____   __ __ ";
	menu.MovePosition(43, 10);
	cout << "|   \\  |    | /    ||    \\ |  |  |";
	menu.MovePosition(43, 11);
	cout << "|    \\  |  | |  o  ||  D  )|  |  |";
	menu.MovePosition(43, 12);
	cout << "|  D  | |  | |     ||    / |  ~  |";
	menu.MovePosition(43, 13);
	cout << "|     | |  | |  _  ||    \\ |___, |";
	menu.MovePosition(43, 14);
	cout << "|     | |  | |  |  ||  .  \\|     |";
	menu.MovePosition(43, 15);
	cout << "|_____||____||__|__||__|\\_||____/ ";

}