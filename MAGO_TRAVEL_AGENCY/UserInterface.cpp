//Author: MarcAntonio and Figo Aranta

#include "UserInterface.h"
using namespace std;
//UserInterface for the main menu
void UserInterface::mainMenu() {
	int x,y;
	string xString;
	

	
	while (true) {
		system("cls");
		cout << "=============================" << endl;
		cout << " Welcome to Mago Travel Agent" << endl;
		cout << "=============================" << endl;
		cout << "[1] Search and Book package." << endl;
		cout << "[2] Current Status." << endl;
		cout << "[3] Customize" << endl;
		cout << "[4] Save and Exit" << endl;
		cin >> xString;
		try{
			x=stoi(xString);
		}
		catch (exception) {
			cout << "Integer only" << endl;
			x = 0;
		}
		//interface when user want to search and book package
		if (x == 1) {
			system("cls");
			string yString;
			cout << "==================================" << endl;
			cout << "  Search and Book your travel now" << endl;
			cout << "==================================" << endl;
			cout << "[1]. Search Travel Packages" << endl;
			cout << "[2]. Search Traveler Data" << endl;
			cout << "[3]. Book a package" << endl;
			cout << "[4]. Back to Main menu" << endl;
			cin >> yString;
			try {
				y = stoi(yString);
			}
			catch (exception) {
				cout << "Integer only" << endl;
				y = 0;
			}
			switch (y)
			{
			//to search travel package
			case 1:
			{	
				searchTravelPackages();
				break;
			}
			//to serach travel data
			case 2:
			{
				searchTraveler();
				break;
			}
			//to book a package
			case 3:
			{
				bookPackage();
				break;
			}
			//to go back to the main menu
			case 4:
			{
				mainMenu();
			    break;
			}
			default:
				cout << "Inappropriate input" << endl;
				break;
			}
		}//to see current status
		else if (x == 2) {
			checkStatus();
		}
		//to customize data
		else if (x == 3) {
			customize();
		}
		//to save and exit
		else if (x == 4)
		{
			functionController.writeFile();
			exit(1);
			
		}
		// error warning when user input inappropriate input
		else
		{
			cout << "Inappropriate input!" << endl;
		}
	}
}

// function for add a new package
void UserInterface::add()
{
	string  packName, packCode,date,codeInput,desc;
	int option, numDate, price, availability,hash;
	TravelPack* pointer=NULL;
	//Userinterface for add new package menu
	system("CLS");
	cout << "========================================" << endl;
	cout << " How do you want to add your new package?" << endl;
	cout << "========================================" << endl;
	cout << "[1]. Add date from the existing package." << endl;
	cout << "[2]. Add a brand new package." << endl;
	cout << "[3]. Back to main menu" << endl;
	cin >> option;
	//to add date from the existing package
	if (option == 1) {
		functionController.printExistingPack();
		bool run = true;
		while (run)
		{
			cout << "Input the code of packs you wished to copy" << endl;
			cin >>codeInput;
			hash = codeInput[0] % hashNum;
			for (int i = 0; i < functionController.packageCount(hash); i++)
			{
				if (functionController.TravelPackData[hash][i].getCode()==codeInput)
				{
					pointer = &functionController.TravelPackData[hash][i];
					run = false;
					break;
				}
			}
			if (run) {
				int cant;
				cout << "Code cannot be found!" << endl;
				cout << "[1]. Try again" << endl;
				cout << "[2]. EXIT" << endl;
				cin >> cant;
				if (cant == 1)continue;
				else if (cant == 2) add();
				else add();
			}
		}
		while (true)
		{
			cout << "You're making a brand new package based on the code of " << pointer->getCode() << endl;
			cout << "Input number of date you wish to add: [1-...]" << endl;
			cin >> numDate;
			if (numDate < 1 || numDate>10)
			{
				cout << "Inappropriate input!" << endl;
				cout << "Make sure you type in the range of 1-10" << endl;
			}
			else break;
		}
		

		for (int i = 0; i < numDate; i++) {
			while (true)
			{
				cout << "Appropriate format date : year-month-date" << endl;
				cout << "Input date ["<<i+1<<" / "<<numDate<<" ]" << endl;
				cin >> date;
				if (ValidateItem(date, "date")) break;
				else cout << "Not inappropriate input" << endl;
			}
			while (true)
			{
				cout << "Input code	(if you type ""_"", it will automatically create it for you):" << endl;
				cout << "ALPHA NUMERIC [3-13 character]" << endl;
				cin >> packCode;
				if (packCode == "_")
				{
					packCode = pointer->getAlphaCode();
					packCode += date;
					break;
				}
				else
				{
					if (ValidateItem(packCode, "codeName"))
					{
						for (int i = 0; i < functionController.packageCount(packCode[0] % hashNum); i++)
						{
							if (packCode == functionController.TravelPackData[packCode[0] % hashNum][i].getCode())
							{
								cout << "Sorry but you may not use this code!" << endl;
							}
						}
						break;
					}
					else cout << "Error typing code" << endl;

				}
			}
			TravelPack copied= *pointer;
			copied.setDate(date);
			copied.setCode(packCode);
			functionController.addNewItem(copied,packCode[0] % hashNum);
			cout << "Your new package has been successfully added..." << endl;

		}
	}//to add a brand new package.
	else if (option == 2)
	{
	
		while (true)
		{
			cout << "input package code" << endl;
			cout << "ALPHA NUMERIC [3-13 character]" << endl;
			cout << "Recommended to attach the dates at the end of the code" << endl;
			cout << "Should not contain any space" << endl;
			getline(cin, packCode);
			if (ValidateItem(packCode, "codeName")) break;
			else cout << "Not inappropriate package code" << endl;
		}
		
		while (true)
		{
			cout << "Package name will be the title of your package" << endl;
			cout << "Example : 3d2n in Wonderful Bali" << endl;
			cout << "Input package name [5 -40 char]" << endl;
			getline(cin, packName);
			if (ValidateItem(packName, "PackageName")) break;
			else cout << "Not inappropriate package Name" << endl;
		}
		
		while (true)
		{
			cout << "price is set for adult, do not set to kids price" << endl;
			cout << "Set price above Rp.100.000 - Rp.100.000.000" << endl;
			cout << "Input package price" << endl;
			cin >> price;
			if (ValidateNumber(price, "price")) break;
			else cout << "Not inappropriate price Name" << endl;
		}
		
		while (true)
		{
			cout << "Appropriate format date : year-month-date" << endl;
			cout << "Input package date of departure" << endl;
			cin >> date;
			if (ValidateItem(date, "date")) break;
			else cout << "Not inappropriate Date Name" << endl;
		}
		
		while (true)
		{
			cin.ignore();
			cout << "Availability must be > 5 and <80" << endl;
			cout << "Input package availability" << endl;
			cin >> availability;
			if (ValidateNumber(availability, "availability")) break;
			else cout << "Not inappropriate Availability" << endl;
		}
		
		while (true)
		{
			cout << "Input brief description to the package" << endl;
			cout << "Describe the package, location and explanation" << endl;
			getline(cin, desc);
			if (ValidateItem(desc, "description")) break;
			else cout << "Not inappropriate description" << endl;
		}
		while (true)
		{
			int inputUser;
			cout << "HERE IS THE PACKAGE YOU'RE ABOUT TO ADD" << endl;
			cout << "Package Code :" << packCode << endl;
			cout << "Package Name:" << packName << endl;
			cout << "Package Price:" << price << endl;
			cout << "Package Date:" << date << endl;
			cout << "Package availability:" << availability<< endl;
			cout << "Description:" << FormattingDesc(desc)<<endl;
			cout << "[1]. Procedd to add" << endl;
			cout << "[2]. Cancel and back to menu" << endl;
			cin >> inputUser;
			if (inputUser == 1)
			{
				functionController.addNewItem(TravelPack(packCode, packName, price, date, availability, desc), packCode[0] % hashNum);
				cout << "Your new package has been successfully added..." << endl;
			}
			else if (inputUser == 2)
			{
				add();
				break;
			}
			else
			{
				cout << "Inappropriate input" << endl;
			}
	}
	}
	// to back to main menu
	else if (option == 3)
	{
		mainMenu();
	}
	else
	{
		cout << "Inappropriate Input" << endl;
	}

}
//funtion for customize travel package and customer data
void UserInterface::customize()
{

	int x;
	string StringX;
	//Interface for customize data menu
	while (true)
	{
		cout << "=================================" << endl;
		cout << " Welcome to Customize menu" << endl;
		cout << "=================================" << endl;
		cout << "[1].Add a package" << endl;
		cout << "[2].Edit a package or Traveler" << endl;
		cout << "[3].Delete a package or Traveler" << endl;
		cout << "[4].Back to Main Menu" << endl;
		cout << "Enter your command	:" << endl;
		cin >> StringX;
		try
		{
			x = stoi(StringX);
		}
		catch (const std::exception&){
		}
		// to add a package
		if (x == 1) {
			add();
		}
		// to edit a package or traveler
		else if (x == 2) {
			editMenu();
		}
		// to delete a packafe or traveler
		else if (x == 3) {
			deleteMenu();
		}
		// to back to main menu
		else if (x == 4)
		{
			mainMenu();
			return;
		}
		// error message when innapropriate input
		else
		{
			cout << "Inappropriate input" << endl;
		}
	}

}

// function to lower string
void UserInterface::toLowering(string &tolowered)
{
	for (int  i = 0; i < tolowered.size(); i++)
	{
		tolower(tolowered[i]);
	}
}
UserInterface::UserInterface()
{
	functionController.readFile();
	activePack = NULL;
}
// function to validate item which contains of string and key
bool UserInterface::ValidateItem(string& content,string key)
{
	if (key == "codeName")
	{
		if (content.size() < 3 || content.size() > 13)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < content.size(); i++)
			{
				if (content[i] == ' ') return false;

				toupper(content[i]);
			}
			return true;
		}
	}
	else if (key == "PackageName")
	{
		if (content.size() < 5 || content.size() > 40)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (key == "date")
	{
		if (content.size() !=8)
		{
			return false;
		}
		
		else
		{
			for (int i = 0; i < content.size(); i++)
			{
				if (!isdigit(content[i])) return false;
			}
			return true;
		}
	}
	else if (key == "description")
	{
		if (content.size() <1 || content.size()>60)
		{
			return false;
		}
		else return true;
	}

	else if (key == "name")
	{
		if (content.size() < 3 || content.size() > 20)return false;
		else
		{
			toupper(content[0]);
			return true;
		}

	}
	else return false;

}
//functuon to validate number
bool UserInterface::ValidateNumber(const int& content, string key)
{
	if (key == "price")
	{
		if (content < 100000 || content >100000000) return false;
		else return true;
	}
	else if (key == "age")
	{
		if (content > 100 || content < 1) return false;
		else return true;
	}
	else if (key == "availability")
	{
		if (content < 1 || content >80) return false;
		else return true;
	}
	else return false;

}
// function to set a format for a description
string UserInterface::FormattingDesc(string desc)
{
	string ret = "";
	string temp = "";
	for (int i = 0; i < desc.size(); i++)
	{
		if (desc[i] == ',')
		{
			ret += temp;
			ret += "\n";
			temp = "";
		}
		else
		{
			temp += desc[i];
		}

	}
	return ret;
}

UserInterface::~UserInterface()
{
}


