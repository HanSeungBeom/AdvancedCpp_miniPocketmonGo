#pragma once
#include "Ball.h"

class BallPocket //���ָӴ�
{
	Ball ball;     //�� �ָӴϿ� �־����ִ� �� ����
	int num;       //����ִ� ��
public:
	BallPocket(Ball ball, int num);
	~BallPocket();
	Ball getBall();
	int getNum();
	void setNum(int num);
	void addNum(int num);
	bool throwBall();
};
