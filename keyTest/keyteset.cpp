#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int keyControl();
void MovePosition(int, int);

int printMenu() {
	MovePosition(4, 1);
	cout << "       o �� ������ ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	MovePosition(4, 2);
	cout << "��  ��������������������                                                                                    �������������������������� ��";
	MovePosition(4, 3);
	cout << "                                                                                                             �� ��";
	MovePosition(4, 4);
	cout << "                                                                                                             �� ��";
	MovePosition(4, 5);
	cout << "��                                                                                                            �� ��";
	MovePosition(4, 6);
	cout << "                                                                                                             �� ��";
	MovePosition(4, 7);
	cout << "��                                                                                                              ��";
	MovePosition(4, 8);
	cout << "��                                                                                                              ��";
	MovePosition(4, 9);
	cout << "��                                                                                                              ��";
	MovePosition(4, 10);
	cout << "��                                                                                                              ��";
	MovePosition(4, 11);
	cout << "��                                                                                                              ��";
	MovePosition(4, 12);
	cout << "��                                                                                                              ��";
	MovePosition(4, 13);
	cout << "��                                                                                                              ��";
	MovePosition(4, 14);
	cout << "��                                                                                                              ��";
	MovePosition(4, 15);
	cout << "��                                                                                                              ��";
	MovePosition(4, 16);
	cout << "��                                                                                                              ��";
	MovePosition(4, 17);
	cout << "��                                                                                                              ��";
	MovePosition(4, 18);
	cout << "��                                                                                                              ��";
	MovePosition(4, 19);
	cout << "��                                                                                                              ��";
	MovePosition(4, 20);
	cout << "��                                                                                                              ��";
	MovePosition(4, 21);
	cout << "�� ��                                                                                                             ";
	MovePosition(4, 22);
	cout << "�� ��                                                                                                            ��";
	MovePosition(4, 23);
	cout << "�� ��                                                                                                              ";
	MovePosition(4, 24);
	cout << "�� ������������������������                                                                                    o �� ������������������ ";
	MovePosition(4, 25);
	cout << " ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������      �� ������������������     ";


	MovePosition(35, 4);
	cout << "                         _   ";
	MovePosition(35, 5);
	cout << "  ___  ___  ___ _ __ ___| |_ ";
	MovePosition(35, 6);
	cout << " / __|/ _ \\/ __| '__/ _ \\ __|";
	MovePosition(35, 7);
	cout << " \\__ \\  __/ (__| | |  __/ |_ ";
	MovePosition(35, 8);
	cout << " |___/\\___|\\___|_|  \\___|\\__|";



	MovePosition(43, 9);
	cout << " ___    ____   ____  ____   __ __ ";
	MovePosition(43, 10);
	cout << "|   \\  |    | /    ||    \\ |  |  |";
	MovePosition(43, 11);
	cout << "|    \\  |  | |  o  ||  D  )|  |  |";
	MovePosition(43, 12);
	cout << "|  D  | |  | |     ||    / |  ~  |";
	MovePosition(43, 13);
	cout << "|     | |  | |  _  ||    \\ |___, |";
	MovePosition(43, 14);
	cout << "|     | |  | |  |  ||  .  \\|     |";
	MovePosition(43, 15);
	cout << "|_____||____||__|__||__|\\_||____/ ";
	
	int x = 51;
	//int x1 = 51;
	int y = 19;

	MovePosition(x-4, y); // �� 54, >�� ����ؾ��ϱ� ������ -2
	cout << ">     �� �� �� ��";
	MovePosition(x, y+2); // 51
	cout << "�� �� �� ȣ �� ��";
	MovePosition(x, y+4);
	cout << "  �� �� �� ��";

	while (1) {
		//int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
		int n=1;
		switch (n)
		{
			case UP: { // �Էµ� ���� UP�� ���
				if (y > 19) {
					MovePosition(x - 4, y);
					cout << " ";
					y -= 2;
					MovePosition(x - 4, y);
					cout << ">";
				}
				break;
			}
			case DOWN: {
				if (y < 23) {
					MovePosition(x - 4, y);
					cout << " ";
					y += 2;
					MovePosition(x - 4, y);
					cout << ">";
				}
			}
			/*case SUBMIT: {
				return y - 19;
			}*/
		}
	}

}


int main() {
	system("mode con:cols=120 lines=28");
	//printMenu();
	int keyCode = keyControl();
	cout << "�Է��� Ű ���� : " << keyCode << "�Դϴ�" << endl;
	//keyControl();
}

int keyControl() {
	char c;
	while (1) {
		if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
			c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
			if (c == -32) {
				c = _getch();
				switch (c)
				{
				case 75:
					printf("�·� �̵�\n");
					return LEFT;
				case 77:
					printf("��� �̵�\n");
					return RIGHT;
				case 72:
					printf("���� �̵�\n");
					return UP;
				case 80:
					printf("�Ʒ��� �̵�\n");
					return DOWN;
				case 32:
					return SUBMIT;
				}

				//}
				//if (c == 75) {
				//	//return LEFT;
				//}
				//else if (c == 77) {
				//	//return RIGHT;
				//}
				//else if (c == 72) {
				//	//return UP;
				//}
				//else if (c == 80) {
				//	//return DOWN;
				//}
				//else if (c == ' ') {
				//	//return SUBMIT;
				//	break;
				//}
			}
		}
	}
}
void MovePosition(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

//void keyControl() {
//	char c;
//
//	while (1) {
//		if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
//			c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�. 
//            if (c == -32) {           // 4. -32�� �ԷµǸ�
//                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���
//                switch (c) {
//                case LEFT:
//                    printf("�·� �̵�\n");
//                    break;
//                case RIGHT:
//                    printf("��� �̵�\n");
//                    break;
//                case UP:
//                    printf("���� �̵�\n");
//                    break;
//                case DOWN:
//                    printf("�Ʒ��� �̵�\n");
//                    break;
//                }
//            }
//		}
//	}
//
//}