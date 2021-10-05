#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_

#include <iostream>
#include <list>

template<class Type>
class DoubleLinkedList
{
	private:
		typedef struct node 
		{

			Type info;
			node *linkF, *linkB;

		}* NodePtr;
		
		NodePtr current;
		NodePtr next;

	protected :
		NodePtr head;
		NodePtr temp;
		NodePtr end;

		int count, countPos;
		bool empty;

	public :
		DoubleLinkedList();
		~DoubleLinkedList();

		void addNode(Type _info);
		void prinktDLL();
};

template<class Type>
DoubleLinkedList<Type>::DoubleLinkedList()
{
	head = nullptr;
	temp = nullptr;
	end = nullptr;
	next = nullptr;

	count = 0;
	countPos = 0;
	empty = false;
}

template<class Type>
DoubleLinkedList<Type>::~DoubleLinkedList() { }

template<class Type>
void DoubleLinkedList<Type>::addNode(Type _info)
{
	NodePtr newNode = new node;
	newNode->info = _info;
	newNode->linkB = head;
	newNode->linkF = nullptr;

	if (head != nullptr)
	{
		current = head;

        while (current->linkF != nullptr)
            current = current->linkF;

		current->linkF = newNode;
		newNode->linkF = end;
	}
	else
	{
		head = newNode;
	}
}

template<class Type>
void DoubleLinkedList<Type>::prinktDLL()
{
	while (head != nullptr)
	{
		std::cout << head->info << "\n";
		head = head->linkF;
	}
}
#endif // !_DOUBLELINKEDLIST_