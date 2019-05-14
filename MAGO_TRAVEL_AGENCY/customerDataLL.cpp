#include "customerDataLL.h"



customerDataLL::customerDataLL()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	itterate = head;
	count = 0;
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
		head = n;
		tail = n;
		tail->prev = NULL;
	}
	else
	{
		tail->link = n;
		n->prev = tail;
		tail = n;
	}
	count++;
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