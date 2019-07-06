//Author: MarcAntonio and Figo Aranta

#include "customerDataLL.h"

// linkedlist to store customers' data
customerDataLL::customerDataLL()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	itterate = head;
}
//function to count the data in the list
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
//function to get the data
customer *customerDataLL::get(int i)
{
	current = head;
	while (current->link!= NULL && i >0)
	{
		current = current->link;
		i--;
	}
	return &current->customerList;
}

customerDataLL::~customerDataLL()
{
}
void customerDataLL::moveItterate()
{
	itterate = itterate->link;
}
//function to add new customer
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
//function to display all traveler data
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
// function to delete customer
void customerDataLL::deleteCustomer(int i)
{
	if (head != NULL)
	{
		Node*delPtr = new Node;
		current = head;
		while (current->link != NULL && i > 1)
		{
			current = current->link;
			i--;
		}
		delPtr = current;
		
		if (delPtr==head)
		{
			if (head->link == NULL)
			{
				head = NULL;
				tail == NULL;
				current = NULL;
			}
			else
			{
				head = head->link;
				head->prev = NULL;
			}
		}
		else if (delPtr == tail)
		{
			tail = tail->prev;
			tail->link = NULL;
		}
		else
		{
			Node* temp = delPtr->prev;
			Node* p = delPtr->link;
			temp->link = p;
			p->prev = temp;
		}
		delete delPtr;

	}
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