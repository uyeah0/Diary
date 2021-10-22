#include <iostream>
#include <mysql.h>
#include <fstream>
#include <string>
#include <conio.h>

#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "diarydb"
#define CHOP(x) x[strlen(x)-1] = ' '

MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result; // select, show, describe, explain 결과 다루기
MYSQL_ROW sql_row; // row 가리킴

int query_stat;

void MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

int main() {
	int sno;
	char date[10];
	char weather[22];
	//char title[62];
	char body[255];
	//string body;
	char query[255];

	mysql_init(&conn);


	// 계정 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	// 한글 사용

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// 데이터 조회

	//query_stat = mysql_query(connection, "select * from user_tb");
	/*
	cout << "검색(날짜나 제목 입력) : ";
	string input;
	cin >> input;

	string title = "select * from user_tb where title like '";
	title.append(input);
	title.append("'");
	cout << "title : " << title << endl;

	const char* pTitle = title.c_str();

	query_stat = mysql_query(connection, pTitle);

	if (query_stat != 0) {
		//cout << mysql_error(connection) << endl << endl;
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	sql_result = mysql_store_result(connection);

	cout << "sno\tdate\tweather\ttitle\tbody" << endl;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << "\t" << sql_row[5] << endl;
	}

	//cout << "\n-*-* Insert Value -*-*\n";

	//cout << "날짜(yyyymmdd) : ";
	//fgets(date, 10, stdin);
	//CHOP(date);

	//cout << "날씨 : ";
	//fgets(weather, 22, stdin);
	//CHOP(weather);

	//cout << "제목 (30자이내) : ";
	//fgets(title, 62, stdin);
	//CHOP(title);

	////cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;

	//cout << "내용 : ( enter 누른 후 '***' 입력 시 저장)" << endl;
	///*string n;
	//while (true) {
	//	getline(cin, n);
	//	if (n != "***")break;
	//	body.append(n);
	//}*/
	//fgets(body, 255, stdin);
	//CHOP(body);

	//sprintf(query, "insert into user_tb(DATE, WEATHER, TITLE, BODY) values " "('%s', '%s', '%s', '%s')", date, weather, title, body);

	//query_stat = mysql_query(connection, query);
	//if (query_stat != 0) {
	//	fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
	//	return 1;
	//}

	
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
		}
		else {
			MovePosition(1, 1);
			cout << "[검색 결과]" << endl;
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		}
	}
	else { // 제목일 경우
		string title = "select * from user_tb where title like '";
		title.append(input);
		title.append("'");
		cout << "title : " << title << endl;

		const char* pTitle = title.c_str();

		query_stat = mysql_query(connection, pTitle);

		if (query_stat != 0) {
			//cout << mysql_error(connection) << endl << endl;
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			return 1;
		}

		sql_result = mysql_store_result(connection);

		bool a = FALSE;

		cout << "sno\tdate\tweather\ttitle\tbody" << endl;
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
			a = TRUE;
			cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << "\t" << sql_row[5] << endl;
		}

		if (!a) {
			cout << "일기가 존재하지 않습니다.";
		}

		/*system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "일기가 존재하지 않습니다!" << endl;
		}
		//else {
			cout << pTitle;
			MovePosition(1, 1);
			cout << "[검색 결과]" << endl;

			
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // 조회 결과 출력
				MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		//}*/
	}


	mysql_close(connection);

}