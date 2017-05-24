#include "Monster.h"


Monster::Monster(int id,string nickname, int hp, int attk,int def,int cp)
	{
	this->id = id;
	this->nickname = nickname;
	this->hp = hp;
	this->attk = attk;
	this->def = def;
	this->cp = cp;
}

Monster::~Monster()
{
}

string Monster::getNickname(){
	return nickname;
}

void Monster::setNickname(string nickname){
	this->nickname = nickname;
}

int Monster::getCp(){
	return cp;
}

int Monster::getId(){
	return id;
}


