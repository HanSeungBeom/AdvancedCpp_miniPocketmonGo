#pragma once
#include <iostream>
#include <string>
using namespace std;
class Monster
{
	int num;		//������ ID
	string name;	 //���� �̸�
	int type;		 //Ÿ��
	int probability; //Ȯ��

	string nickname; //������ ����
	int hp;			 //���� ü��
	int atk;		 //���� ���ݷ�
	int def;		 //���� ����
public:
	Monster();
	~Monster();
	
};

