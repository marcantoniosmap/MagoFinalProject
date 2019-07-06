//Author: MarcAntonio and Figo Aranta

#include "UserInterface.h"
// function to search travel packages from userinterface
void UserInterface::searchTravelPackages()
{
	int searchInput;
	string searchInputS;
	bool runSearchMenu = true;
	vector<TravelPack*>temporaryVector;
		//userinterface of searching function
	while (runSearchMenu)
	{

		system("cls");
		cout << "===============================" << endl;
		cout << "	SEARCH MENU" << endl;
		cout << "===============================" << endl;
		cout << "[1]. Search Code" << endl;
		cout << "[2]. Search Name and Keyword" << endl;
		cout << "[3]. Search by date" << endl;
		cout << "[4]. Advanced search" << endl;
		cout << "[5]. Exit from search menu" << endl;
		cout << "Select your command:" << endl;
		cin >> searchInputS;
		try
		{
			searchInput = stoi(searchInputS);
		}
		catch (const std::exception&)
		{
			searchInput = 0;
		}
		switch (searchInput)
		{

		case 1:
		{//search code
			string inputCode;
			cout << "You are now searching for a Travel based on its code" << endl;
			cout << "Input your code here: " << endl;
			cin >> inputCode;
			functionController.searchCode(inputCode);
			ActivatingSearch();
			break;

		}
		case 2:
		{
			//search by keyword
			string keyword;
			cout << "You are now searching for a Travel based on its keyword" << endl;
			cout << "This search function will search the substring" << endl;
			cout << "Input your keyword here: " << endl;
			cin.ignore();
			getline(cin, keyword);
			toLowering(keyword);
			functionController.searchKeyword(keyword);
			ActivatingSearch();
			break;
		}
		case 3:
		{
			//search by date
			string date;
			cout << "You are now searching for a Travel based on its date" << endl;
			cout << "Input date here: " << endl;
			cin >> date;
			functionController.searchDate(date);
			ActivatingSearch();
			break;
		}
		case 4:
		{
			//advance search
			int avancesearchinput;
			bool startSearch = false;
			string filterApplied = "";

			bool run = true;
			//userinterface of advance searching
			while (run)
			{
				system("cls");
				cout << "=============================" << endl;
				cout << "    THIS IS ADVANCE SEARCH" << endl;
				cout << "=============================" << endl;
				cout << "[1] Set price range" << endl;
				cout << "[2] Set date range" << endl;
				cout << "[3] Add a keyword" << endl;
				cout << "[4] Clear filters" << endl;
				cout << "[5] View search result" << endl;
				cout << "[6] Exit from advance search" << endl;
				cout << "Filter applied:" <<filterApplied<< endl;
				cout << "Select your command:" << endl;
				cin >> avancesearchinput;
				switch (avancesearchinput)
				{
				// to search by price range
				case 1:
				{
					int minimum, maximum;
					cout << "Setting price range" << endl;
					cout << "Enter minimum price:" << endl;
					cin >> minimum;
					cout << "Enter maximum price:" << endl;
					cin >> maximum;
					if (!startSearch)
					{
						for (int j = 0; j < hashNum; j++)
						{
							for (int i = 0; i < functionController.packageCount(j); i++)
							{
								if (minimum<=functionController.TravelPackData[j][i].getPrice() && maximum >= functionController.TravelPackData[j][i].getPrice())
								{
									temporaryVector.push_back(&functionController.TravelPackData[j][i]);
									startSearch = true;
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < temporaryVector.size(); i++)
						{
							if (minimum>=temporaryVector[i]->getPrice() ||maximum <= temporaryVector[i]->getPrice())
							{
								temporaryVector.erase(temporaryVector.begin() + i);
							}
						}
					}
					filterApplied += (", Price range from " + to_string(minimum) + "-" + to_string(maximum)+"\n");
					break;
				}
				//to serach by date range
				case 2:
				{
					int minimumDate, maximumDate;
					cout << "Setting date range" << endl;
					cout << "Enter starting date:" << endl;
					cin >> minimumDate;
					cout << "Enter last date:" << endl;
					cin >> maximumDate;
					if (!startSearch)
					{
						for (int j = 0; j < hashNum; j++)
						{
							for (int i = 0; i < functionController.packageCount(j); i++)
							{
								if (minimumDate<functionController.TravelPackData[j][i].getIntDate() && maximumDate > functionController.TravelPackData[j][i].getIntDate())
								{
									temporaryVector.push_back(&functionController.TravelPackData[j][i]);
									startSearch = true;
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < temporaryVector.size(); i++)
						{
							if (minimumDate<=temporaryVector[i]->getIntDate() || maximumDate >= temporaryVector[i]->getIntDate())
							{
								temporaryVector.erase(temporaryVector.begin() + i);
							}
						}
					}
					filterApplied += (", Date range from " + to_string(minimumDate) + "-" + to_string(maximumDate) + "\n");
					break;
				}
				//to add a keyword
				case 3:
				{
					string keywordSearched;
					cout << "Adding a keyword" << endl;
					cout << "Enter the desired keyword:" << endl;
					cin.ignore();
					getline(cin, keywordSearched);
					toLowering(keywordSearched);
					if (!startSearch)
					{
						for (int j = 0; j < hashNum; j++)
						{
							for (int i = 0; i < functionController.packageCount(j); i++)
							{
								if (functionController.TravelPackData[j][i].getPackName().find(keywordSearched) != string::npos || functionController.TravelPackData[j][i].getDescription().find(keywordSearched) != string::npos)
								{
									temporaryVector.push_back(&functionController.TravelPackData[j][i]);
									startSearch = true;
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < temporaryVector.size(); i++)
						{
							if (temporaryVector[i]->getPackName().find(keywordSearched) != string::npos || temporaryVector[i]->getDescription().find(keywordSearched) != string::npos)
							{
								continue;
							}
							else
							{
								temporaryVector.erase(temporaryVector.begin() + i);
							}
						}
					}
					filterApplied += ("Containing keyword : " + keywordSearched + "\n");
					break;
				}
				// to clear all filter
				case 4:
				{
					filterApplied + "";
					startSearch = false;
					temporaryVector.clear();
					break;
				}
				//to view search result
				case 5:
				{
					cout << "--------------------------------------------------------------------------------------------" << endl;
					cout << "				FILTERED PACKAGES" << endl;
					cout << "--------------------------------------------------------------------------------------------" << endl;
					cout << "||" << setw(15) << "code" << "||" << setw(40) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
					cout << "--------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < temporaryVector.size(); i++)
					{
						cout << "||" << setw(15) << temporaryVector[i]->getCode() << "||" << setw(40) << temporaryVector[i]->getPackName() << "||"
							<< setw(12) << temporaryVector[i]->getPrice() << "||" << setw(10) << temporaryVector[i]->getDate() << "||" << endl;
					}
					cout << "--------------------------------------------------------------------------------------------" << endl;
					ActivatingSearch();
					break;
				}
				//to exit from advance search
				case 6:
				{
					run = false;
					break;
				}
				default:
				{
					cout << "Inappropriate input" << endl;
					break;
				}
				}
				
			}
		}//to exit from search menu
		case 5:
		{
			runSearchMenu = false;
			break;
		}
		default:
		{
			cout << "Inappropriate input" << endl;
			break;
		}
		}
	}
	
}
//  menu after user press search by code
void UserInterface::ActivatingSearch()
{
	bool run = true;
	while (run)
	{
		int yesOrNoinput;
		string inp;
		cout << "Find what you need?" << endl;
		cout << "[1] Yes, i'll input the code" << endl;
		cout << "[2] No, i would like to perform another search" << endl;
		cout << "[3] Exit to main menu" << endl;
		cout << "Enter your command:" << endl;
		cin >> yesOrNoinput;
		switch (yesOrNoinput)
		{
		//after the user input the code. Then user has to enter the complete code.
		case 1:
		{
			cout << "Enter complete code: " << endl;
			cin.ignore();
			getline(cin, inp);
			int hash = inp[0] % hashNum;
			for (int i = 0; i < functionController.packageCount(hash); i++)
			{
				if (inp == functionController.TravelPackData[hash][i].getCode())
				{
					cout << "Code found [press enter to continue]" << endl;
					activePack = &functionController.TravelPackData[hash][i];
					cin.ignore();
					run = false;
					break;
				}
			}
			break;
		}
		//to perform another search
		case 2:
		{
			run = false;
			break;
		}
		// to exit from main menu
		case 3:
		{
			mainMenu();
			return;
			break;
		}

		default:
			cout << "Inappropriate input" << endl;
			break;
		}
	}
	return;
}
//function to search by traveler
void UserInterface::searchTraveler()
{	
	system("cls");
	int inp;
	bool run = true;
	// the userinterface menu
	while (run)
	{
		cout << "===============================" << endl;
		cout << "	SEARCH TRAVELER MENU" << endl;
		cout << "===============================" << endl;
		cout << "[1]. List Traveler by Active package" << endl;
		cout << "[2]. Search by name" << endl;
		cout << "[3]. Search by nationality" << endl;
		cout << "[4]. Exit from search menu" << endl;
		cout << "Select your command:" << endl;
		cin >> inp;
		switch (inp)
		{
			// to list traveler by active package.
		case 1:
		{
			int yesNoUserInput;
			cout << "List of Traveler by Travel Code" << endl;
			cout << "Do you want to list the active package?" << endl;
			cout << "[1]. Yes i would like to search all traveler from the active package" << endl;
			cout << "[2]. I would like to choose the package first" << endl;
			cin >> yesNoUserInput;
			if (yesNoUserInput == 2) searchTravelPackages();
			else if (yesNoUserInput == 1)
			{
				if (activePack != NULL)
				{
					functionController.listAllCustomer(activePack);
				}
				else
				{
					cout << "Sorry, but you have not set your active package" << endl;
				}
			}
			break;
		}
		//to search by name
		case 2:
		{
			string searchName;
			cout << "Searching by Traveler name" << endl;
			cout << "Enter traveler name you wish to search" << endl;
			cin.ignore();
			getline(cin, searchName);
			toLowering(searchName);
			functionController.searchAllName(searchName);

			break;
		}
		//to search by nationality
		case 3:
		{
			string NationalityName;
			cout << "Searching by Traveler name" << endl;
			cout << "Enter traveler nationality you wish to search" << endl;
			cin.ignore();
			getline(cin, NationalityName);
			toLowering(NationalityName);
			functionController.searchNationality(NationalityName);
			break;
		}
		// to exit to main menu
		case 4:
		{
			run = false;
			break;
		}
		//error message when user input inapropriate input
		default:
		{	
			cout << "Inappropriate input" << endl;
			break;
		
		}
		}
	}
}
//function to book package
void UserInterface::bookPackage()
{
	bool run = true;
	//userinterface of booking package menu
	while (run)
	{
		int bookInput;
		cout << "===============================" << endl;
		cout << "	BOOKING TOUR MENU" << endl;
		cout << "===============================" << endl;
		cout << "[1]. Book Activated package" << endl;
		cout << "[2]. List package availability" << endl;
		cout << "[3]. Set Payment in the activated package" << endl;
		cout << "[4]. Set the activated Package" << endl;
		cout << "[5]. Exit from booking menu" << endl;
		cout << "Select your command:" << endl;
		cin >> bookInput;
		switch (bookInput)
		{
		// to book activated package
		case 1:
		{
			bookingPage();
			break;
		}
		// to list package availability
		case 2:
		{
			string available;
			cout << "==================================" << endl;
			cout << "  List of Package availability" << endl;
			cout << "==================================" << endl;
			cout << setw(15) << "Code" << "||" << setw(15) << "availability" << endl;
			cout << "-----------------------------" << endl;
			for (int j = 0; j < hashNum; j++)
			{
				for (int i = 0; i < functionController.packageCount(j); i++)
				{
					available = to_string(functionController.TravelPackData[j][i].getCurrentAvailability()) + " / " + to_string(functionController.TravelPackData[j][i].getAvailability());
					cout << setw(15) << functionController.TravelPackData[j][i].getCode() << "||" << setw(15) <<
						available << endl;
				}
			}
			break;
		}
		// to set payment in activated package.
		case 3:
		{
			int yesNoUserInput;
			cout << "Set Payment to the activated Package" << endl;
			cout << "Do you want to list the active package?" << endl;
			cout << "[1]. Yes i would like to search all traveler from the active package" << endl;
			cout << "[2]. I would like to choose the package first" << endl;
			cin >> yesNoUserInput;
			if (yesNoUserInput == 2) searchTravelPackages();
			else if (yesNoUserInput == 1)
			{
				if (activePack != NULL)
				{
					int inputIndex,payment,repeat;
					
					while (true)
					{
						functionController.ListComplete((activePack));
						if (activePack->getTravelerNumber() == 0) cout << "The pack is still empty" << endl;
						else
						{
							cout << "Input the Number of the customer in order to set the payment" << endl;
							cin >> inputIndex;
							if (inputIndex > 0 && inputIndex <= activePack->getTravelerNumber())
							{
								inputIndex = inputIndex - 1;
								cout << "Set Payment For" << endl;
								cout << "First Name		:" << activePack->getTraveler().get(inputIndex)->getFirstName() << endl;
								cout << "Last Name		:" << activePack->getTraveler().get(inputIndex)->getSurName() << endl;
								cout << "Citizenship	:" << activePack->getTraveler().get(inputIndex)->getCitizenship() << endl;
								cout << "To Pay			:" << activePack->getTraveler().get(inputIndex)->getPrice() << endl;
								cout << "PAID			:" << activePack->getTraveler().get(inputIndex)->getPaidText() << endl;
								cout << "SET PAYMENT TO" << endl;
								cout << "[1]. PAID" << endl;
								cout << "[2]. UNPAID" << endl;
								cout << "[3]. CANCEL" << endl;
								cout << "[3]. EXIT" << endl;
								cin >> payment;
								if (payment == 1) activePack->getTraveler().get(inputIndex)->setPaid(true);
								else if (payment == 2) activePack->getTraveler().get(inputIndex)->setPaid(false);
								else if (payment == 3)continue;
								else break;
								cout << "Would you like to repeat or redo a process" << endl;
								cout << "[1]. YES" << endl;
								cout << "[2]. NO" << endl;
								cin >> repeat;
								if (repeat == 1) continue;
								else break;

							}
							else
							{
								cout << "Inappropriate input" << endl;
							}
						}
					}
					
				}
				else
				{
					cout << "Sorry, but you have not set your active package" << endl;
				}
			}
			break;
			break;
		}
		//to activate package
		case 4:
		{
			searchTravelPackages();
			break;
		}
		// to exit to main menu
		case 5:
		{
			run = false;
			break;
		}
		default:
			break;
		}
	}
}
//interface for booking page
void UserInterface::bookingPage()
{
	if (activePack == NULL)
	{
		cout << "You have not chosen the activated package" << endl;
		bookPackage();
		return;
	}
	int inp;
	system("cls");
	cout << "===============================" << endl;
	cout << "		BOOKING TOUR MENU" << endl;
	cout << "===============================" << endl;
	cout << "You are about to book this tour package" << endl;
	cout << "Code			:" << activePack->getCode() << endl;
	cout << "Name			:" << activePack->getPackName() << endl;
	cout << "Price			:" << activePack->getPrice()<<endl;
	cout << "Date			:" << activePack->getDate()<<endl;
	cout << "Availability	:" << activePack->getCurrentAvailability()<<endl;
	cout << "===============================" << endl;
	cout << "[1]. Confirm order" << endl;
	cout << "[2]. Exit" << endl;
	cin >> inp;
	switch (inp)
	{
	// to confirm an order, user has to input for how many people and the customer data for each person
	case 1:
	{
		int NumberOfPeople;
		cout << "Enter number of people you want to book for [ MAX : "<<activePack->getCurrentAvailability()<<" ]" << endl;
		cin >> NumberOfPeople;
		bool check = true;
		while (check)
		{
			
				
			if (NumberOfPeople<0 || NumberOfPeople>activePack->getCurrentAvailability())
			{
				cout << "Your input is inappropriate" << endl;
				cout << "[1]. Try again" << endl;
				cout << "[2]. Exit" << endl;
				int inp;
				cin >> inp;
				if (inp == 1) continue;
				else if (inp == 2) bookingPage();
				else continue;
			}
			else
			{
				string fName, lName, Nationality;
				int ageInput, paid,price;
				for (int i = 0; i < NumberOfPeople; i++)
				{
					cout << "=====================" << endl;
					cout << "Traveler Input ("<<i+1<<" / "<<NumberOfPeople<<")" << endl;
					cout << "=====================" << endl;
					cout << "Enter First name of the traveler:" << endl;
					cin.ignore();
					getline(cin, fName);
					cout << "Enter Last name of the traveler:	" << endl;
					getline(cin, lName);
					cout << "Enter citizenship of the traveler:	" << endl;
					getline(cin, Nationality);
					cout << "Enter current age of the traveler:" << endl;
					cin >> ageInput;
					if (ageInput < 15)
					{
						int inpY;
						cout << "This inputted traveler is below 15 years old" << endl;
						cout << "[1]. Input updatted price"<< endl;
						cout << "[2]. Use Normal price" << endl;
						cin >> inpY;
						if (inpY == 1)
						{
							int newPrice;
							while (true)
							{
								cout << "Input new price" << endl;
								cout << "Old price was :	" << activePack->getPrice() << endl;
								cin >> newPrice;
								if (newPrice > 0)price = newPrice; break;

							}
						}
						else price=activePack->getPrice();
					}
					else
					{
						price = activePack->getPrice();
					}
					int payment;
					bool paid;
					cout << "Set Payment to :" << endl;
					cout << "[1]. PAID" << endl;
					cout << "[2]. UNPAID" << endl;
					cout << "Select command" << endl;
					cin >> payment;
					if (payment == 1) paid = true;
					else paid = false;

					activePack->addCustomer(customer(activePack->getCode(), fName, lName, ageInput, Nationality, paid, price));
					cout << "New traveler data is inputted" << endl;

				}
				check = false;
				
			}
		}
		break;
	}
	// to exit
	case 2:
	{
		bookPackage();
		return;
	}
	default:
		break;
	}


	
}