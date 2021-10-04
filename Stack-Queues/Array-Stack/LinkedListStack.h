#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

template <typename T>
class LinkedListStack : public Stack<T>
{
private:
    LinkedList<T> *linkedlist;

public:
    LinkedListStack()
    {
        linkedlist = new LinkedList<T>();
    }

    int getSize()
    {
        return linkedlist->getSize();
    }

    bool isEmpty()
    {
        return linkedlist->isEmpty();
    }
    //压入栈顶
    void push(T e)
    {
        linkedlist->addFirst(e);
    }

    //弹出栈顶
    T pop()
    {
        return linkedlist->removeFirst();
    }

    //观察栈顶元素
    T peek()
    {
        return linkedlist->getFirst();
    }

    //打印输出
    void print()
    {
        cout << "Stack: size= " << linkedlist->getSize() << endl;
        cout << "top ";
        linkedlist->print();
        cout << "bottom " << endl;
    }
};

#endif