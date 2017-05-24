#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <string>

class Menu
{
	string title;
	vector<string> menus;
	
public:
	Menu(string title);
	~Menu();
	void addMenu(string menu);
	void delMenu(int position);
	void setMenu(int position,string menu);
	int getMenuNum();
	void printMenu();
	int input();
};

