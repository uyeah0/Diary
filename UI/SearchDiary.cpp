#include "SearchDiary.h"

void SearchDiary::SelectMenu() { // 메뉴 고르기?
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
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
	}



};


void SearchDiary::Search() { // 일기 검색
	SearchDiary searchdiary = SearchDiary();


	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;


	mysql_init(&conn);
	// 계정 연결
	connection = mysql_real_connect(&conn, "localhost", "root", "mirim", "diarydb", 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// 한글 사용

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	Menu menu = Menu(1, 1);


	system("cls");
	menu.MovePosition(1, 1);
	cout << "검색(날짜나 제목 입력) : ";
	string input;
	cin >> input;


	if (input.substr(0, 1) == "2") {// 날짜일 경우 
		string date = "select * from user_tb where date like '";
		date.append(input);
		date.append("'");
		cout << "date : " << date << endl;
		//조회
		const char* pDate = date.c_str();
		

		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) { 
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "일기가 존재하지 않습니다!" << endl;
			cout << "일기 목록으로 돌아가려면 아무 키나 누르세요." << endl;

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.Search();
			}
		}
		else {
			//int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				//menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		}
		

		mysql_close(connection);
	}
	else { // 제목일 경우
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
			cout << "일기가 존재하지 않습니다!" << endl;
			cout << "일기 목록으로 돌아가려면 아무 키나 누르세요." << endl;

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.Search();
			}
		}
		else {
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		}


		mysql_close(connection);
	}


};

void SearchDiary::ListDiary() { // 일기 보여주기
	system("cls");
	Main main = Main();
	Menu menu = Menu();


	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;


	mysql_init(&conn);
	// 계정 연결
	connection = mysql_real_connect(&conn, "localhost", "root", "mirim", "diarydb", 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	//// 한글 사용

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// 데이터 조회

	query_stat = mysql_query(connection, "select * from user_tb");

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	sql_result = mysql_store_result(connection);

	menu.MovePosition(20, 3);
	cout << "일기 목록" << endl;

	int x = 13, y = 5;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		menu.MovePosition(x, y++);
		cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
	}

	mysql_close(connection);

	SelectMenu();
};