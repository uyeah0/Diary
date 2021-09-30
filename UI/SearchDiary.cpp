#include "SearchDiary.h"

void SearchDiary::SelectMenu() { // �޴� ����?
	Menu menu = Menu();
	Main main = Main();
	SearchDiary_func ldf = SearchDiary_func();

	menu.SPrintMenu();
	menu.SRecieveMenu();

	bool isRun = TRUE;
	bool isWatchDiary = FALSE;
	bool isEditDiary = FALSE;
	bool isDeleteDiary = FALSE;
	bool isBackToMain = FALSE;
	
	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWatchDiary) {
				ldf.WatchDiary();
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isEditDiary) {
				ldf.ModifyDiary();
				isEditDiary = TRUE;
			}
			break;
		case 3:
			if (!isDeleteDiary) {
				ldf.DeleteDiary();
				isDeleteDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) {
				system("cls");
				main.printMain();
			}
		default:
			if (!chk) {
				system("cls");
				main.printMain();
			}
			break;
		}

		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			menu.MovePosition(45, 15);
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
	}



};


void SearchDiary::Search() { // �ϱ� �˻�
	SearchDiary searchdiary = SearchDiary();


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

	Menu menu = Menu(1, 1);


	system("cls");
	menu.MovePosition(1, 1);
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

		system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
			cout << "�ϱ� ������� ���ư����� �ƹ� Ű�� ��������." << endl;

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.Search();
			}
		}
		else {
			//int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
				//menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
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

		system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
			cout << "�ϱ� ������� ���ư����� �ƹ� Ű�� ��������." << endl;

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.Search();
			}
		}
		else {
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
				menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		}


		mysql_close(connection);
	}


};

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

	menu.MovePosition(20, 3);
	cout << "�ϱ� ���" << endl;

	int x = 13, y = 5;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		menu.MovePosition(x, y++);
		cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
	}

	mysql_close(connection);

	SelectMenu();
};