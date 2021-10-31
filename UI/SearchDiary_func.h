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
	void EditDiary(); // 일기 수정
	void ListDiary(); // 쓴 일기 보기
	void Search(); // 일기 검색
};