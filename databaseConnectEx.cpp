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
	int sno;
	char date[10];
	char weather[22];
	//char title[62];
	char body[255];
	//string body;
	char query[255];

	mysql_init(&conn);


	// ���� ����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);


	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	// �ѱ� ���

	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	// ������ ��ȸ

	//query_stat = mysql_query(connection, "select * from user_tb");
	/*
	cout << "�˻�(��¥�� ���� �Է�) : ";
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

	//cout << "��¥(yyyymmdd) : ";
	//fgets(date, 10, stdin);
	//CHOP(date);

	//cout << "���� : ";
	//fgets(weather, 22, stdin);
	//CHOP(weather);

	//cout << "���� (30���̳�) : ";
	//fgets(title, 62, stdin);
	//CHOP(title);

	////cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;

	//cout << "���� : ( enter ���� �� '***' �Է� �� ����)" << endl;
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

	
	cout << "�˻�(��¥�� ���� �Է�) : ";
	string input;
	cin >> input;


	if (input.substr(0, 1) == "2") {// ��¥�� ��� 
		string date = "select * from user_tb where date like '";
		date.append(input);
		date.append("'");
		cout << "date : " << date << endl;
		//��ȸ
		const char* pDate = date.c_str();


		query_stat = mysql_query(connection, pDate);

		if (query_stat != 0) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		}

		sql_result = mysql_store_result(connection);

		system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
		}
		else {
			MovePosition(1, 1);
			cout << "[�˻� ���]" << endl;
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
				MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		}
	}
	else { // ������ ���
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
			cout << "�ϱⰡ �������� �ʽ��ϴ�.";
		}

		/*system("cls");
		if ((sql_row = mysql_fetch_row(sql_result)) == NULL) {
			cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
		}
		//else {
			cout << pTitle;
			MovePosition(1, 1);
			cout << "[�˻� ���]" << endl;

			
			int x = 1, y = 5;
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) { // ��ȸ ��� ���
				MovePosition(x, y++);
				cout << sql_row[1] << "\t" << sql_row[2] << "\t" << "<" << sql_row[3] << ">" << endl;
			}
		//}*/
	}


	mysql_close(connection);

}