#pragma once
#include "MonsterData.h"
#include "Ball.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//���� ������
	Player* player;		//���� �÷��̾�
	vector<MonsterData> monsters;	//���� ������
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
	//void menuMonster();
	void menuBuy();
	//void menuGetPoketmon();
	//void menuExit();
	
	void debug();
};

