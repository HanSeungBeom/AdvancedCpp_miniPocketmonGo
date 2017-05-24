#pragma once
#include "MonsterData.h"
#include "Ball.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//���� ������
	Player* player;		//���� �÷��̾�
	vector<MonsterData> monstersData;	//���� ������
	vector<Ball> balls;		//���ͺ� ������

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
	string getMonsterName(int id); 
	//void menuGetPoketmon();
	//void menuExit();
	
	void debug();
};

