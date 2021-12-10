#include <set>
#include <iostream>
#include <vector>

class Solution
{
public:
    void intersection(std::vector<int> nums1, std::vector<int> nums2)
    {
        std::set<int> s = std::set<int>();
        //遍历数组一的元素，并将其放入set中
        for (auto x : nums1)
        {
            s.insert(x);
        }
        std::vector<int> v1;
        //遍历数组二，如果在集合中出现过则放入新数组里面
        for (auto x : nums2)
        {
            if (s.count(x))
            {
                v1.push_back(x);
                s.erase(x); //并在集合中删除该元素
            }
        }

        for (auto x : v1)
        {
            std::cout << x << " ";
        }
    }
};
