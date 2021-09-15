#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array arr1 = Array(20);
    for (int i = 0; i < 10; i++)
    {
        arr1.addLast(i);
    }
    arr1.print();
    arr1.add(1, 100); //在1位置添加100
    arr1.print();
    arr1.addFirst(-1);
    arr1.print();
    return 0;
}