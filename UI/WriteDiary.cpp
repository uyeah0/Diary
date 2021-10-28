#include "WriteDiary.h"

void WriteDiary::Write() {

	Main main = Main();
	Menu menu = Menu();
	
	
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;


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


	// 계정 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// 한글 사용

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");
	
	system("cls");
	main.printBorder();
	menu.MovePosition(12, 5);
	cout << "날짜(yyyymmdd) :  ";

	menu.MovePosition(80, 5);
	cout << "날씨 : ";

	menu.MovePosition(12, 7);
	cout << "제목(30자 이내) : ";

	menu.MovePosition(12, 9);
	cout << "내용(최대 10줄) : " << endl;

	menu.MovePosition(30, 5); // 날짜 입력
	while (fgets(date, 10, stdin) != NULL) {
		if (strlen(date) > 8)
			break;
	}
	CHOP(date);

	menu.MovePosition(87, 5); // 날씨 입력
	while (fgets(weather, 22, stdin) != NULL) {
		if (strlen(weather) > 0)
			break;
	}
	CHOP(weather);

	menu.MovePosition(30, 7); // 제목 입력
	fgets(title, 60, stdin);
	CHOP(title);

	menu.MovePosition(12, 11); // body 입력
	int y = 11;

	fgets(body1, 253, stdin);
	if (body1[0] != '*' && body1[1] != '*' && body1[2] != '*') {
		CHOP(body1);
		menu.MovePosition(12, ++y);
		fgets(body2, 253, stdin);
		if (body2[0] != '*' && body2[1] != '*' && body2[2] != '*') {
			CHOP(body2);
			menu.MovePosition(12, ++y);
			fgets(body3, 253, stdin);
			if (body3[0] != '*' && body3[1] != '*' && body3[2] != '*') {
				CHOP(body3);
				menu.MovePosition(12, ++y);
				fgets(body4, 253, stdin);
				if (body4[0] != '*' && body4[1] != '*' && body4[2] != '*') {
					CHOP(body4);
					menu.MovePosition(12, ++y);
					fgets(body5, 253, stdin);
					if (body5[0] != '*' && body5[1] != '*' && body5[2] != '*') {
						CHOP(body5);
						menu.MovePosition(12, ++y);
						fgets(body6, 253, stdin);
						if (body6[0] != '*' && body6[1] != '*' && body6[2] != '*') {
							CHOP(body6);
							menu.MovePosition(12, ++y);
							fgets(body7, 253, stdin);
							if (body7[0] != '*' && body7[1] != '*' && body7[2] != '*') {
								CHOP(body7);
								menu.MovePosition(12, ++y);
								fgets(body8, 253, stdin);
								if (body8[0] != '*' && body8[1] != '*' && body8[2] != '*') {
									CHOP(body8);
									menu.MovePosition(12, ++y);
									fgets(body9, 253, stdin);
									if (body9[0] != '*' && body9[1] != '*' && body9[2] != '*') {
										CHOP(body9);
										menu.MovePosition(12, ++y);
										fgets(body10, 253, stdin);
										if (body10[0] != '*' && body10[1] != '*' && body10[2] != '*') {
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
	
	sprintf(query, "insert into diary(DATE, WEATHER, TITLE, BODY1, body2, body3, body4, body5, BODY6, body7, body8, body9, body10) values " "( '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s','%s','%s', '%s','%s','%s')", date, weather, title, body1, body2, body3, body4, body5,body6, body7, body8, body9, body10);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}


	mysql_close(connection);

	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	menu.MovePosition(32, 12);
	cout << "() ()						(\\ /)";
	menu.MovePosition(32, 13);
	cout << "( '.' )						( . .)♥";
	menu.MovePosition(50, 13);
	cout << "일 기 저 장 완 료";
	menu.MovePosition(32, 14);
	cout << "(\")_(\")						c(”)(”)";

	
	menu.MovePosition(37, 16);
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요";
	char ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
