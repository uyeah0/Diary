#include "WriteDiary.h"

void WriteDiary::Write() {

	Main main = Main();
	Menu menu = Menu();
	
	
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
	MYSQL_ROW sql_row; // row ����Ŵ

	int query_stat;

	system("cls");
	menu.MovePosition(4, 1);
	cout << "       o �� ������ ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	menu.MovePosition(4, 2);
	cout << "��  ��������������������                                                                                    �������������������������� ��";
	menu.MovePosition(4, 3);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 4);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 5);
	cout << "��                                                                                                            �� ��";
	menu.MovePosition(4, 6);
	cout << "                                                                                                             �� ��";
	menu.MovePosition(4, 7);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 8);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 9);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 10);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 11);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 12);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 13);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4,  14);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 15);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 16);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 17);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 18);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 19);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 20);
	cout << "��                                                                                                              ��";
	menu.MovePosition(4, 21);
	cout << "�� ��                                                                                                             ";
	menu.MovePosition(4, 22);
	cout << "�� ��                                                                                                            ��";
	menu.MovePosition(4, 23);
	cout << "�� ��                                                                                                              ";
	menu.MovePosition(4, 24);
	cout << "�� ������������������������                                                                                    o �� ������������������ ";
	menu.MovePosition(4, 25);
	cout << " ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������      �� ������������������     ";
	

	char date[10] = {'\0', };
	char weather[22] = { '\0', };
	char title[62] = { '\0', };
	char body1[255] = { '\0', };
	char body2[255] = { '\0', };
	char body3[255] = { '\0', };
	char body4[255] = { '\0', };
	char body5[255] = { '\0', };
	char body6[255] = { '\0', };
	char body7[255] = { '\0', };
	char body8[255] = { '\0', };
	char body9[255] = { '\0', };
	char body10[255] = { '\0', };
	
	char query[255] = { '\0', };

	mysql_init(&conn);


	// ���� ����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// �ѱ� ���

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	menu.MovePosition(12, 5);
	//menu.MovePosition(7, 5);

	cout << "��¥(yyyymmdd) :  ";

	menu.MovePosition(80, 5);
	cout << "���� : ";

	menu.MovePosition(12, 7);
	cout << "����(30�� �̳�) : ";

	menu.MovePosition(12, 9);
	cout << "����(�ִ� 10��) : " << endl;

	menu.MovePosition(30, 5);
	while (fgets(date, 10, stdin) != NULL) {
		if (strlen(date) > 8)
			break;
	}
	CHOP(date);

	menu.MovePosition(87, 5);
	while (fgets(weather, 22, stdin) != NULL) {
		if (strlen(weather) > 0)
			break;
	}
	CHOP(weather);

	menu.MovePosition(30, 7);
	fgets(title, 60, stdin);
	CHOP(title);

	menu.MovePosition(12, 11);
	int y = 11;

	fgets(body1, 255, stdin);
	if ( strcmp(body1,"***")) {
		CHOP(body1);
		menu.MovePosition(12, ++y);
		fgets(body2, 255, stdin);
		if (strcmp(body2, "***")) {
			CHOP(body2);
			menu.MovePosition(12, ++y);
			fgets(body3, 255, stdin);
			if (strcmp(body3, "***")) {
				CHOP(body3);
				menu.MovePosition(12, ++y);
				fgets(body4, 255, stdin);
				if (strcmp(body4, "***")) {
					CHOP(body4);
					menu.MovePosition(12, ++y);
					fgets(body5, 255, stdin);
					if (strcmp(body5, "***")) {
						CHOP(body5);
						menu.MovePosition(12, ++y);
						fgets(body6, 255, stdin);
						if (strcmp(body6, "***")) {
							CHOP(body6);
							menu.MovePosition(12, ++y);
							fgets(body7, 255, stdin);
							if (strcmp(body7, "***")) {
								CHOP(body7);
								menu.MovePosition(12, ++y);
								fgets(body8, 255, stdin);
								if (strcmp(body8, "***")) {
									CHOP(body8);
									menu.MovePosition(12, ++y);
									fgets(body9, 255, stdin);
									if (strcmp(body9, "***")) {
										CHOP(body9);
										menu.MovePosition(12, ++y);
										fgets(body10, 255, stdin);
										if (strcmp(body10, "***")) {
											CHOP(body10);
											menu.MovePosition(12, ++y);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	

	/*fgets(body, 255, stdin);
	CHOP(body);*/

	sprintf(query, "insert into diary(DATE, WEATHER, TITLE, BODY1, body2, body3, body4, body5) values " "( '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')", date, weather, title, body1, body2, body3, body4, body5);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}


	mysql_close(connection);

	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	menu.MovePosition(30, 30);
	
	menu.MovePosition(30, 30);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	char ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
