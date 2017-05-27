#pragma once
#include "MonsterData.h"
#include "BallData.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//파일 관리자
	Player* player;		//게임 플레이어
	vector<MonsterData> monstersData;	//몬스터 데이터
	vector<BallData> ballsData;		//몬스터볼 데이터
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

