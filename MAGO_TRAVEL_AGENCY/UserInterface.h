#pragma once
#include <iomanip>
#include <string>
#include "FunctionController.h"

class UserInterface
{
private:
	FunctionController functionController;
public:

	void mainMenu();
	void checkStatus();
	void add();
	void addEditDelete();
	void editItem();
	void deleteItem();
	UserInterface();
	~UserInterface();
};
