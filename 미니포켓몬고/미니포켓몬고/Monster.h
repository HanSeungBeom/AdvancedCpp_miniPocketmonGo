#pragma once
#include <iostream>
#include <string>
using namespace std;
class Monster
{
	int num;		//몬스터의 ID
	string name;	 //몬스터 이름
	int type;		 //타입
	int probability; //확률

	string nickname; //몬스터의 별명
	int hp;			 //몬스터 체력
	int atk;		 //몬스터 공격력
	int def;		 //몬스터 방어력
public:
	Monster();
	~Monster();
	
};

