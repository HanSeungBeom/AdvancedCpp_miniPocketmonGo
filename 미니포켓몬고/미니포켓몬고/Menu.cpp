#include "Menu.h"


Menu::Menu(string title)
{
	//�޴��� ���� ���� ���� Ÿ��Ʋ
	this->title = title;
}

Menu::~Menu()
{
}

void Menu::addMenu(string menu){
	//�޴��� vector�� �߰��Ѵ�.
	menus.push_back(menu);
}
void Menu::delMenu(int position){
	//�ش� position�� �޴��� �����Ѵ�.
	menus.erase(menus.begin() + position);
}
void Menu::setMenu(int position, string menu){
	//�ش� position�� �޴��� �޾ƿ� string ���ڷ� �ٲ۴�.
	menus.at(position) = menu;
}
int Menu::getMenuNum(){
	//�޴��� ������ �����Ѵ�.
	return menus.size();
}
void Menu::printMenu(){
	//�޴��� ����ϴ� �κ��̴�.
	system("cls");
	cout << title << endl<<endl;
	for (int i = 0; i < menus.size(); i++){
		cout<<(i+1)<<" . "<< menus.at(i) << endl;
	}
}

int Menu::input(){
	//���� �޴����� ������ input�� �޾� �����ϴ� �Լ���.
	while (1){
		int inputNum;
		cin >> inputNum;
		if (0 <= (inputNum - 1) && (inputNum - 1) < menus.size()){
			return inputNum;
		}
		else{
			cout << "�Է� ������ ������ϴ�." << endl;
			continue;
		}
	}
}

void Menu::clearMenu(){
	//��� �޴��� �����ϴ� �޴���.
	menus.clear();
}

