#pragma once
#include <iostream>
#include <iomanip>
#include "customer.h"
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
	void empty();
	void AddNewCustomer(customer addNew);
	void moveItterate();
	void displayAll();
	void deleteCustomer();
	void search();

};
