#include "Start.h"

void Start::printStart() {
	system("mode con:cols=170 lines=43");
	Menu menu = Menu();

	menu.MovePosition(20,4);
	cout << "   ___                                      _     ";
	menu.MovePosition(20, 5);
	cout << "  / __|    ___     __       _ _    ___     | |_   ";
	menu.MovePosition(20, 6);
	cout << "  \\__ \\   / -_)   / _|     | '_|  / -_)    |  _|  ";
	menu.MovePosition(20, 7);
	cout << "  |___/   \\___|   \\__|_   _|_|_   \\___|    _\\__|  ";
	menu.MovePosition(20, 8);
	cout << "_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| ";
	menu.MovePosition(20, 9);
	cout << "\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' ";
	
	

	menu.MovePosition(40, 13);
	cout << "_______                                          ";
	menu.MovePosition(40, 14);
	cout << "\\  ___ `'.   .--.                                ";
	menu.MovePosition(40, 15);
	cout << " ' |--.\\  \\  |__|                .-.          .- ";
	menu.MovePosition(40, 16);
	cout << " | |    \\  ' .--.          .-,.--.\\ \\        / / ";
	menu.MovePosition(40, 17);
	cout << " | |     |  '|  |    __    |  .-. |\\ \\      / /  ";
	menu.MovePosition(40, 18);
	cout << " | |     |  ||  | .:--.'.  | |  | | \\ \\    / /   ";
	menu.MovePosition(40, 19);
	cout << " | |     ' .'|  |/ |   \\ | | |  | |  \\ \\  / /    ";
	menu.MovePosition(40, 20);
	cout << " | |___.' /' |  |`\" __ | | | |  '-    \\ `  /     ";
	menu.MovePosition(40, 21);
	cout << "/_______.'/  |__| .'.''| | | |         \\  /      ";
	menu.MovePosition(40, 22);
	cout << "\\_______|/       / /   | |_| |         / /       ";
	menu.MovePosition(40, 23);
	cout << "                 \ \._,\ '/|_|     |`-' /        ";
	menu.MovePosition(40, 24);
	cout << "                  `--'  `\"          '..'         ";

}





int main() {
	system("cls");
	//Start start = Start();
	//start.printStart();

	Main main = Main();
	main.printMain();
	return 0;
}