#include "UserInterface.h"


void UserInterface::mainMenu() {
	int x,y;
	functionController.readFile();
	while (true) {
		system("cls");
		cout << "=============================" << endl;
		cout << "Welcome to Mago Travel Agent" << endl;
		cout << "=============================" << endl;
		cout << "[1] Search and Book package." << endl;
		cout << "[2] Current Status." << endl;
		cout << "[3] Add / Edit / Delete" << endl;
		cout << "[4] Save and Exit" << endl;
		cin >> x;
		if (x == 1) {
			system("cls");
			cout << "===============================" << endl;
			cout << "Search and Book your travel now" << endl;
			cout << "===============================" << endl;
			cout << "[1].Search Travel Packages" << endl;
			cout << "[2].Search Traveler Data" << endl;
			cout << "[3].Book a package" << endl;
			cin >> y;
			switch (y)
			{
			case 1:
			{	
				searchTravelPackages();
				break;
			}
			case 2:
			{
				searchTraveler();
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Inappropriate input" << endl;
				break;
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
			return;
		}
		else
		{
			cout << "Inappropriate input!" << endl;
		}
	}
}

void UserInterface::checkStatus()
{
	
}

void UserInterface::book()
{
	
}

void UserInterface::deleteItem()
{

}
void UserInterface::add()
{
	string  packName, packCode,date,codeInput,desc;
	int option, numDate, price, availability,hash;
	TravelPack* pointer;
	
	system("CLS");
	cout << "========================================" << endl;
	cout << "How do you want to add your new package." << endl;
	cout << "========================================" << endl;
	cout << "[1]. Add date from the existing package." << endl;
	cout << "[2]. Add a brand new package." << endl;
	cin >> option;
	if (option == 1) {
		functionController.printExistingPack();

		while (true)
		{
			cout << "Input the code of packs you wished to copy" << endl;
			cin >>codeInput;
			hash = codeInput[0] % 26;
			for (int i = 0; i < functionController.TravelPackData[hash].size(); i++)
			{
				if (functionController.TravelPackData[hash][i].getCode()==codeInput)
				{
					pointer = &functionController.TravelPackData[hash][i];
				}
			}
			int cant;
			cout << "Code cannot be found!" << endl;
			cout << "[1]. Try again" << endl;
			cout << "[2]. EXIT" << endl;
			cin >> cant;
			if (cant == 1)continue;
			else if (cant == 2) add();
			else add();
		}
		while (true)
		{
			cout << "Input number of date you wish to add: [1-...]" << endl;
			cin >> numDate;
			if (numDate < 1 || numDate>10)
			{
				cout << "Inappropriate input!" << endl;
			}
			else break;
		}
		

		for (int i = 0; i < numDate; i++) {
			cout << "Input date ["<<i+1<<" / "<<numDate<<" ]" << endl;
			cin >> date;
			cout << "Input code	(if you type ""_"", it will automatically create it for you):" << endl;
			cin >> packCode;
			if (packCode == " ")
			{
				packCode = pointer->getAlphaCode();
				packCode += date;
			}
			else
			{
				for (int  i = 0; i < functionController.packageCount(hash); i++)
				{
					if (packCode == functionController.TravelPackData[hash][i].getCode())
					{
						cout << "Sorry but you may not use this code!" << endl;
					}
				}
				
			}
			TravelPack copied= *pointer;
			copied.setDate(date);
			copied.setCode(packCode);
			functionController.addNewItem(copied,packCode[0] % 26);
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
			cout << "Input description" << endl;
			getline(cin, desc);

			functionController.addNewItem(TravelPack(packCode, packName, price, date, availability,desc),packCode[0]%26);
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
	/*string packName;
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

	}*/
}

void UserInterface::toLowering(string &tolowered)
{
	for (int  i = 0; i < tolowered.size(); i++)
	{
		tolower(tolowered[i]);
	}
}
UserInterface::UserInterface()
{
	activePack = NULL;
}


UserInterface::~UserInterface()
{
}
