#include "FunctionController.h"


FunctionController::FunctionController()
{
	for (int i = 0; i < 26; i++)
	{
		TravelPackData[i].empty();
	}
	
}


FunctionController::~FunctionController()
{
}
int FunctionController::packageCount(int hashIndex)
{
	return TravelPackData[hashIndex].size();
}


void FunctionController::addNewItem(TravelPack p,int HashIndex)
{
	TravelPackData[HashIndex].push_back(p);
}

void FunctionController::searchCode(string searchCode)
{
	int hash = searchCode[0]%26;
	cout << "----------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(30) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < TravelPackData[hash].size(); i++)
	{
		if (TravelPackData[hash][i].getCode().find(searchCode) != string::npos)
		{
			printview(hash,i);
		}
	}
	cout << "----------------------------------------------------------" << endl;
}

void FunctionController::searchKeyword(string searchKey)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(30) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < TravelPackData[j].size(); i++)
		{
			if (TravelPackData[j][i].getPackName().find(searchKey) != string::npos || TravelPackData[j][i].getDescription().find(searchKey) != string::npos)
			{
				printview(j,i);
			}
		}
	}
	cout << "----------------------------------------------------------" << endl;
}

void FunctionController::searchDate(string date)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(30) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < TravelPackData[j].size(); i++)
		{
			if (TravelPackData[j][i].getDate().find(date) != string::npos)
			{
				printview(j,i);
			}
		}
	}
	cout << "----------------------------------------------------------" << endl;
}


void FunctionController::myReplace(string& str, const string& oldStr, const string& newStr)
{
	string::size_type pos = 0u;
	while ((pos = str.find(oldStr, pos)) != string::npos) {
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
}
void FunctionController::readFile()
{
	ifstream file("TravelP.txt");
	string codep, pname, date,desc,price_s;
	int availability, hash;
	if (file.is_open())
	{
		while (file>>codep>>pname>>price_s>>date>>availability>>desc)
		{
			myReplace(pname, "_", " ");
			myReplace(desc, "_", " ");
			int price = stoi(price_s);
			hash = codep[0]%26;
			TravelPackData[hash].push_back(TravelPack (codep, pname, price, date, availability,desc));
		}
		
		ifstream file2("TravelerData.txt");
		string codel, firstN, surN, Nationality;
		bool paid;
		int age, price,hashTrav;
		if (file2.is_open()) {
			while (file2 >> codel >> firstN >> surN >> age >> Nationality >> paid >> price)
			{
				myReplace(firstN, "_", " ");
				myReplace(surN, "_", " ");
				hashTrav = codel[0] % 26;
				for (int i = 0; i < TravelPackData[hashTrav].size(); i++)
				{
					if (TravelPackData[hashTrav][i].getCode() == codel)
					{
						TravelPackData[hashTrav][i].addCustomer(customer(codel, firstN, surN, age, Nationality, paid, price));
					}
				}
			}
			file.close();
			file2.close();
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cout << "SORRY CAN'T READ TXT!" << endl;
		
	}
}

void FunctionController::writeFile()
{
	ofstream file("TravelP.txt");

	string codep, packageName,date,desc,priceS,availibility_s;
	int price,availability;
	if (!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (file.good())
	{
		for (int j = 0; j < 26; j++)
		{
			for (int i = 0; i < packageCount(j); i++)
			{
				codep = TravelPackData[j][i].getCode();
				packageName = TravelPackData[j][i].getPackName();
				date = TravelPackData[j][i].getDate();
				price = TravelPackData[j][i].getPrice();
				availability = TravelPackData[j][i].getAvailability();
				desc = TravelPackData[j][i].getDescription();
				priceS = "" + price;
				availibility_s = ""+availability;
				myReplace(packageName, " ", "_");
				myReplace(desc, " ", "_");

				file << codep << " " << packageName << " " << price << " " << date << " " << availability << " "<<desc<<endl;
			}
		}file.close();
	}
	
	ofstream file2("TravelerData.txt");

	string codeN, fName, sName, Nationality;
	int priceN, age;
	bool paid;
	if (!file2.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (file2.good())
	{
		for (int j = 0; j < 26; j++)
		{
			for (int i = 0; i < packageCount(j); i++)
			{
				while (TravelPackData[j][i].getTraveler().itterate != NULL)
				{
					codeN = TravelPackData[j][i].getTraveler().itterate->customerList.getCode();
					fName = TravelPackData[j][i].getTraveler().itterate->customerList.getFirstName();
					sName = TravelPackData[j][i].getTraveler().itterate->customerList.getSurName();
					Nationality = TravelPackData[j][i].getTraveler().itterate->customerList.getCitizenship();
					priceN = TravelPackData[j][i].getTraveler().itterate->customerList.getPrice();
					age = TravelPackData[j][i].getTraveler().itterate->customerList.getAge();
					paid = TravelPackData[j][i].getTraveler().itterate->customerList.getPaid();
					myReplace(fName, " ", "_");
					myReplace(sName, " ", "_");

					file2 << codeN << " " << fName << " " << sName << " " << age << " " << Nationality << " " << paid << " " << priceN << " " << endl;
					TravelPackData[j][i].getTraveler().moveItterate();
				}
			}
		}file2.close();
	}
	
}

void FunctionController::printExistingPack()
{
	int count = 1;
	cout << "----------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "||" << setw(3) << "No." << "||" << setw(15) << "code" << "||" << setw(30) << "Name" << "||" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < TravelPackData[j].size(); i++)
		{
			cout << "||" << setw(3) << count << "||" << setw(15) << TravelPackData[j][i].Pcode << "||" << setw(30) << TravelPackData[j][i].packName << "||" << endl;
			count++;
		}
	}

}

void FunctionController::printview(int hash,int index)
{
		cout << "||"  << setw(15) << TravelPackData[hash][index].getCode() << "||" << setw(30) << TravelPackData[hash][index].getPackName() << "||"
			<<setw(12)<<TravelPackData[hash][index].getPrice() <<"||"<<setw(10)<< TravelPackData[hash][index].getFormattedDate() <<"||"<<endl;
}