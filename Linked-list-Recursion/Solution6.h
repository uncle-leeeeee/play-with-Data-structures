#include <iostream>
template <class T>
class Solution6
{
public:
    //定义一个去除特定元素的函数，要传入调用时的深度
    ListNode<T> *removeElements(ListNode<T> *head, int val, int depth)
    {
        print(depth);                                //表示这是在第几层调用该函数
        std::cout << "Call: remove " << val << "in"; //要删除的元素是
        head->print();                               //打印出目前的链表元素

        if (head == nullptr)
        {
            print(depth);
            std::cout << "Return: ";
            head->print();
            return head;
        }

        ListNode<T> *res = removeElements(head->next, val, depth + 1); //在下一个节点处递归调用
        print(depth);
        std::cout << "After remove" << val << ":";
        res->print();
        ListNode<T> *ret;
        if (head->val == val)
        {
            ret = res;
        }
        else
        {
            head->next = res;
            ret = head;
        }
        print(depth);
        std::cout << "Return:";
        ret->print();
        return ret;
    }
};

void print(int depth)
{
    for (int i = 0; i < depth; i++)
    {
        std::cout << "--";
    }
}