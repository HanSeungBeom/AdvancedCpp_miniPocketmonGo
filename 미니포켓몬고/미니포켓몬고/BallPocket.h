#pragma once
#include "Ball.h"

class BallPocket //���ָӴ�
{
	Ball ball;
	int id;     //�� �ָӴϿ� �־����ִ� �� ����
	int num;     //����ִ� ��
public:
	BallPocket(Ball ball,int id, int num);
	~BallPocket();
	int getId();
	int getNum();
	void setNum(int num);
	void addNum(int num);
	bool throwBall();
};
