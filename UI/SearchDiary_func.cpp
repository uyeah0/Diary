#include "SearchDiary_func.h"

//bool DiaryExists() {
//	bool isFind = FALSE;
//
//
//}

void SearchDiary_func::Search() { // 일기 검색
	SearchDiary searchdiary = SearchDiary();
	int isSearch = 0;

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;

	string input;


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

	Menu menu = Menu();
	Main main = Main();

	main.printBorder();

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
	menu.MovePosition(37, 13);
	cout << "작성한 일기를 봅니다." << endl;
	menu.MovePosition(37, 14);
	cout << "보고 싶은 일기의 제목이나 날짜를 검색해주세요.\n" << endl;
	menu.MovePosition(37, 15);
	cout << "=>";
	menu.MovePosition(39, 15);
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

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 확인
			isSearch++;
		}

		system("cls");
		main.printBorder();
		if (isSearch == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			menu.MovePosition(37, 13);
			cout << "일기가 존재하지 않습니다!";
			menu.MovePosition(37, 14);
			cout << "아무 키나 누르면 되돌아갑니다.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}
		else if (isSearch == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			query_stat = mysql_query(connection, pDate);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);
			system("cls");
			main.printBorder();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				menu.MovePosition(12, 5);
				cout << "날짜(yyyymmdd) : " << sql_row[1];

				menu.MovePosition(80, 5);
				cout << "날씨 : " << sql_row[2];

				menu.MovePosition(12, 7);
				cout << "제목 (30자이내) : " << sql_row[3];

				menu.MovePosition(12, 9);
				cout << "내용 : " << endl;
				for (int i = 11; i <= 20; i++) {
					menu.MovePosition(12, i); // body 출력
					cout << sql_row[i - 7];
				}

			}

		}
		else { // 일기가 한 개 이상이라면
			int x = 30, y = 6;

			vector<string> content;

			query_stat = mysql_query(connection, pDate);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 확인
				menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << "<" << sql_row[3] << ">"; // 일기 출력 
			}
			/*보려는 일기 날짜와 제목을 정확하게 입력해주세요*/
			menu.MovePosition(x, y++);
			cout << "보려는 일기 날짜와 제목을 정확하게 입력해주세요.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			menu.MovePosition(x, y++);
			cout << "※공백으로 구분";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			menu.MovePosition(x, y);
			cout << "=>";
			menu.MovePosition(x, y);
			string in;
			string in2;
			cin >> in >> in2;


			istringstream ss(in); // 공백으로 날짜 제목 구분한거 날짜와 제목으로 넣기
			string stringBuffer;
			menu.MovePosition(x+3, y);
			while (getline(ss, stringBuffer, ' ')) {
				content.push_back(stringBuffer); 
				cout << stringBuffer << " ";
			}
			string sDate, sTitle;
			/*sDate = content[0];
			sTitle = content[1];*/
			
			sDate = in;
			sTitle = in2;
			
			string find = "select * from diary where date like '"; // 입력 값 찾기
			find.append(sDate);
			find.append("' and title like '");
			find.append(sTitle);
			find.append("'");

			//조회
			const char* pF = find.c_str();
		
			query_stat = mysql_query(connection, pF);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);

			system("cls");
			main.printBorder();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				menu.MovePosition(12, 5);
				cout << "날짜(yyyymmdd) : " << sql_row[1];

				menu.MovePosition(80, 5);
				cout << "날씨 : " << sql_row[2];

				menu.MovePosition(12, 7);
				cout << "제목 (30자이내) : " << sql_row[3];

				menu.MovePosition(12, 9);
				cout << "내용 : " << endl;
				for (int i = 11; i <= 20; i++) {
					menu.MovePosition(12, i); // body 출력
					cout << sql_row[i - 7];
				}

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

		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 확인
			isSearch++;
		}

		system("cls");
		if (isSearch == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			menu.MovePosition(37, 5);
			cout << "일기가 존재하지 않습니다!";
			menu.MovePosition(37, 16);
			cout << "아무 키나 누르면 되돌아갑니다.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			char ch = _getch();
			if (ch != 0) {
				system("cls");
				searchdiary.SelectMenu();
			}
		}
		else if (isSearch == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			query_stat = mysql_query(connection, pTitle);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);

			system("cls"); 
			main.printBorder();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";
			
	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				menu.MovePosition(12, 5);
				cout << "날짜(yyyymmdd) : " << sql_row[1];

				menu.MovePosition(80, 5);
				cout << "날씨 : " << sql_row[2];

				menu.MovePosition(12, 7);
				cout << "제목 (30자이내) : " << sql_row[3];

				menu.MovePosition(12, 9);
				cout << "내용 : " << endl;
				for (int i = 11; i <= 20; i++) {
					menu.MovePosition(12, i); // body 출력
					cout << sql_row[i - 7];
				}

			}
		}
		else { // 일기가 한 개 이상이라면
			int x = 17, y = 7;
			vector<string> content;

			query_stat = mysql_query(connection, pTitle);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 확인
				menu.MovePosition(x, y++);
				cout << sql_row[1] << "\t" << "<" << sql_row[3] << ">"; // 일기 출력 
			}
			/*보려는 일기 날짜와 제목을 정확하게 입력해주세요*/
			menu.MovePosition(x, y++);
			cout << "보려는 일기 날짜와 제목을 정확하게 입력해주세요.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			menu.MovePosition(x, y++);
			cout << "※공백으로 구분";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			menu.MovePosition(x, y);
			cout << "=>";
			menu.MovePosition(++x, y);
			string in;
			cin >> in;


			istringstream ss(in); // 공백으로 날짜 제목 구분한거 날짜와 제목으로 넣기
			string stringBuffer;
			menu.MovePosition(x + 3, y);
			while (getline(ss, stringBuffer, ' ')) {
				content.push_back(stringBuffer);
				cout << stringBuffer << " ";
			}
			string sDate, sTitle;
			sDate = content[0];
			sTitle = content[1];

			string find = "select * from diary where date like '"; // 입력 값 찾기
			find.append(sDate);
			find.append("' and title like '%");
			find.append(sTitle);
			find.append("'");

			//조회
			const char* pF = find.c_str();

			query_stat = mysql_query(connection, pF);

			if (query_stat != 0) {
				fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			}

			sql_result = mysql_store_result(connection);
			system("cls");
			main.printBorder();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			menu.MovePosition(80, 7);
			cout << "아무 키나 누르면 되돌아갑니다.";
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				menu.MovePosition(12, 5);
				cout << "날짜(yyyymmdd) : " << sql_row[1];

				menu.MovePosition(80, 5);
				cout << "날씨 : " << sql_row[2];

				menu.MovePosition(12, 7);
				cout << "제목 (30자이내) : " << sql_row[3];

				menu.MovePosition(12, 9);
				cout << "내용 : " << endl;
				for (int i = 11; i <= 20; i++) {
					menu.MovePosition(12, i); // body 출력
					cout << sql_row[i - 7];
				}

			}
			

		}
		

		mysql_close(connection);
	}
	char ch = _getch();
	if (ch != 0) {
		system("cls");
		searchdiary.SelectMenu();
	}


};

void SearchDiary_func::ListDiary() { // 일기 목록
	Main main = Main();
	Menu menu = Menu();


	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;


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

	// 데이터 조회

	/*query_stat = mysql_query(connection, "select * from diary");

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	sql_result = mysql_store_result(connection);


	menu.MovePosition(1, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << "┌────────────[일기 목록]────────────┐" << endl;
	int x = 10, y = 5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		menu.MovePosition(x, y++);
		y++;
		cout <<sql_row[1] << "\t" << "\t" << "<" << sql_row[3] << ">" <<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << "└───────────────────────────────────┘" << endl;

	mysql_close(connection);*/

};

void SearchDiary_func::EditDiary() {
	system("cls");
	SearchDiary searchdiary = SearchDiary();
	Menu menu = Menu();
	Main main = Main();
	int choose; // 일기를 수정할 것인지 아닌지
	bool isSearch = FALSE; // 검색 결과
	string input; // 

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴
	int query_stat;

	char dateE[10] = { '\0', };
	char weatherE[22] = { '\0', };
	char titleE[62] = { '\0', }; //  바뀐 제목
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	menu.MovePosition(30, 10);
	cout << "[주의] 이전의 내용은 사라집니다." << endl;
	menu.MovePosition(30, 12);
	cout << "그래도 진행하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
	cin >> choose;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	switch (choose)
	{
	case 1: {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), VIOLET);
		main.printBorder();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		menu.MovePosition(38, 10);
		cout << "수정하려는 일기 제목이나 날짜를 입력해주세요." << endl;

		menu.MovePosition(38, 12);
		cout << "=>";
		menu.MovePosition(41, 12);
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

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과
				isSearch = TRUE;
			}

			system("cls");
			main.printBorder();
			if (!isSearch) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				menu.MovePosition(37, 5);
				cout << "일기가 존재하지 않습니다!";
				menu.MovePosition(37, 16);
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
				system("cls");
				main.printBorder();
				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
					menu.MovePosition(12, 5);
					cout << "날짜(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 5);
					cout << "날씨 : " << sql_row[2];

					menu.MovePosition(12, 7);
					cout << "제목 (30자이내) : " << sql_row[3];

					menu.MovePosition(12, 9);
					cout << "내용 : " << endl;
					for (int i = 11; i <= 20; i++) {
						menu.MovePosition(12, i); // body 출력
						cout << sql_row[i - 7];
					}

				}
				menu.MovePosition(30, 5); // 날짜 입력
				while (fgets(dateE, 10, stdin) != NULL) {
					if (strlen(dateE) > 8)
						break;
				}
				CHOP(dateE);

				menu.MovePosition(87, 5); // 날씨 입력
				while (fgets(weatherE, 22, stdin) != NULL) {
					if (strlen(weatherE) > 0)
						break;
				}
				CHOP(weatherE);

				menu.MovePosition(30, 7); // 제목 입력
				fgets(titleE, 60, stdin);
				CHOP(titleE);

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
													else { body10[0] = { '\0', }; }
												}
												else { body9[0] = { '\0', }; }
											}
											else { body8[0] = { '\0', }; }
										}
										else { body7[0] = { '\0', }; }
									}
									else { body6[0] = { '\0', }; }
								}
								else { body5[0] = { '\0', }; }
							}
							else { body4[0] = { '\0', }; }
						}
						else { body3[0] = { '\0', }; }
					}
					else { body2[0] = { '\0', }; }
				}
				else { body1[0] = { '\0', }; }


				sprintf(query, "insert into diary(DATE, WEATHER, TITLE, BODY1, body2, body3, body4, body5, BODY6, body7, body8, body9, body10) values " "( '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s','%s','%s', '%s','%s','%s')", dateE, weatherE, titleE, body1, body2, body3, body4, body5, body6, body7, body8, body9, body10);

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
				cout << "일 기 수 정 완 료";
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

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과
				isSearch = TRUE;
			}
			system("cls");
			main.printBorder();
			if (!isSearch) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				menu.MovePosition(37, 5);
				cout << "일기가 존재하지 않습니다!";
				menu.MovePosition(37, 16);
				cout << "아무 키나 누르면 되돌아갑니다.";

				char ch = _getch();
				if (ch != 0) {
					system("cls");
					searchdiary.SelectMenu();
				}
			}
			else {
				// 데이터 수정
				system("cls");
				main.printBorder();
				query_stat = mysql_query(connection, pTitle);

				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}

				sql_result = mysql_store_result(connection);
				while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
					menu.MovePosition(12, 5);
					cout << "날짜(yyyymmdd) : " << sql_row[1];

					menu.MovePosition(80, 5);
					cout << "날씨 : " << sql_row[2];

					menu.MovePosition(12, 7);
					cout << "제목 (30자이내) : " << sql_row[3];

					menu.MovePosition(12, 9);
					cout << "내용 : " << endl;
					for (int i = 11; i <= 20; i++) {
						menu.MovePosition(12, i); // body 출력
						cout << sql_row[i - 7];
					}

				}
				menu.MovePosition(30, 5); // 날짜 입력
				while (fgets(dateE, 10, stdin) != NULL) {
					if (strlen(dateE) > 8)
						break;
				}
				CHOP(dateE);

				menu.MovePosition(87, 5); // 날씨 입력
				while (fgets(weatherE, 22, stdin) != NULL) {
					if (strlen(weatherE) > 0)
						break;
				}
				CHOP(weatherE);

				menu.MovePosition(30, 7); // 제목 입력
				fgets(titleE, 60, stdin);
				CHOP(titleE);

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
													else { body10[0] = { '\0', }; }
												}
												else { body9[0] = { '\0', }; }
											}
											else { body8[0] = { '\0', }; }
										}
										else { body7[0] = { '\0', }; }
									}
									else { body6[0] = { '\0', }; }
								}
								else { body5[0] = { '\0', }; }
							}
							else { body4[0] = { '\0', }; }
						}
						else { body3[0] = { '\0', }; }
					}
					else { body2[0] = { '\0', }; }
				}
				else { body1[0] = { '\0', }; }


				sprintf(query, "insert into diary(DATE, WEATHER, TITLE, BODY1, body2, body3, body4, body5, BODY6, body7, body8, body9, body10) values " "( '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s','%s','%s', '%s','%s','%s')", dateE, weatherE, titleE, body1, body2, body3, body4, body5, body6, body7, body8, body9, body10);

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
				cout << "일 기 수 정 완 료";
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
		}

		break;
	}
	case 0: {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
		searchdiary.SelectMenu();
		break;
	}
	default:
		break;
	}
}

