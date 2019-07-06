//Author: MarcAntonio and Figo Aranta

#include "UserInterface.h"

//function to edit active package, traveler data or set the activated package
void UserInterface::editMenu()
{
	system("cls");
	bool run = true;
	string bIString;
	// edit menu interface
	while (run)
	{
		int bookInput;
		cout << "===============================" << endl;
		cout << "	EDIT MENU" << endl;
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
			// to edit active package
			case 1:
			{
				editItem();
				break;
			}
			// to edit traveler data
			case 2:
			{
				int yesNoUserInput;
				cout << "Set editing process to the activated Package customer" << endl;
				cout << "Do you want to list the customer from active package?" << endl;
				cout << "[1]. Yes i would like to search all traveler from the active package" << endl;
				cout << "[2]. I would like to choose the package first" << endl;
				cin >> yesNoUserInput;
				if (yesNoUserInput == 2) searchTravelPackages();
				else if (yesNoUserInput == 1)
				{
					if (activePack != NULL)
					{
						int inputIndex, edit, repeat;
						bool run = true;
						while (run)
						{
							functionController.ListComplete((activePack));
							if (activePack->getTravelerNumber() == 0) cout << "The pack is still empty" << endl;
							else
							{
								cout << "Input the Number of the customer in order to edit" << endl;
								cin >> inputIndex;
								if (inputIndex > 0 && inputIndex <= activePack->getTravelerNumber())
								{
									inputIndex = inputIndex - 1;
									cout << " Editing Account" << endl;
									cout << " [1] Edit First Name	:" << activePack->getTraveler().get(inputIndex)->getFirstName() << endl;
									cout << " [2] Edit Last Name		:" << activePack->getTraveler().get(inputIndex)->getSurName() << endl;
									cout << " [3] Edit Citizenship	:" << activePack->getTraveler().get(inputIndex)->getCitizenship() << endl;
									cout << " [4] Edit Price			:" << activePack->getTraveler().get(inputIndex)->getPrice() << endl;
									cout << " [5] EXIT" << endl;
									cout << " Select field you wish to edit" << endl;
									cin >> edit;
									switch (edit)
									{
										// to edit first name of customer data
									case 1:
									{
										string fName;
										while (true)
										{
											cout << "Enter new First Name" << endl;
											getline(cin, fName);
											if (ValidateItem(fName, "name"))
											{
												activePack->getTraveler().get(inputIndex)->setFirstName(fName);
												cout << "Succesfully changed" << endl;
												break;
											}
											else
											{
												cout << "Inappropriate input" << endl;
											}
										}
										break;
									}
									// to edit last name of customer data
									case 2:
									{
										string LName;
										while (true)
										{
											cout << "Enter new Last Name" << endl;
											getline(cin, LName);
											if (ValidateItem(LName, "name"))
											{
												activePack->getTraveler().get(inputIndex)->setSurName(LName);
												cout << "Succesfully changed" << endl;
												break;
											}
											else
											{
												cout << "Inappropriate input" << endl;
											}
										}
										break;
									}
									//to edit the citizenship of customer data
									case 3:
									{
										string citizenship;
										while (true)
										{
											cout << "Enter new citizenship:" << endl;
											getline(cin, citizenship);
											if (ValidateItem(citizenship, "name"))
											{
												activePack->getTraveler().get(inputIndex)->setCitizenship(citizenship);
												cout << "Succesfully changed" << endl;
												break;
											}
											else
											{
												cout << "Inappropriate input" << endl;
											}
										}
										break;
									}
									// to edit the price
									case 4:
									{
										int newPrice;
										while (true)
										{
											cout << "Enter new Price" << endl;
											cin >> newPrice;
											if (ValidateNumber(newPrice, "price"))
											{
												activePack->getTraveler().get(inputIndex)->setPrice(newPrice);
												cout << "Succesfully changed" << endl;
												break;
											}
											else
											{
												cout << "Inappropriate input" << endl;
											}
										}
										break;
									}
									// to exit from the menu
									case 5:
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
			// to set the activated package
			case 3:
			{
				searchTravelPackages();
				break;
			}
			//to  exit from from edit menu
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
//function to edit travel package
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
	//userinterace to edit the chosen package
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
			//userinterface when user want to edit the package
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
				// to edit package code
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
				// to edit package name
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
				// to edit package price
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
					//to edit package date
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
					// to edit package availability
				}case 5:
				{
					int availability;
					while (true)
					{
						cin.ignore();
						int minimum;
						minimum = (activePack->getTravelerNumber() > 5) ? activePack->getTravelerNumber() : 5;
						cout << "Availability must be > "<<minimum<<" and <80" << endl;
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
					// to edit package description
				}case 6:
				{
					string desc;
					while (true)
					{
						cin.ignore();
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
					// to finish the edit and exit
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
		//to exit
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
// function to delete package
void UserInterface::deleteMenu()
{
	int x;
	string StringX;
	bool run = true;
	// userinterface of delete menu
	while (run)
	{
		cout << "===============================" << endl;
		cout << "	DELETE MENU" << endl;
		cout << "===============================" << endl;
		cout << "[1]. Delete Active Package" << endl;
		cout << "[2]. Delete Traveler Data" << endl;
		cout << "[3]. Set the activated Package" << endl;
		cout << "[4]. Exit from delete menu" << endl;
		cout << "Select your command:" << endl;
		cin >> StringX;
		try
		{
			x = stoi(StringX);
		}
		catch (const std::exception&) { x = 0; }
		switch (x)
		{
			//to delete active package
		case 1:
		{
			deleteItem();
			break;
		}
		// to delete traveler data
		case 2:
		{
			int yesNoUserInput;
			cout << "Set Deleting process to the activated Package" << endl;
			cout << "Do you want to list the active package?" << endl;
			cout << "[1]. Yes i would like to search all traveler from the active package" << endl;
			cout << "[2]. I would like to choose the package first" << endl;
			cin >> yesNoUserInput;
			if (yesNoUserInput == 2) searchTravelPackages();
			else if (yesNoUserInput == 1)
			{
				if (activePack != NULL)
				{
					int inputIndex, deletion, repeat;

					while (true)
					{
						functionController.ListComplete((activePack));
						if (activePack->getTravelerNumber() == 0) cout << "The pack is still empty" << endl;
						else
						{
							cout << "Input the Number of the customer in order to delete" << endl;
							cin >> inputIndex;
							if (inputIndex > 0 && inputIndex <= activePack->getTravelerNumber())
							{
								inputIndex = inputIndex - 1;
								cout << "Delete Account" << endl;
								cout << "Travel Code		:" << activePack->getCode() << endl;
								cout << "First Name		:" << activePack->getTraveler().get(inputIndex)->getFirstName() << endl;
								cout << "Last Name		:" << activePack->getTraveler().get(inputIndex)->getSurName() << endl;
								cout << "Citizenship	:" << activePack->getTraveler().get(inputIndex)->getCitizenship() << endl;
								cout << "To Pay			:" << activePack->getTraveler().get(inputIndex)->getPrice() << endl;
								cout << "PAID			:" << activePack->getTraveler().get(inputIndex)->getPaidText() << endl;
								cout << "Delete this Traveler Data (this would be permanent)" << endl;
								cout << "[1]. Delete This Traveler" << endl;
								cout << "[2]. CANCEL" << endl;
								cout << "[3]. EXIT" << endl;
								cin >> deletion;
								if (deletion == 1)
									activePack->getTraveler().deleteCustomer(inputIndex);
								else if (deletion == 2) continue;
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
						break;
					}

				}
				else
				{
					cout << "Sorry, but you have not set your active package" << endl;
				}
			}
			break;
			
		}
		// set the activated package
		case 3:
		{
			searchTravelPackages();
			break;
		}
		//to exit to main menu
		case 4:
		{
			customize();
			run = false;
			break;
		}
		default:
			cout << "Inappropriate input" << endl;
		
		}
	
	}
}
// function when user proceed to delete the package
void UserInterface::deleteItem()
{
	

	if (activePack == NULL)
	{
		cout << "You have not chosen a package" << endl;
		return;
	}
	int inp;
	string StringInp;
	
	system("cls");
	cout << "=====================================" << endl;
	cout << " DELETE PREVIEW" << endl;
	cout << "=====================================" << endl;
	cout << "Code			:" << activePack->getCode() << endl;
	cout << "Name			:" << activePack->getPackName() << endl;
	cout << "Price			:" << activePack->getPrice() << endl;
	cout << "Date			:" << activePack->getDate() << endl;
	cout << "Availability	:" << activePack->getCurrentAvailability() << endl;
	cout << "===============================" << endl;
	cout << "[1]. Yes i would like to delete this package with all the traveler" << endl;
	cout << "[2]. Exit" << endl;
	cin >> StringInp;
	try
	{
		inp = stoi(StringInp);
	}
	catch (const std::exception&)
	{
		inp = 0;
	}
	//to delete the whole entire package
	if (inp==1)
	{
		if (functionController.deletePack(activePack->getCode()))
		{
			cout << "Your Data had been succesfully deleted" << endl;
			activePack = NULL;
		}
		else
		{
			cout << "ERROR deleting the pack" << endl;
		}
		return;
	}
	else
	{
		deleteItem();
	}


}