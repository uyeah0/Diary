#include "SearchDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

void SearchDiary_func::WatchDiary() {
	Menu menu = Menu();
	SearchDiary searchdiary = SearchDiary();
	bool isSearch = FALSE;
	string input;

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

	system("cls");
	menu.MovePosition(20, 3);
	searchdiary.ListDiary();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	menu.MovePosition(60, 3);
	cout << "작성한 일기를 봅니다." << endl;
	menu.MovePosition(60, 5);
	cout << "보고 싶은 일기의 제목이나 날짜를 검색해주세요.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	menu.MovePosition(60, 7);
	cin >> input;


	if (input.substr(0, 1) == "2") {// 날짜일 경우 
		string date = "select * from diary where date like '%";
		date.append(input);
		date.append("%'");
		//조회
		const char* pDate = date.c_str();


		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);
		system("cls");

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
			isSearch = TRUE;
			menu.MovePosition(5, 1);
			cout << "날짜(yyyymmdd) : " << sql_row[1];

			menu.MovePosition(80, 1);
			cout << "날씨 : " << sql_row[2];

			menu.MovePosition(5, 5);
			cout << "제목 (30자이내) : " << sql_row[3];

			menu.MovePosition(5, 9);
			cout << "내용 : " << endl;
			menu.MovePosition(5, 11);
			cout << sql_row[4];

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 5);
			cout << "이전으로 돌아가려면 아무 키나 누르세요.";

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
			cout << "일기가 존재하지 않습니다!";
			menu.MovePosition(20, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}


		mysql_close(connection);
	}
	else { // 제목일 경우
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
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
			isSearch = TRUE;
			menu.MovePosition(5, 1);
			cout << "날짜(yyyymmdd) : " << sql_row[1];

			menu.MovePosition(80, 1);
			cout << "날씨 : " << sql_row[2];

			menu.MovePosition(5, 5);
			cout << "제목 (30자이내) : " << sql_row[3];

			menu.MovePosition(5, 9);
			cout << "내용 : ";
			menu.MovePosition(5, 11);
			cout << sql_row[4];

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 5);
			cout << "이전으로 돌아가려면 아무 키나 누르세요.";

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
			cout << "일기가 존재하지 않습니다!";
			menu.MovePosition(20, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";

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
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴
	int query_stat;

	char dateE[10] = { '\0', };
	char weatherE[22] = { '\0', };
	char titleE[62] = { '\0', }; //  바뀐 제목
	char bodyE[255] = { '\0', };
	char query[255] = { '\0', };

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

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨간색
	menu.MovePosition(30, 2);
	cout << "[주의] 이전의 내용은 사라집니다." << endl;
	menu.MovePosition(30, 4);
	cout << "그래도 진행하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
	cin >> choose;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //흰색
	switch (choose)
	{
	case 1: {
		menu.MovePosition(30, 6);
		cout << "수정하려는 일기 제목이나 날짜를 입력해주세요." << endl;

		menu.MovePosition(30, 8);
		cout << "=>";
		menu.MovePosition(33, 8);
		cin >> input;


		if (input.substr(0, 1) == "2") {// 날짜일 경우 
			string date = "select * from diary where date like '%";
			date.append(input);
			date.append("%'");
			//조회
			const char* pDate = date.c_str();


			query_stat = mysql_query(connection, pDate);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);
			system("cls");
			char* snoE = 0;
			int snoED;
			
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과
				isSearch = TRUE;
				snoED = atoi(sql_row[0]); // 일련번호, 문자열을 정수타입으로 바꾸는 atoi함수 사용
			}
			
			if (!isSearch) {
				//system("cls");
				menu.MovePosition(20, 5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "일기가 존재하지 않습니다!";
				menu.MovePosition(20, 7);
				cout << "아무 키나 누르면 되돌아갑니다.";

				char ch = _getch();
				if (ch != 0) {
					system("cls");
					searchdiary.SelectMenu();
				}
			}
			else {
				// 데이터 수정
				query_stat = mysql_query(connection, pDate);

				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}

				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
					menu.MovePosition(5, 1);
					cout << "날짜(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 1);
					cout << "날씨 : " << sql_row[2];

					menu.MovePosition(5, 5);
					cout << "제목 (30자이내) : " << sql_row[3];

					menu.MovePosition(5, 9);
					cout << "내용 : " << endl;
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
				cout << "------------------------일기 수정 완료----------------------- " << endl;
				cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
				char ch = _getch();
				if (ch != 0) {
					system("cls");
					main.printMain();
				}

				mysql_close(connection);
			}

			
		}
		else { // 제목일 경우
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

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과
				isSearch = TRUE;
				snoED = atoi(sql_row[0]); // 일련번호, 문자열을 정수타입으로 바꾸는 atoi함수 사용
			}

			if (!isSearch) {
				//system("cls");
				menu.MovePosition(20, 5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "일기가 존재하지 않습니다!";
				menu.MovePosition(20, 7);
				cout << "아무 키나 누르면 되돌아갑니다.";

				char ch = _getch();
				if (ch != 0) {
					system("cls");
					searchdiary.SelectMenu();
				}
			}
			else {
				// 데이터 수정
				query_stat = mysql_query(connection, pTitle);

				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}

				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
					menu.MovePosition(5, 1);
					cout << "날짜(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 1);
					cout << "날씨 : " << sql_row[2];

					menu.MovePosition(5, 5);
					cout << "제목 (30자이내) : " << sql_row[3];

					menu.MovePosition(5, 9);
					cout << "내용 : " << endl;
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
				cout << "------------------------일기 수정 완료----------------------- " << endl;
				cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
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
		cout << "\n되돌아갑니다." << endl;
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


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨간색
	menu.MovePosition(30, 2);
	cout << "[주의] 내용 복구가 불가능합니다." << endl;
	menu.MovePosition(30, 4);
	cout << "그래도 진행하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //흰색
	/*삭제할껀지 아닌지*/



	searchDiary.Search(); // 검색


	system("cls");
	menu.MovePosition(20, 3);
	cout << "검색(날짜나 제목 입력) : ";
	cin >> input;


	if (input.substr(0, 1) == "2") {// 날짜일 경우 
		string date = "select * from diary where date like '%";
		date.append(input);
		date.append("%'");
		//조회
		const char* pDate = date.c_str();


		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		system("cls");
		menu.MovePosition(20, 3);
		cout << "[검색 결과]" << endl;
		int x = 1, y = 3;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}

		if (!isSearch) {
			menu.MovePosition(20, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "일기가 존재하지 않습니다!";
			menu.MovePosition(20, 7);
			cout << "일기 목록으로 돌아가려면 아무 키나 누르세요.";

			char ch = _getch();
			if (ch != 0) {
				system("cls");
				//searchdiary.SelectMenu();
			}
		}

		mysql_close(connection);
	}
	else { // 제목일 경우
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
		cout << "[검색 결과]" << endl;
		int x = 1, y = 5;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
			isSearch = TRUE;
			menu.MovePosition(x, y++);
			cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
		}



		mysql_close(connection);
	}

}


void DiaryPrint() {

}