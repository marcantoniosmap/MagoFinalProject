#pragma once
#include <iomanip>
#include  <iostream>
#include <string>
#include <stdlib.h>
#include "FunctionController.h"

class UserInterface
{
private:
	FunctionController functionController;
	TravelPack* activePack;
public:

	
	void mainMenu();
	void book();
	void searchTravelPackages();
	void searchTraveler();
	void bookPackage();
	void checkStatus();
	void add();
	void addEditDelete();
	void editItem();
	void deleteItem();
	void toLowering(string &tolowered);
	void ActivatingSearch();
	void bookingPage();
	UserInterface();
	~UserInterface();
};