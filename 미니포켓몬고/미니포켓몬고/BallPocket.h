#pragma once
#include "BallData.h"

class BallPocket //���ָӴ�
{
	BallData ball;
	int id;     //�� �ָӴϿ� �־����ִ� �� ����
	int num;     //����ִ� ��
public:
	BallPocket(BallData ball, int id, int num);
	~BallPocket();
	int getId();
	int getNum();
	void setNum(int num);
	void addNum(int num);
	bool throwBall();
};
