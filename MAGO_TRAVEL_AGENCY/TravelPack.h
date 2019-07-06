//Author: MarcAntonio and Figo Aranta

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
//list of functions for travel pack and customer data
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
	string getCode();
	string getAlphaCode();
	string getPackName();
	string getDate();
	string getFormattedDate();
	int getIntDate();
	int getPrice();
	int getAvailability();
	int getCurrentAvailability();
	customerDataLL getTraveler();
	int getTravelerNumber();
	string getDescription();
	string getFormattedDescripition();
	
	~TravelPack();
};
