#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Ball.h"

class Player
{
	string name;//�̸�
	int sex;	//���� 1:����/2:����
	int money;	//������
	int maxMonster; //�ִ� ���� �� �ִ� ������ ��
	int maxBall;	//�ִ� ���� ���ͺ� ��
	int ballKind;	//���� ���� ������
	vector<Ball,int> ball;


public:
	Player();
	~Player();
};

