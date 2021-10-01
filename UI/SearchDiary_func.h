#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <mysql.h>
#include <conio.h>
#include <cstdio>
#include "Main.h"
#include "SearchDiary.h"
#include <string>
#include <cstdlib>
#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "diarydb"
#define CHOP(x) x[strlen(x)-1] = ' '

class SearchDiary_func {
public:
	void DeleteDiary();
	void EditDiary();
	void WatchDiary();
	void DiaryPrint();
};