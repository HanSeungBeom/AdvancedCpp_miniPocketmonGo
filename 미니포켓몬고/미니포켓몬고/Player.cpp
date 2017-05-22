#include "Player.h"
#include "BallPocket.h"
#include "Monster.h"

Player::Player(string name,
	int sex,
	int money,
	int maxMonster,
	int maxBall,
	int ballKind,
	vector<BallPocket> ballPocket,
	int monsterCount,
	vector<Monster> monsters)
{
	this->name = name;
	this->sex = sex;
	this->money = money;
	this->maxMonster = maxMonster;
	this->maxBall = maxBall;
	this->ballKind = ballKind;
	this->ballPocket = ballPocket;
	this->monsterCount = monsterCount;
	this->monsters = monsters;
}

Player::~Player()
{
}
