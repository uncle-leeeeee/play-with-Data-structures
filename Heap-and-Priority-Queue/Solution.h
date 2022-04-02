#include <iostream>
#include <vector>
#include <unordered_map>
#include "PriorityQueue.h"

class Solution
{
public:
    /***建立一个map存放值与频次；接着，建立通过maxheap实现的优先队列，频次越小优先级别越高，需要新建一个类并重载<>运算符，
     遍历map中元素，若PQ中未有k个元素，则添加该元素到队列中，否则比较队首元素的频次，比队首元素频次高，则入队
    ***/
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]] += 1;
        }
        PriorityQueue<Freq> *priorityQueue = new PriorityQueue<Freq>();
        for(unordered_map<int, int>::iterator it=record.begin();it!=record.end();++it){
            
        }
    }
};