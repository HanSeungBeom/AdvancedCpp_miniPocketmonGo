#pragma once
#include <iostream>
#include <string>
using namespace std;

class BallData
{
	int id;				//����ȣ
	string name;		//���̸�
	int price;			//������
	int probability;	//Ȯ��
public:
	BallData();
	BallData(int id, string ballName, int price, int probability);
	~BallData();

	//getter
	int getId();
	string getName();
	int getPrice();
	int getProbability();
};
