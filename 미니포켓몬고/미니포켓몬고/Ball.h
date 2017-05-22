#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ball
{
	int id;				//볼번호
	string name;		//볼이름
	int price;			//볼가격
	int probability;	//확률
public:
	Ball();
	Ball(int id, string ballName, int price, int probability);
	~Ball();
	int getId();
	
};
