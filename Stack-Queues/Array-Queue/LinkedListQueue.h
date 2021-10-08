#ifndef LINKLISTQUEUE_H
#define LINKLISTQUEUE_H

#include "Queue.h"
#include <cassert>
#include <iostream>

template <typename T>
class QNode
{
public:
    T e;
    QNode<T> *next;
    QNode(T e, QNode<T> *next) : e(e), next(next) {}
    QNode(T e) : e(e), next(nullptr) {}
    QNode() : e(), next(nullptr) {}
};

template <typename T>
class LinkedListQueue : public Queue<T>
{
public:
    LinkedListQueue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedListQueue()
    {
        head = nullptr;
        tail = nullptr;
        delete head;
        delete tail;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    //入队操作
    void enqueue(T e)
    {
        if (tail == nullptr)
        {
            tail = new QNode<T>(e);
            head = tail;
        }
        else
        {
            tail->next = new QNode<T>(e);
            tail = tail->next;
        }
        //记得维护队列元素个数
        size++;
    }

    T dequeue()
    {
        //判断当前队列是否为空。
        assert(!isEmpty());
        QNode<T> *TemNode = head;
        head = TemNode->next;
        TemNode->next = nullptr;
        //还需要判断，出队后，队列是否为空，如果为空，则tail指向也需要进行改变。
        if (head == nullptr)
        {
            tail = nullptr;
        }
        //维护元素个数
        size--;
        return TemNode->e;
    }

    //获取队首元素
    T getFront()
    {
        assert(isEmpty());
        return head->e;
    }

    //打印输出
    void print()
    {
        QNode<T> *prev = head;
        cout << "LinkedListQueue: size= " << size << endl;
        cout << "front"
             << "[";
        while (prev != nullptr)
        {
            cout << prev->e;
            if (prev->next != nullptr)
            {
                cout << ",";
            }
            prev = prev->next;
        }
        cout << "] tail" << endl;
    }

private:
    QNode<T> *head;
    QNode<T> *tail;
    int size;
};
#endif