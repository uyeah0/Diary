#include "Main.h"

void Main::printMain() {
	Menu menu = Menu(50, 1);
	
	WriteDiary writediary;
	SearchDiary searchdiary;
	bool isRun = TRUE;
	bool isPrintHelp = FALSE;
	bool isWriteDiary = FALSE;
	bool isSearchDiary = FALSE;
	bool isTrue = FALSE;

	menu.PrintMenu();
	menu.RecieveMenu(); // �޴� �Է¹ޱ�
	


	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu(); // �Է� �޴� ��������
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
				searchdiary.ListDiary();
				isSearchDiary = TRUE;
			}
			break;
		case 3://����
			isRun = FALSE;
			break;
		case 4://����
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
			cout << "���α׷��� �����մϴ�." << endl;
			exit(0);
		}
	}
}


int main() {
	
	system("cls");
	Main main = Main();
	main.printMain();
	return 0;
}