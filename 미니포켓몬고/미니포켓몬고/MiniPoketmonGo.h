#pragma once
#include "MonsterData.h"
#include "BallData.h"
#include "FileManager.h"

class MiniPoketmonGo
{
	FileManager* fm;		//���� ������
	Player* player;			//���� �÷��̾�
	vector<MonsterData> monstersData;//���� ������
	vector<BallData> ballsData;		 //���ͺ� ������
	bool loadSuccess;

public:
	MiniPoketmonGo();
	~MiniPoketmonGo();

	//���� �ý��� �Լ�
	void loadData(); //������ �ε� �Լ�
	void run();      //���� ���� �Լ�
	
	//���� �÷��� �Լ�
	int menu_main(); //���� �Լ� 
	void menuPlayer(); //�÷��̾�����
	void menuMonster(); //�� ����
	void menuBuy(); //���ͺ� ����
	void menuGetPoketmon(); //���ϸ� ���
	void menuExitandSave(); //����&����

	//��Ÿ �Լ�
	Monster getRandomMonster();//���� ���� �����Լ�
	string getMonsterName(int id);//id�� �´� ���� �̸�
	string getBallName(int id);  //id�� �´� �� �̸�
	int getBallprice(int id); //id�� �´� �� ����
	
};

