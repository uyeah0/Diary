#include "WriteDiary.h"

void WriteDiary::Write() {

	Main main = Main();
	Menu menu = Menu();
	
	
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
	MYSQL_ROW sql_row; // row ����Ŵ

	int query_stat;

	system("cls");
	char date[10] = {'\0', };
	char weather[22] = { '\0', };
	char title[62] = { '\0', };
	char body[255] = { '\0', };
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

	menu.MovePosition(5, 1);
	cout << "��¥(yyyymmdd) : ";

	menu.MovePosition(80, 1);
	cout << "���� : ";

	menu.MovePosition(5, 5);
	cout << "���� (30���̳�) : ";

	menu.MovePosition(5, 9);
	cout << "���� : " << endl;

	menu.MovePosition(23, 1);
	while (fgets(date, 10, stdin) != NULL) {
		if (strlen(date) > 8)
			break;
	}
	CHOP(date);

	menu.MovePosition(87, 1);
	while (fgets(weather, 22, stdin) != NULL) {
		if (strlen(weather) > 0)
			break;
	}
	CHOP(weather);

	menu.MovePosition(23, 5);
	fgets(title, 60, stdin);
	CHOP(title);

	
	menu.MovePosition(5, 11);
	fgets(body, 255, stdin);
	CHOP(body);

	sprintf(query, "insert into diary(DATE, WEATHER, TITLE, BODY) values " "( '%s', '%s', '%s', '%s')", date, weather, title, body);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}


	mysql_close(connection);
	cout << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "------------------------�ϱ� ���� �Ϸ�----------------------- " << endl;	
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	char ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
