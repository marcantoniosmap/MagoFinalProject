//Author: MarcAntonio and Figo Aranta

#include "FunctionController.h"


FunctionController::FunctionController()
{
	for (int i = 0; i < hashNum; i++)
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
	int hash = searchCode[0]% hashNum;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(50) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < TravelPackData[hash].size(); i++)
	{
		if (TravelPackData[hash][i].getCode().find(searchCode) != string::npos)
		{
			printview(hash,i);
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
}

void FunctionController::searchKeyword(string searchKey)
{
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(50) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < hashNum; j++)
	{
		for (int i = 0; i < packageCount(j); i++)
		{
			if (toLoweringRet(TravelPackData[j][i].getPackName()).find(searchKey) != string::npos || toLoweringRet(TravelPackData[j][i].getDescription()).find(searchKey) != string::npos)
			{
				printview(j,i);
			}
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
}

void FunctionController::searchDate(string date)
{
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(50) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < hashNum; j++)
	{
		for (int i = 0; i < TravelPackData[j].size(); i++)
		{
			if (TravelPackData[j][i].getDate().find(date) != string::npos)
			{
				printview(j,i);
			}
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
}

void FunctionController::searchAllName(string customerName)
{
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "			ALL CUSTOMER NAME" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(20) << "SurName" << "||" << setw(20) << "FirstName" << "||" << setw(10) << "Cost" << "||" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < hashNum; j++)
	{
		for (int i = 0; i < packageCount(j); i++)
		{
			Node* counter = TravelPackData[j][i].getTraveler().get_head();
			while (counter!= NULL && (toLoweringRet(counter->customerList.getSurName()).find(customerName) != string::npos || toLoweringRet(counter->customerList.getFirstName()).find(customerName) != string::npos))
			{
				cout << "||" << setw(15) << counter->customerList.getCode() << "||" << setw(20) << counter->customerList.getSurName() << "||" << setw(20) << counter->customerList.getFirstName() << "||" << setw(10) << counter->customerList.getPrice() << "||" << endl;
				counter = counter->link;
			}
		}
	}
	cout << "---------------------------------------------------------------------------------------------" << endl;
}

void FunctionController::searchNationality(string nationality)
{
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "			ALL CUSTOMER NAME (NATIONALITY)" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(20) << "SurName" << "||" << setw(20) << "FirstName" << "||" << setw(15) << "Citizenship" << "||" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (int j = 0; j < hashNum; j++)
	{
		for (int i = 0; i <packageCount(j); i++)
		{
			Node* counter = TravelPackData[j][i].getTraveler().get_head();
			while (counter != NULL && (toLoweringRet(counter->customerList.getCitizenship()).find(nationality) != string::npos))
			{
				cout << "||" << setw(15) << counter->customerList.getCode() << "||" << setw(20) << counter->customerList.getSurName() << "||" << setw(20) << counter->customerList.getFirstName() << "||" << setw(15) << counter->customerList.getCitizenship() << "||" << endl;
				counter = counter->link;
			}
		}
	}
	cout << "---------------------------------------------------------------------------" << endl;
}

void FunctionController::listAllCustomer(TravelPack *active)
{
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "			ALL CUSTOMER NAME " << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(20) << "SurName" << "||" << setw(20) << "FirstName" << "||" << setw(10) << "Cost" << "||" <<setw(7)<< "PAID"<< endl;
	cout << "---------------------------------------------------------------------------" << endl;
	Node* counter = active->getTraveler().get_head();
	while (counter != NULL)
	{
		cout << "||" << setw(15) << counter->customerList.getCode() << "||" << setw(20) << counter->customerList.getSurName() << "||" << setw(20) << counter->customerList.getFirstName() << "||" << 
			setw(10) << counter->customerList.getPrice() << "||" <<setw(7)<< counter->customerList.getPaidText()<<endl;
		counter = counter->link;
	}
	cout << "---------------------------------------------------------------------------" << endl;
}


void FunctionController::ListComplete(TravelPack *active)
{
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "			ALL CUSTOMER NAME " << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(5) << "No" << "||" << setw(20) << "SurName" << "||" << setw(20) << "FirstName" << "||" <<setw(20)<<"Citizenship"<<"||"<< setw(10) << "Cost" << "||" << setw(7) << "PAID" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	Node* counter = active->getTraveler().get_head();
	int count = 1;
	while (counter != NULL)
	{
		cout << "||" << setw(5) << count << "||" << setw(20) << counter->customerList.getSurName() << "||" << setw(20) << counter->customerList.getFirstName() << "||" <<
			setw(20)<< counter->customerList.getCitizenship()<<"||"<<setw(10) << counter->customerList.getPrice() << "||" << setw(7) << counter->customerList.getPaidText() << endl;
		counter = counter->link;
		count++;
	}
	cout << "---------------------------------------------------------------------------" << endl;
}
void FunctionController::listSimilar(TravelPack *active)
{
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "			SIMILAR PACKAGES" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "||" << setw(15) << "code" << "||" << setw(50) << "Name" << "||" << setw(12) << "price" << "||" << setw(10) << "date" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
	int hashKey = active->getCode()[0] % hashNum;
	for (int i = 0; i <packageCount(hashKey); i++)
	{
		if (active->getAlphaCode() == TravelPackData[hashKey][i].getAlphaCode()&& active->getDate() != TravelPackData[hashKey][i].getDate())
		{
			printview(hashKey, i);
		}
	}
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

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
	string codep, pname, date,desc,price_s,avail_s;
	int availability, hash;
	if (file.is_open())
	{
		while (file>>codep>>pname>>price_s>>date>>avail_s>>desc)
		{
			myReplace(pname, "_", " ");
			myReplace(desc, "_", " ");
			int price = stoi(price_s);
			availability = stoi(avail_s);
			hash = codep[0]% hashNum;
			TravelPackData[hash].push_back(TravelPack (codep, pname, price, date, availability,desc));
		}
		
		ifstream file2("TravelerData.txt");
		string codel, firstN, surN, Nationality,ages,prices,paids;
		bool paid;
		int age, price,hashTrav;
		if (file2.is_open()) {
			while (file2 >> codel >> firstN >> surN >> ages >> Nationality >> paids >> prices)
			{
				if (paids == "0") {
					paid = false;
				}
				else {
					paid = true;
				}
				age = stoi(ages);
				price = stoi(prices);
				myReplace(firstN, "_", " ");
				myReplace(surN, "_", " ");
				myReplace(Nationality, "_", " ");
				hashTrav = codel[0] % hashNum;
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
	string tres;

	string codep, packageName,date,desc,priceS,availibility_s;
	int price,availability;
	if (!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int j = 0; j < hashNum; j++)
		{
			for (int i = 0; i < packageCount(j); i++)
			{
				codep = TravelPackData[j][i].getCode();
				packageName = TravelPackData[j][i].getPackName();
				cout << packageName;
				date = TravelPackData[j][i].getDate();
				price = TravelPackData[j][i].getPrice();
				availability = TravelPackData[j][i].getAvailability();
				desc = TravelPackData[j][i].getDescription();
				priceS = to_string(price);
				availibility_s = to_string(availability);
				myReplace(packageName, " ", "_");
				myReplace(desc, " ", "_");

				file << codep << " " << packageName << " " << priceS << " " << date << " " << availibility_s << " "<<desc<<endl;
			}
		}
		file.close();
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
		for (int j = 0; j < hashNum; j++)
		{
			for (int i = 0; i < packageCount(j); i++)
			{
				Node* counter = NULL;
				if (TravelPackData[j][i].getTraveler().CustomerCount() > 0){
					counter = TravelPackData[j][i].getTraveler().get_head();
				}
				while (counter != NULL)
				{
					codeN = counter->customerList.getCode();
					fName = counter->customerList.getFirstName();
					sName= counter->customerList.getSurName();
					Nationality = counter->customerList.getCitizenship();
					priceN = counter->customerList.getPrice();
					age = counter->customerList.getAge();
					paid = counter->customerList.getPaid();
					myReplace(fName, " ", "_");
					myReplace(sName, " ", "_");
					myReplace(Nationality, " ", "_");

					file2 << codeN << " " << fName << " " << sName << " " << age << " " << Nationality << " " << paid << " " << priceN << " " << endl;
					counter = counter->link;
				}
			}
		}
		file2.close();
	}
	
}

bool FunctionController::deletePack(string codeDelete)
{
	int position = codeDelete[0] %hashNum;
	for (int i = 0; i < packageCount(position); i++)
	{
		if (TravelPackData[position][i].getCode() == codeDelete)
		{
			TravelPackData[position].erase(TravelPackData[position].begin() + i);
			return true;
		}
	}
	return false;
}

void FunctionController::printExistingPack()
{
	int count = 1;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "			ALL EXISTING PACKAGE" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "||" << setw(3) << "No." << "||" << setw(15) << "Package code" << "||" << setw(50) << "Package Name" << "||" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	for (int j = 0; j < hashNum; j++)
	{
		for (int i = 0; i < TravelPackData[j].size(); i++)
		{
			cout << "||" << setw(3) << count << "||" << setw(15) << TravelPackData[j][i].Pcode << "||" << setw(50) << TravelPackData[j][i].packName << "||" << endl;
			count++;
		}
	}

}

void FunctionController::printview(int hash,int index)
{
		cout << "||"  << setw(15) << TravelPackData[hash][index].getCode() << "||" << setw(50) << TravelPackData[hash][index].getPackName() << "||"
			<<setw(12)<<TravelPackData[hash][index].getPrice() <<"||"<<setw(10)<< TravelPackData[hash][index].getDate() <<"||"<<endl;
}

string FunctionController::toLoweringRet(string tolowered)
{
	string ret="";
	for (int i = 0; i < tolowered.size(); i++)
	{
		ret += tolowered[i];
	}
	return ret;
}