#pragma once
#include <iostream>
#include <iomanip>
#include "customer.h"
using namespace std;

struct Node
{
	//node that store customers' data
	customer customerList;
	Node* link;
	Node* prev;
	
};

class customerDataLL
{
private:
//the pointers of node
	Node* head;
	Node* tail;
	Node* current;
	
public:
//construtors
	const Node* itterate;
	customerDataLL();
	~customerDataLL();
	customer* get(int i);
	//list of funtions
	void empty();
	int CustomerCount();
	void AddNewCustomer(customer addNew);
	void moveItterate();
	void displayAll();
	void deleteCustomer(int i);
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