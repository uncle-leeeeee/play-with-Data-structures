#include <iostream>
#include "ArrayStack.h"
#include "LinkedListStack.h"
using namespace std;

int main()
{
    //简单测试1
    // ArrayStack<int> *arraystack = new ArrayStack<int>();
    // for (int i = 0; i < 5; i++)
    // {
    //     arraystack->push(i);
    // }
    // cout << arraystack->pop() << endl;
    // arraystack->print();
    // arraystack = nullptr;
    //delete arraystack;

    LinkedListStack<int> *linkedliststack = new LinkedListStack<int>();
    for (int i = 0; i < 5; i++)
    {
        linkedliststack->push(i);
        linkedliststack->print();
    }

    cout << linkedliststack->pop() << endl;
    linkedliststack->print();
    linkedliststack = nullptr;

    return 0;
}