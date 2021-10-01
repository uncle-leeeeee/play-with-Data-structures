#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> *Linklist = new LinkedList<int>();
    //向链表加入元素
    for (int i = 0; i < 10; i++)
    {
        Linklist->addFirst(i);
    }
    Linklist->print();
    Linklist->add(2, 20);
    Linklist->print();
    cout << Linklist->ifContain(20) << endl;
    Linklist->addLast(0);
    Linklist->print();
    cout << Linklist->get(5) << endl;
    Linklist->set(5, 10);
    Linklist->print();

    return 0;
}