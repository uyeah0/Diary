#include "SearchDiary.h"

void SearchDiary::SelectMenu() { // �޴� ����
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
			if (!isWatchDiary) { // �ϱ� ���
				cout << "�ϱ���";
				cout << "���� ����� �Ұ����մϴ� �������� ����� �˼��մϴ�.";
				/*sdf.WatchDiary();*/
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isSearchDiary) { // �ϱ� �˻�
				sdf.Search();
				isSearchDiary = TRUE;
			}
			break;
		case 3:
			if (!isEditDiary) { // �ϱ� ����
				sdf.EditDiary();
				isEditDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) { // ���� ���ư���
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
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
	}



};

