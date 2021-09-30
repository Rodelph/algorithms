#include "linkedlist.h"

int main()
{
    linkedlist *head = NULL;

    pushList(&head, 10);

    pushList(&head, 11);

    pushList(&head, 101);

    pushList(&head, 103);

    printList(head);

    searchListRec(head, 101);
    return 0;
}