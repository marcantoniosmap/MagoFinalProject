// #include "UserInterface.h"


void UserInterface::mainMenu() {
	int x,y;
	functionController.readFile();
	while (true) {
		cout << "=============================" << endl;
		cout << "Welcome to Mago Travel Agent" << endl;
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
				cout << functionController.TravelPackData[0].getCode() << endl;
				search();
			}
			else if (y == 2) {
				book();
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
	
}

void UserInterface::book()
{
	
}
void UserInterface::search()
{

}
void UserInterface::deleteItem()
{

}
void UserInterface::add()
{
	string  packName, packCode;
	int option, numDate, index, price,date, availability;
	
	system("CLS");
	cout << "========================================" << endl;
	cout << "How do you want to add your new package." << endl;
	cout << "========================================" << endl;
	cout << "[1]. Add from the existing package." << endl;
	cout << "[2]. Add new package." << endl;
	cin >> option;
	if (option == 1) {
		functionController.printExistingPack();

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
			//n.setDate(date);
			n.setCode(packCode);
			functionController.addNewItem(n);
			cout << "Your new package has been successfully added..." << endl;

		}
	}
	else if (option == 2)
	{

		cout << "Input number of date you want to add" << endl;
		cin >> numDate;
		for (int i = 0; i < numDate; i++) {
			cout << "input package code" << endl;
			cin.ignore();
			getline(cin, packCode);
			cout << "Input package name" << endl;
			getline(cin, packName);
			cout << "Input package price" << endl;
			cin >> price;
			cout << "Input package date" << endl;
			cin >> date;
			cin.ignore();
			cout << "Input package availability" << endl;
			cin >> availability;

			//functionController.addNewItem(TravelPack(packCode, packName, price, date, availability));
			cout << "Your new package has been successfully added..." << endl;
		}
	}

}

void UserInterface::addEditDelete()
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

void UserInterface::editItem()
{
	string packName;
	int  date, index = 0;
	int element = 0;
	cout << "Which package do you wish to edit." << endl;
	cin >> packName;
	for (int i = 0; i < functionController.TravelPackData.size(); i++) {
		if (functionController.TravelPackData[i].getPackName() == packName) {
			cout << index << "." << functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName() << functionController.TravelPackData[i].date << endl;
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
