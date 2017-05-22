#include "MiniPoketmonGo.h"
#include "FileManager.h"
#include "Player.h"
#include <fstream>

MiniPoketmonGo::MiniPoketmonGo()
{
	fm = new FileManager();
	loadData();
}


MiniPoketmonGo::~MiniPoketmonGo()
{
	
}
void MiniPoketmonGo::loadData(){
	monsters = fm->readMonsterFromFile();
	balls = fm->readMonsterBallFromFile();
	player = fm->readPlayerFromFile(monsters, balls);
}


void MiniPoketmonGo::debug(){
	for (int i = 0; i < monsters.size(); i++){
		cout << monsters.at(i).getName() << endl;
	}
}

void MiniPoketmonGo::run(){
	bool out = false;
	while (!out){
		switch (menu_main()){
		case 1:
			menuPlayer();
			break;
		case 2:
			//menuMonster();
			break;
		case 3:
			//menuBuy();
			break;
		case 4:
			//menuGetPoketmon();
			break;
		case 5:
			//menuExit();
			out = true;
			break;
		}
	}
}
int MiniPoketmonGo::menu_main(){
	int selectedNum;
	bool isError = false;
	while (1){
		system("cls");
		cout << "�̴� ���ϸ� ��" << endl << endl;
		cout << "1. �÷��̾� ���� ���� & ���� ����" << endl;
		cout << "2. �� ���� ���� & ���� ����" << endl;
		cout << "3. ���ͺ� �����ϱ�" << endl;
		cout << "4. ���� ���" << endl;
		cout << "5. ���� & ����" << endl;
		if (isError)
			cout << "�Է¹����� ���� �����ϴ�. �ٽ� �Է����ּ���" << endl;
		cin >> selectedNum;
		if (!(1 <= selectedNum && selectedNum <= 5))
			isError = true;
		
		else
			break;
		
	}
	return selectedNum;
}

void MiniPoketmonGo::menuPlayer(){
	bool isError = false;
	bool out = false;
	int selectedNum;
	while (!out){
		while (1){
			system("cls");
			cout << "�÷��̾� ����" << endl << endl;
			cout << "�̸� : " << player->getName() << endl;
			cout << "���� : " << ((player->getSex() == 1) ? "��" : "��") << endl;
			cout << "������ : " << player->getMoney() << endl;
			cout << "�ִ� ���� ���� ���� �� : " << player->getMaxMonster() << endl;
			cout << "�ִ� ���� ���� ���� �� �� : " << player->getMaxBall() << endl<<endl;

			cout << "1. �÷��̾� �̸� ����" << endl;
			cout << "2. ������ �߰��ϱ�" << endl;
			cout << "3. �ִ� ���� ���� ���� �� �߰��ϱ�" << endl;
			cout << "4. �ִ� ���� ���� ���� �� �� �߰��ϱ�" << endl;
			cout << "5. ���� �޴��� ���ư���" << endl;

			if (isError)
				cout << "�Է¹����� ���� �����ϴ�. �ٽ� �Է����ּ���" << endl;
			cin >> selectedNum;
			if (!(1 <= selectedNum && selectedNum <= 5)){
				isError = true;
			}
			else
				break;
		}

		switch (selectedNum){
		case 1:{
				   string newName;
				   cin.ignore();
				   cout << "������ �̸��� �Է��ϼ��� : ";
				   getline(cin, newName);
				   player->setName(newName);
		}
			break;
		case 2:{
				   int addMoney;
				   cout << "�߰��� �׼��� �Է��ϼ��� : ";
				   cin >> addMoney;
				   player->setMoney(player->getMoney()+addMoney);
		}
			break;
		case 3:{
				   int addMaxMonster;
				   cout << "�߰��� ���� �Է��ϼ��� : ";
				   cin >> addMaxMonster;
				   player->setMaxMonster(player->getMaxMonster() + addMaxMonster);
		}
			break;
		case 4:{
				   int addMaxBall;
				   cout << "�߰��� ���� �Է��ϼ��� : ";
				   cin >> addMaxBall;
				   player->setMaxBall(player->getMaxBall() + addMaxBall);
		}
			break;
		case 5:
			out = true;
			break;
		}
	}

}