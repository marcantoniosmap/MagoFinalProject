#pragma once
#include <iostream>
#include <vector>
#include "customer.h"
using namespace std;

class TravelPack
{
public:
	static int increment;
	string code;
	string packName;
	int date; //year-month-date
	int price;
	int availability;
	vector <customer> traveler;
	string description;


public:
	void setPackName(string name);
	void setPrice(int price);
	void setAvailability(int availability);
	void setDescription(string description);
	void addDescription(string description);
	void addCustomer(customer c);
	void setDate(int date);
	string getCode() const;
	string getPackName()const;
	int getDate()const;
	int getPrice()const;
	int getAvailability()const;
	string getDescription()const;
	TravelPack();
	TravelPack(string packName,int price,int availability);
	~TravelPack();
};


