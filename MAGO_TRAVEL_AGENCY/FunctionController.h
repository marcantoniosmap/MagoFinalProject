#pragma once
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "TravelPack.h"
using namespace std;
class FunctionController
{

public:	
	vector<TravelPack>TravelPackData;
	FunctionController();
	void readFile();
	void writeFile();
	void myReplace(string& str, const string& oldStr, const string& newStr);
	void addNewItem(TravelPack p);
	void printExistingPack();
	~FunctionController();

};
