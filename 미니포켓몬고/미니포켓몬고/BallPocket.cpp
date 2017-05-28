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
	//�ش� �������� ���� ������ �Լ�
	//���� �ϳ� �����ϰ�
	//���� Ȯ���� ���� ��Ҵ��� ����Ҵ��� bool ���� �����Ѵ�.

	this->num--;
	int randNum = rand() % 100;

	if (0 <= randNum && randNum < ball.getProbability()) return true;
	else return false;

	/*
	���� ���� �� �� �ָӴϴ� Ȯ�� 20�� ���� ��� �ָӴ϶�� �ϸ�
	0~19 ������ ���� ������ ���͸� ��Ҵٰ� true ���� �����ϰ�
	20~99 ������ ���� ������ ���͸� ���ƴٰ� false���� �����Ѵ�.
	*/
}