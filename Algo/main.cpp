#include "LinkedListC.h"

int main()
{
    LinkedListC<int> list;
    list.addNode(20);
    list.addNode(10);
    list.addNode(5);
    list.addNode(2);
    list.printLL();
    std::cout << "\n";
    list.printLL();


}