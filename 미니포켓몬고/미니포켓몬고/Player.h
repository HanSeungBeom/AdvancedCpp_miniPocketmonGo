#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Monster.h"

class Player
{
	string name;//�̸�
	int sex;	//���� 1:����/2:����
	int money;	//������
	int maxMonster; //�ִ� ���� �� �ִ� ������ ��
	int maxBall;	//�ִ� ���� ���ͺ� ��
	int ballKind;	//���� ���� ������
	int*ballCount;  //������ �� ��
	int monsterCount; //��ȹ�� ���� ��
	vector<Monster> mosters;	//���� ����
public:
	Player();
	~Player();
};

