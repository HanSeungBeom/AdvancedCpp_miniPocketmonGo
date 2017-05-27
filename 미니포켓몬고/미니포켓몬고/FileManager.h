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
	//txt파일 이름
	string playerFile;
	string poketmonFile;
	string mosterballFile;

public:
	FileManager();
	~FileManager();

	//파일로부터 읽어오는 함수
	vector<BallData> readMonsterBallFromFile(bool& loadSuccess);
	vector<MonsterData> readMonsterFromFile(bool& loadSuccess);
	Player* readPlayerFromFile(vector<MonsterData> monsterData, vector<BallData> ballsData);
	
	//파일에 쓰는 함수
	void writePlayerToFile(Player* player);
	
};
