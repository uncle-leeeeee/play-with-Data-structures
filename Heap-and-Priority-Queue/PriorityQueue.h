#ifndef HEAP_PRIORITYQUEUE_H
#define HEAP_RPIORITYQUEUE_H

#include "Queue.h"
#include "MaxHeap.h"

template <class T>
class PriorityQueue : public Queue<T>
{
private:
    MaxHeap<T> *maxHeap;

public:
    PriorityQueue()
    {
        maxHeap = new MaxHeap<T>();
    }

    int getSize()
    {
        return maxHeap->getSize();
    }

    bool isEmpty()
    {
        return maxHeap->isEmpty();
    }

    void enqueue(T e)
    {
        maxHeap->add(e);
    }

    T getFront()
    {
        return maxHeap->findMax();
    }

    T dequeue()
    {
        return maxHeap->extractMax();
    }

    void print()
    {
        std::cout << "This Priority Queue: size=  " << maxHeap->size() << std::endl;
        std::cout << "front ";
        maxHeap->print();
        std::cout << " tail" << std::endl;
    }
};

#endif