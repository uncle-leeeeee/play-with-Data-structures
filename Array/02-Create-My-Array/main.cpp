#include <iostream>
#include "Array.h"
#include "Student.h"
using namespace std;

int main()
{

    Array<int> arr1 = Array<int>(20);
    for (int i = 0; i < 10; i++)
    {
        arr1.addLast(i);
    }
    arr1.print();
    arr1.add(1, 100); //在1位置添加100
    arr1.print();
    arr1.addFirst(-1);
    arr1.print();

    arr1.remove(2);
    arr1.print();

    arr1.removeElement(9);
    arr1.print();

    // Array<Student> arr2 = Array<Student>();
    // arr2.addFirst(Student("Alice", 100));
    // arr2.addLast(Student("Bob", 66));
    // arr2.print();

    for (int i = 0; i < 2; i++)
    {
        arr1.removeLast();
        arr1.print();
        arr1.removeFirst();
        arr1.print();
        arr1.addLast(1);
        arr1.addLast(1);
        arr1.addLast(1);
        arr1.addLast(1);
        arr1.print();
    }

    return 0;
}