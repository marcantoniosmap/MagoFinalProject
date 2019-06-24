#pragma once
#include <iostream>
#include "customerDataLL.h"
using namespace std;

class TravelPack
{
public:
	string Pcode;
	string packName;
	string date; //year-month-date
	int price;
	int availability;
	customerDataLL traveler;
	string description;


public:

	TravelPack(const TravelPack&copy);
	TravelPack(string Pcode, string packName, int price, string date, int availability,string desc);
	void setCode(string c);
	void setPackName(string name);
	void setPrice(int price);
	void setAvailability(int availability);
	void setDescription(string description);
	void addDescription(string description);
	void addCustomer(customer c);
	void setDate(string date);
	void initializeT();
	string getCode()const;
	string getAlphaCode();
	string getPackName()const;
	string getDate()const;
	string getFormattedDate();
	int getIntDate();
	int getPrice()const;
	int getAvailability()const;
	int getCurrentAvailability();
	customerDataLL getTraveler();
	int getTravelerNumber();
	string getDescription()const;
	
	~TravelPack();
};
