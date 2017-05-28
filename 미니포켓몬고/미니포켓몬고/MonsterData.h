#pragma once

#include "Monster.h"
#include <string>
using namespace std;

class MonsterData
{
	int id;		     //������ ID
	string name;	 //���� �̸�
	int type;		 //Ÿ��
	int probability; //Ȯ��
public:
	MonsterData(int id,string name,int type,int probability);
	MonsterData();
	~MonsterData();

	//getter
	int getId();
	string getName();
	int getType();
	int getProbability();

	//�ش� ���� ���� ��ü ����
	Monster genMonster();
	//�����͸� �ε��Ҷ� ����� �޼ҵ�
	Monster genMonster(string nickname, int hp, int attk, int def);
};

