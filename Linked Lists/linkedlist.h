#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct linkedlist
{
    int info;
    linkedlist *link;
};

// Prints every node info in the list
void printList(linkedlist* _link) // Complexity is O(N)
{
    while(_link != nullptr)
    {
        std::cout << _link->info << "\n";
        _link = _link->link;
    }
}

// Inserts a new element after the head
void pushList(linkedlist **_list, int _info) // Complelxity is O(1)
{
    linkedlist *new_list = new linkedlist();
   
    new_list->info = _info; 
    new_list->link = (*_list);
    (*_list) = new_list;
}

// Inserts a new element after a specific node
void insertAfterList(linkedlist* _prevList, int _info)  // Complexity is O(1)
{
    if(_prevList == nullptr)
        return;
    
    linkedlist* newList = new linkedlist();
    newList->info = _info;
    newList->link = _prevList->link;
    _prevList->link = newList;
}

// Inserts an element at the end of the list

/*
This method can also be optimized to work in O(1) by keeping an extra pointer to the tail of linked list (double linked list)
*/
void insertAtEnd(linkedlist** _headList, int _info) //Complexity is O(n)
{
    linkedlist *newNode = new linkedlist();
    linkedlist *last = *_headList;

    newNode->info = _info;
    newNode->link = nullptr;

    if (*_headList == nullptr)
    {
        *_headList = newNode;
        return;
    }

    while (last->link != nullptr)
        last = last->link;
    
    last->link = newNode;
    return;
}

// Looks for a specific node (normal iteration)
bool searchListNorm(linkedlist* _headList, int _info) // Complexity is O(n)
{
    while(_headList != nullptr)
    {
        if(_headList->info == _info)
            return true;
        
        _headList = _headList->link;
    }
    return false;
}

// Looks for a specific node (recursive)
bool searchListRec(linkedlist* _headList, int _info) // Complexity is O(n)
{
    if (_headList == nullptr)
        return false;
    else if(_headList->info == _info)
        return true;
    else
        return searchListRec(_headList->link, _info);
}

// Deletes a specific node (normal iteration)
void deleteNode(linkedlist** _headList, int _info) // Complexity O(n)
{
    linkedlist *tmp = *_headList;
    linkedlist *prev = nullptr;

    if (tmp != nullptr && tmp->info == _info)
    {
        *_headList = tmp->link;
        delete tmp;
        return;
    }
    else 
    {
        while(tmp != nullptr && tmp->info != _info)
        {
            prev = tmp;
            tmp = tmp->link;
        }
    
        if (tmp == nullptr)
            return;

        prev->link = tmp->link;

        delete tmp;
    }
}

// Deletes a specific node (recursively)
void deleteNodeRec(linkedlist** _headList, int _info) // O(n)
{
    linkedlist *tmp = *_headList;
    linkedlist *prev = nullptr;

    if (tmp != nullptr && tmp->info == _info)
    {
        *_headList = tmp->link;
        delete tmp;
        return;
    }
    else if (tmp == nullptr)
    {
        delete tmp;
        return;
    }
    else if (tmp != nullptr && tmp->info != _info)
        deleteNodeRec(_headList, _info);
}

// finding the length of a linkedlist (normal)
int countList(linkedlist* _headList) // O(n)
{
    int count = 0;
    while (_headList != nullptr)
    {
        _headList = _headList->link;
        count++;
    }
    return count;
}

// finding the length of a linkedlit (recursive)
int countListRec(linkedlist *_headlist) // Complexity O(n)
{
    if (_headlist == nullptr)
        return 0;
    else if(_headlist != nullptr)
    {
        return 1 + countListRec(_headlist->link);
    }
}

// Deletes a node based on the pisition n-1
void deleteNodePos(linkedlist **_headList, int pos) // O(n)
{
    if (*_headList == nullptr)
        return;
    
    linkedlist *temp = *_headList;
    
    if(pos == 0)
    {
        *_headList = temp->link;
        delete temp;
        return;
    }

    for (int i = 0 ; temp != nullptr && i < pos - 1 ; i++)
        temp = temp->link;

    linkedlist *next = temp->link->link;

    delete temp->link;

    temp->link = next;
}

// Deletes the whole linked-list from the memory
void deleteFullList(linkedlist **_headList) // O(n)
{
    linkedlist *current = *_headList;
    linkedlist *next = nullptr;

    while(current != nullptr)
    {
        next = current->link;
        delete current;
        current = next;
    }

    *_headList = nullptr;
}

#endif //LINKEDLIST_H