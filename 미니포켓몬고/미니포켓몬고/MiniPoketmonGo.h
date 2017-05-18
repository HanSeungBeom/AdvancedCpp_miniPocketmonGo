#pragma once
#include "player.h"
#include "Ball.h"


class MiniPoketmonGo
{
	Player player;		//���� �÷��̾�
	Monster* monsters;	//���� ������
	Ball balls;			//���ͺ� ������

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();
	void loadData();		
	void loadPlayerData();	//�÷��̾� ���ϵ����� �ε�
	void loadMosterData();	//���� ���ϵ����� �ε�
	void loadBallData();	//���ͺ� ���ϵ����� �ε�
	void saveData();
	void savePlayerData();  //�÷��̾� ���ϵ����� ���̺�
	void saveMonsterData(); //���� ���ϵ����� ���̺�
	void saveBallData();	//���ͺ� ���ϵ����� ���̺�

	void menuPlayer();
	void menuMonster();
	void menuBuy();
	void menuGetPoketmon();
	void menuExit();
};

