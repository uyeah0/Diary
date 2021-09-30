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
				searchdiary.ListDiary();
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


int main() {
	
	system("cls");
	Main main = Main();
	main.printMain();
	return 0;
}