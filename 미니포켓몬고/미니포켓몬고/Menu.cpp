#include "Menu.h"


Menu::Menu(string title)
{
	//메뉴의 제일 위에 나올 타이틀
	this->title = title;
}

Menu::~Menu()
{
}

void Menu::addMenu(string menu){
	//메뉴를 vector에 추가한다.
	menus.push_back(menu);
}
void Menu::delMenu(int position){
	//해당 position의 메뉴를 삭제한다.
	menus.erase(menus.begin() + position);
}
void Menu::setMenu(int position, string menu){
	//해당 position의 메뉴를 받아온 string 인자로 바꾼다.
	menus.at(position) = menu;
}
int Menu::getMenuNum(){
	//메뉴의 개수를 리턴한다.
	return menus.size();
}
void Menu::printMenu(){
	//메뉴를 출력하는 부분이다.
	system("cls");
	cout << title << endl<<endl;
	for (int i = 0; i < menus.size(); i++){
		cout<<(i+1)<<" . "<< menus.at(i) << endl;
	}
}

int Menu::input(){
	//현재 메뉴에서 가능한 input을 받아 리턴하는 함수다.
	while (1){
		int inputNum;
		cin >> inputNum;
		if (0 <= (inputNum - 1) && (inputNum - 1) < menus.size()){
			return inputNum;
		}
		else{
			cout << "입력 범위를 벗어났습니다." << endl;
			continue;
		}
	}
}

void Menu::clearMenu(){
	//모든 메뉴를 삭제하는 메뉴다.
	menus.clear();
}

