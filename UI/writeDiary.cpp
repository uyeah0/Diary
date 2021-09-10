#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<Windows.h>
#include<iostream>
#include "WriteDirary.h"

using namespace std;
#pragma comment(lib, "libmySQL.lib")

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "userDB"
//#define CHOP(x) x[strlen(x)-1] = ' '

MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result; // select, show, describe, explain ��� �ٷ��
MYSQL_ROW sql_row; // row ����Ŵ

int query_stat;



WriteDiary::WriteDiary(int x, int y) {
	MovePosition(x, y);
}

void WriteDiary::MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void WriteDiary::Write() {
	int snum;
	char date[10];
	char title[60];
	char weather[20];
	char body[30];
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
		//cout << mysql_error(connection) << endl << endl;
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}

	sql_result = mysql_store_result(connection);

	cout << "snum\tdate\t\ttitle\tweather\tbody" << endl;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		//cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << "\t"
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << endl;
	}

	cout << "\n-*-* Insert Value -*-*\n";
	/*cout << "snum : ";
	cin >> snum;
	*/

	MovePosition(2, 1);
	cout << "��¥(yyyymmdd) : ";
	fgets(date, 10, stdin);
	//CHOP(date);

	MovePosition(50, 1);
	cout << "���� : ";
	fgets(weather, 20, stdin);
	
	//CHOP(title);

	MovePosition(2, 3);
	cout << "���� (30���̳�) : ";
	fgets(title, 60, stdin);
	//CHOP(weather);

	MovePosition(50, 3);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������.";

	MovePosition(2, 5);
	cout << "���� : ( enter ���� �� '***' �Է� �� ����)";
	/*string n;
	while (n != "***") {
		getline(cin, n);
		body.append(n);
	}*/
	fgets(body, 30, stdin);
	//CHOP(body);

	sprintf(query, "insert into user(DATE, TITLE, WEATHER, BODY) values " "('%s', '%s', '%s', '%s')", date, title, weather, body);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		//return 1;
	}

	mysql_close(connection);
	
}

/*
int main() {
	MovePosition(2, 1);
	string date;
	cout << "��¥(yyyymmdd) : ";
	cin >> date;
	
	MovePosition(50, 1);
	string weather;
	cout << "���� : ";
	cin >> weather;

	
	gotoxy(2, 3);
	string title;
	cout << "���� (30���̳�) : ";
	cin >> title;

	gotoxy(50, 3);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������.";

	gotoxy(2, 5);
	string body;
	cout << "���� : ( enter ���� �� '***' �Է� �� ����)";
	gotoxy(2, 6);
	cin >> body;

	return 0;
}*/