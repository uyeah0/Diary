#include "SearchDiary.h"

void SearchDiary::SelectMenu() { // �޴� ����
	system("cls");
	Menu menu = Menu();
	Main main = Main();
	SearchDiary_func sdf = SearchDiary_func();

	menu.FPrintMenu();
	menu.FRecieveMenu();

	

	bool isRun = TRUE;
	bool isWatchDiary = FALSE;
	bool isEditDiary = FALSE;
	bool isDeleteDiary = FALSE;
	bool isBackToMain = FALSE;
	
	main.printBorder();

	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWatchDiary) {
				sdf.WatchDiary();
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isEditDiary) {
				sdf.EditDiary();
				isEditDiary = TRUE;
			}
			break;
		case 3:
			if (!isDeleteDiary) {
				sdf.DeleteDiary();
				isDeleteDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) {
				system("cls");
				main.printMain();
			}
		default:
			/*if (!chk) {
				system("cls");
				main.printMain();
			}*/
			break;
		}

		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			menu.MovePosition(45, 15);
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
	}



};


void SearchDiary::Search() { // �ϱ� �˻�
	SearchDiary searchdiary = SearchDiary();
	bool isSearch = FALSE;

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


//	menu.MovePosition(20, 3);

	string input;
	cin >> input;


	if (input.substr(0, 1) == "2") {// ��¥�� ��� 
		string date = "select * from diary where date like '%";
		date.append(input);
		date.append("%'");
		//��ȸ
		const char* pDate = date.c_str();
		

		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) { 
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		system("cls");
		int x = 17, y = 7;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		if (!isSearch) {
			system("cls");
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "�ϱⰡ �������� �ʽ��ϴ�!";
			menu.MovePosition(20, 7);
			cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}

		mysql_close(connection);
	}
	else { // ������ ���
		string title = "select * from diary where title like '";
		title.append(input);
		title.append("'");

		const char* pTitle = title.c_str();

		query_stat = mysql_query(connection, pTitle);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		system("cls");
		int x = 17, y = 7;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}
		
		if (!isSearch) {
			system("cls");
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "�ϱⰡ �������� �ʽ��ϴ�!";
			menu.MovePosition(20, 7);
			cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}


		mysql_close(connection);
	}


};

void SearchDiary::ListDiary() { // �ϱ� �����ֱ�
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
	
	/*query_stat = mysql_query(connection, "select * from diary");

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	sql_result = mysql_store_result(connection);

	
	menu.MovePosition(1, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << "��������������������������[�ϱ� ���]��������������������������" << endl;
	int x = 10, y = 5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		menu.MovePosition(x, y++);
		y++;
		cout <<sql_row[1] << "\t" << "\t" << "<" << sql_row[3] << ">" <<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << "��������������������������������������������������������������������������" << endl;

	mysql_close(connection);*/

};