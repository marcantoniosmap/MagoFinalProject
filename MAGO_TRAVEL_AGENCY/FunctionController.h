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

//construtors
	int packageCount(int hashIndex);

	void myReplace(string& str, const string& oldStr, const string& newStr);
	void addNewItem(TravelPack p,int hashIndex);

	//seraching funtion,  delete, list ,print, read and write.
	void searchCode(string searchCode);
	void searchKeyword(string searchKey);
	void searchDate(string date);
	void searchAllName(string customerName);
	void searchNationality(string nationality);

	bool deletePack(string codeDelete);
	void listAllCustomer(TravelPack *active);
	void ListComplete(TravelPack *active);
	void listSimilar(TravelPack *active);

	void printExistingPack();
	string toLoweringRet(string tolowered);
	void printview(int hash,int index);
	void readFile();
	void writeFile();
	~FunctionController();
	
};