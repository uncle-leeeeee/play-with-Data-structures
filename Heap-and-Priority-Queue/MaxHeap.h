#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H
#include "Array.h"

// create a binary tree by array
template <class T>
class MaxHeap
{
private:
    Array<T> *data;
    int leftchild(int index)
    {
        return index * 2 + 1;
    }
    int rightchild(int index)
    {
        return index * 2 + 2;
    }

    // lift the value at k
    void shiftUp(int k)
    {
        while (k > 0 && data->get(parent(k)) < data->get(k))
        {
            data->swap(k, parent(k));
            k = parent(k);
        }
    }

    // shift down the value at k
    void shiftDown(int k)
    {
        // check if the k out of index
        //通过这个逻辑，最后的叶子节点不需要shiftdown，可以通过shiftdown他们的parent来实现规整
        while (leftchild(k) < data->getSize())
        {
            // find the largest one between its children
            int j = leftchild(k);
            if (j + 1 < data->getSize() && data->get(j + 1) > data->get(j))
            {
                j++;
            }
            if (data->get(k) >= data->get(j))
            {
                break;
            }
            data->swap(k, j);
            k = j;
        }
    }

public:
    class NoParent
    {
    };

    class Empty
    {
    };
    // ctor
    MaxHeap(int capacity)
    {
        data = new Array<T>(capacity);
    }

    MaxHeap()
    {
        data = new Array<T>();
    }

    MaxHeap(T arr[], int n)
    {
        data = new Array<T>(arr, n);
        // reorganize the heap
        for (int i = parent(n - 1); i >= 0; i--)
        {
            shiftDown(i);
        }
    }

    int size()
    {
        return data->getSize();
    }

    bool isEmpty()
    {
        return data->isEmpty();
    }

    int parent(int index)
    {
        if (index == 0)
        {
            throw NoParent();
        }
        return (index - 1) / 2;
    }

    // add element and tune the order in array
    void add(T e)
    {
        data->addLast(e);
        shiftUp(data->getSize() - 1);
    }

    T findMax()
    {
        if (data->isEmpty())
        {
            throw Empty();
        }
        return data->get(0);
    }

    T extractMax()
    {
        T ret = findMax();
        data->swap(0, data->getSize() - 1); // swap first one and the last one
        data->removeLast();
        shiftDown(0);
        return ret;
    }

    T replace(T e)
    {
        T ret = findMax();
        data->set(0, e);
        shiftDown(0);
        return ret;
    }
};

#endif