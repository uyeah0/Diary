#include <iostream>;
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD Pos; //x, y를 가지고 있는 구조체 
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	gotoxy(2, 1);
	string date;
	cout << "날짜(xxxx.xx.xx) : ";
	cin >> date;
	
	gotoxy(50, 1);
	string wheater;
	cout << "날씨 : ";
	cin >> wheater;

	
	gotoxy(2, 3);
	string title;
	cout << "제목 (30자이내) : ";
	cin >> title;

	gotoxy(50, 3);
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요.";

	gotoxy(2, 5);
	string body;
	cout << "내용 : ( enter 누른 후 '***' 입력 시 저장)";
	gotoxy(2, 6);

	return 0;
}