#pragma once

#include "customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
	customer customerList;
	Node*link;
	Node* prev;
	
};

class customerDataLL
{
private:
	Node* head;
	Node* tail;
	Node* current;
	
	int count;
public:
	const Node* itterate;
	customerDataLL();
	~customerDataLL();
	void AddNewCustomer(customer addNew);
	void moveItterate();
	void displayAll();
	void deleteCustomer();
	void search();

};

