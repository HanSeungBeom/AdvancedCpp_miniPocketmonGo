#pragma once

#include "Monster.h"
#include <string>
using namespace std;

class MonsterData
{
	int id;		     //몬스터의 ID
	string name;	 //몬스터 이름
	int type;		 //타입
	int probability; //확률
public:
	MonsterData(int id,string name,int type,int probability);
	MonsterData();
	~MonsterData();

	//getter
	int getId();
	string getName();
	int getType();
	int getProbability();

	//해당 몬스터 랜덤 객체 생성
	Monster genMonster();
	//데이터를 로드할때 사용할 메소드
	Monster genMonster(string nickname, int hp, int attk, int def);
};

