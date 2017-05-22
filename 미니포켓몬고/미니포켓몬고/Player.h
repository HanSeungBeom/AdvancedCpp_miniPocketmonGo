#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BallPocket.h"
#include "Monster.h"
using namespace std;

class Player
{
	string name;//�̸�
	int sex;	//���� 1:����/2:����
	int money;	//������
	int maxMonster; //�ִ� ���� �� �ִ� ������ ��
	int maxBall;	//�ִ� ���� ���ͺ� ��
	int ballKind;	//���� ���� ������
	vector<BallPocket> ballPocket;  //������ �� 
	int monsterCount; //��ȹ�� ���� ��
	vector<Monster> monsters;	//���� ����
public:
	Player(string name, 
		int sex, 
		int money, 
		int maxMonster, 
		int maxBall, 
		int ballKind, 
		vector<BallPocket> ballPocket, 
		int monsterCount, 
		vector<Monster> monsters);
	~Player();
};

#pragma once

