#pragma once
#include <string>
#include "FunctionController.h"

class UserInterface
{
private:
	//don't create another instace here.
	FunctionController functionController;
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
		//every time ada menu, give a heading yang memperjelas ini di menu apa, and an option to balik to main menu
		//good work man
		cout<<"[1]. Add from the existing package."<<endl;
		cout<<"[2]. Add new package."<<endl;
		cin>> option;
		if(option == 1){
			for(int i = 0 ; i< functionController.TravelPackData.size();i++){
				cout<< functionController.TravelPackData[i].getCode() << functionController.TravelPackData[i].getPackName()<<endl;
			}

			cout<<"Input index"<<endl;
			cin>> index;
			
			cout<<"Number of date you want to add:"<<endl;
			cin>>numDate;

				for(int i = 0 ; i < numDate;i++){
				cout<<"Input date:"<<endl;
				cin>> date;
				TravelPack n= functionController.TravelPackData[index];
				n.setDate(date) ;
				
				}
		}
		else if (option == 2)
		{
			
			//rapihin and give more guide (berapa character and validation)
			//use getline(cin,packName) instead, cus bisa kasih space
			//i think pake while loop "Number of date" kaya yang diatas juga perlu, cus pas mau bikin
			// mau tau juga berapa banyak yang dia mau,

			cout<<"input package code"<<endl;
			cin>>packCode;
			//give the user the freedom to choose mereka pilih code sendiri atau kita aja yang nentuin.
			cout<<"Input package name"<<endl;
			cin>>packName;
			cout<<"Input package price"<<endl;
			cin>>price;
			cout<<"Input package date"<<endl;
			cin>>date;
			//instead tanya date nya satu per satu and validasiin valid gak 
			cout<<"Input package availability"<<endl;
			cin>>availability;
			
			//cout something that tells the user (udah ke add loh)
			//and maybe tampilin lagi, "are u sure u want to create blabla)
			functionController.addNewItem(TravelPack(packCode,packName,price,date,availability));
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