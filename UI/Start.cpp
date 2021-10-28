#include "Start.h"

void Start::printStart() {
	system("mode con:cols=120 lines=28");
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



	menu.MovePosition(54, 19);
	cout << "시작하기";
	menu.MovePosition(52, 21);
	cout << "비밀번호 설정";
	menu.MovePosition(54, 23);
	cout << "종료하기";


}





int main() {
	system("cls");
	/*Start start = Start();
	start.printStart();*/

	Main main = Main();
	main.printMain();
	return 0;
}