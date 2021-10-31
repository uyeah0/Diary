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



class SearchDiary {
public:
	void SelectMenu();
};