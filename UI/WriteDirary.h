#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <mysql.h>
#include <string>
#include<conio.h>
#include "Main.h"
using namespace std;

class WriteDiary {
public:
	WriteDiary(int x, int y);

	void Write();
	
	void MovePosition(int x, int y);
};
