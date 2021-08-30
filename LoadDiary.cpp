#include "LoadDiary.h"

void LoadDiary::SelectMenu() {
	Menu menu = Menu(60, 0);
	Main main = Main();
	LoadDiary_func ldf = LoadDiary_func();
	menu.LPrintMenu();
}