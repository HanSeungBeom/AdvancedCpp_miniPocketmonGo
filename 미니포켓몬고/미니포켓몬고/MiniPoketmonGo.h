#pragma once
#include "player.h"
#include "Ball.h"


class MiniPoketmonGo
{
	Player player;		//게임 플레이어
	Monster* monsters;	//몬스터 데이터
	Ball balls;			//몬스터볼 데이터

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();
	void loadData();		
	void loadPlayerData();	//플레이어 파일데이터 로드
	void loadMosterData();	//몬스터 파일데이터 로드
	void loadBallData();	//몬스터볼 파일데이터 로드
	void saveData();
	void savePlayerData();  //플레이어 파일데이터 세이브
	void saveMonsterData(); //몬스터 파일데이터 세이브
	void saveBallData();	//몬스터볼 파일데이터 세이브

	void menuPlayer();
	void menuMonster();
	void menuBuy();
	void menuGetPoketmon();
	void menuExit();
};

