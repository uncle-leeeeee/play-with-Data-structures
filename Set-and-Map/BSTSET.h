#ifndef BSTSET_H
#define BSTSET_H

#include <iostream>
#include <string>
#include <vector>
#include "BST.h"
#include "Set.h"

template <class T>
class BSTSET : public Set<T> //继承父类Set
{
private: //私有成员一个二叉搜索树
    BST<T> *bst;

public:
    BSTSET()
    {
        bst = new BST<T>();
    }

    ~BSTSET()
    {
        std::cout << "BSTSET::~BSTSET()" << std::endl;
    }

    int getSize()
    {
        return bst->getsize();
    }

    void add(T e)
    {
        bst->add(e);
    }

    void remove(T e)
    {
        bst->remove(e);
    }

    bool contains(T e)
    {
        return bst->contains(e);
    }

    bool isEmpty()
    {
        return bst->isEmpty();
    }
};

#endif