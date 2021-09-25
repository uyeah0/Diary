#include <iostream>
#include <mysql.h>
#include <fstream>
#include <string>

#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "userDB"
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
	int snum;
	char date[10];
	char weather[20];
	char title[60];
	char body[255];
	//string body;
	char query[255];
	
	mysql_init(&conn);

	
	// 계정 연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	//mysql_set_character_set(&conn, "euckr");


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}
	
	// 한글 사용
	
	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// 데이터 조회

	query_stat = mysql_query(connection, "select * from user");

	if (query_stat != 0) {
		//cout << mysql_error(connection) << endl << endl;
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}

	sql_result = mysql_store_result(connection);

	cout << "snum\tdate\t\ttitle\tweather\tbody" << endl;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << endl << sql_row[5]  << endl;
	}

	cout << "\n-*-* Insert Value -*-*\n";

	//MovePosition(2, 1);
	//MovePosition(2, 20);
	cout << "날짜(yyyymmdd) : ";
	fgets(date, 10, stdin);
	CHOP(date);

	//MovePosition(50, 1);
	//MovePosition(50, 20);
	cout << "날씨 : ";
	fgets(weather, 20, stdin);

	CHOP(weather);

	//MovePosition(2, 3);
	//MovePosition(2, 22);
	cout << "제목 (30자이내) : ";
	fgets(title, 60, stdin);
	CHOP(title);

	//MovePosition(50, 3);
	//MovePosition(50, 22);
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;

	//MovePosition(2, 5);
	//MovePosition(2, 24);
	cout << "내용 : ( enter 누른 후 '***' 입력 시 저장)" << endl;
	//MovePosition(1, 26);
	
	fgets(body, 255, stdin);
	//CHOP(body);

	sprintf(query, "insert into user(DATE, TITLE, WEATHER, BODY) values " "('%s', '%s', '%s', '%s')", date, title, weather, body);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}


	mysql_close(connection);

}
