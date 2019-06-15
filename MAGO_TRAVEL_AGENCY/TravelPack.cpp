#include "TravelPack.h"

//Constructor

TravelPack::TravelPack(string code,string packName,int price,int date, int availability)
{
	this->code = code;
	this->packName = packName;
	this->price = price;
	this->date = date;
	this->availability = availability;
}
TravelPack::TravelPack(const TravelPack&copy) {
	this->packName = copy.packName;
	this->availability = copy.availability;
	this->description = copy.description;
	this->price = copy.price;
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
void TravelPack::setDate(int date)
{
	this->date = date;
}
void TravelPack::initializeT()
{
	this->traveler.empty();
}
string TravelPack::getCode()const
{
	return code;
}
string TravelPack::getPackName()const
{
	return packName;
}

int TravelPack::getDate()const
{
	return date;
}
//int TravelPack::getIntDate()
//{
//	return stoi(date);
//}

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