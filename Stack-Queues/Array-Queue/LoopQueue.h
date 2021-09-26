#include "Queue.h"
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class LoopQueue : public Queue<T>
{
public:
    //无参构造函数
    LoopQueue()
    {
        data = new T[10];
        front = 0;
        tail = 0;
        capacity = 10;
    }

    //有参构造函数
    LoopQueue(int capacity)
    {
        data = new T[capacity];
        front = 0;
        tail = 0;
        this->capacity = capacity;
    }
    //析构函数
    ~LoopQueue()
    {
        delete[] data;
        data = nullptr;
    }
    //通过队首和队尾下标是否一致判断是否为空，因此循环队列无法沿用
    bool isEmpty()
    {
        return front == tail;
    }

    T getFront()
    {
        //先判断队列是否为空
        assert(front != tail);
        return data[front];
    }
    //获取当前元素个数，无论tail在前还是后都可以
    int getSize()
    {
        return (tail - front + capacity) % capacity;
    }

    int getCapacity()
    {
        return capacity;
    }

    //入队，首先要判断当前队列是否已满,满了须扩容
    void enqueue(T e)
    {
        if ((tail + 1) % capacity == front)
        {
            resize(capacity * 2); //这里的resize函数很重要。
        }
        data[tail] = e;
        tail = (tail + 1) % capacity; //调整tail的位置，但如果没有及时更新容量，可能会造成tail和front重合，最后导致判断队列为空，没有输出结果。
    }
    //出队，记得从队首出队
    T dequeue()
    {
        //先判断队列是否为空
        assert(front != tail);
        T e = data[front];
        front = (front + 1) % capacity;
        //判断是否需要改变数组大小
        if (getSize() == capacity / 4 && capacity / 2 != 0)
        {
            resize(capacity / 2);
        }
        return e;
    }

    //输出函数
    void print()
    {
        cout << "LoopQueue: size= " << getSize() << ", capacity= " << capacity << endl;
        cout << "front[";
        for (int i = front; i != tail; i = (i + 1) % capacity)
        {
            cout << data[i];
            //判断是否最后一个输出，如果不是则输出一个逗号
            if ((i + 1) % capacity != tail)
            {
                cout << ",";
            }
        }
        cout << "] tail" << endl;
    }

private:
    T *data;
    int front, tail; //这里的尾部指向最后一个元素再后一位。
    int capacity;

    //将数组空间容量进行改变，放到私有成员，不允许外界直接访问
    void resize(int newCapacity)
    {
        T *newdata = new T[newCapacity + 1]; //由于多出一位元素为空，所以这里要在多加哎
        //把旧数组元素放入新数组
        for (int i = 0; i < getSize(); i++)
        {
            newdata[i] = data[(front + i) % capacity]; //怎么取旧数组的元素要考虑得比较细。
        }

        data = newdata;   //将data指针指向新数组
        tail = getSize(); //由于新数组是从0到size都有元素,更新tail为getSize()
        front = 0;
        capacity = newCapacity; //这里要重新赋值为新的capacity，不然会造成难以发现的错误
        newdata = nullptr;
    }
};