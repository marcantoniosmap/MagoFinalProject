//Author: MarcAntonio and Figo Aranta

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
	static int const hashNum = 26;
	vector<TravelPack>TravelPackData[hashNum];
	FunctionController();


	int packageCount(int hashIndex);

	void myReplace(string& str, const string& oldStr, const string& newStr);
	void addNewItem(TravelPack p,int hashIndex);

	//searching function
	void searchCode(string searchCode);
	void searchKeyword(string searchKey);
	void searchDate(string date);
	void searchAllName(string customerName);
	void searchNationality(string nationality);

	void listAllCustomer(TravelPack *active);
	void printExistingPack();
	void printview(int hash,int index);
	void readFile();
	void writeFile();
	~FunctionController();
	
};