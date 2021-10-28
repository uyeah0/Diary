#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define MENU_WRITE_DIARY 1
#define MENU_READ_DIARY 2
#define MENU_EXIT 3

class Menu {
private:
	int selectedMenu;	//선택한 메뉴 저장

public:
	Menu(int x, int y); //생성자
	Menu();
	void MovePosition(int x, int y);
	void PrintMenu(); // 기본메뉴 출력
	// void LPrintMenu(); // 기능 출력

	int GetSelectedMenu(); // 메뉴 선택
	void FPrintMenu(); // 기본 메뉴 
	void RecieveMenu(); // 메뉴 입력 받기
	int FGetSelectedMenu(); // 메뉴 값 받기
	void FRecieveMenu(); // selectMenu 입력 받기

};