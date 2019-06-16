#pragma once

#include  <iostream>
#include <string>
using namespace std;

class customer
{
private:
	string TravelCode;
	string firstname;
	string surname;
	int age;
	string citizenship;
	int price;
	bool paid;

public:
	customer();
	customer(string fName, string sName, int age, string citizenship);
	//for reading the txt file
	customer(string tc,string fName, string sName, int age, string citizenship, bool paid, int p);
	void setTravelCode(string code);
	void setFirstName(string fName);
	void setSurName(string sName);
	void setAge(int age);
	void setCitizenship(string citizenship);
	void setPaid(bool p);
	void setPrice(int p);
	string getCode()const;
	string getFirstName()const;
	string getSurName()const;
	int getAge()const;
	string getCitizenship()const;
	int getPrice()const;
	bool getPaid()const;
	~customer();
};

