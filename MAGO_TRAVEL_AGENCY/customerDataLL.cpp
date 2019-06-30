//Author: MarcAntonio and Figo Aranta

#include "customerDataLL.h"


customerDataLL::customerDataLL()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	itterate = head;
}
int customerDataLL::CustomerCount()
{
	int count = 1;
	Node* counter = head;
	if (head == NULL)
	{
		return 0;
	}
	try {
		while (counter->link != NULL)
		{
			count++;
			counter = counter->link;
		}
		return count;
	}
	catch (exception){
		return 0;
	}
	return 0;
}

customerDataLL::~customerDataLL()
{
}
void customerDataLL::moveItterate()
{
	itterate = itterate->link;
}
void customerDataLL::AddNewCustomer(customer addNew)
{
	Node* n = new Node;
	n->customerList = addNew;
	n->link = NULL;
	if (head == NULL)
	{
		head = tail = n;
		tail->prev = NULL;
	}
	else
	{
		tail->link = n;
		n->prev = tail;
		tail = n;
	}
}
void customerDataLL::displayAll()
{
	current = head;
	cout << "=============================" << endl;
	cout << "LIST OF TRAVELER" << endl;
	while (current != NULL)
	{
		cout << current->customerList.getFirstName() << endl;
		current = current->link;
	}
	
}
void customerDataLL::deleteCustomer()
{

}
void customerDataLL::search()
{

}

void customerDataLL::empty()
{
    head=NULL;
    tail=NULL;
    current = NULL;
	itterate = head;
}