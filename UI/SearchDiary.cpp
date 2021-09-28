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

	menu.MovePosition(1, 5);
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

	Menu menu = Menu();
	cout << "�˻�(��¥�� ���� �Է�) : ";
	string input;
	cin >> input;

	if (input.substr(0, 1) == "2") {// ��¥�� ��� 
		string date = "select * from user_tb where date like '";
		date.append(input);
		date.append("'");
		cout << "date : " << date << endl;
		//��ȸ
		const char* pDate = date.c_str();
		

		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) { 
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		//menu.MovePosition(0, 3);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		mysql_close(connection);
	}
	else { // ������ ���
		string title = "select * from user_tb where title like '";
		title.append(input);
		title.append("'");
		cout << "title : " << title << endl;

		const char* pTitle = title.c_str();

		query_stat = mysql_query(connection, pTitle);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		//menu.MovePosition(0, 3);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		mysql_close(connection);
	}


};
