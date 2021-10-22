#include "SearchDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

void SearchDiary_func::WatchDiary() {
	Menu menu = Menu();
	SearchDiary searchdiary = SearchDiary();
	bool isSearch = FALSE;
	string input;

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

	system("cls");
	menu.MovePosition(20, 3);
	searchdiary.ListDiary();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	menu.MovePosition(60, 3);
	cout << "�ۼ��� �ϱ⸦ ���ϴ�." << endl;
	menu.MovePosition(60, 5);
	cout << "���� ���� �ϱ��� �����̳� ��¥�� �˻����ּ���.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	menu.MovePosition(60, 7);
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

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(5, 1);
			cout << "��¥(yyyymmdd) : " << sql_row[1];

			menu.MovePosition(80, 1);
			cout << "���� : " << sql_row[2];

			menu.MovePosition(5, 5);
			cout << "���� (30���̳�) : " << sql_row[3];

			menu.MovePosition(5, 9);
			cout << "���� : " << endl;
			menu.MovePosition(5, 11);
			cout << sql_row[4];

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 5);
			cout << "�������� ���ư����� �ƹ� Ű�� ��������.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}

		if (!isSearch) {
			system("cls");
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�ϱⰡ �������� �ʽ��ϴ�!";
			menu.MovePosition(20, 7);
			cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";

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
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(5, 1);
			cout << "��¥(yyyymmdd) : " << sql_row[1];

			menu.MovePosition(80, 1);
			cout << "���� : " << sql_row[2];

			menu.MovePosition(5, 5);
			cout << "���� (30���̳�) : " << sql_row[3];

			menu.MovePosition(5, 9);
			cout << "���� : ";
			menu.MovePosition(5, 11);
			cout << sql_row[4];

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 5);
			cout << "�������� ���ư����� �ƹ� Ű�� ��������.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}

		if (!isSearch) {
			system("cls");
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�ϱⰡ �������� �ʽ��ϴ�!";
			menu.MovePosition(20, 7);
			cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}


		mysql_close(connection);
	}




}

void SearchDiary_func::EditDiary() {
	system("cls");
	SearchDiary searchdiary = SearchDiary();
	Menu menu = Menu();
	Main main = Main();
	int choose;
	bool isSearch = FALSE;
	string input;

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
	MYSQL_ROW sql_row; // row ����Ŵ
	int query_stat;

	char dateE[10] = { '\0', };
	char weatherE[22] = { '\0', };
	char titleE[62] = { '\0', }; //  �ٲ� ����
	char bodyE[255] = { '\0', };
	char query[255] = { '\0', };

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

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
	menu.MovePosition(30, 2);
	cout << "[����] ������ ������ ������ϴ�." << endl;
	menu.MovePosition(30, 4);
	cout << "�׷��� �����Ͻ÷��� 1, �������� �ǵ��ư����� 0�� �Է��ϼ���=> ";
	cin >> choose;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //���
	switch (choose)
	{
	case 1: {
		menu.MovePosition(30, 6);
		cout << "�����Ϸ��� �ϱ� �����̳� ��¥�� �Է����ּ���." << endl;

		menu.MovePosition(30, 8);
		cout << "=>";
		menu.MovePosition(33, 8);
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
			char* snoE = 0;
			int snoED;
			
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ���
				isSearch = TRUE;
				snoED = atoi(sql_row[0]); // �Ϸù�ȣ, ���ڿ��� ����Ÿ������ �ٲٴ� atoi�Լ� ���
			}
			
			if (!isSearch) {
				//system("cls");
				menu.MovePosition(20, 5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "�ϱⰡ �������� �ʽ��ϴ�!";
				menu.MovePosition(20, 7);
				cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";

				char ch = _getch();
				if (ch != 0) {
					system("cls");
					searchdiary.SelectMenu();
				}
			}
			else {
				// ������ ����
				query_stat = mysql_query(connection, pDate);

				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}

				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
					menu.MovePosition(5, 1);
					cout << "��¥(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 1);
					cout << "���� : " << sql_row[2];

					menu.MovePosition(5, 5);
					cout << "���� (30���̳�) : " << sql_row[3];

					menu.MovePosition(5, 9);
					cout << "���� : " << endl;
					menu.MovePosition(5, 11);
					cout << sql_row[4];
				}
				menu.MovePosition(22, 1);
				while (fgets(dateE, 10, stdin) != NULL) { 
					if (strlen(dateE) > 8)
						break;
				}
				CHOP(dateE);

				menu.MovePosition(87, 1);
				while (fgets(weatherE, 22, stdin) != NULL) {
					if (strlen(weatherE) > 0)
						break;
				}
				CHOP(weatherE);

				menu.MovePosition(23, 5);
				fgets(titleE, 60, stdin);
				CHOP(titleE);


				menu.MovePosition(5, 11);
				fgets(bodyE, 255, stdin);
				CHOP(bodyE);

				sprintf(query, "update diary set DATE = '%s', WEATHER = '%s', TITLE = '%s', BODY = '%s' where sno = %d", dateE, weatherE, titleE, bodyE, snoED);
				cout << query << endl;

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

				mysql_close(connection);
			}

			
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
			char* snoE = 0;
			int snoED;

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ���
				isSearch = TRUE;
				snoED = atoi(sql_row[0]); // �Ϸù�ȣ, ���ڿ��� ����Ÿ������ �ٲٴ� atoi�Լ� ���
			}

			if (!isSearch) {
				//system("cls");
				menu.MovePosition(20, 5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "�ϱⰡ �������� �ʽ��ϴ�!";
				menu.MovePosition(20, 7);
				cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�.";

				char ch = _getch();
				if (ch != 0) {
					system("cls");
					searchdiary.SelectMenu();
				}
			}
			else {
				// ������ ����
				query_stat = mysql_query(connection, pTitle);

				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}

				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
					menu.MovePosition(5, 1);
					cout << "��¥(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 1);
					cout << "���� : " << sql_row[2];

					menu.MovePosition(5, 5);
					cout << "���� (30���̳�) : " << sql_row[3];

					menu.MovePosition(5, 9);
					cout << "���� : " << endl;
					menu.MovePosition(5, 11);
					cout << sql_row[4];
				}
				menu.MovePosition(22, 1);
				while (fgets(dateE, 10, stdin) != NULL) {
					if (strlen(dateE) > 8)
						break;
				}
				CHOP(dateE);

				menu.MovePosition(87, 1);
				while (fgets(weatherE, 22, stdin) != NULL) {
					if (strlen(weatherE) > 0)
						break;
				}
				CHOP(weatherE);

				menu.MovePosition(23, 5);
				fgets(titleE, 60, stdin);
				CHOP(titleE);


				menu.MovePosition(5, 11);
				fgets(bodyE, 255, stdin);
				CHOP(bodyE);

				sprintf(query, "update diary set DATE = '%s', WEATHER = '%s', TITLE = '%s', BODY = '%s' where sno = %d", dateE, weatherE, titleE, bodyE, snoED);
				cout << query << endl;

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

				mysql_close(connection);
			}
		}

		break;
	}
	case 0: {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n�ǵ��ư��ϴ�." << endl;
		searchdiary.SelectMenu();
		break;
	}
	default:
		break;
	} 
	
	// 
}

void SearchDiary_func::DeleteDiary() {
	system("cls");
	SearchDiary searchDiary = SearchDiary();
	Menu menu = Menu();
	bool isSearch = FALSE;
	string input;

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


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
	menu.MovePosition(30, 2);
	cout << "[����] ���� ������ �Ұ����մϴ�." << endl;
	menu.MovePosition(30, 4);
	cout << "�׷��� �����Ͻ÷��� 1, �������� �ǵ��ư����� 0�� �Է��ϼ���=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //���
	/*�����Ҳ��� �ƴ���*/



	searchDiary.Search(); // �˻�


	system("cls");
	menu.MovePosition(20, 3);
	cout << "�˻�(��¥�� ���� �Է�) : ";
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
		menu.MovePosition(20, 3);
		cout << "[�˻� ���]" << endl;
		int x = 1, y = 3;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		if (!isSearch) {
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�ϱⰡ �������� �ʽ��ϴ�!";
			menu.MovePosition(20, 7);
			cout << "�ϱ� ������� ���ư����� �ƹ� Ű�� ��������.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				//searchdiary.SelectMenu();
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
		menu.MovePosition(1, 1);
		cout << "[�˻� ���]" << endl;
		int x = 1, y = 5;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}



		mysql_close(connection);
	}

}


void DiaryPrint() {

}