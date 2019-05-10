#include "TravelPack.h"


//Constructor
TravelPack::TravelPack()
{
	this->code = increment++;
}
TravelPack::TravelPack(string packName,int price, int availability)
{
	this->code = "PKT" + increment;
	this->packName = packName;
	this->price = price;
	this->availability = availability;
}


//setter and getter
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
	this->traveler.push_back(c);
}
void TravelPack::setDate(int date)
{
	this->date = date;
}
string TravelPack::getCode() const
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
int TravelPack::getPrice()const
{
	return price;
}
int TravelPack::getAvailability()const
{
	return availability;
}
string TravelPack::getDescription()const
{
	return description;
}
//Destructor
TravelPack::~TravelPack()
{
}

int TravelPack::increment = 1;