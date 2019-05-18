#pragma once
#include <fstream>
#include <cstdlib>
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
	~FunctionController();

};




FunctionController::FunctionController()
{
	TravelPackData.empty();
}


FunctionController::~FunctionController()
{
}



void FunctionController::addNewItem(TravelPack p)
{
	TravelPackData.push_back(p);
}





void FunctionController::myReplace(string& str,const string& oldStr,const string& newStr)
{
	string::size_type pos = 0u;
	while ((pos = str.find(oldStr, pos)) != string::npos) {
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
}
void FunctionController::readFile()
{
	ifstream file("TravelPackage.txt");

	string code, packageName, date;
	int price, availability;

	if (file.is_open()) {
		while (file >> code >> packageName >> price >> date >> availability)
		{
			myReplace(packageName, "_", " ");
			TravelPackData.push_back(TravelPack(code, packageName, price, date, availability));
		}

		file.close();

		ifstream file2("TravelerData.txt");

		string code, firstN, surN, Nationality;
		bool paid;
		int age, price;
		if (file2.is_open()) {
			while (file2 >> code >> firstN >> surN >> age >> Nationality >> paid >> price)
			{
				myReplace(firstN, "_", " ");
				myReplace(surN, "_", " ");

				for (int i = 0; i < TravelPackData.size(); i++)
				{
					if (TravelPackData[i].getCode() == code)
					{
						TravelPackData[i].addCustomer(customer(code, firstN, surN, age, Nationality, paid, price));
					}
				}
			}

			file2.close();
		}
	}
	else
	{
		cout << "SORRY CAN'T READ TXT!" << endl;
		exit(EXIT_FAILURE);
	}
}

void FunctionController::writeFile()
{
	ofstream file("TravelPackage.txt");

	string code, packageName, date;
	int price, availability;
	if (!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (file.good())
	{
		for (int i = 0; i < TravelPackData.size(); i++)
		{
			code = TravelPackData[i].getCode();
			packageName = TravelPackData[i].getPackName();
			date = TravelPackData[i].getDate();
			price = TravelPackData[i].getPrice();
			availability = TravelPackData[i].getAvailability();
			myReplace(packageName, " ", "_");

			file << code << " " << packageName<<" " << price<< " " << date<< " " << availability << endl;

		}
		file.close();
	}
	ofstream file2("TravelData.txt");

	string codeN,fName, sName, Nationality;
	int priceN, age;
	bool paid;
	if (!file2.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (file2.good())
	{
		for (int i = 0; i < TravelPackData.size(); i++)
		{
			while (TravelPackData[i].getTraveler().itterate != NULL)
			{
				codeN = TravelPackData[i].getTraveler().itterate->customerList.getCode();
				fName = TravelPackData[i].getTraveler().itterate->customerList.getFirstName();
				sName = TravelPackData[i].getTraveler().itterate->customerList.getSurName();
				Nationality = TravelPackData[i].getTraveler().itterate->customerList.getCitizenship();
				priceN = TravelPackData[i].getTraveler().itterate->customerList.getPrice();
				age = TravelPackData[i].getTraveler().itterate->customerList.getAge();
				paid = TravelPackData[i].getTraveler().itterate->customerList.getPaid();
				myReplace(fName, " ", "_");
				myReplace(sName, " ", "_");

				file2 << codeN << " " << fName << " " << sName << " " << age << " " << Nationality << " "<<paid<<" " << priceN << " " << endl;
				TravelPackData[i].getTraveler().moveItterate();
			}
		}
		file2.close();
	}

}