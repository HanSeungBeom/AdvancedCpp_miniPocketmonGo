#pragma once
#include <iostream>
#include <string>

using namespace std;
class Monster
{
	int id;			 //���� id
	string nickname; //������ ����
	int hp;			 //���� ü��
	int attk;		 //���� ���ݷ�
	int def;		 //���� ����
	int cp;			 //������ cp
public:
	Monster(int id,
		string nickname,
		int hp,
		int attk,
		int def,
		int cp);
	~Monster();
};

