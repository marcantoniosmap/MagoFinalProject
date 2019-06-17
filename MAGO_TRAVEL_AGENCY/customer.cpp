// #include "customer.h"


customer::customer()
{
	firstname = "";
	surname = "";
	age = 5;
	citizenship = "";
	paid = false;
	price = 0;
	
}

customer::customer(string fName, string sName,int age, string citizenship)
{
	this->firstname =fName;
	this->surname = sName;
	this->age = age;
	this->citizenship = citizenship;
	this->paid = false;
	this->price = 0;

}

customer::customer(string tc,string fName, string sName, int age, string citizenship,bool paid,int p)
{
	this->TravelCode = tc;
	this->firstname = fName;
	this->surname = sName;
	this->age = age;
	this->citizenship = citizenship;
	this->paid = paid;
	this->price = p;

}
void customer::setTravelCode(string code)
{
	this->TravelCode = code;
}
void customer::setFirstName(string fName)
{
	this->firstname = fName;
}
void customer::setSurName(string sName)
{
	this->surname = sName;
}
void customer::setAge(int age)
{
	this->age = age;
}
void customer::setCitizenship(string citizenship)
{
	this->citizenship = citizenship;
}
void customer::setPaid(bool p)
{
	this->paid = p;
}
void customer::setPrice(int p)
{
	this->price = p;
}
string customer::getFirstName()const
{
	return firstname;
}
string customer::getSurName()const
{
	return surname;
}
int customer::getAge()const
{
	return age;
}
string customer::getCitizenship()const
{
	return citizenship;
}
bool customer::getPaid()const
{
	return paid;
}
int customer::getPrice()const
{
	return price;
}
string customer::getCode()const
{
	return TravelCode;
}
customer::~customer()
{
}