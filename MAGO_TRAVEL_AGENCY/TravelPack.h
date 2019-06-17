#pragma once
#include <iostream>
#include "customerDataLL.h"
using namespace std;

class TravelPack
{
public:
	string code;
	string packName;
	string date; //year-month-date
	int price;
	int availability;
	customerDataLL traveler;
	string description;


public:

	TravelPack(const TravelPack&copy);
	TravelPack(string code, string packName, int price, string date, int availability);
	TravelPack(string code, string packName, string price, string date, string availability)
	{
		this->code = code;
		this->packName = packName;
		this->price = stoi(price);
		this->date = date;
		this->availability = stoi(availability);
	}
	TravelPack(){}
	void setCode(string c);
	void setPackName(string name);
	void setPrice(int price);
	void setAvailability(int availability);
	void setDescription(string description);
	void addDescription(string description);
	void addCustomer(customer c);
	//void setDate(int date);
	void initializeT();
	string getCode()const;
	string getPackName()const;
	//int getDate()const;
	int getPrice()const;
	int getAvailability()const;
	customerDataLL getTraveler();
	string getDescription()const;
	
	~TravelPack();
};
#include"TravelPack.cpp"
