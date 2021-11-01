#include "SearchDiary.h"

void SearchDiary::SelectMenu() { // 메뉴 고르기
	system("cls");
	Menu menu = Menu();
	Main main = Main();
	SearchDiary_func sdf = SearchDiary_func();

	menu.FPrintMenu();
	menu.FRecieveMenu();
	

	bool isRun = TRUE;
	bool isWatchDiary = FALSE;
	bool isEditDiary = FALSE;
	bool isBackToMain = FALSE;
	bool isSearchDiary = FALSE;
	bool chk = FALSE;
	
	main.printBorder();

	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWatchDiary) { // 일기 목록
				cout << "일기목록";
				cout << "현재 사용이 불가능합니다 불편함을 드려서 죄송합니다.";
				/*sdf.WatchDiary();*/
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isSearchDiary) { // 일기 검색
				sdf.Search();
				isSearchDiary = TRUE;
			}
			break;
		case 3:
			if (!isEditDiary) { // 일기 수정
				sdf.EditDiary();
				isEditDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) { // 메인 돌아가기
				system("cls");
				main.printMain();
			}
		default:
			if (!chk) {
				system("cls");
				main.printMain();
			}
			break;
		}

		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			menu.MovePosition(45, 15);
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
	}



};

