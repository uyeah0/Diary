#include "Main.h"

void Main::printMain() {
	system("mode con:cols=120 lines=28");
	Menu menu = Menu(50, 1);
	
	WriteDiary writediary;
	SearchDiary searchdiary;
	bool isRun = TRUE;
	bool isPrintHelp = FALSE;
	bool isWriteDiary = FALSE;
	bool isSearchDiary = FALSE;
	bool isTrue = FALSE;

	menu.PrintMenu();
	menu.RecieveMenu(); // 메뉴 입력받기
	


	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu(); // 입력 메뉴 가져오기
		switch (selectedMenu)
		{
		case 1:
			if (!isWriteDiary) {
				writediary.Write();
				isWriteDiary = TRUE;
			}
			break;
		case 2:
			if (!isSearchDiary) {
				searchdiary.SelectMenu();
				isSearchDiary = TRUE;
			}
			break;
		case 3://도움말
			isRun = FALSE;
			break;
		case 4://종료
			isRun = FALSE;
			break;
		default:
			if (!isTrue) {
				printMain();
				isTrue = TRUE;
			}
		}
		if (!isRun) {
			menu.MovePosition(45, 20);
			cout << "프로그램을 종료합니다." << endl;
			exit(0);
		}
	}
}

void Main::printBorder() {
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
}