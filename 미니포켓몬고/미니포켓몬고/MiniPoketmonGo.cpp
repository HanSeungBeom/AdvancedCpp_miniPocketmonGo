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
			menuBuy();
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

void MiniPoketmonGo::menuBuy(){
	system("cls");
	cout << "���ͺ� ���� (������ : " << player->getMoney() << "��)" << endl << endl;
	vector<BallPocket>& ballPocket = player->getBallPocket();

	int playerTotalBallNum = 0;
	for (int i = 0; i < ballPocket.size(); i++) playerTotalBallNum += ballPocket.at(i).getNum();

	for (int i = 0; i < ballPocket.size()+1; i++){
		
		if (i == ballPocket.size()){
			cout << (i + 1) << ". ���θ޴��� ���ư���" << endl;
		}
		else{
			BallPocket nowPocket = ballPocket.at(i);
			cout << (i + 1) << ". " << nowPocket.getBall().getName()
			<< "(" << nowPocket.getNum() << "�� ���� ��) ���� " << nowPocket.getBall().getPrice() << "��" << endl;
		}
	}
	
	while (1){
		int selectedNum; cin >> selectedNum;
		if (1 <= selectedNum && selectedNum <= ballPocket.size()+1){
			if (selectedNum == (ballPocket.size()+1) ){
				return;
			}
			while (1){
				cout << "���ϴ� ���� ������ �Է��ϼ��� : ";
				int num; cin >> num;
				if (player->getMaxBall() < playerTotalBallNum + num){
					cout << "�� ���� ������ �Ѿ�� �˴ϴ�." << endl;
					continue;
				}
				else{
					int price = num * (ballPocket.at(selectedNum - 1).getBall().getPrice());
					if (player->getMoney() < price){
						cout << "������ �ݾ׺��� ���� �ݾ��� �ʿ��մϴ�." << endl;
					}
					else{
						player->setMoney(player->getMoney() - price);
						ballPocket.at(selectedNum - 1).addNum(num);
						return;
					}
				}
			}
		}
		else{
			cout << "�Է� ������ ������ϴ�." << endl;
		}
	}
}
