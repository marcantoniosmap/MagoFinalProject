#include "UserInterface.h"


void UserInterface::mainMenu() {
	int x,y;
	cout <<"==================" << endl;
	cout << "Welcome to Mago... Travellers" << endl; 
	cout <<"==================" << endl;
	cout << "[1] Search and Book package." << endl;
	cout << "[2] Current Status." << endl;
	cout << "[3] Add / Edit / Delete" << endl;
	cin >> x;
	if (x == 1) {
		cout << "[1].Search" << endl;
		cout << "[2].Book" << endl;
		cin >> y;
		if (y == 1) {
			//search();
		}
		else if (y == 2) {
			//book();
		}
	}
	else if (x == 2) {
		//checkStatus();
	}
	else if (x == 3) {
		addEditDelete();
	}

}




UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
