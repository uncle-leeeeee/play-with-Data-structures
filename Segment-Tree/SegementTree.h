#ifndef SEGMENT_TREE_SEMENTREE_H
#define SEGMENT_TREE_SEMENTREE_H

#include <cassert>

template <class T>
class SegmentTree
{
private:
    T *data;
    T *tree;
    int size;

    int leftChild(int index)
    {
        return index * 2 + 1;
    }

    int rightChild(int index)
    {
        return index * 2 + 2;
    }

public:
    SegmentTree(T[] arr, int n)
    {
        data = new T[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
        Tree = new T[4 * n];
        size = 4 * n;
    }

    int getSize()
    {
        return size;
    }

    T get(int index)
    {
        assert(index >= 0 && index < size);
        return data[index];
    }
};

#endif