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
	//txt���� �̸�
	string playerFile;
	string poketmonFile;
	string mosterballFile;

public:
	FileManager();
	~FileManager();

	//���Ϸκ��� �о���� �Լ�
	vector<BallData> readMonsterBallFromFile(bool& loadSuccess);
	vector<MonsterData> readMonsterFromFile(bool& loadSuccess);
	Player* readPlayerFromFile(vector<MonsterData> monsterData, vector<BallData> ballsData);
	
	//���Ͽ� ���� �Լ�
	void writePlayerToFile(Player* player);
	
};
