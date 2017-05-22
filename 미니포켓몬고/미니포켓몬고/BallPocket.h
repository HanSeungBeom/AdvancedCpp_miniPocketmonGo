#pragma once
#include "Ball.h"

class BallPocket //볼주머니
{
	Ball ball;     //볼 주머니에 넣어져있는 볼 종류
	int num;       //들어있는 수
public:
	BallPocket(Ball ball, int num);
	~BallPocket();
};
