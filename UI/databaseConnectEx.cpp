#include <iostream>
#include <mysql.h>

#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "userDB"
#define CHOP(x) x[strlen(x)-1] = ' '


int main() {

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	
	int query_stat;

	int snum;
	char date[10];
	char title[60];
	char weather[20];
	char body[30];
	char query[255];

	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}
	query_stat = mysql_query(connection, "select * from user");
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}
	
	sql_result = mysql_store_result(connection);
	cout << "snum\tdate\ttitle\tweather\tbody" << endl;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		//cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << "\t" << sql_row[3] << "\t" << sql_row[4] << "\t"
		cout << sql_row[0] << "\t" << sql_row[1] << "\t" << sql_row[2] << endl;
	}

	cout << "\n-*-* Insert Value -*-*\n";
	/*cout << "snum : ";
	cin >> snum;
	*/

	cout << "date : ";
	fgets(date, 10, stdin);
	//CHOP(date);

	cout << "title : ";
	fgets(title, 60, stdin);
	//CHOP(title);

	cout << "weather : ";
	fgets(weather, 20, stdin);
	//CHOP(weather);

	cout << "body : ";
	fgets(body, 30, stdin);
	//CHOP(body);
	`1 
	sprintf(query, "insert into user(DATE, TITLE, WEATHER, BODY) values " "('%s', '%s', '%s', '%s')", date, title, weather, body);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	mysql_close(connection);
	return 0;
}