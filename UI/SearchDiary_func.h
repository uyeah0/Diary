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
#include <vector>
#include<sstream>
#pragma comment(lib, "libmySQL.lib")
using namespace std;


class SearchDiary_func {
public:
	void EditDiary(); // �ϱ� ����
	void ListDiary(); // �� �ϱ� ����
	void Search(); // �ϱ� �˻�
};