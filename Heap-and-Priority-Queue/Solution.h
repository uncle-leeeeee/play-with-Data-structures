#include <iostream>
#include <vector>
#include <unordered_map>
#include "PriorityQueue.h"

/***建立一个map存放值与频次；接着，建立通过maxheap实现的优先队列，频次越小优先级别越高，需要新建一个类并重载<>运算符，
     遍历map中元素，若PQ中未有k个元素，则添加该元素到队列中，否则比较队首元素的频次，比队首元素频次高，则入队
***/