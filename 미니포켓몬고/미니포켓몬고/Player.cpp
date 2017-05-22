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

string Player::getName(){ return name; }
void Player::setName(string name){ this->name = name; }
int Player::getSex(){ return sex; }
void Player::setSex(int sex){ this->sex = sex; }
int Player::getMoney(){ return money; }
void Player::setMoney(int money){ this->money = money; }
int Player::getMaxMonster(){ return maxMonster; }
void Player::setMaxMonster(int maxMonster){ this->maxMonster = maxMonster; }
int Player::getMaxBall(){ return maxBall; }
void Player::setMaxBall(int maxBall){ this->maxBall = maxBall; }