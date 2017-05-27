#pragma once
#include <iostream>
#include <string>
using namespace std;

class BallData
{
	int id;				//볼번호
	string name;		//볼이름
	int price;			//볼가격
	int probability;	//확률
public:
	BallData();
	BallData(int id, string ballName, int price, int probability);
	~BallData();
	int getId();
	string getName();
	int getPrice();
	int getProbability();
	
};
