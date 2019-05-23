#pragma once
#include <iostream>
#include <vector>
#include "customer.h"
#include "customerDataLL.h"
using namespace std;

class TravelPack
{
private:
	string code;
	string packName;
	string date; //year-month-date
	int price;
	int availability;
	customerDataLL traveler;
	
	string description;


public:
	TravelPack(const TravelPack&copy){
		this->packName = copy.packName;
		this->availability = copy.availability;
		this->description = copy.description;
		this->price = copy.price;
	}
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
	string getPackName()const;
	string getDate()const;
	int getIntDate();
	int getPrice()const;
	int getAvailability()const;
	customerDataLL getTraveler();
	string getDescription()const;
	TravelPack();
	TravelPack(string code,string packName,int price,string date,int availability);
	~TravelPack();
};
#include"TravelPack.cpp"
