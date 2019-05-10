#include <iostream>
#include "TravelPack.h"
using namespace std;

int main()
{
	TravelPack travel1("cool",20,3);
	travel1.setAvailability(4);
	cout << travel1.getAvailability();

	cin.ignore();
	return 0;
}