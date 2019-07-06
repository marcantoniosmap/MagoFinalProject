//Author: MarcAntonio and Figo Aranta

#include "TravelPack.h"

//Constructor

TravelPack::TravelPack( string Pcode,string packName,int price, string date, int availability,string desc)
{
	
	this->packName = packName;
	this->Pcode = Pcode;
	this->price = price;
	this->date =date;
	this->availability = availability;
	this->description = desc;
	this->traveler.init();
}
TravelPack::TravelPack(const TravelPack&copy) {
	this->Pcode = copy.Pcode;
	this->packName = copy.packName;
	this->availability = copy.availability;
	this->description = copy.description;
	this->price = copy.price;
	this->date = copy.date;
	this->traveler.init();
}

//setter and getter
void TravelPack::setCode(string c)
{
	this->Pcode = c;
}

void TravelPack::setPackName(string name)
{
	this->packName = name;
}
void TravelPack::setPrice(int price)
{
	this->price = price;
}
void TravelPack::setAvailability(int availability)
{
	this->availability = availability;
}
void TravelPack::setDescription(string description)
{
	this->description = description;
}
void TravelPack::addDescription(string description)
{
	this->description += description;
}
void TravelPack::addCustomer(customer c)
{
	this->traveler.AddNewCustomer(c);
	
}
void TravelPack::setDate(string date)
{
	this->date = date;
}
void TravelPack::initializeT()
{
	this->traveler.empty();
}
string TravelPack::getCode()
{
	return Pcode;
}

string TravelPack::getAlphaCode()
{
	string alpha;
	for (int i = 0; i < Pcode.size(); i++)
	{
		if (isalpha(Pcode[i]))
		{
			alpha+=Pcode[i];
		}
	}
	return alpha;
}
string TravelPack::getPackName()
{
	return packName;
}

string TravelPack::getDate()
{
	return date;
}
string TravelPack::getFormattedDate()
{
	string year = ""+date[0] + date[1] + date[2] + date[3];
	string month = ""+date[4] + date[5];
	//string date = ""+date[6] + date[7];
	string rep = month + " - " + year;
	return rep;
}
int TravelPack::getIntDate()
{
	return stoi(date);
}

int TravelPack::getPrice()
{
	return price;
}
int TravelPack::getAvailability()
{
	return availability;
}
int TravelPack::getCurrentAvailability()
{
	return availability - traveler.CustomerCount();
}
customerDataLL TravelPack::getTraveler()
{
	return traveler;
}
int TravelPack::getTravelerNumber()
{
	return traveler.CustomerCount();
}


string TravelPack::getDescription()
{
	return description;
}

string TravelPack::getFormattedDescripition()
{
	string ret = "";
	string temp = "";
	for (int i = 0; i < description.size(); i++)
	{
		if (description[i] == ',')
		{
			ret +=temp;
			ret += "\n";
			temp = "";
		}
		else
		{
			temp += description[i];
		}
		
	}
	return ret;
}
//Destructor
TravelPack::~TravelPack()
{
}