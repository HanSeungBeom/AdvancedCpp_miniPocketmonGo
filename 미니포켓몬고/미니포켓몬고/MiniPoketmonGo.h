#pragma once
#include "MonsterData.h"
#include "BallData.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//파일 관리자
	Player* player;			//게임 플레이어
	vector<MonsterData> monstersData;//몬스터 데이터
	vector<BallData> ballsData;		 //몬스터볼 데이터
	bool loadSuccess;

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();

	//게임 시스템 함수
	void loadData(); //데이터 로딩 함수
	void run();      //게임 실행 함수
	
	//게임 플레이 함수
	int menu_main(); //선택 함수 
	void menuPlayer(); //플레이어정보
	void menuMonster(); //내 몬스터
	void menuBuy(); //몬스터볼 구입
	void menuGetPoketmon(); //포켓몬 잡기
	void menuExitandSave(); //저장&종료

	//기타 함수
	Monster getRandomMonster();//랜덤 몬스터 생성함수
	string getMonsterName(int id);//id에 맞는 몬스터 이름
	string getBallName(int id);  //id에 맞는 공 이름
	int getBallprice(int id); //id에 맞는 공 가격
	
};

