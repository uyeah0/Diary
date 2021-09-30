#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include "Main.h"
#include "SearchDiary.h"
#include <string>

using namespace std;

class SearchDiary_func {
public:
	void DeleteDiary();
	void EditDiary();
	void WatchDiary();
};