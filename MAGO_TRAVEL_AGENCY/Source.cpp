#include <iostream>
#include "UserInterface.h"
 #include "FunctionController.h"
using namespace std;
 
int main()
{	UserInterface UI;

	while(true){
	
	TravelPack t("0038","3 days blabla",3000,"07062019",10);
	t.addCustomer((customer("0038", "Marc", "Purnama", 19, "Indonesian", 0, 3000)));
	t.getTraveler().displayAll();
	FunctionController run;	
	run.readFile();
	// run.TravelPackData[0].getTraveler().displayAll();
	
	UI.mainMenu(); 
	run.writeFile();
	}
	cin.ignore(); 
	return 0;
	}  