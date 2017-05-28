#include "BallPocket.h"
#include "BallData.h"


BallPocket::BallPocket(BallData ball, int id, int num)
{
	this->ball = ball;
	this->id = id;
	this->num = num;
}

BallPocket::~BallPocket()
{
}

int BallPocket::getId(){
	return id;
}

int BallPocket::getNum(){
	return num;
}

void BallPocket::setNum(int num){
	this->num = num;
}

bool BallPocket::throwBall(){
	//해당 볼포켓의 공을 던지는 함수
	//공을 하나 감소하고
	//공의 확률에 따라 잡았는지 안잡았는지 bool 값을 리턴한다.

	this->num--;
	int randNum = rand() % 100;

	if (0 <= randNum && randNum < ball.getProbability()) return true;
	else return false;

	/*
	가령 현재 이 볼 주머니는 확률 20인 볼을 담는 주머니라고 하면
	0~19 까지의 값이 나오면 몬스터를 잡았다고 true 값을 리턴하고
	20~99 까지의 값이 나오면 몬스터를 놓쳤다고 false값을 리턴한다.
	*/
}