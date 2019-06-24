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
	vector<TravelPack>TravelPackData[26];
	FunctionController();
	int packageCount(int hashIndex);

	void myReplace(string& str, const string& oldStr, const string& newStr);
	void addNewItem(TravelPack p,int hashIndex);
	void searchCode(string searchCode);
	void searchKeyword(string searchKey);
	void searchDate(string date);
	void printExistingPack();
	void printview(int hash,int index);


	void readFile();
	void writeFile();
	~FunctionController();
};