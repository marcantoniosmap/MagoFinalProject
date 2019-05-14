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
		else if (y == 20) {
			//book();
		}
	}
	else if (x == 2) {
		//checkStatus();
	}
	else if (x == 3) {
		cout << "[1].Add" << endl;
		cout << "[2].Edit" << endl;
		cout << "[3].Delete" << endl;
		cin >> y;
		if (y == 1) {
			//addItem();
		}
		else if (y == 2) {
			//editItem();
		}
		else if (y == 3) {
		//	deleteItem();
		}
	}

}




UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
