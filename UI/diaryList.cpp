#include <iostream>;
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD Pos; //x, y�� ������ �ִ� ����ü 
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printList() {

	gotoxy(2, 1);
	string search;
	cout << "��¥ or ���� �˻� : ";
	cin >> search;

	gotoxy(2, 5);
	cout << "20211028 �ҽ� <����>";

	gotoxy(2, 7);
	cout << "20211028 <�ð� ������>";
	
	gotoxy(2, 9);
	cout << "20210715 ���� <����>";

	gotoxy(2, 11);
	cout << "20210602 ���� <������>";

	gotoxy(2, 13);
	cout << "20210501 <����ȸ ����ʹ�>";

	gotoxy(2, 15);
	cout << "20210425 �ٶ��ּ� <c++>";

	gotoxy(2, 17);
	cout << "20210401 <�� �߰�>";

	gotoxy(2, 19);
	cout << "20210301 <�� ����>";
	cout << endl;

}


int main() {

	printList();


	return 0;
}