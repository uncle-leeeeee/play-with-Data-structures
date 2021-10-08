#include <iostream>
#include "LoopQueue.h"
#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include <time.h>
using namespace std;

//定义一个测试函数，测试循环队列和普通数组队列的入队，出队效率
template <typename T>
double testQueue(T *queue, int opCount)
{
    clock_t starttime = clock();      //计时
    srand(60);                        //随机种子
    for (int i = 0; i < opCount; i++) //进行入队操作，如果是数组队列，则这里加上循环后的入队复杂度为O(n^2),而循环队列是O(n)
    {
        queue->enqueue(rand());
    }
    //出队操作
    for (int j = 0; j < opCount; j++)
    {
        queue->dequeue();
    }

    clock_t endtime = clock();
    return (endtime - starttime) / CLOCKS_PER_SEC; //计算运行时间
}

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

    // LoopQueue<int> *lq = new LoopQueue<int>(10);
    // for (int i = 0; i < 10; i++)
    // {
    //     lq->enqueue(i);
    //     lq->print();
    // }

    // lq->enqueue(20);
    // lq->enqueue(50);
    // lq->print();
    // lq->dequeue();
    // lq->print();
    // cout << lq->getSize() << " " << lq->getFront() << endl;
    // delete[] lq;
    // lq = nullptr;

    int opCount = 100000;
    // ArrayQueue<int> *arrQ = new ArrayQueue<int>();
    // cout << "ArrayQueue time: " << testQueue(arrQ, opCount) << " s" << endl;
    LoopQueue<int> *looQ = new LoopQueue<int>();
    cout << "LoopQueue time: " << testQueue(looQ, opCount) << endl;
    LinkedListQueue<int> *LLQ = new LinkedListQueue<int>();
    cout << "LinkedListQueue time: " << testQueue(LLQ, opCount) << endl;
    cout << "end";
    looQ = nullptr;
    LLQ = nullptr;
    delete looQ;
    delete LLQ;

    return 0;
}