#pragma once
#include "MonsterData.h"
#include "Ball.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//���� ������
	Player* player;		//���� �÷��̾�
	vector<MonsterData> monstersData;	//���� ������
	vector<Ball> ballsData;		//���ͺ� ������

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();
	void loadData();	
	/*
	void saveData();

	*/
	void run();
	int menu_main();
	void menuPlayer();
	void menuMonster();
	void menuBuy();
	void menuGetPoketmon();
	string getMonsterName(int id); 
	string getBallName(int id);
	//void menuGetPoketmon();
	//void menuExit();
	
	void debug();
	Monster getRandomMonster();

};

