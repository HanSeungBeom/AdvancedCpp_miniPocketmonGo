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
	string getName();
	void setName(string name);
	int getSex();
	void setSex(int sex);
	int getMoney();
	void setMoney(int money);
	int getMaxMonster();
	void setMaxMonster(int maxMonster);
	int getMaxBall();
	void setMaxBall(int maxBall);
	int getBallKind();
	vector<BallPocket>& getBallPocket();
	vector<Monster>& getMonster();
	
};

#pragma once

