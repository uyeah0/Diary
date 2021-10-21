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
MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
MYSQL_ROW sql_row; // row ����Ŵ

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


	// ���� ����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	//mysql_set_character_set(&conn, "euckr");


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}

	// �ѱ� ���

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// ������ ��ȸ

	query_stat = mysql_query(connection, "select * from user");

	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}

	sql_result = mysql_store_result(connection);

	cout << "snum\tdate\t\ttitle\tweather\tbody" << endl;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << endl << sql_row[5] << endl;
	}


	cout << "\n-*-* Insert Value -*-*\n";

	//MovePosition(2, 1);
	//MovePosition(2, 20);
	cout << "��¥(yyyymmdd) : ";
	fgets(date, 10, stdin);
	CHOP(date);

	//MovePosition(50, 1);
	//MovePosition(50, 20);
	cout << "���� : ";
	fgets(weather, 20, stdin);

	CHOP(weather);

	//MovePosition(2, 3);
	//MovePosition(2, 22);
	cout << "���� (30���̳�) : ";
	fgets(title, 60, stdin);
	CHOP(title);

	//MovePosition(50, 3);
	//MovePosition(50, 22);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;

	//MovePosition(2, 5);
	//MovePosition(2, 24);
	cout << "���� : ( enter ���� �� '***' �Է� �� ����)" << endl;
	//MovePosition(1, 26);
	/*
	string n;
	while (true) {
		getline(cin, n);
		if (n != "***")break;
		body.append(n);
	}
	*/
	fgets(body, 255, stdin);
	CHOP(body);


	//if(weather)
	sprintf(query, "insert into user(DATE, TITLE, WEATHER, BODY) values " "('%s', '%s', '%s', '%s')", date, title, weather, body);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}


	mysql_close(connection);

}