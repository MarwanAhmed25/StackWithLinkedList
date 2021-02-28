//program to impliment stack datastructure by using single linkedlist;
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int v, Node* n = nullptr)
	{
		value = v;
		next = n;
	}
	//setting vlaue of currnt node;
	void setValue(int v)
	{
		value = v;
	}
	//setting next of next node;
	void setNext(Node* n)
	{
		next = n;
	}
	//return vlaue of currnt node;
	int getValue()
	{
		return value;
	}
	//return address of next node;
	Node* getNext()
	{
		return next;
	}
private:
	int value;
	Node* next;
};
//class LinkedList create list of Nodes;
class LinkedList
{
public:
	/// <summary>
	/// constractor of this class whitch call member function Push(int) to add new Node;
	/// </summary>
	/// <param name="data"></param>
	LinkedList(int data)
	{
		Push(data);
	}
	/// <summary>
	/// member function for deleting last node of list ;
	/// </summary>
	void Pop()
	{
		node = head;
		head = head->getNext();
		delete node;
	}
	/// <summary>
	/// member function for adding new Node in list;
	/// </summary>
	/// <param name="data"></param>
	void Push(int data)
	{
		if (head == NULL)
			head = new Node(data);
		else
		{
			node = new Node(data);
			node->setNext(head);
			head = node;
		}
	}
	/// <summary>
	/// membrer function for show nodes of list;
	/// </summary>
	void DisplayAll()
	{
		node = head;
		while (node)
		{
			cout << node->getValue()<<"   ";
			node = node->getNext();
		}
	}
	/// <summary>
	/// member function for returning number of nodes in list;
	/// </summary>
	/// <returns>sinze of list(int)</returns>
	int Size()
	{
		count = 0;
		node = head;
		while (node)
		{
			count++;
			node=node->getNext();
		}
		return count;
	}
	/// <summary>
	/// member function for clearing all nodes of list; 
	/// </summary>
	void ClearAll()
	{
		while (head)
		{
			node = head;
			head = head->getNext();
			delete node;
		}
	}
	//destractor of class call member funtion ClearAll() ;
	~LinkedList()
	{
		ClearAll();
	}
private:
	int count;
	Node* head;
	Node* node;
};

int main()
{
	LinkedList* list = new LinkedList(0);
	list->Push(1);
}
