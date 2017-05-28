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
		cout << "데이터를 가져오는데 실패하여 프로그램이 종료됩니다." << endl;
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
						ballPocket.at(selectedNum - 1).setNum( ballPocket.at(selectedNum-1).getNum() + num);
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


	while (!(runaway || catchPoketmon)){ //도망치거나, 몬스터를 잡으면 종료
	
		//값 초기화
		menu.clearMenu();
		bool empty = true;

		//플레이어의 볼 포켓 정보를 가져온다.
		vector<BallPocket>& playerPocket = player->getBallPocket();	


		//볼을 선택하지 않았을 때(처음 메뉴에 들어왔을 때)
		if (selectedPocket == -1){ 

			//가장 id가 빠른 순 부터 조사하여 공이 있으면 메뉴에 등록한다.
			for (int i = 0; i < playerPocket.size(); i++){
				if (playerPocket.at(i).getNum() != 0){
					empty = false; //공을 있으니 empty를 false로 하고
					selectedPocket = (i+1); //선택된 볼 포켓 번호를 저장한다.
					menu.addMenu(getBallName(playerPocket.at(i)
						.getId()) + " 던지기(" + to_string((playerPocket.at(i).getNum())) + "개 남음)");
					break;
				}
			}
		}
		//볼을 선택한 경우 (볼 변경으로 볼을 변경한 이후)
		else{
			//공이 있을 경우 메뉴에 추가
			if (playerPocket.at(selectedPocket - 1).getNum() != 0){
				empty = false;
				menu.addMenu(getBallName(playerPocket.at(selectedPocket - 1)
				.getId()) + " 던지기(" + to_string((playerPocket.at(selectedPocket - 1).getNum())) + "개 남음)");
			}
			//없을 경우 empty = true
			else{
				empty = true;
			}
		}

		//화면출력 부분
		if (empty){
			menu.addMenu("포켓몬 볼 던지기(포켓볼이 없습니다.)");
		}
		menu.addMenu("몬스터 볼 변경");
		menu.addMenu("도망가기");
		menu.printMenu();
		
		//메뉴 선택 부분
		int input = menu.input();
		switch (input){
		case 1:{//포켓몬 볼 던지기

				   //공이 없으면
				   if (empty){
					   cout << "포켓볼이 없습니다. 다른 메뉴를 선택해주세요" << endl;
					   cin.ignore();
					   getchar();
				   }
				   //공이 있으면
				   else{
					   //현재 선택된 볼 포켓 정보를 가져온다.
					   BallPocket& nowBallPocket = playerPocket.at(selectedPocket - 1);
					   
					   //잡았을 때
					   if (nowBallPocket.throwBall()){
						   //플레이어의 몬스터 리스트를 가져온다.
						   vector<Monster>& playerMonster = player->getMonster();

						   //생성된 몬스터를 리스트에 넣는다.
						   playerMonster.push_back(genMonster);
						   cout << "잡았습니다. (엔터 입력시 메인 메뉴로 돌아갑니다.)" << endl;
						   cin.ignore(); getchar();
						   catchPoketmon = true;
				
					   }
					   //놓쳤을 때
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
				   selectedPocket = selBallMenu.input();//선택한 번호를 저장한다.
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
	//파일매니저를 통해 현재의 player객체를 Player.txt에 저장한다.
	fm->writePlayerToFile(player);
}

Monster MiniPoketmonGo::getRandomMonster(){
	int totalProbability = 0;
	
	//각 몬스터들이 나올 확률을 전체를 다 더한다.
	for (int i = 0; i < monstersData.size(); i++){
		totalProbability += monstersData.at(i).getProbability();
	}

	//랜덤 수를 전체중에 뽑는다.
	int randNum = rand() % totalProbability;
	
	//A확률이 20, B확률이 10, C확률이 5라면
	//totalProbability = 35 이면
	// A포켓몬확률(0~19), B포켓몬 확률(20~29), C포켓몬(30~34)로 생각을 하였다.
	// 그래서 아래는 randNum이 저 중에 어디에 속하는지를 따지는 알고리즘이다.
	
	
	int index = 0;
	while (randNum >= monstersData.at(index).getProbability()){
		randNum -= monstersData.at(index).getProbability();
		index++;
	}
	/*
	예를 들면 위의 상황에서 randNum 이 22가 나왔다면
	randNum (22) 은 첫번째 몬스터의 가능성 20 보다 크므로
	randNum에서 첫번째 몬스터의 가능성을 뺀값을 저장한다.
	그리고 index를 다음칸으로 옮긴다.

	그러면 randNum(2) 는 둡너째 몬스터의 가능성 10보다 작으므로 while문을 빠져나오고
	두번째 몬스터의 데이터를 가지고 몬스터를 만들어서 return 한다.
	*/

	return monstersData.at(index).genMonster();
}

string MiniPoketmonGo::getMonsterName(int id){
	//id에 해당하는 몬스터 이름을 return한다.
	for (int i = 0; i < monstersData.size(); i++){
		if (monstersData.at(i).getId() == id){
			return monstersData.at(i).getName();
		}
	}
}

string MiniPoketmonGo::getBallName(int id){
	//id에 해당하는 볼이름을 return한다.
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getName();
		}
	}
}

int MiniPoketmonGo::getBallprice(int id){
	//id에 해당하는 볼가격을 return한다.
	for (int i = 0; i < ballsData.size(); i++){
		if (ballsData.at(i).getId() == id){
			return ballsData.at(i).getPrice();
		}
	}
}