#pragma once
#include <iostream>
#include "customerDataLL.h"
using namespace std;

class TravelPack
{
private:
	string code;
	string packName;
	int date; //year-month-date
	int price;
	int availability;
	customerDataLL traveler;
	string description;


public:

	TravelPack(const TravelPack&copy);
	TravelPack(string code, string packName, int price, int date, int availability);
	TravelPack(){}
	void setCode(string c);
	void setPackName(string name);
	void setPrice(int price);
	void setAvailability(int availability);
	void setDescription(string description);
	void addDescription(string description);
	void addCustomer(customer c);
	void setDate(int date);
	void initializeT();
	string getCode()const;
	string getPackName()const;
	int getDate()const;
	int getPrice()const;
	int getAvailability()const;
	customerDataLL getTraveler();
	string getDescription()const;
	
	~TravelPack();
};
