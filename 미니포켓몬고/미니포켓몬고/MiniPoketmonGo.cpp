#include "MiniPoketmonGo.h"
#include "FileManager.h"
#include "Player.h"
#include "Menu.h"
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
	monstersData = fm->readMonsterFromFile();
	balls = fm->readMonsterBallFromFile();
	player = fm->readPlayerFromFile(monstersData, balls);
}


void MiniPoketmonGo::debug(){
	for (int i = 0; i < monstersData.size(); i++){
		cout << monstersData.at(i).getName() << endl;
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
			menuMonster();
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

	for (int i = 0; i < ballPocket.size() + 1; i++){
		
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

void MiniPoketmonGo::menuMonster(){
	
	vector<Monster>& monsters = player->getMonster();
	Menu menu("�� ���� ���� & ���� ����");
	for (int i = 0; i < monsters.size(); i++){
		menu.addMenu("�̸� : " + monsters.at(i).getNickname()
			+ "(" + getMonsterName(monsters.at(i).getId()) + ")"
			+ " / CP : " + to_string(monsters.at(i).getCp()));
	}
	menu.addMenu("���� ����ϱ�");
	menu.addMenu("���� �޴��� ���ư���");
	
	while (1){
		menu.printMenu();
		int input = menu.input();
		if (input == menu.getMenuNum() - 1){//���� ����ϱ�
			
			if (monsters.size() == 0){
				cout << "����� ���Ͱ� �����ϴ�." << endl;
				cin.ignore(); getchar();
				return;
			}

			int num;
			cout << "����� ���ϸ��� ��ȣ�� �Է��ϼ��� : ";
			while (1){
				cin >> num;
				if (0<num && num<=monsters.size()){
					monsters.erase(monsters.begin() + (num - 1));
					menu.delMenu(num - 1);
					break;
				}
				else{
					cout << "�Է� ������ ������ϴ�." << endl;
				}
			}

		}
		else if (input == menu.getMenuNum()){//���� �޴��� ���ư���
			break;
		}
		else{//�ش� ���� Ŭ���Ͽ��� ��.
			string nickname;
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin.ignore();
			getline(cin, nickname);
			monsters.at(input - 1).setNickname(nickname);
			menu.setMenu(input - 1, "�̸� : " + monsters.at(input-1).getNickname()
				+ "(" + getMonsterName(monsters.at(input - 1).getId()) + ")"
				+ " / CP : " + to_string(monsters.at(input - 1).getCp()));
		}
	}

}

string MiniPoketmonGo::getMonsterName(int id){
	for (int i = 0; i < monstersData.size(); i++){
		if (monstersData.at(i).getId() == id){
			return monstersData.at(i).getName();
		}
	}
}