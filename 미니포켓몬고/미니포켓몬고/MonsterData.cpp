#include "MonsterData.h"
#include "Monster.h"

MonsterData::MonsterData(int id,string name,int type, int probability)
{
	this->id = id;
	this->name = name;
	this->type = type;
	this->probability = probability;
}


MonsterData::MonsterData(){

}
MonsterData::~MonsterData()
{
}

Monster MonsterData::genMonster(){
	int hp = rand() % 16;
	int attk = rand() % 16;
	int def = rand() % 16;
	int cp = hp*attk*attk*def;
	Monster newMonster(id,name,hp, attk, def,cp);
	return newMonster;
}

Monster MonsterData::genMonster(string nickname, int hp, int attk, int def){
	Monster newMonster(id, nickname, hp, attk, def, hp*attk*attk*def);
	return newMonster;
}

int MonsterData::getId(){
	return id;
}

string MonsterData::getName(){
	return name;
}
int MonsterData::getType(){
	return type;
}

int MonsterData::getProbability(){
	return probability;
}