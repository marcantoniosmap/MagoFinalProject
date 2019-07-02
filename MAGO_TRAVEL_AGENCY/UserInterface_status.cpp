#include "UserInterface.h"

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
		case 2:
		{
			functionController.ListComplete(activePack);
			break;
		}
		case 3:
		{
			functionController.listSimilar(activePack);
			break;
		}
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