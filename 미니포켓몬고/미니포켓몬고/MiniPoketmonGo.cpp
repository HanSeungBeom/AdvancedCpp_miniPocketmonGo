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
	ballsData = fm->readMonsterBallFromFile();
	player = fm->readPlayerFromFile(monstersData, ballsData);
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
		cout << "미니 포켓몬 고" << endl << endl;
		cout << "1. 플레이어 정보 보기 & 정보 변경" << endl;
		cout << "2. 내 몬스터 보기 & 정보 변경" << endl;
		cout << "3. 몬스터볼 구입하기" << endl;
		cout << "4. 몬스터 잡기" << endl;
		cout << "5. 저장 & 종료" << endl;
		if (isError)
			cout << "입력범위가 벗어 났습니다. 다시 입력해주세요" << endl;
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
			cout << "플레이어 정보" << endl << endl;
			cout << "이름 : " << player->getName() << endl;
			cout << "성별 : " << ((player->getSex() == 1) ? "남" : "여") << endl;
			cout << "소지금 : " << player->getMoney() << endl;
			cout << "최대 보유 가능 몬스터 수 : " << player->getMaxMonster() << endl;
			cout << "최대 보유 가능 몬스터 볼 수 : " << player->getMaxBall() << endl<<endl;

			cout << "1. 플레이어 이름 변경" << endl;
			cout << "2. 소지금 추가하기" << endl;
			cout << "3. 최대 보유 가능 몬스터 수 추가하기" << endl;
			cout << "4. 최대 보유 가능 몬스터 볼 수 추가하기" << endl;
			cout << "5. 메인 메뉴로 돌아가기" << endl;

			if (isError)
				cout << "입력범위가 벗어 났습니다. 다시 입력해주세요" << endl;
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
				   cout << "변경할 이름을 입력하세요 : ";
				   getline(cin, newName);
				   player->setName(newName);
		}
			break;
		case 2:{
				   int addMoney;
				   cout << "추가할 액수를 입력하세요 : ";
				   cin >> addMoney;
				   player->setMoney(player->getMoney()+addMoney);
		}
			break;
		case 3:{
				   int addMaxMonster;
				   cout << "추가할 수를 입력하세요 : ";
				   cin >> addMaxMonster;
				   player->setMaxMonster(player->getMaxMonster() + addMaxMonster);
		}
			break;
		case 4:{
				   int addMaxBall;
				   cout << "추가할 수를 입력하세요 : ";
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
	cout << "몬스터볼 구입 (소지금 : " << player->getMoney() << "원)" << endl << endl;
	vector<BallPocket>& ballPocket = player->getBallPocket();

	int playerTotalBallNum = 0;
	for (int i = 0; i < ballPocket.size(); i++) playerTotalBallNum += ballPocket.at(i).getNum();

	for (int i = 0; i < ballPocket.size() + 1; i++){
		
		if (i == ballPocket.size()){
			cout << (i + 1) << ". 메인메뉴로 돌아가기" << endl;
		}
		else{
			BallPocket nowPocket = ballPocket.at(i);
			cout << (i + 1) << ". " << getBallName(nowPocket.getId())
			<< "(" << nowPocket.getNum() << "개 보유 중) 개당 " << getBallprice(nowPocket.getId()) << "원" << endl;
		}
	}
	
	while (1){
		int selectedNum; cin >> selectedNum;
		if (1 <= selectedNum && selectedNum <= ballPocket.size()+1){
			if (selectedNum == (ballPocket.size()+1) ){
				return;
			}
			while (1){
				cout << "원하는 구매 수량을 입력하세요 : ";
				int num; cin >> num;
				if (player->getMaxBall() < playerTotalBallNum + num){
					cout << "총 보유 수량을 넘어서게 됩니다." << endl;
					continue;
				}
				else{
					int price = num * getBallprice(ballPocket.at(selectedNum - 1).getId());
					if (player->getMoney() < price){
						cout << "보유한 금액보다 많은 금액이 필요합니다." << endl;
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
			cout << "입력 범위를 벗어났습니다." << endl;
		}
	}
}

void MiniPoketmonGo::menuMonster(){
	
	vector<Monster>& monsters = player->getMonster();
	Menu menu("내 몬스터 보기 & 정보 변경");
	for (int i = 0; i < monsters.size(); i++){
		menu.addMenu("이름 : " + monsters.at(i).getNickname()
			+ "(" + getMonsterName(monsters.at(i).getId()) + ")"
			+ " / CP : " + to_string(monsters.at(i).getCp()));
	}
	menu.addMenu("몬스터 방류하기");
	menu.addMenu("메인 메뉴로 돌아가기");
	
	while (1){
		menu.printMenu();
		int input = menu.input();
		if (input == menu.getMenuNum() - 1){//몬스터 방류하기
			
			if (monsters.size() == 0){
				cout << "방류할 몬스터가 없습니다." << endl;
				cin.ignore(); getchar();
				return;
			}

			int num;
			cout << "방류할 포켓몬의 번호를 입력하세요 : ";
			while (1){
				cin >> num;
				if (0<num && num<=monsters.size()){
					monsters.erase(monsters.begin() + (num - 1));
					menu.delMenu(num - 1);
					break;
				}
				else{
					cout << "입력 범위를 벗어났습니다." << endl;
				}
			}

		}
		else if (input == menu.getMenuNum()){//메인 메뉴로 돌아가기
			break;
		}
		else{//해당 몬스터 클릭하였을 때.
			string nickname;
			cout << "변경할 이름을 입력하세요 : ";
			cin.ignore();
			getline(cin, nickname);
			monsters.at(input - 1).setNickname(nickname);
			menu.setMenu(input - 1, "이름 : " + monsters.at(input-1).getNickname()
				+ "(" + getMonsterName(monsters.at(input - 1).getId()) + ")"
				+ " / CP : " + to_string(monsters.at(input - 1).getCp()));
		}
	}

}

void MiniPoketmonGo::menuGetPoketmon(){
	
	
	Monster genMonster = getRandomMonster();
	string title = "몬스터 잡기\n\n"+  getMonsterName(genMonster.getId()) + "(CP : " + to_string(genMonster.getCp()) + ")";
	Menu menu(title);
	bool runaway = false;
	bool catchPoketmon = false;
	int selectedPocket = -1;
	while (!(runaway || catchPoketmon)){
		menu.clearMenu();
		vector<BallPocket>& playerPocket = player->getBallPocket();	
		bool empty = true;
		if (selectedPocket == -1){ //볼을 직접 선택한 것이 아니라면
			for (int i = 0; i < playerPocket.size(); i++){
				if (playerPocket.at(i).getNum() != 0){
					empty = false;
					selectedPocket = (i+1);
					menu.addMenu(getBallName(playerPocket.at(i)
						.getId()) + " 던지기(" + to_string((playerPocket.at(i).getNum())) + "개 남음)");
					break;
				}
			}
		}
		else{
			int selectedPocketNum = playerPocket.at(selectedPocket - 1).getNum();
			if (selectedPocketNum!= -1){ //선택한 볼이 있으면
				if (playerPocket.at(selectedPocket - 1).getNum() != 0){
					menu.addMenu(getBallName(playerPocket.at(selectedPocket - 1)
					.getId()) + " 던지기(" + to_string((playerPocket.at(selectedPocket - 1).getNum())) + "개 남음)");
					empty = false;
				}
				else{
					empty = true;
				}
			}
			else{
				empty = true;
			}
		}

		if (empty){
			menu.addMenu("포켓몬 볼 던지기(포켓볼이 없습니다.)");
		}
		menu.addMenu("몬스터 볼 변경");
		menu.addMenu("도망가기");
		menu.printMenu();
		
		int input = menu.input();
		switch (input){
		case 1:{//포켓몬 볼 던지기
				   if (empty){
					   cout << "포켓볼이 없습니다. 다른 메뉴를 선택해주세요" << endl;
					   cin.ignore();
					   getchar();
				   }
				   else{
					   BallPocket& nowBallPocket = playerPocket.at(selectedPocket - 1);
					   if (nowBallPocket.throwBall()){//잡았을 때
						   vector<Monster>& playerMonster = player->getMonster();
						   playerMonster.push_back(genMonster);
						   cout << "잡았습니다. (엔터 입력시 메인 메뉴로 돌아갑니다.)" << endl;
						   cin.ignore(); getchar();
						   catchPoketmon = true;
				
					   }
					   else{
						   cout << "튀어나왔습니다." << endl;
						   cin.ignore();
						   getchar();
					   }

				   }
		}
			break;
		case 2:{//몬스터 볼 변경
				   Menu selBallMenu("몬스터 볼 변경");

				   for (int i = 0; i < playerPocket.size(); i++){
					   selBallMenu.addMenu(getBallName(playerPocket.at(i).getId()) + "(" + to_string(playerPocket.at(i).getNum()) + "개 남음)");
				   }
				   selBallMenu.printMenu();
				   selectedPocket = selBallMenu.input();
		}
			break;
		case 3:{//도망가기
				   runaway = true;
		}
			break;
		}

	}
}

void MiniPoketmonGo::menuExitandSave(){
	fm->writePlayerToFile(player);
}

Monster MiniPoketmonGo::getRandomMonster(){
	int totalProbability = 0;
	for (int i = 0; i < monstersData.size(); i++){
		totalProbability += monstersData.at(i).getProbability();
	}
	int randNum = rand() % totalProbability;
	int index = 0;
	while (randNum >= monstersData.at(index).getProbability()){
		randNum -= monstersData.at(index).getProbability();
		index++;
	}
	return monstersData.at(index).genMonster();
}

string MiniPoketmonGo::getMonsterName(int id){
	for (int i = 0; i < monstersData.size(); i++){
		if (monstersData.at(i).getId() == id){
			return monstersData.at(i).getName();
		}
	}
}

string MiniPoketmonGo::getBallName(int id){
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getName();
		}
	}
}

int MiniPoketmonGo::getBallprice(int id){
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getPrice();
		}
	}
}