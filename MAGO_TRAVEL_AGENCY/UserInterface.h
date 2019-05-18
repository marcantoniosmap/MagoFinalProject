#pragma once
#include <string>
#include "FunctionController.h"

class UserInterface
{
private:
	TravelPack TP;
	FunctionController FC;
public:

	void mainMenu();

	// void search() {

	// }
	// void book(){
	// 	string packageName,firstName,surname,citizenship;
	// 	int age,peopleCount;
	// 	cout<<"Input package name."<<endl;
	// 	cin>>packageName;
	// 	for(int i = 0 ; i< FC.TravelPackData.size() ;i++){
	// 		if(packageName == FC.TravelPackData[i].getCode());
	// 			cout<<"Input for how many people."<<endl;
	// 			cin>> peopleCount;
	// 			for(int i = 0 ; i< peopleCount;i++){
	// 				cout<<"Input first Name:"<<endl;
	// 				cin>> firstName;
	// 				customer.setFirstName(firstName);
	// 				cout<<"Input Surname."<<endl;
	// 				cin>>surname;
	// 				customer.setSurName(surname);
	// 				cout<<"Input Age:"<<endl;
	// 				cin>>age;
	// 				customer.setAge(age);
	// 				cout<<"Input Citizenship:"<<endl;
	// 				cin>>citizenship;
	// 			}
				

	// 		}
	// 	}

	// }
	// void checkStatus();

	void add(){
		string date,packName,packCode;
		int option,numDate,index,price,availability;
		cout<<"[1]. Add from the existing package."<<endl;
		cout<<"[2]. Add new package."<<endl;
		cin>> option;
		if(option == 1){
			for(int i = 0 ; i< FC.TravelPackData.size();i++){
				cout<<FC.TravelPackData[i].getCode() <<FC.TravelPackData[i].getPackName()<<endl;
			}

			cout<<"Input index"<<endl;
			cin>> index;
			
			cout<<"Number of date you want to add:"<<endl;
			cin>>numDate;

				for(int i = 0 ; i < numDate;i++){
				cout<<"Input date:"<<endl;
				cin>> date;
				TravelPack n=FC.TravelPackData[index];
				n.setDate(date) ;
				
				}
		}
		else if (option == 2)
		{
			cout<<"input package code"<<endl;
			cin>>packCode;
			cout<<"Input package name"<<endl;
			cin>>packName;
			cout<<"Input package price"<<endl;
			cin>>price;
			cout<<"Input package date"<<endl;
			cin>>date;
			cout<<"Input package availability"<<endl;
			cin>>availability;
			TP.setCode(packCode);
			TP.setPackName(packName);
			TP.setPrice(price);
			TP.setDate(date);
			TP.setAvailability(availability);
			FC.addNewItem(TP);
		}
		
	}

	void addEditDelete(){
		int x;
		cout<<"[1].Add"<<endl;
		cout<<"[2].Edit"<<endl;
		cout<<"[3].Delete"<<endl;
		cin>> x;
		if(x == 1){
			add();
		}
		
		
	}
	// void editItem();
	// void deleteItem();
	UserInterface();
	~UserInterface();
};

#include"UserInterface.cpp"