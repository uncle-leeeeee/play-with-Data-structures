#include <iostream>
#include <cassert>
template <typename T>
class ListNode
{
public: //因为removeelement删除函数需要直接访问链表里面的元素，所以需要设置为公有成员。
    T val;
    ListNode<T> *next;
    ListNode(T x)
    {
        val = x;
        next = nullptr;
    }

    //利用数组进行初始化
    ListNode<T>(T arr[], int n)
    {
        assert(arr != nullptr && n != 0);
        val = arr[0];
        ListNode<T> *cur = this;
        for (int i = 1; i < n; i++) //通过数组里面的元素进行链表初始化
        {
            cur->next = new ListNode<T>(arr[i]);
            cur = cur->next;
        }
    }

    ~ListNode()
    {
        next = nullptr;
    }

    //输出函数
    void print()
    {
        ListNode<T> *cur = this;
        while (cur != nullptr)
        {
            std::cout << cur->val << "->";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};