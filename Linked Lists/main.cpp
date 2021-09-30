#include "linkedlist.h"

int main()
{
    linkedlist *head = NULL;

    pushList(&head, 10);

    pushList(&head, 11);

    pushList(&head, 101);

    pushList(&head, 11);

    pushList(&head, 101);

    pushList(&head, 103);

    pushList(&head, 103);

    printList(head);
    
    std::cout << "\n";

    std::cout << "count : " << countListRec(head) << std::endl;

    std::cout << "\n";
    
    for (int i = 0 ; i < countList(head) ; i++)
    {
        if(searchListNorm(head, 103) == true)
            deleteNodeRec(&head, 103);
    }

    deleteNodePos(&head, 0);

    std::cout << "\n";

    printList(head);

    deleteFullList(&head);

    printList(head);

    return 0;
}