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
	delete fm;
	delete player;
}

void MiniPoketmonGo::loadData(){
	monstersData = fm->readMonsterFromFile(loadSuccess);
	ballsData = fm->readMonsterBallFromFile(loadSuccess);
	player = fm->readPlayerFromFile(monstersData, ballsData);
}

void MiniPoketmonGo::run(){
	if (!loadSuccess){
		cout << "�����͸� �������µ� �����Ͽ� ���α׷��� ����˴ϴ�." << endl;
		cin.ignore();
		getchar();
		return;
	}

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
			menuGetPoketmon();
			break;
		case 5:
			menuExitandSave();
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
			cout << (i + 1) << ". " << getBallName(nowPocket.getId())
			<< "(" << nowPocket.getNum() << "�� ���� ��) ���� " << getBallprice(nowPocket.getId()) << "��" << endl;
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
					int price = num * getBallprice(ballPocket.at(selectedNum - 1).getId());
					if (player->getMoney() < price){
						cout << "������ �ݾ׺��� ���� �ݾ��� �ʿ��մϴ�." << endl;
					}
					else{
						player->setMoney(player->getMoney() - price);
						ballPocket.at(selectedNum - 1).setNum( ballPocket.at(selectedNum-1).getNum() + num);
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

void MiniPoketmonGo::menuGetPoketmon(){
	Monster genMonster = getRandomMonster();
	string title = "���� ���\n\n"+  getMonsterName(genMonster.getId()) + "(CP : " + to_string(genMonster.getCp()) + ")";
	Menu menu(title);
	bool runaway = false;
	bool catchPoketmon = false;
	int selectedPocket = -1;


	while (!(runaway || catchPoketmon)){ //����ġ�ų�, ���͸� ������ ����
	
		//�� �ʱ�ȭ
		menu.clearMenu();
		bool empty = true;

		//�÷��̾��� �� ���� ������ �����´�.
		vector<BallPocket>& playerPocket = player->getBallPocket();	


		//���� �������� �ʾ��� ��(ó�� �޴��� ������ ��)
		if (selectedPocket == -1){ 

			//���� id�� ���� �� ���� �����Ͽ� ���� ������ �޴��� ����Ѵ�.
			for (int i = 0; i < playerPocket.size(); i++){
				if (playerPocket.at(i).getNum() != 0){
					empty = false; //���� ������ empty�� false�� �ϰ�
					selectedPocket = (i+1); //���õ� �� ���� ��ȣ�� �����Ѵ�.
					menu.addMenu(getBallName(playerPocket.at(i)
						.getId()) + " ������(" + to_string((playerPocket.at(i).getNum())) + "�� ����)");
					break;
				}
			}
		}
		//���� ������ ��� (�� �������� ���� ������ ����)
		else{
			//���� ���� ��� �޴��� �߰�
			if (playerPocket.at(selectedPocket - 1).getNum() != 0){
				empty = false;
				menu.addMenu(getBallName(playerPocket.at(selectedPocket - 1)
				.getId()) + " ������(" + to_string((playerPocket.at(selectedPocket - 1).getNum())) + "�� ����)");
			}
			//���� ��� empty = true
			else{
				empty = true;
			}
		}

		//ȭ����� �κ�
		if (empty){
			menu.addMenu("���ϸ� �� ������(���Ϻ��� �����ϴ�.)");
		}
		menu.addMenu("���� �� ����");
		menu.addMenu("��������");
		menu.printMenu();
		
		//�޴� ���� �κ�
		int input = menu.input();
		switch (input){
		case 1:{//���ϸ� �� ������

				   //���� ������
				   if (empty){
					   cout << "���Ϻ��� �����ϴ�. �ٸ� �޴��� �������ּ���" << endl;
					   cin.ignore();
					   getchar();
				   }
				   //���� ������
				   else{
					   //���� ���õ� �� ���� ������ �����´�.
					   BallPocket& nowBallPocket = playerPocket.at(selectedPocket - 1);
					   
					   //����� ��
					   if (nowBallPocket.throwBall()){
						   //�÷��̾��� ���� ����Ʈ�� �����´�.
						   vector<Monster>& playerMonster = player->getMonster();

						   //������ ���͸� ����Ʈ�� �ִ´�.
						   playerMonster.push_back(genMonster);
						   cout << "��ҽ��ϴ�. (���� �Է½� ���� �޴��� ���ư��ϴ�.)" << endl;
						   cin.ignore(); getchar();
						   catchPoketmon = true;
				
					   }
					   //������ ��
					   else{
						   cout << "Ƣ��Խ��ϴ�." << endl;
						   cin.ignore();
						   getchar();
					   }

				   }
		}
			break;
		case 2:{//���� �� ����
				   Menu selBallMenu("���� �� ����");

				   for (int i = 0; i < playerPocket.size(); i++){
					   selBallMenu.addMenu(getBallName(playerPocket.at(i).getId()) + "(" + to_string(playerPocket.at(i).getNum()) + "�� ����)");
				   }
				   selBallMenu.printMenu();
				   selectedPocket = selBallMenu.input();//������ ��ȣ�� �����Ѵ�.
		}
			break;
		case 3:{//��������
				   runaway = true;
		}
			break;
		}

	}
}

void MiniPoketmonGo::menuExitandSave(){
	//���ϸŴ����� ���� ������ player��ü�� Player.txt�� �����Ѵ�.
	fm->writePlayerToFile(player);
}

Monster MiniPoketmonGo::getRandomMonster(){
	int totalProbability = 0;
	
	//�� ���͵��� ���� Ȯ���� ��ü�� �� ���Ѵ�.
	for (int i = 0; i < monstersData.size(); i++){
		totalProbability += monstersData.at(i).getProbability();
	}

	//���� ���� ��ü�߿� �̴´�.
	int randNum = rand() % totalProbability;
	
	//AȮ���� 20, BȮ���� 10, CȮ���� 5���
	//totalProbability = 35 �̸�
	// A���ϸ�Ȯ��(0~19), B���ϸ� Ȯ��(20~29), C���ϸ�(30~34)�� ������ �Ͽ���.
	// �׷��� �Ʒ��� randNum�� �� �߿� ��� ���ϴ����� ������ �˰����̴�.
	
	
	int index = 0;
	while (randNum >= monstersData.at(index).getProbability()){
		randNum -= monstersData.at(index).getProbability();
		index++;
	}
	/*
	���� ��� ���� ��Ȳ���� randNum �� 22�� ���Դٸ�
	randNum (22) �� ù��° ������ ���ɼ� 20 ���� ũ�Ƿ�
	randNum���� ù��° ������ ���ɼ��� ������ �����Ѵ�.
	�׸��� index�� ����ĭ���� �ű��.

	�׷��� randNum(2) �� �ӳ�° ������ ���ɼ� 10���� �����Ƿ� while���� ����������
	�ι�° ������ �����͸� ������ ���͸� ���� return �Ѵ�.
	*/

	return monstersData.at(index).genMonster();
}

string MiniPoketmonGo::getMonsterName(int id){
	//id�� �ش��ϴ� ���� �̸��� return�Ѵ�.
	for (int i = 0; i < monstersData.size(); i++){
		if (monstersData.at(i).getId() == id){
			return monstersData.at(i).getName();
		}
	}
}

string MiniPoketmonGo::getBallName(int id){
	//id�� �ش��ϴ� ���̸��� return�Ѵ�.
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getName();
		}
	}
}

int MiniPoketmonGo::getBallprice(int id){
	//id�� �ش��ϴ� �������� return�Ѵ�.
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getPrice();
		}
	}
}