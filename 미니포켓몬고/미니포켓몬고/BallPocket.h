#pragma once
#include "BallData.h"

class BallPocket //볼주머니
{
	BallData ball;
	int id;     //볼 주머니에 넣어져있는 볼 종류
	int num;     //들어있는 수
public:
	BallPocket(BallData ball, int id, int num);
	~BallPocket();
	int getId();
	int getNum();
	void setNum(int num);
	void addNum(int num);
	bool throwBall();
};
