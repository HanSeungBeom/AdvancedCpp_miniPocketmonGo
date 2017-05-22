#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"
#include "MonsterData.h"
#include "Ball.h"
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

	vector<Ball> readMonsterBallFromFile();
	vector<MonsterData> readMonsterFromFile();
	Player* readPlayerFromFile(vector<MonsterData> monsterDatas, vector<Ball> balls);
};
