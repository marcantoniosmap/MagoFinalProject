#pragma once
#include <iostream>
#include <iomanip>
#include "customer.h"
using namespace std;

struct Node
{
	customer customerList;
	Node* link;
	Node* prev;
	
};

class customerDataLL
{
private:
	Node* head;
	Node* tail;
	Node* current;
	
public:
	const Node* itterate;
	customerDataLL();
	~customerDataLL();
	void empty();
	int CustomerCount();
	void AddNewCustomer(customer addNew);
	void moveItterate();
	void displayAll();
	void deleteCustomer();
	void search();
	void init()
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		itterate = head;
	}
	Node* get_head() {
		return head;
	}

};