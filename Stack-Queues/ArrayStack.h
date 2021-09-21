#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack.h"
#include "Array.h"

template <typename T>
class ArrayStack : public Stack<T>
{
public:
    ArrayStack(int capacity) //有参构造函数
    {
        array = new Array<T>(capacity);
    }

    ArrayStack() //无参构造函数
    {
        array = new Array<T>();
    }

    ~ArrayStack() //析构函数
    {
        delete[] array;
        array = nullptr;
    }

    int getSize()
    {
        return array->getSize();
    }

    bool isEmpty()
    {
        return array->isEmpty();
    }

    void push(T e) //向栈顶压入元素，这里把元素压入了数组的尾部
    {
        array->addLast(e);
    }

    T pop() //弹出栈顶元素并删去
    {
        return array->removeLast();
    }

    T peek() //返回当前栈顶元素
    {
        return array->getLast();
    }

    void print()
    {
        std::cout << "ArrayStack: size=" << array->getSize() << " , capacity= " << array->getCapacity() << std::endl;
        std::cout << "bottom ";
        array->print();
        std::cout << "top";
    }

private:
    Array<T> *array;
};

#endif
