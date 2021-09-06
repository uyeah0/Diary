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

void printList() {

	gotoxy(2, 1);
	string search;
	cout << "날짜 or 제목 검색 : ";
	cin >> search;

	gotoxy(2, 5);
	cout << "20211028 쌀쌀 <졸려>";

	gotoxy(2, 7);
	cout << "20211028 <시간 빠르다>";
	
	gotoxy(2, 9);
	cout << "20210715 더워 <방학>";

	gotoxy(2, 11);
	cout << "20210602 더움 <내생일>";

	gotoxy(2, 13);
	cout << "20210501 <수련회 가고싶다>";

	gotoxy(2, 15);
	cout << "20210425 바람솔솔 <c++>";

	gotoxy(2, 17);
	cout << "20210401 <곧 중간>";

	gotoxy(2, 19);
	cout << "20210301 <곧 개학>";
	cout << endl;

}


int main() {

	printList();


	return 0;
}