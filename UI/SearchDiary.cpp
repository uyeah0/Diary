#include "SearchDiary.h"

void SearchDiary::ListDiary() { // �ϱ� �����ֱ�
	system("cls");
	Main main = Main();
	Menu menu = Menu();


	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
	MYSQL_ROW sql_row; // row ����Ŵ

	int query_stat;


	mysql_init(&conn);
	// ���� ����
	connection = mysql_real_connect(&conn, "localhost", "root", "mirim", "diarydb", 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// �ѱ� ���

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// ������ ��ȸ

	query_stat = mysql_query(connection, "select * from user_tb");

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	sql_result = mysql_store_result(connection);

	menu.MovePosition(0, 20);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
	}

	mysql_close(connection);


	SearchDiary searchdiary;

	searchdiary.Search();
	searchdiary.SelectMenu();
	/*cout << endl;
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;

	char ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}*/
};

void SearchDiary::SelectMenu() { // �޴� ����?
	Menu menu = Menu(60, 0);
	Main main = Main();

	

};
void SearchDiary::Search() { // �ϱ� �˻�

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
	MYSQL_ROW sql_row; // row ����Ŵ

	int query_stat;


	mysql_init(&conn);
	// ���� ����
	connection = mysql_real_connect(&conn, "localhost", "root", "mirim", "diarydb", 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// �ѱ� ���

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	Menu menu = Menu(0,0);
	cout << "�˻� : ";
	//char* s;
	string input;
	cin >> input;
	//s1 = stoi(s);

	if (input.substr(0, 1) == "2") {//��¥
	//if (s[0] == '2') {
		string a = "select * from user_tb where date like '";
		a.append(a);
		a.append("'");
		cout << "a : " << a << endl;
		//const char s1[40];
		//s1 = "select * from user_tb where date like '";
		a += input;
		//��ȸ
		const char* pStr = a.c_str();
		

		query_stat = mysql_query(connection, pStr);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		//menu.MovePosition(0, 3);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		mysql_close(connection);
	}
	else { // ����

	}

};
