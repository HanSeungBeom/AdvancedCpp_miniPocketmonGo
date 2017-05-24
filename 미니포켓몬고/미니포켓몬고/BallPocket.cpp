#include "BallPocket.h"
#include "Ball.h"


BallPocket::BallPocket(Ball ball,int num)
{
	this->ball = ball;
	this->num = num;
}

BallPocket::~BallPocket()
{
}

Ball BallPocket::getBall(){
	return ball;
}
int BallPocket::getNum(){
	return num;
}

void BallPocket::setNum(int num){
	this->num = num;
}
void BallPocket::addNum(int num){
	this->num += num;
}
bool BallPocket::throwBall(){
	this->num--;
	int randNum = rand() % 100;

	if (0 <= randNum && randNum < ball.getProbability()) return true;
	else return false;
}