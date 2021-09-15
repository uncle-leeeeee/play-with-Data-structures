#include <cassert>
#include <iostream>
using namespace std;
//创建出来的数组类要能够执行 增 删 改 查 操作。
class Array
{
private:
    int *data;
    int size;
    int capacity;

    //构建有参构造函数
public:
    Array(int capacity)
    {
        data = new int[capacity];
        size = 0; //size就是目前元素最大下标值
        this->capacity = capacity;
    }
    //构建无参构造函数
    Array()
    {
        data = new int[10];
        size = 0;
        capacity = 10;
    }

    //获取数组中元素个数
    int getSize()
    {
        return this->size;
    }

    //获取数组的容量大小
    int getCapacity()
    {
        return this->capacity;
    }

    //判断该数组是否为空
    bool isEmpty()
    {
        return size == 0;
    }

    //向数组类指定位置中添加元素
    void add(int index, int e)
    {
        //判断目前数组容量，以及index是否合法，当前size不能超过capacity
        assert(size < capacity && index >= 0 && index <= size);
        //index后面所有元素往后挪一位
        for (int i = size; i >= index + 1; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = e; //把元素放入index位置
        size++;          //更新size
    }

    //向所有元素后添加一个新元素
    void addLast(int e)
    {
        // assert(size < this->capacity); //先判断加入元素是否会越界
        // data[size] = e;
        // size++;
        add(size, e); //调用add函数
    }

    //在第一位添加一个元素
    void addFirst(int e)
    {
        add(0, e);
    }

    //获取index索引位置的元素，通过这样的方式可以保证用户无法接触到data数据，保证了数据的安全。
    int get(int index)
    {
        assert(index < size && index >= 0);
        return data[index];
    }

    //更新数组里面的元素
    void set(int index, int e)
    {
        assert(index < size && index >= 0);
        data[index] = e;
    }

    //数组输出函数
    void print()
    {
        if (isEmpty())
        {
            cout << "Array is empty!";
            return;
        }
        cout << "Array: size= " << this->size << " , capacity= " << getCapacity() << endl;
        cout << "[";
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i != size - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};