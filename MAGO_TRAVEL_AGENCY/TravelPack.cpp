#include "TravelPack.h"


//Constructor
TravelPack::TravelPack()
{
	
}
TravelPack::TravelPack(string code,string packName,int price,string date, int availability)
{
	this->code = code;
	this->packName = packName;
	this->date = date;
	this->price = price;
	this->availability = availability;
}


//setter and getter
void TravelPack::setCode(string c)
{
	this->code = c;
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
string TravelPack::getCode()
{
	return code;
}
string TravelPack::getPackName()const
{
	return packName;
}
string TravelPack::getDate()const
{
	return date;
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

customerDataLL TravelPack::getTraveler()
{
	return traveler;
}
string TravelPack::getDescription()const
{
	return description;
}
//Destructor
TravelPack::~TravelPack()
{
}
