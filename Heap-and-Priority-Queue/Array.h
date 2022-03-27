#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array
{
private:
    T *data;
    int size;
    int capacity;

    //重新分配数组容量空间
    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        data = newData;
        capacity = newCapacity;
    }

public:
    class Full
    {
    };
    class Range
    {
    };
    //构造函数
    Array(int capacity)
    {
        data = new T[capacity];
        size = 0;
        this->capacity = capacity;
    }

    Array()
    {
        data = new T[5];
        size = 0;
        capacity = 5;
    }

    int getCapacity()
    {
        return capacity;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void add(int index, T e)
    {
    }
};

#endif