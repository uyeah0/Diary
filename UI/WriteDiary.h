#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <fstream>
#include <conio.h>
#include <string>
#include "Main.h"
#include "Menu.h"

#pragma comment(lib, "libmySQL.lib")
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "mirim"
#define DB_NAME "diarydb"
#define CHOP(x) x[strlen(x)-1] = ' '



class WriteDiary {
public:
	void Write();
};
