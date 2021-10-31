#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define MENU_WRITE_DIARY 1
#define MENU_READ_DIARY 2
#define MENU_EXIT 3

#define UP 0
#define DOWN 1
#define SUBMIT 2

class Menu {
private:
	int selectedMenu;	//선택한 메뉴 저장

public:
	Menu(int x, int y); //생성자
	Menu();
	void MovePosition(int x, int y);

	int SPrintMenu(); // 시작 메뉴 출력 동시 입력
	
	void RecieveMenu(); // 기본 메뉴 입력 받기
	int GetSelectedMenu(); // 기본 메뉴 값 주기

	void PrintMenu(); //  기능 메뉴 출력
	void FPrintMenu(); // 상세 기능 메뉴 function print menu
	void FRecieveMenu(); // 기능 입력 받기
	int FGetSelectedMenu(); // 기능 메뉴 값 받기

	int keyControl();
	void bgDraw();
};