#include "Start.h"

void Start::printStart() {
	system("mode con:cols=120 lines=28");
	Menu menu = Menu();

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

	menu.MovePosition(20, 2);
	cout << "                         _   ";
	menu.MovePosition(20, 3);
	cout << "  ___  ___  ___ _ __ ___| |_ ";
	menu.MovePosition(20, 4);
	cout << " / __|/ _ \\/ __| '__/ _ \\ __|";
	menu.MovePosition(20, 5);
	cout << " \\__ \\  __/ (__| | |  __/ |_ ";
	menu.MovePosition(20, 6);
	cout << " |___/\\___|\\___|_|  \\___|\\__|";


	menu.MovePosition(27, 7);
	cout << " ______     .-./`)    ____    .-------.       ____     __  ";
	menu.MovePosition(27, 8);
	cout << "|    _ `\'\'. \\ .-.\') .\'  __ `. |  _ _   \\      \\   \\   /  / ";
	menu.MovePosition(27, 9);
	cout << "| _ | ) _  \\/ `-\' \\/   \'  \\  \\| ( \' )  |       \\  _. /  \'  ";
	menu.MovePosition(27, 10);
	cout << "|( \'\'_\'  ) | `-\'`\"`|___|  /  ||(_ o _) /        _( )_ .\'  ";
	menu.MovePosition(27, 11);
	cout << "| . (_) `. | .---.    _.-`   || (_,_).\' __  ___(_ o _)\'    ";
	menu.MovePosition(27, 12);
	cout << "|(_    ._) \' |   | .\'   _    ||  |\\ \\  |  ||   |(_,_)\'     ";
	menu.MovePosition(27, 13);
	cout << "|  (_.\\.\' /  |   | |  _( )_  ||  | \\ `\'   /|   `-\'  /      ";
	menu.MovePosition(27, 14);
	cout << "|       .\'   |   | \\ (_ o _) /|  |  \\    /  \\      /       ";
	menu.MovePosition(27, 15);
	cout << "\'-----\'`     \'---\'  \'.(_,_).\' \'\'-\'   `\'-\'    `-..-\'        ";
	
	
	menu.MovePosition(27, 18);
	cout << "START";
	menu.MovePosition(35, 18);
	cout << "SET-PASSWORD";
	menu.MovePosition(50, 18);
	cout << "END";
	
}





int main() {
	system("cls");
	/*Start start = Start();
	start.printStart();*/

	Main main = Main();
	main.printMain();
	return 0;
}