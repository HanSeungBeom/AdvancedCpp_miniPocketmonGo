#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Ball.h"

class Player
{
	string name;//이름
	int sex;	//성별 1:남자/2:여자
	int money;	//소지금
	int maxMonster; //최대 잡을 수 있는 몬스터의 수
	int maxBall;	//최대 소유 몬스터볼 수
	int ballKind;	//가진 볼의 정보수
	vector<Ball,int> ball;


public:
	Player();
	~Player();
};

