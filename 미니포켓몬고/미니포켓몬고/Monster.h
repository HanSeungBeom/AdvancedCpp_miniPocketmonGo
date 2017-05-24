#pragma once
#include <iostream>
#include <string>

using namespace std;
class Monster
{
	int id;			 //몬스터 id
	string nickname; //몬스터의 별명
	int hp;			 //몬스터 체력
	int attk;		 //몬스터 공격력
	int def;		 //몬스터 방어력
	int cp;			 //몬스터의 cp
public:
	Monster(int id,
		string nickname,
		int hp,
		int attk,
		int def,
		int cp);
	~Monster();
	string getNickname();
	void setNickname(string nickname);
	int getCp();
	int getId();
	int getHp();
	int getAttk();
	int getDef();
};

