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


class SearchDiary_func {
public:
	void DeleteDiary();
	void EditDiary();
	void WatchDiary();
	void DiaryPrint();
};