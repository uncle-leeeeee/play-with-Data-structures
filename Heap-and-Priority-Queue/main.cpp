#include <iostream>
#include <ctime>
#include "MaxHeap.h"
#include <cassert>

template <typename T>
double testHeap(T testData[], int n, bool isHeapify)
{
    clock_t startTime = clock();
    MaxHeap<T> *maxHeap;
    if (isHeapify)
    {
        maxHeap = new MaxHeap<T>(testData, n);
    }
    else
    {
        maxHeap = new MaxHeap<T>();
        for (int i = 0; i < n; i++)
        {
            maxHeap->add(testData[i]);
        }
    }

    T *arr = new T[n];
    for (int j = 0; j < n; j++)
    {
        arr[j] = maxHeap->extractMax();
    }
    // std::cout << "after heapifying " << std::endl;
    // for (int i = 0; i < 20; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }

    for (int i = 1; i < 20; i++)
    {
        assert(arr[i - 1] >= arr[i]);
    }
    std::cout << "Test MaxHeap completed." << std::endl;
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main()
{
    int n = 10000000;
    int *testData = new int[n];
    for (int i = 0; i < n; i++)
    {
        testData[i] = rand() % INT32_MAX;
    }
    double time1 = testHeap(testData, n, false);

    std::cout << "without heapify: " << time1 << " s " << std::endl;
    double time2 = testHeap(testData, n, true);
    std::cout << "with heapify: " << time2 << " s " << std::endl;
    return 0;
}