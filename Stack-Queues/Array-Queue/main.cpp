#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main()
{
    ArrayQueue<int> *arrQ = new ArrayQueue<int>();
    for (int i = 0; i < 10; i++)
    {
        arrQ->enqueue(i);
        arrQ->print();

        if (i % 2 == 0)
        {
            arrQ->dequeue();
            arrQ->print();
        }
    }
    delete[] arrQ;
    arrQ = nullptr;
    return 0;
}