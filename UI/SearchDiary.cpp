#include "SearchDiary.h"

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

	menu.MovePosition(0, 20);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
	}

	mysql_close(connection);


	SearchDiary searchdiary;

	searchdiary.Search();
	searchdiary.SelectMenu();
	/*cout << endl;
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;

	char ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}*/
};

void SearchDiary::SelectMenu() { // 메뉴 고르기?
	Menu menu = Menu(60, 0);
	Main main = Main();

	

};
void SearchDiary::Search() { // 일기 검색

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

	Menu menu = Menu(0,0);
	cout << "검색 : ";
	//char* s;
	string input;
	cin >> input;
	//s1 = stoi(s);

	if (input.substr(0, 1) == "2") {//날짜
	//if (s[0] == '2') {
		string a = "select * from user_tb where date like '";
		a.append(a);
		a.append("'");
		cout << "a : " << a << endl;
		//const char s1[40];
		//s1 = "select * from user_tb where date like '";
		a += input;
		//조회
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
	else { // 제목

	}

};
