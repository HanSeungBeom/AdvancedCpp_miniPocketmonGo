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
	bool loadSuccess;

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
	int getBallprice(int id);
	void menuExitandSave();
	
	void debug();
	Monster getRandomMonster();
	

};

