#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ball
{
	int id;				//����ȣ
	string name;		//���̸�
	int price;			//������
	int probability;	//Ȯ��
public:
	Ball();
	Ball(int id, string ballName, int price, int probability);
	~Ball();
	int getId();
	string getName();
	int getPrice();
	int getProbability();
	
};
