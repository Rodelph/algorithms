#ifndef _LINKEDLISTC_
#define _LINKEDLISTC_

#include <iostream>

template<class Type>
class LinkedListC
{
    private:
        typedef struct node
        {
            Type info;
            node* link;
        }*NodePtr;

        NodePtr current;

    protected:
        NodePtr head;
        NodePtr temp;
        int count;

    public:
        LinkedListC();
        //~LinkedListC();

        void addNode(Type _info);
        void deleteNode(Type _info);

        int countNodes();

        void printLL();
};

template<class Type>
LinkedListC<Type>::LinkedListC()
{
    head = nullptr;
    current = nullptr;
    temp = nullptr;
    count = 0;
}

template<class Type>
int LinkedListC<Type>::countNodes()
{
    while (head != nullptr)
    {
        count++;
        head = head->link;
    }

    return count;
}

template<class Type>
void LinkedListC<Type>::addNode(Type _info)
{
    NodePtr newNode = new node;
    newNode->info = _info;
    newNode->link = nullptr;

    if (head != nullptr)
    {
        current = head;

        while (current->link != nullptr)
            current = current->link;

        current->link = newNode;
    }
    else
        head = newNode;
}

template<class Type>
void LinkedListC<Type>::deleteNode(Type _info)
{
    NodePtr delPtr = nullptr;
    temp = head;
    current = head;

    while (current != nullptr && current->info != _info)
    {
        temp = current;
        current = current->link;
    }

    if (current == nullptr)
    {
        std::cout << _info << " was not found in the list !";
        delete delPtr;
    }
    else
    {
        delPtr = current;
        current = current->link;
        temp->next = current;
        delete delPtr;
        std::cout << _info << " was deleted successfully !";
    }
}

template<class Type>
void LinkedListC<Type>::printLL()
{
    current = head;
    while (current != nullptr)
    {
        std::cout << current->info << "\n";
        current = current->link;
    }
}
#endif