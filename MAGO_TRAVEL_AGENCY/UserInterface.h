//Author: MarcAntonio and Figo Aranta

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
	//constructor
	UserInterface();
	int hashNum = 26;

	//menus
	void mainMenu();
	void customize();
	void editMenu();
	void deleteMenu();
	void checkStatus();

	void searchTravelPackages();
	void searchTraveler();
	void bookPackage();
	
	void add();
	void editItem();
	void deleteItem();
	void ActivatingSearch();
	void bookingPage();

	//formatting
	bool ValidateItem(string& content, string key);
	bool ValidateNumber(const int& content, string key);
	string FormattingDesc(string desc);
	void toLowering(string &tolowered);
	
	~UserInterface();
};