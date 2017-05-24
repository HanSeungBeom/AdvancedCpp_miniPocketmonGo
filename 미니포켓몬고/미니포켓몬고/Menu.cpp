#include "Menu.h"


Menu::Menu(string title)
{
	this->title = title;
}

Menu::~Menu()
{
}

void Menu::addMenu(string menu){
	menus.push_back(menu);
}
void Menu::delMenu(int position){
	menus.erase(menus.begin() + position);
}
void Menu::setMenu(int position, string menu){
	menus.at(position) = menu;
}
int Menu::getMenuNum(){
	return menus.size();
}
void Menu::printMenu(){
	system("cls");
	cout << title << endl<<endl;
	for (int i = 0; i < menus.size(); i++){
		cout<<(i+1)<<" . "<< menus.at(i) << endl;
	}
}

int Menu::input(){
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
	menus.clear();
}

