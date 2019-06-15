#pragma once
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "FunctionController.h"
#include "customerDataLL.h"

class UserInterface
{
private:
	//don't create another instance here.
	FunctionController functionController;
	//I'm sorry man, im just gonna try.
	customerDataLL customerLL;
public:

	void mainMenu();

	void book(){
		string packCode,surName,firstName,citizenship,packName;
		int age,numPeople;
		for(int i = 0 ; i < functionController.TravelPackData.size();i++){
			cout<<functionController.TravelPackData[i].getCode()<<functionController.TravelPackData[i].getPackName()<<functionController.TravelPackData[i].getDate()<<endl;
		}
		cout<<"Which package do you wish to book."<<endl;
		cin>>packName;

		for(int i = 0 ; i < functionController.TravelPackData.size();i++){
			cout<<"lol"<<endl;
			if(functionController.TravelPackData[i].getPackName()==packName){
				cout<<"Input how many people do you wish to book"<<endl;
				cin>> numPeople;

				for(int j = 0 ; j<numPeople;i++){
					cout<<"Input Fisrt Name"<<endl;
					cin>> firstName;

					cout<<"Input Surname."<<endl;
					cin>>surName;

					cout<<"Input Age"<<endl;
					cin>>age;

					cout<<"Input citizenship"<<endl;
					cin>>citizenship;

					customerLL.AddNewCustomer(customer(firstName,surName,age,citizenship));
				}
			}
			else
			{
				cout<<"Error Goblog"<<endl;
			}
			
		}
		cout<<"Your Package has been booked successfully"<<endl;
		
	}

	void search() {
		int option;
		string packName;
		cout<<"Input package name"<<endl;
		cin>> packName;
		for(int i = 0; i < functionController.TravelPackData.size();i++){
			cout<<"pusing pala ae"<<endl;
			if(functionController.TravelPackData[i].getPackName()==packName){
				cout<< functionController.TravelPackData[i].getPrice()<<endl;
				cout<< functionController.TravelPackData[i].getAvailability()<<endl;
				cout<< functionController.TravelPackData[i].getDate()<<endl;
				cout<< functionController.TravelPackData[i].getPackName()<<endl;
			}
			else
			{
				cout<<"Invalid Input"<<endl;
				cout<<endl;
				cout<<"Would you like to try again?"<<endl;
				cout<<"Press[1] to retry"<<endl;
				cout<<"Press[2] to exit"<<endl;
				cin>>option;
				if(option == 1){
					search();
				}
				else if (option == 2)
				{
					cout<<"lol"<<endl;
					return;
				}
				else
				{
					return;
				}
				
				
			}
			
		}
	}

	void checkStatus(){
		cout<<"Current Status."<<endl;
		for(int i= 0 ; i< functionController.TravelPackData.size();i++){
			// cout<<functionController.TravelPackData[i].getCode()<<functionController.TravelPackData[i].getPackName()<<functionController.TravelPackData[i].getPrice()<<functionController.TravelPackData[i].getDate()<<functionController.TravelPackData[i].getAvailability() <<endl;
			cout<<functionController.TravelPackData[i].getPackName()<<endl;
		}
	}

	void add(){
		string date,packName,packCode;
		int option,numDate,index,price,availability;
		//every time ada menu, give a heading yang memperjelas ini di menu apa, and an option to balik to main menu
		//good work man

		cout<<"========================================"<<endl;
		cout<<"How do you want to add your new package."<<endl;
		cout<<"========================================"<<endl;
		cout<<"[1]. Add from the existing package."<<endl;
		cout<<"[2]. Add new package."<<endl;
		cin>> option;
		if(option == 1){
			for(int i = 0 ; i< functionController.TravelPackData.size();i++){
				cout<< i <<" "<< functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName()<<endl;
			}

			cout<<"Input index"<<endl;
			cin>> index;
			
			cout<<"Number of date you want to add:"<<endl;
			cin>>numDate;

				for(int i = 0 ; i < numDate;i++){
				cout<<"Input date:"<<endl;
				cin>> date;
				cout<<"Input code"<<endl;
				cin>>packCode;
				TravelPack n(functionController.TravelPackData[index]);
				n.setDate(date);
				n.setCode(packCode);
				functionController.addNewItem(n);
				cout<<"Your new package has been successfully added..."<<endl;
				
				}
		}
		else if (option == 2)
		{
			
			//rapihin and give more guide (berapa character and validation)
			//use getline(cin,packName) instead, cus bisa kasih space
			//i think pake while loop "Number of date" kaya yang diatas juga perlu, cus pas mau bikin
			// mau tau juga berapa banyak yang dia mau,
			cout<<"Input number of date you want to add"<<endl;
			cin>>numDate;
			for(int i = 0 ; i<numDate;i++){
			cout<<"input package code"<<endl;
			cin.ignore();
			getline(cin,packCode);
			//give the user the freedom to choose mereka pilih code sendiri atau kita aja yang nentuin.
			cout<<"Input package name"<<endl;
			getline(cin,packName);
			cout<<"Input package price"<<endl;
			cin>>price;
			cout<<"Input package date"<<endl;
			cin.ignore();
			getline(cin,date);
			
			//instead tanya date nya satu per satu and validasiin valid gak 
			cout<<"Input package availability"<<endl;
			cin>>availability;
			
			//cout something that tells the user (udah ke add loh)
			//and maybe tampilin lagi, "are u sure u want to create blabla)
			functionController.addNewItem(TravelPack(packCode,packName,price,date,availability));
			cout<<"Your new package has been successfully added..."<<endl;
		}
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
		else if( x == 2){
			editItem();
		}
		else if( x == 3){
			deleteItem();
		}
		
		
	}
	void editItem(){
	
		string packName, date;
		int index = 0;
		int element = 0;
		cout<<"Which package do you wish to edit."<<endl;
		cin>>packName;
		for(int i = 0 ; i <functionController.TravelPackData.size();i++){
			if(functionController.TravelPackData[i].getPackName() == packName){
			cout<<index<<"."<< functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName()<<functionController.TravelPackData[i].getDate() <<endl;
			}
			else
			{
				element++;
			}
			
			index++;
	}
	cout<<"Input Index of the package you wish to edit."<<endl;
	cin>>index;
	cout<<"Input your new Date."<<endl;
	cin>> date;
	functionController.TravelPackData[index+element].setDate(date);
	}

	void deleteItem(){
		int element = 0;
		string packCode;
		cout<<"Input the package code for the package you want to delete"<<endl;
		cin>>packCode;
		for(int i = 0; i < functionController.TravelPackData.size();i++){
			if(functionController.TravelPackData[i].getCode() == packCode){
				functionController.TravelPackData.erase(functionController.TravelPackData.begin()+element);
				 cout<<"Your package has been successfully deleted"<<endl;
				break;
			}
			else
			{
				element++;
			}
			
		}
	}
	UserInterface();
	~UserInterface();
};

#include"UserInterface.cpp"