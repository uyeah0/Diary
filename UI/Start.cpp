#include "Start.h"

void Start::printStart() {
	Menu menu = Menu(50, 1);
	Main main = Main();

	bool isRun = TRUE;
	bool isMain = FALSE;
	bool isSetPW = FALSE;
	bool isTrue = FALSE;

	
	int menuCode = menu.SPrintMenu();
	
	while (isRun) {
		switch (menuCode)
		{
		case 0:
			if (!isMain) { // 들어가기
				string pw;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				main.printBorder();

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				menu.MovePosition(38, 13);
				cout << "비밀번호 입력";
				menu.MovePosition(57, 13);
				cin >> pw;
				if (CorrectPW(pw)) {
					main.printMain();
				}
				else {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					main.printBorder();
					menu.MovePosition(38, 12);
					cout << "새 비밀번호와 비밀번호 확인이 일치하지 않습니다.";
					menu.MovePosition(43, 14);
					cout << "아무 키나 누르면 되돌아갑니다.";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					char ch = _getch();
					if (ch != 0) {
						system("cls");
						printStart();
					}
				}
				isMain = TRUE;
			}
			break;
		case 2:
			if (!isSetPW) {
				SetPW();
				isSetPW = TRUE;
			}
			break;
		case 4://종료
			isRun = FALSE;
			break;
		default: // 다른 값 넣었을 때 
			if (!isTrue) {
				printStart();
				isTrue = TRUE;
			}
		}
		if (!isRun) {
			system("cls");
			menu.MovePosition(45, 20);
			cout << "프로그램을 종료합니다." << endl;
			exit(0);
		}
	}
}



void Start::SetPW() {
	Main main = Main();
	Menu menu = Menu();
	Start start = Start();
	int choose;

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;

	char query[255] = { '\0', };
	bool isSearch = FALSE;
	string IPW;
	char SPW[12] = { '\0', }; // 비밀번호 첫 설정
	char NPW[12] = { '\0', }; // 새 비밀번호
	char CPW[12] = { '\0', }; // 재입력 결과가 맞는지 비교 할 비밀번호


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

	query_stat = mysql_query(connection, "select * from user order by pw desc limit 1"); // 최근에 저장한 값이 있는지? 

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	}

	sql_result = mysql_store_result(connection);

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), VIOLET);
	main.printBorder();
	if (mysql_fetch_row(sql_result) != NULL) {
		isSearch = TRUE;
	}
	if (!isSearch) {

			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), VIOLET);
			main.printBorder();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			menu.MovePosition(32, 12);
			cout << "비밀번호(10자 이내)";

			menu.MovePosition(32, 14);
			cout << "비밀번호 확인";

			menu.MovePosition(53, 12);
			fgets(SPW, 10, stdin);
			CHOP(SPW);

			menu.MovePosition(53, 14);
			fgets(CPW, 10, stdin);
			CHOP(CPW);

			if (!strcmp(SPW, CPW)) {
				sprintf(query, "insert into user(PW) values " "( '%s')", SPW);
				query_stat = mysql_query(connection, query);
				if (query_stat != 0) {
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
				}
				system("cls");
				main.printBorder();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
				menu.MovePosition(32, 12);
				cout << "() ()						(\\ /)";
				menu.MovePosition(32, 13);
				cout << "( '.' )						( . .)♥";
				menu.MovePosition(50, 13);
				cout << "비 밀 번 호 설 정 완 료";
				menu.MovePosition(32, 14);
				cout << "(\")_(\")						c(”)(”)";


				menu.MovePosition(39, 16);
				cout << "시작 화면으로 돌아가려면 아무 키나 누르세요";
				char ch = _getch();
				if (ch != 0) {
					system("cls");
					start.printStart();
				}
			}
			else {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					main.printBorder();
					menu.MovePosition(39, 12);
					cout << "비밀번호와 비밀번호 확인이 일치하지 않습니다.";
					menu.MovePosition(43, 14);
					cout << "아무 키나 누르면 되돌아갑니다.";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					char ch = _getch();
					if (ch != 0) {
						system("cls");
						printStart();
					}
			}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		menu.MovePosition(32, 10);
		cout << "현재 비밀번호가 존재합니다. 새로 변경하시겠습니까? " << endl;
		menu.MovePosition(30, 12);
		cout << "변경하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
		cin >> choose;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		switch (choose) {
		case 1: {

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				main.printBorder();

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				menu.MovePosition(36, 10);
				cout << "현재 비밀번호";

				menu.MovePosition(36, 13);
				cout << "새 비밀번호";

				menu.MovePosition(36, 16);
				cout << "새 비밀번호 확인";


				menu.MovePosition(58, 10); // 현재 비번과 비번 바꾸기 전 비번 입력 비교 
				cin >> IPW;

				menu.MovePosition(58, 13); // 새 비밀번호 입력
				while (fgets(NPW, 10, stdin) != NULL) {
					if (strlen(NPW) > 3)
						break;
				}
				CHOP(NPW);

				menu.MovePosition(58, 16); // 비교할 비밀번호 입력
				while (fgets(CPW, 10, stdin) != NULL) {
					if (strlen(CPW) > 3)
						break;
				}
				CHOP(CPW);


				if (CorrectPW(IPW)) {
					if (!strcmp(NPW, CPW)) {
						sprintf(query, "update user set pw = " "( '%s')", NPW);


						query_stat = mysql_query(connection, query);
						if (query_stat != 0) {
							fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
						}

						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
						menu.MovePosition(32, 12);
						cout << "() ()						(\\ /)";
						menu.MovePosition(32, 13);
						cout << "( '.' )						( . .)♥";
						menu.MovePosition(50, 13);
						cout << "비 밀 번 호 변 경 완 료";
						menu.MovePosition(32, 14);
						cout << "(\")_(\")						c(”)(”)";


						menu.MovePosition(39, 16);
						cout << "시작 화면으로 돌아가려면 아무 키나 누르세요";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						char ch = _getch();
						if (ch != 0) {
							system("cls");
							start.printStart();
						}

					}
					else {
						system("cls");
						main.printBorder();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						menu.MovePosition(38, 12);
						cout << "새 비밀번호와 비밀번호 확인이 일치하지 않습니다.";
						menu.MovePosition(43, 14);
						cout << "아무 키나 누르면 되돌아갑니다.";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						char ch = _getch();
						if (ch != 0) {
							system("cls");
							printStart();
						}
					}
					

				}
				else {
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					main.printBorder();
					menu.MovePosition(40, 12);
					cout << "현재 비밀번호가 일치하지 않습니다.";
					menu.MovePosition(43, 14);
					cout << "아무 키나 누르면 되돌아갑니다.";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					char ch = _getch();
					if (ch != 0) {
						system("cls");
						printStart();
					}

				}

		}break;
		case 0: {
			menu.MovePosition(39, 16);
			cout << "시작 화면으로 돌아가려면 아무 키나 누르세요";
			char ch = _getch();
			if (ch != 0) {
				system("cls");
				start.printStart();
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
			start.printStart();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
			break;
		}
		default:
			break;
		}

	}
	mysql_close(connection);
}

bool Start::CorrectPW(string IPW) {// 입력받은 비밀번호
	Main main = Main();
	Menu menu = Menu();
	Start start = Start();

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
	MYSQL_ROW sql_row; // row 가리킴

	int query_stat;

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

	
	string cor= "select * from user where pw like '";
	cor.append(IPW);
	cor.append("'");

	const char* pData = cor.c_str();

	query_stat = mysql_query(connection, pData);

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	sql_result = mysql_store_result(connection);

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		return TRUE;
	}

	

	return FALSE;
}



int main() {
	system("cls");
	Start start = Start();
	start.printStart();

	return 0;
}