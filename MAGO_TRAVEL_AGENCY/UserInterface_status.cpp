#include "UserInterface.h"
//userinterface when user want to check the travel pack
void UserInterface::checkStatus()
{
	string xString;
	int x;
	while (true)
	{
		cout << "==================================" << endl;
		cout << "  ABOUT THIS TRAVEL PACK" << endl;
		cout << "==================================" << endl;
		cout << "[1]. All Description" << endl;
		cout << "[2]. Traveler Data" << endl;
		cout << "[3]. List of different Date" << endl;
		cout << "[4]. Back to Main menu" << endl;
		cin >> xString;
		try {
			x = stoi(xString);
		}
		catch (exception) {
			cout << "Integer only" << endl;
			x = 0;
		}
		switch (x)
		{
			// to show all descripton of the travel package
		case 1:
		{
			system("cls");
			cout << "===========================================" << endl;
			cout << "		DESCRIPTION" << endl;
			cout << "===========================================" << endl;
			cout << "You are about to book this tour package" << endl;
			cout << "Code			:" << activePack->getCode() << endl;
			cout << "Name			:" << activePack->getPackName() << endl;
			cout << "Price			:" << activePack->getPrice() << endl;
			cout << "Date			:" << activePack->getDate() << endl;
			cout << "Max people		:" << activePack->getAvailability() << endl;
			cout << "Availability		:" << activePack->getCurrentAvailability() << endl;
			cout << "Description		:" << activePack->getFormattedDescripition() << endl;
			cout << "===========================================" << endl;
			break;
		}
		// to show traveller data
		case 2:
		{
			functionController.ListComplete(activePack);
			break;
		}
		// to see the list of different date
		case 3:
		{
			functionController.listSimilar(activePack);
			break;
		}
		//to back to main menu
		case 4:
		{
			mainMenu();
			return;
		}
		default:
			break;
		}
	}
}