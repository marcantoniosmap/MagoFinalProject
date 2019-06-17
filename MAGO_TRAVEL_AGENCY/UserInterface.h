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
public:

	void mainMenu();
	void book();
	void search();
	void checkStatus();
	void add();
	void addEditDelete();
	void editItem();
	void deleteItem();
	UserInterface();
	~UserInterface();
};
#include "UserInterface.cpp"