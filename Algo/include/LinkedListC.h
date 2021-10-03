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
        NodePtr next;

    protected:
        NodePtr head;
        NodePtr temp;
        int count;
        bool empty, exist;
        int countPos;

    public:
        LinkedListC();
        ~LinkedListC();

        void addNode(Type _info);
        void addNodeAfter(Type _info, Type _prevInfo);
        void addAtEnd(Type _info);
        void deleteNode(Type _info);
        void deleteList();

        Type valueOfNode(int _pos);

        int countNodes();
        bool listIsEmpty();
        bool searchNode(Type _info);

        void printLL();
};

template<class Type>
LinkedListC<Type>::~LinkedListC() { LinkedListC<Type>::deleteList(); }

template<class Type>
void LinkedListC<Type>::deleteList()
{

    if (head != nullptr)
    {
        current = head;
        while (current != nullptr)
        {
            next = current->link;
            delete current;
            current = next;
        }
    }
    else
        std::cout << "The list is inexistant !\n";

    head = nullptr;
}

template<class Type>
LinkedListC<Type>::LinkedListC()
{
    head = nullptr;
    current = nullptr;
    next = nullptr;
    temp = nullptr;
    count = 0;
    countPos = 0;
    empty = false;
    exist = false;
}

template<class Type>
bool LinkedListC<Type>::searchNode(Type _info)
{
    current = head;
    while (current != nullptr)
    {
        current = current->link;
        if (current->info == _info)
            return true;
    }

    return false;
}

template<class Type>
Type LinkedListC<Type>::valueOfNode(int _pos)
{
    if (head == nullptr)
        std::cout << "The list is empty !\n";
    
    if (head->link != nullptr)
    {
        current = head;
        while (current->link != nullptr)
        {
            current = current->link;
            countPos++;

            if (countPos == _pos)
                return current->info;
        }
    }
}

template<class Type>
void LinkedListC<Type>::addAtEnd(Type _info)
{
    NodePtr newNode = new node;
    newNode->info = _info;
    newNode->link = nullptr;

    if (head == nullptr)
    {
        std::cout << "The list is empty !\n";
        delete newNode;
    }

    if (head->link != nullptr)
    {
        current = head;

        while (current->link != nullptr)
            current = current->link;
        
        if (current->link == nullptr)
            current->link = newNode;
    }
}

template<class Type>
void LinkedListC<Type>::addNodeAfter(Type _info, Type _prevInfo)
{
    NodePtr newNode = new node;
    newNode->info = _info;
    newNode->link = nullptr;

    if (head == nullptr)
    {
        std::cout << "The node that you want to insert after does not exist !\n";
        delete newNode;
        return;
    }


    
    if (head->link != nullptr)
    {
        current = head;

        while (current->link != nullptr)
        {
            if (current->info == _prevInfo)
            {
                newNode->link = current->link;
                current->link = newNode;
            }

            current = current->link;
        }
    }
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
bool LinkedListC<Type>::listIsEmpty()
{
    if (head == nullptr)
        empty = true;
    
    return empty;
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