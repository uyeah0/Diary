#pragma once
#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <fstream>
#include <string>
#include "Main.h"
#include "Menu.h"
#include "WriteDiary.h"
#include "SearchDiary_func.h"

#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "diarydb"
#define CHOP(x) x[strlen(x)-1] = ' '


class SearchDiary {
public:
	void Search();
	void SelectMenu();
	void ListDiary();
};