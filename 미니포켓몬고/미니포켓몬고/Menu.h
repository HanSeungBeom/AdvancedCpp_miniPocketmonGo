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
	Menu(string title); //�޴��� ������ ����
	~Menu();

	//�޴� ��� �Լ�
	void addMenu(string menu); //�޴��� ���Ѵ�
	void delMenu(int position);//�޴��� �����Ѵ�.
	void setMenu(int position,string menu); //�޴��� �����Ѵ�.
	void clearMenu(); //��� �޴� �����

	void printMenu(); //�޴��� ���
	int input();      //����ڷκ��� ���� ����
	
	int getMenuNum(); //��ü �޴� ���� ����

};

