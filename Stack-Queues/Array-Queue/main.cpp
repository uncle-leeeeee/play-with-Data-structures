#include <iostream>
#include "LoopQueue.h"
using namespace std;

int main()
{
    // ArrayQueue<int> *arrQ = new ArrayQueue<int>();
    // for (int i = 0; i < 10; i++)
    // {
    //     arrQ->enqueue(i);
    //     arrQ->print();

    //     if (i % 2 == 0)
    //     {
    //         arrQ->dequeue();
    //         arrQ->print();
    //     }
    // }
    // delete[] arrQ;
    // arrQ = nullptr;

    //测试循环队列

    LoopQueue<int> *lq = new LoopQueue<int>(10);
    for (int i = 0; i < 10; i++)
    {
        lq->enqueue(i);
        lq->print();
    }

    lq->enqueue(20);
    lq->enqueue(50);
    lq->print();
    lq->dequeue();
    lq->print();
    cout << lq->getSize() << " " << lq->getFront() << endl;
    delete[] lq;
    lq = nullptr;

    return 0;
}