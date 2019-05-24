#include "UserInterface.h"


void UserInterface::mainMenu() {
	int x,y;
	functionController.readFile();
	while (true) {
		cout << "=============================" << endl;
		cout << "Welcome to Mago... Travellers" << endl;
		cout << "=============================" << endl;
		cout << "[1] Search and Book package." << endl;
		cout << "[2] Current Status." << endl;
		cout << "[3] Add / Edit / Delete" << endl;
		cout << "[4] Save and Exit" << endl;
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
			checkStatus();
		}
		else if (x == 3) {
			addEditDelete();
		}
		else if (x == 4)
		{
			functionController.writeFile();
			//insert goodbye text
			break;
		}
		else
		{
			cout << "error mathefake" << endl;
		}
	}
}

void UserInterface::checkStatus()
{
	cout << "Current Status." << endl;
	for (int i = 0; i < functionController.TravelPackData.size(); i++) {
		cout << functionController.TravelPackData[i].getPrice() << functionController.TravelPackData[i].getPackName() << endl;
	}
}

void UserInterface::add()
{
	string date, packName, packCode;
	int option, numDate, index, price, availability;
	//every time ada menu, give a heading yang memperjelas ini di menu apa, and an option to balik to main menu
	//good work man

	cout << "========================================" << endl;
	cout << "How do you want to add your new package." << endl;
	cout << "========================================" << endl;
	cout << "[1]. Add from the existing package." << endl;
	cout << "[2]. Add new package." << endl;
	cin >> option;
	if (option == 1) {
		for (int i = 0; i < functionController.TravelPackData.size(); i++) {
			cout << i << " " << functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName() << endl;
		}

		cout << "Input index" << endl;
		cin >> index;

		cout << "Number of date you want to add:" << endl;
		cin >> numDate;

		for (int i = 0; i < numDate; i++) {
			cout << "Input date:" << endl;
			cin >> date;
			cout << "Input code" << endl;
			cin >> packCode;
			TravelPack n(functionController.TravelPackData[index]);
			n.setDate(date);
			n.setCode(packCode);
			functionController.addNewItem(n);
			cout << "Your new package has been successfully added..." << endl;

		}
	}
	else if (option == 2)
	{

		//rapihin and give more guide (berapa character and validation)
		//use getline(cin,packName) instead, cus bisa kasih space
		//i think pake while loop "Number of date" kaya yang diatas juga perlu, cus pas mau bikin
		// mau tau juga berapa banyak yang dia mau,
		cout << "Input number of date you want to add" << endl;
		cin >> numDate;
		for (int i = 0; i < numDate; i++) {
			cout << "input package code" << endl;
			cin.ignore();
			getline(cin, packCode);
			//give the user the freedom to choose mereka pilih code sendiri atau kita aja yang nentuin.
			cout << "Input package name" << endl;
			getline(cin, packName);
			cout << "Input package price" << endl;
			cin >> price;
			cout << "Input package date" << endl;
			getline(cin, date);
			cin.ignore();
			//instead tanya date nya satu per satu and validasiin valid gak 
			cout << "Input package availability" << endl;
			cin >> availability;

			//cout something that tells the user (udah ke add loh)
			//and maybe tampilin lagi, "are u sure u want to create blabla)
			functionController.addNewItem(TravelPack(packCode, packName, price, date, availability));
			cout << "Your new package has been successfully added..." << endl;
		}
	}

}

void UserInterface::addEditDelete()
{
	{
		int x;
		cout << "[1].Add" << endl;
		cout << "[2].Edit" << endl;
		cout << "[3].Delete" << endl;
		cin >> x;
		if (x == 1) {
			add();
		}
		else if (x == 2) {
			editItem();
		}
		else if (x == 3) {
			deleteItem();
		}


	}
}

void UserInterface::editItem()
{
	string packName, date;
	int index = 0;
	int element = 0;
	cout << "Which package do you wish to edit." << endl;
	cin >> packName;
	for (int i = 0; i < functionController.TravelPackData.size(); i++) {
		if (functionController.TravelPackData[i].getPackName() == packName) {
			cout << index << "." << functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName() << functionController.TravelPackData[i].getDate() << endl;
		}
		else
		{
			element++;
		}

		index++;
	}
	cout << "Input Index of the package you wish to edit." << endl;
	cin >> index;
	cout << "Input your new Date." << endl;
	cin >> date;
	functionController.TravelPackData[index + element].setDate(date);
}

void UserInterface::deleteItem()
{
	int element = 0;
	string packCode;
	cout << "Input the package code for the package you want to delete" << endl;
	cin >> packCode;
	for (int i = 0; i < functionController.TravelPackData.size(); i++) {
		if (functionController.TravelPackData[i].getCode() == packCode) {
			functionController.TravelPackData.erase(functionController.TravelPackData.begin() + element);
			cout << "Your package has been successfully deleted" << endl;
			break;
		}
		else
		{
			element++;
		}

	}
}
UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
