#include <cassert>
#include <iostream>
using namespace std;
//创建出来的数组类要能够执行 增 删 改 查 操作。

template <typename T>
class Array
{
private:
    T *data;
    int size;
    int capacity;

    //构建有参构造函数
public:
    Array(int capacity)
    {
        data = new T[capacity];
        size = 0; //size就是目前元素最大下标值
        this->capacity = capacity;
    }
    //构建无参构造函数
    Array()
    {
        data = new T[10];
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
    void add(int index, T e)
    {
        //判断目前数组容量，以及index是否合法，当前size不能超过capacity
        // assert(size < capacity && index >= 0 && index <= size);
        //优化版，当前size如果超过了capacity，则该数组容量翻倍
        assert(index >= 0 && index <= size);
        if (size == capacity)
        {
            resize(2 * capacity);
        }

        //index后面所有元素往后挪一位
        for (int i = size; i >= index + 1; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = e; //把元素放入index位置
        size++;          //更新size
    }

    //向所有元素后添加一个新元素
    void addLast(T e)
    {
        // assert(size < this->capacity); //先判断加入元素是否会越界
        // data[size] = e;
        // size++;
        add(size, e); //调用add函数
    }

    //在第一位添加一个元素
    void addFirst(T e)
    {
        add(0, e);
    }

    //获取index索引位置的元素，通过这样的方式可以保证用户无法接触到data数据，保证了数据的安全。
    int get(int index)
    {
        assert(index < size && index >= 0);
        return data[index];
    }

    //获取第一和第二个元素
    T getFirst()
    {
        //因为get方法本身已经帮助我们判断异常，因此继续借用其来判断
        return get(0);
    }

    T getLast()
    {
        return get(size - 1);
    }

    //更新数组里面的元素
    void set(int index, T e)
    {
        assert(index < size && index >= 0);
        data[index] = e;
    }

    //查找数组里面是否有元素e
    bool contains(T e)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == e)
            {
                return true;
            }
        }
        return false;
    }

    //返回查找元素的索引，找到返回i，否则返回-1
    int find(T e)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == e)
            {
                return i;
            }
        }
        return -1;
    }

    //从数组中删除index的元素，并返回被删除的元素
    T remove(int index)
    {
        assert(index < size && index >= 0);
        T e = data[index];                     //先把要删除的元素存起来
        for (int i = index; i < size - 1; i++) //从index+1开始，元素往前挪
        {
            data[i] = data[i + 1];
        }
        size--; //要记得更新size的位置。
        //如果删除后的size大小为原来容量的一半，则可以对数组容量进行调整
        if (size == capacity / 2 && capacity / 2 != 0)
        {
            resize(capacity / 2);
        }
        return e;
    }

    //从数组中删除第一个元素，返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }

    //从数组中删除最后一个元素，返回删除的元素
    T removeLast()
    {
        return remove(size - 1);
    }

    //从数组中删除元素e
    void removeElement(T e)
    {
        if (find(e) != -1)
        {
            remove(find(e));
        }
        else
        {
            cout << "该数组不存在该数";
        }
    }

    //定义调整数组容量函数
    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity]; //新开辟一个空间，将旧数组的数据放入新数组里面
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        data = newData; //更新旧数组的容量以及数据
        capacity = newCapacity;
        newData = nullptr; //将newData地址指向空指针
        delete[] newData;  //手动删除新数组指针
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