#pragma once
#include "MonsterData.h"
#include "Ball.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//파일 관리자
	Player* player;		//게임 플레이어
	vector<MonsterData> monsters;	//몬스터 데이터
	vector<Ball> balls;		//몬스터볼 데이터

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();
	void loadData();	
	/*
	void saveData();
	void savePlayerData();  //플레이어 파일데이터 세이브
	void saveMonsterData(); //몬스터 파일데이터 세이브
	void saveBallData();	//몬스터볼 파일데이터 세이브

	void menu_main();
	void menuPlayer();
	void menuMonster();
	void menuBuy();
	void menuGetPoketmon();
	void menuExit();
	*/
	void debug();
};

