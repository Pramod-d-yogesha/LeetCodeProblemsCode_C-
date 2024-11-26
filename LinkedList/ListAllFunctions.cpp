/*************************************************************
                  LINKED LIST

  Initial List = 100 90 80 70 60 50 40 30 20 10
==================================================

1:push_front 2:push_back
3:pop_front
4:pop_back
5:show_list
6:Reverse list
7:find
8:mid position list
9:checkList is cyclic
10:exit 
Enter the choice

****************************************************************/

#include <iostream>
#include<string>
#include<sstream>
using namespace std;
class Node
{
public:
	int val;
	Node* next;

	Node(): val(0),next(nullptr) {}
	Node(int v):val(v),next(nullptr) {}
	Node(int v,Node* nxt):val(v),next(nxt) {}
};
class LinkedList
{

public:
	Node* Head;
	void push_front(int value)
	{
		Node* temp=new Node(value);
		if(Head == nullptr)
		{
			Head=temp;
		}
		else
		{
			temp->next=Head;
			Head=temp;
		}

	}
	void pop_front()
	{
		if(Head == nullptr)
		{
			cout<<"The List is Empty"<<endl;
			return;
		}
		Node* temp=Head;
		Head=Head->next;
		delete(temp);
	}
	void show_list()
	{
		for(Node* temp=Head; temp!=nullptr; temp=temp->next)
		{
			cout<<temp->val<<" ";
		}
		cout<<endl;
	}
	void pop_back()
	{
		if(Head==nullptr)
		{
			cout<<"List is Null"<<endl;
			return;
		}
		Node* temp=Head;
		while(temp->next->next!=nullptr) {
			temp=temp->next;
		}
		Node* prev=temp;
		temp=temp->next;
		delete temp;
		prev->next=nullptr;
	}
	void push_back(int val)
	{
		Node* newNode=new Node(val);
		Node* temp=Head;
		if(Head == nullptr)
		{
			Head=temp;
		}
		else
		{
			while(temp->next!=nullptr) {
				temp=temp->next;
			}
			temp->next=newNode;

		}
	}
	void reverse_list()
	{
		Node *prevNode=NULL,*currentNode=Head,*nextNode;
		if(Head==nullptr)
		{
			cout<<"List is Null"<<endl;
			return;
		}
		while(nextNode!=nullptr)
		{
			nextNode=currentNode->next;
			currentNode->next=prevNode;
			prevNode=currentNode;
			currentNode=nextNode;

		}
		Head=prevNode;
	}
	void find(int val)
	{
		if(Head==nullptr)
		{
			cout<<"List is Null"<<endl;
			return;
		}
		int counter=0;
		for(Node* temp=Head; temp!=nullptr; temp=temp->next)
		{
			if(temp->val == val)
			{
				cout<<"The element found at "<<counter<<endl;
				return;
			}
			counter++;
		}
		cout<<"Element not found!...."<<endl;

	}
	void midListPosition()
	{
		Node* ptr1=Head,*ptr2=Head;
		int counter=0;
		while(ptr2!=nullptr && ptr2->next!=nullptr)
		{
			counter++;
			ptr1=ptr1->next;
			ptr2=ptr2->next->next;
		}
		cout<<"Mid List postion = "<<counter<<"\tvalue present="<<ptr1->val<<endl;
	}
	void checkCyclic()
	{
		Node* ptr1=Head,*ptr2=Head->next;
		if(Head==nullptr)
		{
			cout<<"List is empty"<<endl;
			return;
		}
		while(ptr2->next!=nullptr)
		{
			if(ptr1==ptr2)
			{
				cout<<"List is cyclic"<<endl;
				return;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next->next;
		}
		cout<<"List is not cyclic"<<endl;

	}
	~LinkedList() {
	    delete Head;
	}
};
int main()
{
	LinkedList list;
	int choice;
	list.push_front(10);
	list.push_front(20);
	list.push_front(30);
	list.push_front(40);
	list.push_front(50);
	list.push_front(60);
	list.push_front(70);
	list.push_front(80);
	list.push_front(90);
	list.push_front(100);
    cout<<"\t\tLINKED LIST\n"<<endl;
    cout<<"  Initial List = ";
    list.show_list();
    cout<<"==================================================\n"<<endl;
	while(1)
	{
		cout<<"1:push_front 2:push_back\n3:pop_front\n4:pop_back\n5:show_list"<<endl;
		cout<<"6:Reverse list\n7:find\n8:mid position list\n9:checkList is cyclic\n10:exit "<<endl;
		cout<<"Enter the choice"<<endl;
		cin>>choice;
		switch(choice)
		{

		case 1:
			cout<<"Enter Value : "<<endl;
			cin>>choice;
			list.push_front(choice);
			break;
		case 2:
			cout<<"Enter Value : "<<endl;
			cin>>choice;
			list.push_back(choice);
			break;
		case 3:
			list.pop_front();
			break;
		case 4:
			list.pop_back();
			break;
		case 5:
			list.show_list();
			break;
		case 6:
			list.reverse_list();
			break;
		case 7:
			cout<<"Enter Value : "<<endl;
			cin>>choice;
			list.find(choice);
			break;
		case 8:
			list.midListPosition();
			break;
		case 9:
			list.checkCyclic();
			break;
		case 10 :
			return 0;
		default :
			cout<<"Invalid choice"<<endl;

		}
	}
	return 0;
}
