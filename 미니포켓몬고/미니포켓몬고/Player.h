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

	//getter
	string getName();
	int getSex();
	int getMoney();
	int getMaxMonster();
	int getMaxBall();
	int getBallKind();
	vector<BallPocket>& getBallPocket();
	vector<Monster>& getMonster();

	//setter
	void setName(string name);
	void setSex(int sex);
	void setMoney(int money);
	void setMaxMonster(int maxMonster);
	void setMaxBall(int maxBall);	
};

#pragma once

