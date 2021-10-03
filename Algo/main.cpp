#include "LinkedListC.h"

int main()
{
    LinkedListC<int> list;
   for (int i = 10 ; i < 100 ; i++)
        list.addNode(i);

    std::cout << "\n";

    list.addNodeAfter(1000, 10);
}