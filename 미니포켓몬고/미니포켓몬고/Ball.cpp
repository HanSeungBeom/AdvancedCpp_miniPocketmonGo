#include "Ball.h"

Ball::Ball(){

}

Ball::Ball(int id, string name, int price, int probability)
{
	this->id = id;
	this->name = name;
	this->price = price;
	this->probability = probability;
}


Ball::~Ball()
{
}

int Ball::getId(){
	return id;
}
