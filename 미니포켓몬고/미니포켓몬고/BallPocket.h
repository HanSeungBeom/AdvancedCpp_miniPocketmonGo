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

	//getter
	int getId();
	int getNum();
	//setter
	void setNum(int num);
	
	bool throwBall(); //�ش� ���� ������ �Լ�
};
