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
}
TravelPack::TravelPack(const TravelPack&copy) {
	this->Pcode = copy.Pcode;
	this->packName = copy.packName;
	this->availability = copy.availability;
	this->description = copy.description;
	this->price = copy.price;
	this->date = copy.date;
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
string TravelPack::getCode()const
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
string TravelPack::getPackName()const
{
	return packName;
}

string TravelPack::getDate()const
{
	return date;
}
string TravelPack::getFormattedDate()
{
	string year = ""+date[0] + date[1] + date[2] + date[3];
	string month = ""+date[4] + date[5];
	string date = ""+date[6] + date[7];
	return date + "-" + month + "-" + year;
}
int TravelPack::getIntDate()
{
	return stoi(date);
}

int TravelPack::getPrice()const
{
	return price;
}
int TravelPack::getAvailability()const
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


string TravelPack::getDescription()const
{
	return description;
}
//Destructor
TravelPack::~TravelPack()
{
}