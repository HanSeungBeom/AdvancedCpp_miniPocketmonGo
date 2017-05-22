#include "MiniPoketmonGo.h"
#include "FileManager.h"
#include "Player.h"
#include <fstream>

MiniPoketmonGo::MiniPoketmonGo()
{
	fm = new FileManager();
	loadData();
}


MiniPoketmonGo::~MiniPoketmonGo()
{
	
}
void MiniPoketmonGo::loadData(){
	monsters = fm->readMonsterFromFile();
	balls = fm->readMonsterBallFromFile();
	player = fm->readPlayerFromFile(monsters, balls);
}


void MiniPoketmonGo::debug(){
	for (int i = 0; i < monsters.size(); i++){
		cout << monsters.at(i).getName() << endl;
	}
}
