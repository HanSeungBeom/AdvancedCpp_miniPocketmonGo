#pragma once
#include "Ball.h"

class BallPocket //���ָӴ�
{
	Ball ball;     //�� �ָӴϿ� �־����ִ� �� ����
	int num;       //����ִ� ��
public:
	BallPocket(Ball ball, int num);
	~BallPocket();
};
