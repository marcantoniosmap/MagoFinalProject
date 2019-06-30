//Author: MarcAntonio and Figo Aranta

#include "UserInterface.h"


void UserInterface::editMenu()
{
	system("cls");
	bool run = true;
	string bIString;
	while (run)
	{
		int bookInput;
		cout << "===============================" << endl;
		cout << "		EDIT MENU" << endl;
		cout << "===============================" << endl;
		cout << "[1]. Edit Active Package" << endl;
		cout << "[2]. Edit Traveler Data" << endl;
		cout << "[3]. Set the activated Package" << endl;
		cout << "[4]. Exit from edit menu" << endl;
		cout << "Select your command:" << endl;
		cin >> bIString;
		try
		{
			bookInput = stoi(bIString);
		}
		catch (exception) { bookInput = 0; }
		switch (bookInput)
		{
			case 1:
			{
				editItem();
				break;
			}
			case 2:
			{
				
				break;
			}
			case 3:
			{
				searchTravelPackages();
				break;
			}
			case 4:
			{
				customize();
				run = false;
				break;
			}
			default:
			{
				cout << "Inappropriate input" << endl;
			}
		}
	}

}

void UserInterface::editItem()
{
	if (activePack == NULL)
	{
		cout << "You have not chosen a package" << endl;
		return;
	}
	int inp;
	string StringInp;
	bool run = true;
	while (run)
	{
		system("cls");
		cout << "=====================================" << endl;
		cout << " EDIT PREVIEW" << endl;
		cout << "=====================================" << endl;
		cout << "Code			:" << activePack->getCode() << endl;
		cout << "Name			:" << activePack->getPackName() << endl;
		cout << "Price			:" << activePack->getPrice() << endl;
		cout << "Date			:" << activePack->getDate() << endl;
		cout << "Availability	:" << activePack->getCurrentAvailability() << endl;
		cout << "===============================" << endl;
		cout << "[1]. Yes i would like to edit this package!" << endl;
		cout << "[2]. Exit" << endl;
		cin >> StringInp;
		try
		{
			inp = stoi(StringInp);
		}
		catch (const std::exception&)
		{

		}
		if (inp == 1)
		{
			bool run2 = true;
			int attributes;
			string attributesString;
			while (run2)
			{

				cout << "===============================================" << endl;
				cout << "	WHICH ATTRIBUTE WOULD YOU LIKE TO EDIT" << endl;
				cout << "===============================================" << endl;
				cout << "[1]. Package Code" << endl;
				cout << "[2]. Package Name" << endl;
				cout << "[3]. Package price" << endl;
				cout << "[4]. Package Date" << endl;
				cout << "[5]. Package Availability" << endl;
				cout << "[6]. Description" << endl;
				cout << "[7]. Finish and Exit" << endl;
				cout << "Choose field you wish to edit:" << endl;
				cin >> attributesString;
				try
				{
					attributes = stoi(attributesString);
				}
				catch (const std::exception&) {}
				switch (attributes)
				{
				case 1:
				{
					string packCode;
					while (true)
					{
						cin.ignore();
						cout << "input package code" << endl;
						cout << "ALPHA NUMERIC [3-13 character]" << endl;
						cout << "Recommended to attach the dates at the end of the code" << endl;
						cout << "Should not contain any space" << endl;
						getline(cin, packCode);
						if (ValidateItem(packCode, "codeName"))
						{
							activePack->setCode(packCode);

							int update;
							cout << "You're Changing the package Code" << endl;
							cout << "The customer data could be modified too" << endl;
							cout << "[1]. Update their code with the new one" << endl;
							cout << "[2]. Do not update and lose all the customer" << endl;
							cout << "Enter Command:" << endl;
							cin >> update;
							if (update == 1)
							{
								Node* counter = activePack->getTraveler().get_head();
								while (counter)
								{
									counter->customerList.setTravelCode(packCode);
									counter = counter->link;
								}
							}
							else
							{
								activePack->getTraveler().init();
							}
							cout << "You had succesfully changed your code" << endl;
							break;


						}

						else cout << "Not inappropriate package code" << endl;
					}
					break;
				}
				case 2:
				{
					string packName;
					while (true)
					{
						cout << "Package name will be the title of your package" << endl;
						cout << "Example : 3d2n in Wonderful Bali" << endl;
						cout << "Input package name [5 -40 char]" << endl;
						getline(cin, packName);
						if (ValidateItem(packName, "PackageName"))
						{
							activePack->setPackName(packName);
							cout << "Your Package name had been succesfully changed into " << packName << endl;
							break;
						}
						else cout << "Not inappropriate package Name" << endl;
					}
					break;
				}
				case 3:
				{
					int price;
					while (true)
					{
						cout << "price is set for adult, do not set to kids price" << endl;
						cout << "Set price above Rp.100.000 - Rp.100.000.000" << endl;
						cout << "Input package price" << endl;
						cin >> price;
						if (ValidateNumber(price, "price"))
						{
							activePack->setPrice(price);

							int update;
							cout << "You're Changing the package Price" << endl;
							cout << "The customer data could be modified too" << endl;
							cout << "[1]. Update their price with the new one" << endl;
							cout << "[2]. Do not update and let exsisting customer have thier previous price" << endl;
							cout << "Enter Command:" << endl;
							cin >> update;
							if (update == 1)
							{
								Node* counter = activePack->getTraveler().get_head();
								while (counter)
								{
									if (counter->customerList.getPrice() == price)
									{
										counter->customerList.setPrice(price);
									}
									counter = counter->link;
								}
							}

							cout << "You had succesfully changed your price" << endl;
							break;


						}
						else cout << "Not inappropriate price Name" << endl;
					}
					break;
				}case 4:
				{
					string date;
					while (true)
					{
						cout << "Appropriate format date : year-month-date" << endl;
						cout << "Input package date of departure" << endl;
						cin >> date;
						if (ValidateItem(date, "date"))
						{
							activePack->setDate(date);
							break;
						}
						else cout << "Not inappropriate Date Name" << endl;
					}
					break;
				}case 5:
				{
					int availability;
					while (true)
					{
						cin.ignore();
						cout << "Availability must be > 5 and <80" << endl;
						cout << "Input package availability" << endl;
						cin >> availability;
						if (ValidateNumber(availability, "availability"))
						{
							activePack->setAvailability(availability);
							cout << "You had succesfully updated your availability" << endl;
							break;
						}
						else cout << "Not inappropriate Availability" << endl;
					}
					break;
				}case 6:
				{
					string desc;
					while (true)
					{
						cout << "Input brief description to the package" << endl;
						cout << "Describe the package, location and explanation" << endl;
						getline(cin, desc);
						if (ValidateItem(desc, "description"))
						{
							activePack->setDescription(desc);
							cout << "You had succesfully updated your availability" << endl;
							break;

						}

						else cout << "Not inappropriate description" << endl;
					}
					break;
				}case 7:
				{
					editMenu();
					run2 = false;
					break;
				}


				default:
					cout << "Inappropriate input" << endl;
					break;
				}

			}
		}
		else if (inp == 2)
		{
			editMenu();
			return;
		}
		else
		{
			cout << "Inappropriate input" << endl;
		}



	}
}