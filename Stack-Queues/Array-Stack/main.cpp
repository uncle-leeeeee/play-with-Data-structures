#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main()
{
    //简单测试1
    ArrayStack<int> *arraystack = new ArrayStack<int>();
    for (int i = 0; i < 5; i++)
    {
        arraystack->push(i);
    }
    cout << arraystack->pop() << endl;
    arraystack->print();
    arraystack = nullptr;
    //delete arraystack;

    //括号匹配

    return 0;
}