#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"
#include "MonsterData.h"
#include "BallData.h"
using namespace std;

class FileManager
{
	string playerFile;
	string poketmonFile;
	string mosterballFile;

public:
	FileManager();
	~FileManager();

	string getPlayerFile();
	string getPoketmonFile();
	string getMonsterballFile();

	vector<BallData> readMonsterBallFromFile(bool& loadSuccess);
	vector<MonsterData> readMonsterFromFile(bool& loadSuccess);
	Player* readPlayerFromFile(vector<MonsterData> monsterData, vector<BallData> ballsData);
	void writePlayerToFile(Player* player);
	
};
