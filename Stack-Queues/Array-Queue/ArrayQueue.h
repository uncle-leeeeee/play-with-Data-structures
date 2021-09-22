#include "Array.h"
#include "Queue.h"

template <typename T>
class ArrayQueue : public Queue
{
public:
    ArrayQueue() //无参构造函数
    {
        array = new Array<T>(10);
    }

    ArrayQueue(int capacity) //有参构造函数
    {
        array = new Array<T>(capacity);
    }

    ~ArrayQueue() //析构函数
    {
        delete[] array;  //手动删除该指针对应数组元素
        array = nullptr; //并且将该指针设置为空指针。
    }

    int getSize()
    {
        return array->getSize();
    }

    T dequeue() //分离队首元素并返回
    {
        return array->removeFirst();
    }

    T getFront() //获取队首元素
    {
        return array->getFirst();
    }

    void enqueue() //在队尾加入元素
    {
        array->addLast();
    }

    bool isEmpty() //判断该队列是否为空
    {
        return array->isEmpty();
    }

    //打印数组所有元素
    void print()
    {
        std::cout << "front" << endl;
        array->print();
        std::cout << "tail" << endl;
    }
    //设定包含的数组为私有成员
private:
    Array<T> *array;
};