#pragma once
#include <iostream>
#include <Windows.h>
#include "Menu.h"
#include "WriteDiary.h"
#include "SearchDiary.h"
using namespace std;

enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};

class Main {
public:
	void printMain();
    void printBorder();
}; 
