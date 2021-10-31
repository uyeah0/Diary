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
	menu.MovePosition(x - 4, y); // ���� 51, >�� ����ؾ��ϱ� ������ -4
	cout << ">     �� �� �� ��";
	menu.MovePosition(x, y + 2); // 51
	cout << "�� �� �� ȣ �� ��";
	menu.MovePosition(x, y + 4);
	cout << "  �� �� �� ��";

	while (1) {
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
		switch (n)
		{
		case UP: { // �Էµ� ���� UP�� ���
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


void Menu::PrintMenu() { // ��� �޴� 
	system("cls");
	Main main = Main();
	main.printBorder();
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); // �۾� �� �ٲٱ�
	MovePosition(50, 4);
	cout << "[���� �ܼ� ���̾]" << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	MovePosition(46, 8);
	cout << "1. �ϱ� ����" << endl;
	MovePosition(46, 10);
	cout << "2. �ϱ� ����(���, ����)" << endl;
	MovePosition(46, 12);
	cout << "3. ����" << endl;
	MovePosition(46, 14);
	cout << "4. �����ϱ�" << endl << endl;

	MovePosition(46, 17);
	cout << "�޴� ���� >> ";
	
}

void Menu::FPrintMenu() { // �� ��� �޴�
	Menu menu = Menu();
	Main main = Main();
	main.printBorder();

	MovePosition(46, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
	cout << "1. �ϱ� ���";
	
	MovePosition(46, 10);
	cout << "2. �ϱ� �˻�";

	MovePosition(46, 12);
	cout << "3. �ϱ� ����";

	MovePosition(46, 14);
	cout << "4. ����ȭ������ ���ư���";
	
	MovePosition(46, 17);
	cout << "�޴� ����==> ";
}

int Menu::GetSelectedMenu() { // �⺻ �޴� ���� �� ��������
	return selectedMenu;
}

void Menu::RecieveMenu() { // �⺻ �޴� �Է�
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::FGetSelectedMenu() {
	return selectedMenu;
}

void Menu::FRecieveMenu() { // �� ��� �޴� �Է�
	MovePosition(60, 17);
	cin >> selectedMenu;
}

int Menu::keyControl() {
	char c;
	while (1) {
		if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
			c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
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