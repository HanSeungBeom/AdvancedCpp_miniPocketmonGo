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
	Menu(string title); //메뉴의 제목을 결정
	~Menu();

	//메뉴 기능 함수
	void addMenu(string menu); //메뉴를 더한다
	void delMenu(int position);//메뉴를 삭제한다.
	void setMenu(int position,string menu); //메뉴를 변경한다.
	void clearMenu(); //모든 메뉴 지우기

	void printMenu(); //메뉴를 출력
	int input();      //사용자로부터 값을 받음
	
	int getMenuNum(); //전체 메뉴 수를 리턴

};

