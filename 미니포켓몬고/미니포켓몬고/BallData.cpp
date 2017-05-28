#include "BallData.h"

BallData::BallData(){

}

BallData::BallData(int id, string name, int price, int probability)
{
	this->id = id;
	this->name = name;
	this->price = price;
	this->probability = probability;
}

BallData::~BallData()
{
}

int BallData::getId(){
	return id;
}

string BallData::getName(){
	return name;
}

int BallData::getPrice(){
	return price;
}

int BallData::getProbability(){
	return probability;
}


