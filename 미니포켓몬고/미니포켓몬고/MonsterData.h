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
	Monster genMonster(); //�ش� ���� ���� ��ü ����
	Monster genMonster(string nickname, int hp, int attk, int def); //�����͸� �ε��Ҷ� ����� �޼ҵ�
	~MonsterData();
	int getId();
	string getName();
	int getType();
	int getProbability();
	
};

